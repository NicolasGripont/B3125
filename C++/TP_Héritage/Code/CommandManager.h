/*************************************************************************
CommandManager - Header file of the class <CommandManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:37:26
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <CommandManager> (file CommandManager.h)
#if ! defined ( CommandManager_H )
#define CommandManager_H

//-------------------------------------------------------- Used interfaces 

#include <list>
using namespace std;
#include "Command.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

template class std::list<Command*>;

//------------------------------------------------------------------------
// Role of the class <CommandManager>
//
//
//------------------------------------------------------------------------

class CommandManager
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

bool Execute(Command *c);
// Manual :
//
// Contract :
//

void Undo();
// Manual :
//
// Contract :
//

void Redo();
// Manual :
//
// Contract :
//

//------------------------------------------------- Operators overloading 

//CommandManager & operator = (const CommandManager & unCommandManager);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//CommandManager(const CommandManager & unCommandManager);
//// Manual : Copy constructor.
////
//// Contract : None.
////

CommandManager();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~CommandManager();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods

list<Command*> undoStack;
list<Command*> redoStack;

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes

    static const int MAX_UNDO_REDO = 20 ;
};

//---------------------------- Other definition depend on <CommandManager>

#endif // CommandManager_H


