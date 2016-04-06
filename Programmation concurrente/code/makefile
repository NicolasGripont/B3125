#VARIABLES

MAKEFILE = makefile
EXE = Parking
COMP = g++
RM = rm
EDL = g++
ECHO = echo
CONFIG = Config.h
INT = Mere.h Simulation.h Entree.h Sortie.h
REAL = $(INT:.h=.cpp)
OBJ = $(INT:.h=.o)
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = -std=c++11 -Wall 
EDLFLAGS = $(LIBPATH)
LIBS = -ltp -lncurses -ltcl
INCLUDES = includes#/shares/public/tp/tp-multitache
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
	./$(BACKUPFILE) $(MAKEFILE) $(INT) $(REAL) $(RESSOURCES) $(BACKUPFILE) $(CONFIG)

Mere.o : Mere.h Simulation.h Entree.h Sortie.h $(CONFIG) $(MAKEFILE) 
Simulation.o : Simulation.h $(CONFIG) $(MAKEFILE)
Entree.o : Entree.h $(CONFIG) $(MAKEFILE)
Sortie.o : Sortie.h $(CONFIG) $(MAKEFILE)
