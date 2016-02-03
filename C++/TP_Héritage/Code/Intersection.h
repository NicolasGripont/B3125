/*************************************************************************
Intersection - Header file of the class <Intersection>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:51:04
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Intersection> (file Intersection.h)
#if ! defined ( Intersection_H )
#define Intersection_H

//-------------------------------------------------------- Used interfaces 

#include "ComplexShape.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Intersection>
// Describes a Intersection of shape. The class allows the user to
// move the Reunion, and to test if a point p is on the segment.
//------------------------------------------------------------------------

class Intersection : public ComplexShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

bool Include(const Point & p) const;
// Manual : tests if P is on the Intersection.
//
// Contract : none
//

string ToString() const;
// Manual : displays the Intersection's caracteristics.
//
// Contract :
//

virtual Shape* Clone() const;
// Manual : Clone the Intersection, use the copy constructeur, allows to use
// copy with polymorphism
//
// Contract : None.
//

//------------------------------------------------- Operators overloading 

Intersection & operator = (const Intersection & oneIntersection);
// Manual : Overload of = operator
//
// Contract : None
//


//--------------------------------------------- Constructors - destructor

Intersection(const Intersection & oneIntersection);
// Manual : Copy constructor.
//
// Contract : None.
//

Intersection(const string & oneName, const vector<Shape *> & someShapes);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Intersection();
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

//---------------------------- Other definition depend on <Intersection>

#endif // Intersection_H


