/* Add the following to restart.c in reread_params_after_loading_restart()
 * routine to include AGAMA */
#ifdef AGAMA
  if(ThisTask == 0 && All.MainPatternSpeed != all.MainPatternSpeed)
    warn("MainPatternSpeed modified from %g to %g while restarting at Time=%g", All.MainPatternSpeed, all.MainPatternSpeed,
         All.Time);
  All.MainPatternSpeed = all.MainPatternSpeed;
  if(ThisTask == 0 && All.ComponentPatternSpeed != all.ComponentPatternSpeed)
    warn("ComponentPatternSpeed modified from %g to %g while restarting at Time=%g", All.ComponentPatternSpeed, all.ComponentPatternSpeed,
         All.Time);
  All.ComponentPatternSpeed = all.ComponentPatternSpeed;

#endif
