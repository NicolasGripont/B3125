/*************************************************************************
Reunion - Header file of the class <Reunion>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:51:13
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Reunion> (file Reunion.h)
#if ! defined ( Reunion_H )
#define Reunion_H

//-------------------------------------------------------- Used interfaces 

#include "ComplexShape.h"
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Reunion>
// Describes a Reunion of shape. The class allows the user to
// move the Reunion, and to test if a point p is on the segment.
//------------------------------------------------------------------------

class Reunion : public ComplexShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

bool Include(const Point & p) const;
// Manual : tests if P is on the Reunion.
//
// Contract : none
//

string ToString() const;
// Manual : displays the Reunion's caracteristics.
//
// Contract :
//

virtual Reunion *Clone() const;
// Manual : Clone the Reunion, use the copy constructeur, allows to use
// copy with polymorphism
//
// Contract : None.
//

//------------------------------------------------- Operators overloading 

Reunion & operator = (const Reunion & oneReunion);
// Manual : Overload of = operator
//
// Contract : None.
//


//--------------------------------------------- Constructors - destructor

Reunion(const Reunion & oneReunion);
// Manual : Copy constructor.
//
// Contract : None.
//

Reunion(const string & oneName, const vector<Shape *> & someShapes);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Reunion();
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

//---------------------------- Other definition depend on <Reunion>

#endif // Reunion_H


