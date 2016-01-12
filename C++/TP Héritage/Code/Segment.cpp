/*************************************************************************
Segment - Implementation file of the class <Segment>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:57:31
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Segment> (file Segment.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "Segment.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type Segment::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

Segment & Segment::operator = (const Segment & unSegment)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Segment::Segment(const Segment & unSegment)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- End of Segment


Segment::Segment()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Segment>" << endl;
#endif
} //----- End of Segment


Segment::~Segment()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Segment>" << endl;
#endif
} //----- End of ~Segment


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
