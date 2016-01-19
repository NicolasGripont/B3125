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
#if ! defined ( VectorPoint )
#define VectorPoint
template class std::vector<Point>;
#endif
//------------------------------------------------------------------------
// Role of the class <SimpleShape>
//
//
//------------------------------------------------------------------------

class SimpleShape : public Shape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Move(int dx, int dy);
// Manual :
//
// Contract :
//


//------------------------------------------------- Operators overloading 

SimpleShape & operator = (const SimpleShape & oneSimpleShape);
// Manual :
//
// Contract : 
//

vector<Point> GetPoints();
// Manual :
//
// Contract :
//

//--------------------------------------------- Constructors - destructor

SimpleShape(const SimpleShape & oneSimpleShape);
// Manual : Copy constructor.
//
// Contract : None.
//

SimpleShape(string oneName, vector<Point> somePoints);
// Manual : Constructor.
//
// Contract : None.
//

SimpleShape(string oneName);
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

vector<Point> points;

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <SimpleShape>

#endif // SimpleShape_H


