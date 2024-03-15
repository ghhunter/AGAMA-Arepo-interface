AGAMA
=====

The AGAMA module allows for the computation of the acceleration due to the gravitational potential of a given galaxy. AGAMA is a public software library that allows for the modelling and testing of various gravitational systems and provides a library of potentials. The software library is available at: http://github.com/GalacticDynamics-Oxford/Agama

Usage
-----

1. AGAMA must be downloaded and compiled separately (see http://github.com/GalacticDynamics-Oxford/Agama). Check out the INSTALL file.

2. AGMA should be linked to Arepo as an external library. Arepo currently searches for the library under $(HOME)/Agama/src and $(HOME)/Agama/exe/agama.so. 
If they are elsewhere, the ``AGAMA_INCL`` and ``AGAMA_LIB`` variables in `makefile/modules-lib.make` file should point to [Agamadir]/src where [AgamaDir] is the directory where Agama was installed.
In order for the AGAMA to work with the code, ``EXTERNALGRAVITY`` must be on in `Config.sh` as the interface communicates with Arepo via this part of the code.
When all this is setup you can compile Arepo normally with `make`.

3. When AGAMA is enabled, it calculates the acceleration of any particle or gas cell at given point due to the galaxy potential provided in a potential.ini file in the same directory as the Arepo exacutable. The acceleration is then added to any exisiting acceleration being experienced by the particle or gas cell.

The files to generate the potential can be found in the MW_model2D directory of the examples which replicates the 2D Milky Way simulation of Hunter et al. in prep.

Additional Parameters 
---------------------

You can set the pattern speeds of rotating components. Here are the recommended values for a Milky-Way like potential.

* ``MainPatternSpeed``  Angular speed of the main pattern. For the MW's bar it is -37.5 km/s/kpc.
* ``AdditionalComponent`` ToDo - For now the additional component is always on.
* ``ComponentPatternSpeed``  Angular speed of the secondary pattern. For the MW's spiral arm it is -22.5 km/s/kpc.

Additional Config.sh Options
----------------------------

AGAMA
    master switch to enable AGAMA

Authors
-------
* Glen H. Hunter (glen.hunter@uni-heidelberg.de)

Usage Policy and Citation
-------------------------

Please contact the authors before carrying out any development work on this module.

If AGAMA is used in a publication, please cite the following:

Vasiliev E.,2019,MNRAS, 482, 1525. doi:10.1093/mnras/sty2672

and add the link to the AGAMA repository as a footnote: http://github.com/GalacticDynamics-Oxford/Agama
=======
