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

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Point>
//
//
//------------------------------------------------------------------------

class Point
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

// type Method ( parameter liste );
// Manual :
//
// Contract :
//


//------------------------------------------------- Operators overloading 

Point & operator = (const Point & unPoint);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

Point(const Point & unPoint);
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

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Point>

#endif // Point_H


