#VARIABLES

MAKEFILE = makefile
EXE = TP4.exe
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = UnitTesting.h Shape.h SimpleShape.h ComplexShape.h Segment.h Rectangle.h ConvexPolygon.h Point.h Intersection.h Reunion.h Moveable.h ShapeManager.h Command.h ShapeCommand.h MoveShapeCommand.h AddShapesCommand.h RemoveShapesCommand.h ShapeFileManager.h
REAL = $(INT:.h=.cpp) Main.cpp
OBJ = $(INT:.h=.o) Main.o
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = -std=c++11 -Wall -O3 -D TEST #-D MAP
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

Main.o : UnitTesting.h Shape.h SimpleShape.h ComplexShape.h Segment.h Rectangle.h ConvexPolygon.h Point.h Intersection.h Reunion.h Moveable.h ShapeManager.h Command.h ShapeCommand.h MoveShapeCommand.h AddShapesCommand.h RemoveShapesCommand.h ShapeFileManager.h $(MAKEFILE)
Moveable.o : Moveable.h
Shape.o : Shape.h Moveable.h $(MAKEFILE)
SimpleShape.o : SimpleShape.h Shape.h  Moveable.h $(MAKEFILE)
ComplexShape.o : ComplexShape.h Shape.h  Moveable.h $(MAKEFILE)
Segment.o : Segment.h SimpleShape.h Shape.h Point.h SimpleShape.cpp Shape.cpp Point.cpp $(MAKEFILE)
Rectangle.o : Rectangle.h SimpleShape.h Shape.h Point.h $(MAKEFILE)
ConvexPolygon.o : ConvexPolygon.h SimpleShape.h Shape.h Point.h $(MAKEFILE)
Point.o : Point.h $(MAKEFILE)
Intersection.o : Intersection.h ComplexShape.h Shape.h Point.h $(MAKEFILE)
Reunion.o : Reunion.h ComplexShape.h Shape.h Point.h $(MAKEFILE)
ShapeManager.o : ShapeManager.h Reunion.h Intersection.h Segment.h Rectangle.h ConvexPolygon.h SimpleShape.h Shape.h Point.h Segment.h AddShapesCommand.h RemoveShapesCommand.h ShapeFileManager.h $(MAKEFILE)
Command.o : Command.h $(MAKEFILE)
ShapeCommand.o : ShapeCommand.h Command.h $(MAKEFILE)
MoveShapeCommand.o : MoveShapeCommand.h Command.h ShapeCommand.h $(MAKEFILE)
AddShapesCommand.o : AddShapesCommand.h  Command.h ShapeCommand.h $(MAKEFILE)
RemoveShapesCommand.o : RemoveShapesCommand.h  Command.h ShapeCommand.h $(MAKEFILE)
ShapeFileManager.o : Reunion.h Intersection.h Segment.h Rectangle.h ConvexPolygon.h SimpleShape.h Shape.h Point.h Segment.h $(MAKEFILE)
UnitTesting.o :Shape.h SimpleShape.h ComplexShape.h Segment.h Rectangle.h ConvexPolygon.h Point.h Intersection.h Reunion.h Moveable.h ShapeManager.h Command.h ShapeCommand.h MoveShapeCommand.h AddShapesCommand.h RemoveShapesCommand.h ShapeFileManager.h $(MAKEFILE)


$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core main.o


$(SOS) :
	./$(BACKUPFILE) $(MAKEFILE) $(INT) $(REAL) $(RESSOURCES) $(BACKUPFILE)

