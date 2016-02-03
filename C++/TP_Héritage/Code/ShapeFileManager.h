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

//------------------------------------------------------------------------
// Role of the class <ShapeFileManager>
//
//------------------------------------------------------------------------

class ShapeFileManager
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

static int Load(const string & filePath, vector<Shape *> & shapes);
// Manual : Load the shapes saved in the file filePath. It adds the shapes to
// the vector<Shape*> shapes given in parameters.
// Return 0 if succeeded.
// Return 1 if file can't be opened.
// Return 2 if there is an error in the file.
//
// Contract : None
//

static int Save(const string & filePath, const map<string, Shape *> &shapes);
// Manual :// Manual : Save the shapes from the map given in parameters
// in the file filePath. If the file exists it replaces it, else it creates it.
// Return 0 if succeeded.
// Return 1 if file can't be opened.
//
// Contract : None.
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


