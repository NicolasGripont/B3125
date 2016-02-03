/*************************************************************************
Shape - Header file of the class <Shape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:45:37
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Shape> (file Shape.h)
#if ! defined ( Shape_H )
#define Shape_H

//-------------------------------------------------------- Used interfaces 

#include <string>
#include <ostream>
using namespace std;

#include "Point.h"
#include "Moveable.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Shape>
// Abstract class that describes a shape.
// It allows the user to move the shape to a specific new place,
// to know if a point is included in the shape, to know if the shape is
// valid, ...
//------------------------------------------------------------------------

class Shape : public Moveable
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Move(int dx, int dy) = 0;
// Manual :
// Moves the shape to a new place determined by the coordonates (x+dx,y+dy).
// Contract : None.
//

virtual bool Include(const Point & p) const = 0;
// Manual : tests if p is inside the shape.
//
// Contract : None.
//

virtual string ToString() const = 0 ;
// Manual : Return a string with all parameters of the shape.
//
// Contract :
//

virtual bool IsValid() const;
// Manual : Tests if shape is valid. Here return true by default.
//
// Contract :
//

virtual Shape* Clone() const = 0;
// Manual : Clone the shape, use the copy constructeur, allows to use copy with
// polymorphism
//
// Contract : None.
//

string GetName() const;
// Manual : Getter of shape name.
//
// Contract : None.
//

void SetName(string n);
// Manual : Setter of shape name.
//
// Contract : None.
//


//------------------------------------------------- Operators overloading 

Shape & operator = (const Shape & unShape);
// Manual : Overload of = operator.
//
// Contract : None
//

friend ostream & operator << (ostream & os, Shape const & shape);
// Manual : Display the shape parameters.
// Use the virtual methode ToString that allows to use << operator with
// polymorphism.
//
// Contract : None.
//

//--------------------------------------------- Constructors - destructor

Shape(const Shape & oneShape);
// Manual : Copy constructor.
//
// Contract : None.
//

Shape(const string & oneName);
// Manual : Constructor.
//
// Contract : None.
//

Shape();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Shape();
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

string name;          // Name of the shape.

static int nbTabs;    // Static attibutes used for indentation in ToString
                      // of ComplexShapes.

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Shape>

#endif // Shape_H


