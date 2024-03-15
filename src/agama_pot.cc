#include "galaxymodel_base.h"
#include "math_random.h"
#include "math_sphharm.h"
#include "math_spline.h"
#include "particles_io.h"
#include "potential_analytic.h"
#include "potential_base.h"
#include "potential_cylspline.h"
#include "potential_dehnen.h"
#include "potential_disk.h"
#include "potential_factory.h"
#include "potential_multipole.h"
#include "potential_composite.h"
#include "potential_utils.h"
#include "utils.h"
#include "utils_config.h"
#include "debug_utils.h"
#include "units.h"
#include "../allvars.h"

#include "../allvars.h"
#include "arepoconfig.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>

using potential::PtrPotential;
using potential::PtrDensity;

//Define internal units 
static unique_ptr<const units::InternalUnits> unit;//(All.UnitLength_in_cm, All.UnitTime_in_s);

//Define external units (Units used in AREPO)
static unique_ptr<const units::ExternalUnits> converter;//(unit,units::Kpc,units::kms,units::Msun);

//Define the potentials used
PtrPotential pot;
PtrPotential spiral;


//Potential initialisation
#ifdef __cplusplus
extern "C"{
#endif
void potential_init(void){
  //Define internal units
  unit.reset(new units::InternalUnits(All.UnitLength_in_cm, All.UnitTime_in_s));

  //Define external units (Units used in AREPO)
  converter.reset(new units::ExternalUnits(*unit,units::Kpc,units::kms,units::Msun));

  //Potential excluding spiral arm component
  pot = potential::readPotential("potential.ini",*converter);

  //Spiral arms, Li et al 2016
  spiral = potential::readPotential("spiral.ini",*converter);

  return;
}
#ifdef __cplusplus
}
#endif

//Compute force for rotating potential
#ifdef __cplusplus

extern "C"{ 
#endif

void Pot_force(double* pos, double* phi, double* dphi, double box, double time){
  coord::GradCar grad1,grad2,grad3,grad4;
  double coordx, coordy, coordz,x,y,z,x2,y2;
  double forcex,forcey,forcez,phi1,phi2;
  double theta, theta2;

    // Move origin to centre and transform into AGAMA units
  coordx = (pos[0]-0.5*box);
  coordy = (pos[1]-0.5*box);

#ifdef TWODIMS
  coordz = (pos[2]);
#else
  coordz = (pos[2]-0.5*box);
#endif

  // Current angle at given timestep
  theta =  All.MainPatternSpeed*units::kms/units::Kpc * time*units::Myr; // bar pattern angle
  theta2 = All.ComponentPatternSpeed*units::kms/units::Kpc * time*units::Myr; // spiral pattern angle 
  //Rotate particle to bar (unsure how to describe it)
  x = coordx*cos(theta) + coordy*sin(theta);
  y = coordy*cos(theta) - coordx*sin(theta);
  z = coordz;

  x2 = coordx*cos(theta2) + coordy*sin(theta2);
  y2 = coordy*cos(theta2) - coordx*sin(theta2);

  // Calculate potential and gradients from potentials
  pot->eval(coord::PosCar(x,y,z), &phi1 ,&grad1,NULL,time*unit->from_Myr); // axissym pot + bar
  spiral->eval(coord::PosCar(x2,y2,z), &phi2, &grad2, NULL,time*unit->from_Myr); //spiral arms

  *phi = phi1 + phi2;

  //Forces due to bar (maybe rotation function?)
  dphi[0] =  (-grad1.dx*cos(theta) + grad1.dy*sin(theta));
  dphi[1] =  (-grad1.dy*cos(theta) - grad1.dx*sin(theta));
  dphi[2] =  -grad1.dz;


  //Forces due to spiral arms
  dphi[0] +=  (-grad2.dx*cos(theta2) + grad2.dy*sin(theta2));
  dphi[1] +=  (-grad2.dy*cos(theta2) - grad2.dx*sin(theta2));
  dphi[2] +=  -grad2.dz;

  return;
}
#ifdef __cplusplus
}
#endif
