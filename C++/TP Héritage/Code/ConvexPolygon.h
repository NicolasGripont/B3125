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

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <ConvexPolygon>
//
//
//------------------------------------------------------------------------

class ConvexPolygon
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

ConvexPolygon & operator = (const ConvexPolygon & unConvexPolygon);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

ConvexPolygon(const ConvexPolygon & unConvexPolygon);
// Manual : Copy constructor.
//
// Contract : None.
//

ConvexPolygon();
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

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ConvexPolygon>

#endif // ConvexPolygon_H


