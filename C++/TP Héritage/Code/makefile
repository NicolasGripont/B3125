#VARIABLES

MAKEFILE = makefile
EXE = TP4.exe
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = Shape.h Segment.h Point.h
REAL = $(INT:.h=.cpp) Main.cpp
OBJ = $(INT:.h=.o) Main.o
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = -std=c++11 -Wall -O3#-D TEST #-D MAP
EDLFLAGS = 
LIBS = 
LIBPATH =# -L
INCPATH =# -I
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


Main.o : Shape.h Segment.h Point.h Shape.cpp Segment.cpp Point.cpp $(MAKEFILE)
Shape.o : Shape.h Point.h Shape.cpp Point.cpp $(MAKEFILE)
Segment.o : Shape.h Segment.h Point.h Shape.cpp Point.cpp $(MAKEFILE)
Point.o : Point.h $(MAKEFILE)


$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core main.o


# $(SOS) : 
# 	./$(BACKUPFILE) $(MAKEFILE) $(INT) $(REAL) $(RESSOURCES) $(BACKUPFILE)

