/*************************************************************************
Moveable - Implementation file of the class <Moveable>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:55:08
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Moveable> (file Moveable.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "Moveable.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type Moveable::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

//Moveable & Moveable::operator = (const Moveable & unMoveable)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Moveable::Moveable(const Moveable & unMoveable)
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Moveable>" << endl;
#endif
} //----- End of Moveable


Moveable::Moveable()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Moveable>" << endl;
#endif
} //----- End of Moveable


Moveable::~Moveable()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Moveable>" << endl;
#endif
} //----- End of ~Moveable


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
