/*************************************************************************
Rectangle - Implementation file of the class <Rectangle>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:56:27
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Rectangle> (file Rectangle.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "Rectangle.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type Rectangle::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

Rectangle & Rectangle::operator = (const Rectangle & unRectangle)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Rectangle::Rectangle(const Rectangle & unRectangle)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- End of Rectangle


Rectangle::Rectangle()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- End of Rectangle


Rectangle::~Rectangle()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- End of ~Rectangle


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
