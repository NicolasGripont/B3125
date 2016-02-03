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
// Describes a segment defined by two points. The class allows the user to
// move the segment, and to test if a point P is on the segment.
//------------------------------------------------------------------------

class Segment : public SimpleShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual bool Include(const Point & p) const;
// Manual : tests if P is on the segment.
//
// Contract : none
//

virtual string ToString() const;
// Manual : displays the segment's caracteristics.
//
// Contract :
//

virtual Shape* Clone() const;
// Manual : Clone the Segment, use the copy constructeur, allows to use
// copy with polymorphism
//
// Contract : None.
//

int MatchingY(Point p) const;
// Manual : finds the matching y on the segment of the abcisse of the
// point P. This function is only defined to be used in the other
// functions and to make the code easy to read.
//
// Contract : None
//


//------------------------------------------------- Operators overloading 

Segment & operator = (const Segment & oneSegment);
// Manual : Overload of = operator
//
// Contract : None
//


//--------------------------------------------- Constructors - destructor

Segment(const Segment & oneSegment);
// Manual : Copy constructor.
//
// Contract : None.
//

Segment(const string & oneName, const Point & p1, const Point & p2);
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


