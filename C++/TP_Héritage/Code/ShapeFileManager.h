/*************************************************************************
ShapeFileManager - Header file of the class <ShapeFileManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:42:53
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ShapeFileManager> (file ShapeFileManager.h)
#if ! defined ( ShapeFileManager_H )
#define ShapeFileManager_H

//-------------------------------------------------------- Used interfaces 

#include "Shape.h"

#include <map>
#include <deque>
#include <vector>
#include <string>
using namespace std;
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types
#if ! defined ( MapStringShapePtr )
#define MapStringShapePtr
template class std::map<string,Shape*>;
#endif
#if ! defined ( DequeString )
#define DequeString
template class std::deque<string>;
#endif
#if ! defined ( VectorShapePtr )
#define VectorShapePtr
template class std::vector<Shape*>;
#endif
//------------------------------------------------------------------------
// Role of the class <ShapeFileManager>
//
//
//------------------------------------------------------------------------

class ShapeFileManager
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

static vector<Shape*> Load(const string & filePath);
// Manual :
//
// Contract :
//

static bool Save(const string & filePath, const map<string, Shape *> &shapes);
// Manual :
//
// Contract :
//

//------------------------------------------------- Operators overloading 

//ShapeFileManager & operator = (const ShapeFileManager & unShapeFileManager);
//// Manual :
////
//// Contract :
////

//---------------------------------------------------------------- PRIVATE

//------------------------------------ Protected constructors - destructor

protected:

ShapeFileManager(const ShapeFileManager & unShapeFileManager);
// Manual : Copy constructor.
//
// Contract : None.
//

ShapeFileManager();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ShapeFileManager();
// Manual : Destructor.
//
// Contract : None.
//


protected:
//------------------------------------------------------ Protected methods

static Shape* CreateSegment(const deque<string> & params);
// Manual :
//
// Contract :
//

static Shape* CreateRectangle(const deque<string> & params);
// Manual :
//
// Contract :
//

static Shape* CreateConvexPolygon(const deque<string> & params);
// Manual :
//
// Contract :
//

static Shape* CreateComplexShape(ifstream & file, deque<string> params);
// Manual :
//
// Contract :
//

static deque<string> SplitLine(string line);
// Manual :
//
// Contract :
//

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ShapeFileManager>

#endif // ShapeFileManager_H


