/*************************************************************************
ComplexShape - Implementation file of the class <ComplexShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:52:12
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ComplexShape> (file ComplexShape.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ComplexShape.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type ComplexShape::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

ComplexShape & ComplexShape::operator = (const ComplexShape & unComplexShape)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

ComplexShape::ComplexShape(const ComplexShape & unComplexShape)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ComplexShape>" << endl;
#endif
} //----- End of ComplexShape


ComplexShape::ComplexShape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ComplexShape>" << endl;
#endif
} //----- End of ComplexShape


ComplexShape::~ComplexShape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ComplexShape>" << endl;
#endif
} //----- End of ~ComplexShape


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
