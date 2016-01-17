/*************************************************************************
Segment - Header file of the class <Segment>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:50:21
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Segment> (file Segment.h)
#if ! defined ( Segment_H )
#define Segment_H

//-------------------------------------------------------- Used interfaces 

#include "SimpleShape.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Segment>
//
//
//------------------------------------------------------------------------

class Segment : public SimpleShape
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

int LigneEquation();
// Manual :
//
// Contract :
//

bool Intersection(Segment s);
// Manual :
//
// Contract :
//

//------------------------------------------------- Operators overloading 

Segment & operator = (const Segment & oneSegment);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

Segment(const Segment & oneSegment);
// Manual : Copy constructor.
//
// Contract : None.
//

Segment(string oneName, Point p1, Point p2);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Segment();
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

//---------------------------- Other definition depend on <Segment>

#endif // Segment_H


