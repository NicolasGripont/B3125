/*************************************************************************
CommandManager - Implementation file of the class <CommandManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:43:33
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <CommandManager> (file CommandManager.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "CommandManager.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool CommandManager::Execute(Command* c)
// Algorithm :
//
{
    bool result = c->Execute();

    if(result)
    {
        if(undoStack.size() == MAX_UNDO_REDO)
        {
            delete undoStack.back();
            undoStack.pop_back();
        }
        undoStack.push_front(c);
    }

    for(list<Command*>::iterator it = redoStack.begin(); it != redoStack.end(); it++)
    {
        delete *it;
    }

    return result;
} //----- End of Execute

void CommandManager::Undo()
// Algorithm :
//
{
    Command *c;
    c = undoStack.front();
    undoStack.pop_front();
    redoStack.push_front(c);
    c->Execute();
} //----- End of Undo

void CommandManager::Redo()
// Algorithm :
//
{
    Command *c;
    c = redoStack.front();
    redoStack.pop_front();
    undoStack.push_front(c);
    c->Execute();
} //----- End of Redo


//------------------------------------------------- Operators overloading

//CommandManager & CommandManager::operator = (const CommandManager & unCommandManager)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//CommandManager::CommandManager(const CommandManager & unCommandManager)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <CommandManager>" << endl;
//#endif
//} //----- End of CommandManager


CommandManager::CommandManager() :
    undoStack(), redoStack()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandManager>" << endl;
#endif
} //----- End of CommandManager


CommandManager::~CommandManager()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandManager>" << endl;
#endif
    for(list<Command*>::iterator it = undoStack.begin(); it != undoStack.end(); it++)
    {
        delete *it;
    }

    for(list<Command*>::iterator it = redoStack.begin(); it != redoStack.end(); it++)
    {
        delete *it;
    }
} //----- End of ~CommandManager


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
