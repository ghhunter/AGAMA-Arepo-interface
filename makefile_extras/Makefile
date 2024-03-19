# Add the following lines to the Makefile
# if using the public version of the code

ifeq (AGAMA, $(findstring AGAMA, $(CONFIGVARS)))
	OBJS	+= AGAMA/agama_pot.o
	INCL	+= AGAMA/agama_pot.h
	SUBDIRS	+= AGAMA
	CPPC = mpicxx -std=c++11 
	AGAMA_INCL = -I$(HOME)/Agama/src
	AGAMA_LIB = $(HOME)/Agama/exe/agama.so
	LINKER   = $(CPPC) -lgfortran 
endif