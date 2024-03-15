# AREPO Makefile
#   see documentation/getting_started.md
#
# Add source and header files for new modules below.
# Add libraries for new modules in makefiles/modules-lib.make.

ifeq (AGAMA, $(findstring AGAMA, $(CONFIGVARS)))
  OBJS    += AGAMA/agama_pot.o
  INCL    += AGAMA/agama_pot.h
  SUBDIRS += AGAMA
endif

