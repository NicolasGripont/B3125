/*************************************************************************
ShapeManager - Header file of the class <ShapeManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:36:19
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ShapeManager> (file ShapeManager.h)
#if ! defined ( ShapeManager_H )
#define ShapeManager_H

//-------------------------------------------------------- Used interfaces 
#include <string>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <unordered_map>
using namespace std;

#include "Point.h"
#include "Shape.h"
#include "Command.h"
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <ShapeManager>
// Class which is the controller of the application. This class allows to
// manage some shapes : creation, suppression, move, load of file, save in
// file.
// This class is a singleton.
//------------------------------------------------------------------------

class ShapeManager
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

static ShapeManager & GetInstance();
// Manual : Getter on the unique instance of this class
//
// Contract : None.
//

const unordered_map<string, Shape *> & GetShapes() const;
// Manual : Getter on the unordered_map<K,T> containing the shapes with
// K = shape.GetName() and T = Shape*
//
// Contract : None.
//

const Shape * GetShape(const string & name) const;
// Manual : Getter on shape.
// name = name of the shape returned
// Return nullptr if no shape is in the map with the name given
//
// Contract : None.
//

int CreateRectangle(const string & name, const Point & p1, const Point & p2);
// Manual : Method that creates and add a Rectangle in the map. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if name already used in map.
// Return 2 if the Rectangle is not valid. (Rectangle.IsValid() == false)
//
// Contract : None.
//

int CreateSegment(const string & name, const Point & p1, const Point & p2);
// Manual : Method that creates and add a Segment in the map. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if name already used in map.
// Return 2 if the Segment is not valid. (Segment.IsValid() == false)
//
// Contract : None.
//

int CreateConvexPolygon(const string & name, const vector<Point> & somePoints);
// Manual : Method that creates and add a ConvexPolygon in the map. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if name already used in map.
// Return 2 if the ConvexPolygon is not valid. (ConvexPolygon.IsValid() == false)
//
// Contract : None.
//

int CreateIntersection(const string & name, const vector<string> & someShapeNames);
// Manual : Method that creates and add a Intersection in the map. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if name already used in map.
// Return 2 if the Intersection is not valid. (Intersection.IsValid() == false)
// Return 3 if one or more shape name of someShapesNames is not in the map.
//
// Contract : None.
//

int CreateReunion(const string & name, const vector<string> & someShapeNames);
// Manual : Method that creates and add a Reunion in the map. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if name already used in map.
// Return 2 if the Reunion is not valid. (Reunion.IsValid() == false)
// Return 3 if one or more shape name of someShapesNames is not in the map.
//
// Contract : None.
//

int DeleteShape(const vector<string> & names);
// Manual : Method that delete a shape from map. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if a name of names is not in map, the delete is canceled
//
// Contract : None.
//

int MoveShape(const string  & name, int dx, int dy);
// Manual : Method that allows to move the shape named name. (can be undo/redo)
// Return 0 if succeded.
// Return 1 if name is not in the map.
//
// Contract : None.
//

void Undo();
// Manual : Undo the last action that affected the shapes.
//
// Contract : None.
//

void Redo();
// Manual : Redo the last action undone that affected the shapes.
//
// Contract : None.
//

int Include(const string & name, const Point & p) const;
// Manual : Method that allows the user to know if a point p is
// in the shape named name.
// Return 0 if the point is included in the shape.
// Return 1 if the point is not included in the shape.
// Return 2 if the name is not in the map.
//
// Contract : None.
//

void Clear();
// Manual : Method that delete a shape from map. (can be undo/redo)
//
// Contract : None.
//

int Load(const string & filePath);
// Manual : Method that creates Shapes from the file filePath and adds it
// to the map. (can be undo/redo)
// Return 0 if succeeded.
// Return 1 if file can't be opened.
// Return 2 if error in loading, if line is wrong.
// Return 3 if one (or more) figure loaded has a name which is in the map,
// the load is canceled.
// Return 4 if two (or more) figures loaded has the same name.
//
// Contract : None
//


int Save(const string & filePath) const;
// Manual : Method that save shapes from the map in the file filePath.
// It creates the file if it doesn't exist or replace it if it exists.
// Return 0 if succeeded.
// Return 1 if file can't be opened.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

//------------------------------------------------- Operators overloading 

ShapeManager & operator = (const ShapeManager & oneShapeManager);
// Manual : Forbidden.
//
// Contract : None.
//

//--------------------------------------------- Constructors - destructor

private :

ShapeManager(const ShapeManager & oneShapeManager);
// Manual : Copy constructor forbidden.
//
// Contract : None.
//

ShapeManager();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ShapeManager();
// Manual : Destructor.
//
// Contract : None.
//


protected:
//------------------------------------------------------ Protected methods

void Execute(Command *c);
// Manual : Methode execute the command c, put c in the undoStack and removes
// all commands from the redoStack.
//
// Contract :
//

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

static ShapeManager instance;           // singleton.

unordered_map<string,Shape*> shapes;              // map which contains the shapes
                                        // which are accessible by name

list<Command*> undoStack;               // undo stack of commands

list<Command*> redoStack;               // redo stack of commands

static const int MAX_UNDO_REDO = 100 ;  // Max Undo-RedoStack length

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ShapeManager>

#endif // ShapeManager_H


