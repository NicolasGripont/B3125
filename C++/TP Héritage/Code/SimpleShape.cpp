/*************************************************************************
SimpleShape - Implementation file of the class <SimpleShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:58:00
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <SimpleShape> (file SimpleShape.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "SimpleShape.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type SimpleShape::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

SimpleShape & SimpleShape::operator = (const SimpleShape & unSimpleShape)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

SimpleShape::SimpleShape(const SimpleShape & unSimpleShape)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <SimpleShape>" << endl;
#endif
} //----- End of SimpleShape


SimpleShape::SimpleShape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <SimpleShape>" << endl;
#endif
} //----- End of SimpleShape


SimpleShape::~SimpleShape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <SimpleShape>" << endl;
#endif
} //----- End of ~SimpleShape


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
