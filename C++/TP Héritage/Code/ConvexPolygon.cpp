/*************************************************************************
ConvexPolygon - Implementation file of the class <ConvexPolygon>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:54:12
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ConvexPolygon> (file ConvexPolygon.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ConvexPolygon.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type ConvexPolygon::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

ConvexPolygon & ConvexPolygon::operator = (const ConvexPolygon & unConvexPolygon)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

ConvexPolygon::ConvexPolygon(const ConvexPolygon & unConvexPolygon)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ConvexPolygon>" << endl;
#endif
} //----- End of ConvexPolygon


ConvexPolygon::ConvexPolygon()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ConvexPolygon>" << endl;
#endif
} //----- End of ConvexPolygon


ConvexPolygon::~ConvexPolygon()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ConvexPolygon>" << endl;
#endif
} //----- End of ~ConvexPolygon


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
