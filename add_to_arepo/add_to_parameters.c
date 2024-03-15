/* Add the following lines to parameters.c within the read_parameter_file() routine
 * to include Agama */

#ifdef AGAMA
      strcpy(tag[nt], "MainPatternSpeed");
      addr[nt] = &All.MainPatternSpeed;
      id[nt++] = PARAM_REAL;
      strcpy(tag[nt], "ComponentPatternSpeed");
      addr[nt] = &All.ComponentPatternSpeed;
      id[nt++] = PARAM_REAL;
#endif
