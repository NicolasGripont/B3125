/*************************************************************************
ShapeFileManager - Implementation file of the class <ShapeFileManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:45:34
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ShapeFileManager> (file ShapeFileManager.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ShapeFileManager.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type ShapeFileManager::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading

//ShapeFileManager & ShapeFileManager::operator = (const ShapeFileManager & unShapeFileManager)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

ShapeFileManager::ShapeFileManager(const ShapeFileManager & unShapeFileManager)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ShapeFileManager>" << endl;
#endif
} //----- End of ShapeFileManager


ShapeFileManager::ShapeFileManager()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ShapeFileManager>" << endl;
#endif
} //----- End of ShapeFileManager


ShapeFileManager::~ShapeFileManager()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ShapeFileManager>" << endl;
#endif
} //----- End of ~ShapeFileManager


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
