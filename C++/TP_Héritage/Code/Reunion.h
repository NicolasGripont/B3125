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
//
//
//------------------------------------------------------------------------

class Reunion : public ComplexShape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

bool Include(Point p);
// Manual :
//
// Contract :
//

string ToString();
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

Reunion & operator = (const Reunion & oneReunion);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

Reunion(const Reunion & oneReunion);
// Manual : Copy constructor.
//
// Contract : None.
//

Reunion(string oneName, vector<Shape *> someShapes);
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


