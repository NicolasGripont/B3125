/*************************************************************************
ComplexShape - Header file of the class <ComplexShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:49:47
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ComplexShape> (file ComplexShape.h)
#if ! defined ( ComplexShape_H )
#define ComplexShape_H

//-------------------------------------------------------- Used interfaces 
#include <vector>
using namespace std;

#include "Shape.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

#if ! defined ( VectorShapePtr )
#define VectorShapePtr
template class std::vector<Shape*>;
#endif

#if ! defined ( VectorString )
#define VectorString
template class std::vector<string>;
#endif
//------------------------------------------------------------------------
// Role of the class <ComplexShape>
// Abstract class that describes a shape composed of multiple shapes.
// It allows the user to move the shape to a specific new place, ...
//------------------------------------------------------------------------

class ComplexShape : public Shape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Move(int dx, int dy);
// Manual :
// Moves the shape to a new place determined by the coordonates (x+dx,y+dy).
// Contract : None.
//

virtual bool IsValid() const;
// Manual : Tests if the ComplexShape is valid.
//
// Contract : None.
//

const vector<Shape *> & GetChildren() const;
// Manual : Getter on children (shapes).
//
// Contract : None.
//

//------------------------------------------------- Operators overloading 

ComplexShape & operator = (const ComplexShape & unComplexShape);
// Manual : Overload of = operator.
//
// Contract : None.
//


//--------------------------------------------- Constructors - destructor

ComplexShape(const ComplexShape & oneComplexShape);
// Manual : Copy constructor.
//
// Contract : None.
//

ComplexShape(const string & oneName, const vector<Shape *> & someShapes);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ComplexShape();
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

vector<Shape*> children;    // children, shapes that form the ComplexShape

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ComplexShape>

#endif // ComplexShape_H


