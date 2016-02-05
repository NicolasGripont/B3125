/*************************************************************************
Command - Header file of the class <Command>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:37:35
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Command> (file Command.h)
#if ! defined ( Command_H )
#define Command_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Command>
// Class that allows to create a command objet that we can excute
// (and redo) or undo the action command.
//
//------------------------------------------------------------------------

class Command
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Execute() = 0;
// Manual :
// Method that allows to execute the action command (Do and redo)
//
// Contract : none.
//

virtual void Undo() = 0;
// Manual :
// Method that allows to undo the action command
//
// Contract : none.
//

//------------------------------------------------- Operators overloading 

//Command & operator = (const Command & unCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

Command(const Command & oneCommand);
// Manual : Copy constructor.
//
// Contract : None.
//

Command();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Command();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods


private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Command>

#endif // Command_H


