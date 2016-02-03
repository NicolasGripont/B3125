/*************************************************************************
ConvexPolygon - Header file of the class <ConvexPolygon>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:50:48
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ConvexPolygon> (file ConvexPolygon.h)
#if ! defined ( ConvexPolygon_H )
#define ConvexPolygon_H

//-------------------------------------------------------- Used interfaces 

#include "SimpleShape.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <ConvexPolygon>
// Describes a convex polygon. This class first tests if the polygon built
// by the user is convex. If so, the user can move and test if a point is
// inside the polygon.
//------------------------------------------------------------------------

class ConvexPolygon : public SimpleShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual bool Include(const Point & p) const;
// Manual :
// Tests if P is inside the convex polygon.
//
// Contract : The convex polygon must be valid to have a good result.
//

virtual string ToString() const;
// Manual :
// Displays the polygon's caracteristics
//
// Contract :
//

bool IsValid() const;
// Manual : Tests if the convex polygon is valid.
//
// Contract : All the points of the polygon must be ordered.
//
virtual Shape* Clone() const;
// Manual : Clone the ConvexPolygon, use the copy constructeur, allows
// to use copy with polymorphism
//
// Contract : None.
//

//------------------------------------------------- Operators overloading 

ConvexPolygon & operator = (const ConvexPolygon & oneConvexPolygon);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

ConvexPolygon(const ConvexPolygon & oneConvexPolygon);
// Manual : Copy constructor.
//
// Contract : None.
//

ConvexPolygon(const string & oneName, const vector<Point> & somePoints);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ConvexPolygon();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods


private:
//-------------------------------------------------------- Private methods
static int ccw(Point a, Point b, Point c);
// Manual :
//
// Contract :
//

static int sqrDist(Point a, Point b);
// Manual :
//
// Contract :
//

static Point pivot;

static bool POLAR_ORDER(Point a, Point b);
// Manual :
//
// Contract :
//

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ConvexPolygon>

#endif // ConvexPolygon_H


