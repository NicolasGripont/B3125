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


using namespace std;

#include "Point.h"
#include "Shape.h"
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

template class std::map<string,Shape*>;
//template class std::vector<Point>;
template class std::vector<string>;
//template class std::vector<Shape*>;

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

static ShapeManager& GetInstance();
// Manual :
//
// Contract :
//

map<string, Shape *> &GetShapes();
// Manual :
//
// Contract :
//

Shape* GetShape(string name);
// Manual :
//
// Contract :
//

bool CreateRectangle(string name, Point p1, Point p2);
// Manual :
//
// Contract :
//

bool CreateSegment(string name, Point p1, Point p2);
// Manual :
//
// Contract :
//

bool CreateConvexPolygon(string name, vector<Point> somePoints);
// Manual :
//
// Contract :
//

bool CreateIntersection(string name, vector<string> someShapeNames);
// Manual :
//
// Contract :
//

bool CreateReunion(string name, vector<string> someShapeNames);
// Manual :
//
// Contract :
//

bool DeleteShape(string name);
// Manual :
//
// Contract :
//

void MoveShape(string name, int dx, int dy);
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


private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes
    static ShapeManager instance;

    map<string,Shape*> shapes;

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ShapeManager>

#endif // ShapeManager_H


