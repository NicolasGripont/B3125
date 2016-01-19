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
// Manual :
//
// Contract :
//

int GetX();
// Manual :
//
// Contract :
//

int GetY();
// Manual :
//
// Contract :
//

int MaxX(Point p);
// Manual :
//
// Contract :
//

int MaxY(Point p);
// Manual :
//
// Contract :
//

int MinX(Point p);
// Manual :
//
// Contract :
//

int MinY(Point p);
// Manual :
//
// Contract :
//

//------------------------------------------------- Operators overloading 

Point & operator = (const Point & onePoint);
// Manual :
//
// Contract : 
//

bool operator == ( const Point & onePoint );
// Manual :
//
// Contract :
//


//--------------------------------------------- Constructors - destructor

Point(const Point & onePoint);
// Manual : Copy constructor.
//
// Contract : None.
//

Point (int oneX,int oneY);
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


