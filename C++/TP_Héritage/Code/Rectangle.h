/*************************************************************************
Rectangle - Header file of the class <Rectangle>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:50:09
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Rectangle> (file Rectangle.h)
#if ! defined ( Rectangle_H )
#define Rectangle_H

//-------------------------------------------------------- Used interfaces 

#include "SimpleShape.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Rectangle>
// Describes a rectangle defined by its name and the two extrem points of
// one diagonal. It allows the user to move, and to determine if a point
// is inside of the rectangle.
//------------------------------------------------------------------------

class Rectangle : public SimpleShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual bool Include(const Point & p) const;
// Manual : tests if p is inside the rectangle.
//
// Contract : None.
//

virtual string ToString() const;
// Manual : displays the rectangle's caracteristics.
//
// Contract : None
//

virtual Rectangle* Clone() const;
// Manual : Clone the Rectangle, use the copy constructeur, allows to
// use copy with polymorphism
//
// Contract : None.
//

//------------------------------------------------- Operators overloading 

Rectangle & operator = (const Rectangle & oneRectangle);
// Manual : Overload of = operator.
//
// Contract : None.
//


//--------------------------------------------- Constructors - destructor

Rectangle(const Rectangle & oneRectangle);
// Manual : Copy constructor.
//
// Contract : None.
//

Rectangle(const string & oneName, const Point & p1, const Point & p2);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Rectangle();
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

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Rectangle>

#endif // Rectangle_H


