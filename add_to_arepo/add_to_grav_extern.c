/* Add the following to grav_external.c in gravity_external_get_force() routine
 * to add AGAMA*/

#ifdef AGAMA
  double force[3];
  double currenttimemyr = All.Time * All.UnitTime_in_Megayears;

  Pot_force(pos, pot, force, All.BoxSize, currenttimemyr);
  
  acc[0] += force[0];
  acc[1] += force[1];
  acc[2] += force[2];
#endif
