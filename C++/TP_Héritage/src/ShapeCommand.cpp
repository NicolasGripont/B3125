/*************************************************************************
ShapeCommand - Implementation file of the class <ShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:45:10
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ShapeCommand> (file ShapeCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "ShapeCommand.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

// type ShapeCommand::Method ( parameter list )
// Algorithm :
//
//{
//} //----- End of Methode


//------------------------------------------------- Operators overloading


//--------------------------------------------- Constructors - destructor

ShapeCommand::ShapeCommand(const ShapeCommand & oneShapeCommand) :
    Command(), shapes(oneShapeCommand.shapes)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ShapeCommand>" << endl;
#endif
} //----- End of ShapeCommand


ShapeCommand::ShapeCommand(unordered_map<string, Shape *> *someShapes) :
    Command(), shapes(someShapes)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ShapeCommand>" << endl;
#endif
} //----- End of ShapeCommand


ShapeCommand::~ShapeCommand()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ShapeCommand>" << endl;
#endif
} //----- End of ~ShapeCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
