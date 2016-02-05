/*************************************************************************
Command - Implementation file of the class <Command>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:46:29
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Command> (file Command.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "Command.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods


//------------------------------------------------- Operators overloading


//--------------------------------------------- Constructors - destructor

Command::Command(const Command & oneCommand)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Command>" << endl;
#endif
} //----- End of Command


Command::Command()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Command>" << endl;
#endif
} //----- End of Command


Command::~Command()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Command>" << endl;
#endif
} //----- End of ~Command


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
