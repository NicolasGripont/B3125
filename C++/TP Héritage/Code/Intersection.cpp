/*************************************************************************
Intersection - Implementation file of the class <Intersection>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:55:08
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Intersection> (file Intersection.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "Intersection.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type Intersection::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

Intersection & Intersection::operator = (const Intersection & unIntersection)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Intersection::Intersection(const Intersection & unIntersection)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Intersection>" << endl;
#endif
} //----- End of Intersection


Intersection::Intersection()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Intersection>" << endl;
#endif
} //----- End of Intersection


Intersection::~Intersection()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Intersection>" << endl;
#endif
} //----- End of ~Intersection


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
