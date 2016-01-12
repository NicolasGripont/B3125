/*************************************************************************
Point - Implementation file of the class <Point>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:51:41
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Point> (file Point.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "Point.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type Point::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

Point & Point::operator = (const Point & unPoint)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Point::Point(const Point & unPoint)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- End of Point


Point::Point()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- End of Point


Point::~Point()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- End of ~Point


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
