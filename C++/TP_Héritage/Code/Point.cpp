/*************************************************************************
Point - Implementation file of the class <Point>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:51:41
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Point> (file Point.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "Point.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void Point::Move(int dx, int dy)
// Algorithm :
//
{
    x += dx;
    y += dy;
} //----- End of Move

int Point::GetX() const
// Algorithm :
//
{
    return x;
} //----- End of GetX

int Point::GetY() const
// Algorithm :
//
{
    return y;
} //----- End of GetY

int Point::MaxX(Point p) const
// Algorithm :
//
{
    if(x > p.x)
    {
        return x;
    }
    return p.x;
} //----- End of MaxX

int Point::MaxY(Point p) const
// Algorithm :
//
{
    if(y > p.y)
    {
        return y;
    }
    return p.y;
} //----- End of MaxY

int Point::MinX(Point p) const
// Algorithm :
//
{
    if(x < p.x)
    {
        return x;
    }
    return p.x;
} //----- End of MinX

int Point::MinY(Point p) const
// Algorithm :
//
{
    if(y < p.y)
    {
        return y;
    }
    return p.y;
} //----- End of MinY

//------------------------------------------------- Operators overloading

Point & Point::operator = (const Point & onePoint)
// Algorithm :
//
{
    x = onePoint.x;
    y = onePoint.y;
    return *this;
} //----- End of operator =

bool Point::operator == ( const Point & onePoint ) const
// Algorithm :
//
{
    if(x == onePoint.x && y == onePoint.y)
    {
        return true;
    }
    return false;
} //----- end of operator ==

//--------------------------------------------- Constructors - destructor

Point::Point(const Point & onePoint) :
    Moveable(onePoint), x(onePoint.x), y(onePoint.y)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- End of Point

Point::Point(const int & oneX, const int & oneY) :
    Moveable(), x(oneX), y(oneY)
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- End of Point

Point::Point() :
    Moveable(), x(0), y(0)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- End of Point


Point::~Point()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- End of ~Point


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
