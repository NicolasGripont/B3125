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
//
//
//------------------------------------------------------------------------

class ConvexPolygon : public SimpleShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual bool Include(Point P);
// Manual :
//
// Contract :
//

virtual string ToString();
// Manual :
//
// Contract :
//

virtual Shape* Clone();
// Manual :
//
// Contract :
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

ConvexPolygon(string oneName, vector<Point> somePoints);
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


