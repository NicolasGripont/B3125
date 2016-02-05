/*************************************************************************
SimpleShape - Header file of the class <SimpleShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:49:37
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <SimpleShape> (file SimpleShape.h)
#if ! defined ( SimpleShape_H )
#define SimpleShape_H

//-------------------------------------------------------- Used interfaces 
#include <vector>
using namespace std;

#include "Shape.h"
#include "Point.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types
//#if ! defined ( VectorPoint )
//#define VectorPoint
//template class std::vector<Point>;
//#endif
//------------------------------------------------------------------------
// Role of the class <SimpleShape>
// Abstract class that describes a shape of one component.
// It allows the user to move the shape to a specific new place.
//------------------------------------------------------------------------

class SimpleShape : public Shape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Move(int dx, int dy);
// Manual :
// Moves the shape to a new place determined by the coordonates (x+dx,y+dy).
// Contract : None.
//

const vector<Point> & GetPoints() const;
// Manual :
// Getter of the points defining the shape.
// Contract : None.
//


//------------------------------------------------- Operators overloading 

SimpleShape & operator = (const SimpleShape & oneSimpleShape);
// Manual : Overload of = operator.
//
// Contract : None.
//


//--------------------------------------------- Constructors - destructor

SimpleShape(const SimpleShape & oneSimpleShape);
// Manual : Copy constructor.
//
// Contract : None.
//

SimpleShape(const string & oneName, const vector<Point> & somePoints);
// Manual : Constructor.
//
// Contract : None.
//

SimpleShape(const string & oneName);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~SimpleShape();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods


private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

vector<Point> points;   // vector of points of the simple shape

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <SimpleShape>

#endif // SimpleShape_H


