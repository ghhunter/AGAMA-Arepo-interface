# AREPO Makefile
#   see documentation/getting_started.md
#
# Add code below to makefiles/module.make
# of Arepo to add AGAMA module if using dev version
ifeq (AGAMA, $(findstring AGAMA, $(CONFIGVARS)))
  CPPC = mpicxx -std=c++11 
  AGAMA_INCL = -I$(HOME)/Agama/src
  AGAMA_LIB = $(HOME)/Agama/exe/agama.so
  LINKER   = $(CPPC) -lgfortran 
endif

