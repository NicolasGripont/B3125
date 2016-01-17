/*************************************************************************
MoveShapeCommand - Implementation file of the class <MoveShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:51
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <MoveShapeCommand> (file MoveShapeCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "MoveShapeCommand.h"
#include "ShapeManager.h"
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool MoveShapeCommand::Execute()
// Algorithm :
//
{
    ShapeManager::GetInstance().MoveShape(shapeName,dX,dY);
} //----- End of Execute

void MoveShapeCommand::Undo()
// Algorithm :
//
{
    ShapeManager::GetInstance().MoveShape(shapeName,-dX,-dY);
} //----- End of Undo

//------------------------------------------------- Operators overloading

//MoveShapeCommand & MoveShapeCommand::operator = (const MoveShapeCommand & oneMoveShapeCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

MoveShapeCommand::MoveShapeCommand(const MoveShapeCommand & oneMoveShapeCommand) :
    ShapeCommand(oneMoveShapeCommand.shapeName), dX(oneMoveShapeCommand.dX), dY(oneMoveShapeCommand.dY)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <MoveShapeCommand>" << endl;
#endif
} //----- End of MoveShapeCommand


MoveShapeCommand::MoveShapeCommand(string name,int dx, int dy) :
    ShapeCommand(name), dX(dx), dY(dy)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <MoveShapeCommand>" << endl;
#endif
} //----- End of MoveShapeCommand


MoveShapeCommand::~MoveShapeCommand()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <MoveShapeCommand>" << endl;
#endif
} //----- End of ~MoveShapeCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
