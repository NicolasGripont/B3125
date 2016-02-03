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
using namespace std;

#include "Point.h"
#include "Shape.h"
#include "Command.h"
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types
#if ! defined ( ListCommandPtr )
#define ListCommandPtr
template class std::list<Command*>;
#endif
#if ! defined ( MapStringShapePtr )
#define MapStringShapePtr
template class std::map<string,Shape*>;
#endif
#if ! defined ( VectorString )
#define VectorString
template class std::vector<string>;
#endif
#if ! defined ( DequeString )
#define DequeString
template class std::deque<string>;
#endif


//------------------------------------------------------------------------
// Role of the class <ShapeManager>
//
//
//------------------------------------------------------------------------

class ShapeManager
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

static ShapeManager & GetInstance();
// Manual :
//
// Contract :
//

const map<string, Shape *> & GetShapes() const;
// Manual :
//
// Contract :
//

const Shape * GetShape(const string & name) const;
// Manual :
//
// Contract :
//

bool CreateRectangle(const string & name, const Point & p1, const Point & p2);
// Manual :
//
// Contract :
//

bool CreateSegment(const string & name, const Point & p1, const Point & p2);
// Manual :
//
// Contract :
//

bool CreateConvexPolygon(const string & name, const vector<Point> & somePoints);
// Manual :
//
// Contract :
//

bool CreateIntersection(const string & name, const vector<string> & someShapeNames);
// Manual :
//
// Contract :
//

bool CreateReunion(const string & name, const vector<string> & someShapeNames);
// Manual :
//
// Contract :
//

bool DeleteShape(const vector<string> & names);
// Manual :
//
// Contract :
//

void MoveShape(const string  & name, int dx, int dy);
// Manual :
//
// Contract :
//

void Undo();
// Manual :
//
// Contract :
//

void Redo();
// Manual :
//
// Contract :
//

bool Include(const string & name, const Point & p) const;
// Manual :
//
// Contract :
//

bool Clear();
// Manual :
//
// Contract :
//

bool Load(const string & filePath);
// Manual :
//
// Contract :
//

bool Save(const string & filePath) const;
// Manual :
//
// Contract :
//

//---------------------------------------------------------------- PRIVATE

//------------------------------------------------- Operators overloading 

//ShapeManager & operator = (const ShapeManager & oneShapeManager);
//// Manual :
////
//// Contract :
////

//--------------------------------------------- Constructors - destructor

private :

//ShapeManager(const ShapeManager & oneShapeManager);
//// Manual : Copy constructor.
////
//// Contract : None.
////

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
// Manual :
//
// Contract :
//

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

static ShapeManager instance;

map<string,Shape*> shapes;

list<Command*> undoStack;

list<Command*> redoStack;

static const int MAX_UNDO_REDO = 100 ;

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ShapeManager>

#endif // ShapeManager_H


