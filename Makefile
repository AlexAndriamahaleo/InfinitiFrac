# Makefile for EZ-Draw, on Unix and Windows
#
# 18/04/2014 - Edouard.Thiel@lif.univ-mrs.fr
#
# MODIFIED BY ANDRIAMAHALEO ALEX (C)
# FOR PERSONAL USE ONLY
# ALGORITHMIQUE PROJECT
#
# "LOGICIEL"
# VERSION 10.1.0 GCC V0.8
# UNIX UBUNTU 14.04 LTS


# Default system type. Override this on command line: make SYSTYPE=WIN32 ...
SYSTYPE = UNIX

#-------------------------- C O N F I G U R A T I O N -------------------------

ifeq ($(SYSTYPE),UNIX)

    # Unix/X11 systems (linux, Mac OS X, Cygwin, etc)               # SECTION A
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2 -g 
#Modification test
    #CFLAGS2 = -W -Wall -std=c99
    LIBS   = -lX11 -lXext
    LIBS_I = -lm

else ifeq ($(SYSTYPE),WIN32)

    # Windows, all versions                                         # SECTION B
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2
    LIBS   = -lgdi32
    LIBS_I = -lmsimg32

endif

# Add your executables at the end of the lists;                     # SECTION C
#   EXECS     to use ez-draw.o
#   EXECS_M   to use ez-draw.o and -lm
#   EXECS_IM  to use ez-draw.o, ez-image.o and -lm

EXECS = 

EXECS_M = 

EXECS_IM = 

# If your program needs extra modules, add the program              # SECTION D
# name in EXECS_PRO, the modules.o in OBJS_PRO, and the 
# libraries -l... in LIBS_PRO:

EXECS_PRO = logiciel
OBJS_PRO  = menu.o listep_op.o ppm.o flocon_koch.o koch_zoom.o mandel_calcul.o image_op.o cplx*.o pixel_op.o mandelbrot.o julia.o ppm_image.o menu_julia.o ez-image.o
# mandelbrot_zoom.o
LIBS_PRO  =

#----------------- E N D   O F   C O N F I G U R A T I O N --------------------

# Other variables
ifeq ($(SYSTYPE),UNIX)
    SHELL  = /bin/bash
    RM     = rm -f
    EXT    =
else ifeq ($(SYSTYPE),WIN32)
    SHELL  = 
    RM     = del
    EXT    = .exe
else
    $(error Wrong SYSTYPE - expect UNIX or WIN32)
endif

# On Windows, automaticaly appends "$(EXT)" to the executables
ifeq ($(SYSTYPE),WIN32)
    EXECS     := $(patsubst %,%$(EXT),$(EXECS))
    EXECS_M   := $(patsubst %,%$(EXT),$(EXECS_M))
    EXECS_IM  := $(patsubst %,%$(EXT),$(EXECS_IM))
    EXECS_PRO := $(patsubst %,%$(EXT),$(EXECS_PRO))
endif

#Modification test
EXECS_ALL = $(EXECS) $(EXECS_M) $(EXECS_IM) $(EXECS_PRO) $(EXECS_MAN)

%.o : %.c
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options for make : help all clean distclean"

all :: $(EXECS_ALL)


$(EXECS) : %$(EXT) : %.o ez-draw.o
	$(CC) -o $@ $^ $(LIBS)

$(EXECS_M) : %$(EXT) : %.o ez-draw.o
	$(CC) -o $@ $^ $(LIBS) -lm

$(EXECS_IM) : %$(EXT) : %.o ez-draw.o ez-image.o
	$(CC) -o $@ $^ $(LIBS) $(LIBS_I) -lm

$(EXECS_PRO) : %$(EXT) : %.o ez-draw.o $(OBJS_PRO)
	$(CC) -o $@ $^ $(LIBS) $(LIBS_I) $(LIBS_PRO)

clean ::
	$(RM) *.gch *.o core

distclean :: clean
	$(RM) *~ .*.swp $(EXECS_ALL)


