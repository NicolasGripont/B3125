/*************************************************************************
Reunion - Implementation file of the class <Reunion>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:56:58
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Reunion> (file Reunion.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "Reunion.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type Reunion::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

Reunion & Reunion::operator = (const Reunion & unReunion)
// Algorithm :
//
{
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Reunion::Reunion(const Reunion & unReunion)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Reunion>" << endl;
#endif
} //----- End of Reunion


Reunion::Reunion()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Reunion>" << endl;
#endif
} //----- End of Reunion


Reunion::~Reunion()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Reunion>" << endl;
#endif
} //----- End of ~Reunion


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
