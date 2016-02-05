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

//------------------------------------------------------ Personnal include
#include <iostream>
using namespace std;
#include "MoveShapeCommand.h"
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void MoveShapeCommand::Execute()
// Algorithm :
//
{
    unordered_map<string,Shape*>::iterator it;
    it = shapes->find(shapeName);
    if (! (it == shapes->end()) )
    {
        it->second->Move(dX,dY);
    }
} //----- End of Execute

void MoveShapeCommand::Undo()
// Algorithm :
//
{
    unordered_map<string,Shape*>::iterator it;
    it = shapes->find(shapeName);
    if (! (it == shapes->end()) )
    {
        it->second->Move(-dX,-dY);
    }
} //----- End of Undo

//------------------------------------------------- Operators overloading

//MoveShapeCommand & MoveShapeCommand::operator = (const MoveShapeCommand & oneMoveShapeCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

MoveShapeCommand::MoveShapeCommand(const MoveShapeCommand & oneMoveShapeCommand) :
    ShapeCommand(oneMoveShapeCommand), shapeName(oneMoveShapeCommand.shapeName),
    dX(oneMoveShapeCommand.dX), dY(oneMoveShapeCommand.dY)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <MoveShapeCommand>" << endl;
#endif
} //----- End of MoveShapeCommand


MoveShapeCommand::MoveShapeCommand(unordered_map<string, Shape *> *someShapes, const string & name, int dx, int dy) :
    ShapeCommand(someShapes),shapeName(name), dX(dx), dY(dy)
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
