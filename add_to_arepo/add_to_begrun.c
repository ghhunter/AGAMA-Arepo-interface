/* Add the code below to begrun.c in the begrun1() routine
 * to include AGAMA */

#ifdef AGAMA
  potential_init();
  mpi_printf("AGAMA: Initialized potential.\n");
#endif
