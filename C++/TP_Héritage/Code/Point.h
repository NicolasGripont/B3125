/*************************************************************************
Point - Header file of the class <Point>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:51:31
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Point> (file Point.h)
#if ! defined ( Point_H )
#define Point_H

//-------------------------------------------------------- Used interfaces 
#include <ostream>
using namespace std;
#include "Moveable.h"
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Point>
// Describes a point of coordonates (x,y) where x is the abciss and y is
// the ordonate. This class builds the Point and allows move the point to
// another position.
//------------------------------------------------------------------------

class Point : public Moveable
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

void Move(int dx, int dy);
// Manual : modifies the coordonates of the point.
// The point is now defined by (x+dx,y+dy)
// Contract : None
//

int GetX() const;
// Manual : getter of the abcisse.
//
// Contract : None
//

int GetY() const;
// Manual : getter of the ordonate.
//
// Contract : None
//

int MaxX(Point p) const;
// Manual : returns the highest abcisse of the two points.
//
// Contract : None
//

int MaxY(Point p) const;
// Manual : returns the highest ordonate of the two points.
//
// Contract : None
//

int MinX(Point p) const;
// Manual : returns the minimum abcisse of the two points.
//
// Contract : None
//

int MinY(Point p) const;
// Manual : returns the minimum ordonate of the two points.
//
// Contract : None
//

//------------------------------------------------- Operators overloading 

Point & operator = (const Point & onePoint);
// Manual : Overload the = operator.
//
// Contract : None.
//

bool operator == ( const Point & onePoint ) const;
// Manual : Overload the == operator.
//
// Contract : None.
//

friend ostream & operator << (ostream & os, Point const & point);
// Manual : Overload the << operator.
// shows : "point.x point.y"
// Contract : None.
//

//--------------------------------------------- Constructors - destructor

Point(const Point & onePoint);
// Manual : Copy constructor.
//
// Contract : None.
//

Point (const int & oneX, const int & oneY);
// Manual : Copy constructor.
//
// Contract : None.
//

Point();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Point();
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

int x;
int y;

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Point>

#endif // Point_H


