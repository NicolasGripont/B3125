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

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Intersection>
//
//
//------------------------------------------------------------------------

class Intersection
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

Intersection & operator = (const Intersection & unIntersection);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

Intersection(const Intersection & unIntersection);
// Manual : Copy constructor.
//
// Contract : None.
//

Intersection();
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


