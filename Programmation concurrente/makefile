#VARIABLES

MAKEFILE = makefile
EXE = Parking
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = Mere.h Simulation.h
REAL = $(INT:.h=.cpp)
OBJ = $(INT:.h=.o)
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = -std=c++11 -Wall #-O3 #-D PERF#-D TEST #-D MAP
EDLFLAGS = $(LIBPATH)
LIBS = -ltp -lncurses -ltcl
INCLUDES = includes
LIBPATH = -L$(INCLUDES)
INCPATH = -I$(INCLUDES)
CLEAN = clean
SOS = backup
BACKUPFILE = backup.sh
RESSOURCES = 


#RULES

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<


$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core


$(SOS) :
	./$(BACKUPFILE) $(MAKEFILE) $(INT) $(REAL) $(RESSOURCES) $(BACKUPFILE)

Mere.o : Mere.h Simulation.h $(MAKEFILE)
Simulation.o : Simulation.h $(MAKEFILE)
