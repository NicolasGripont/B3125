/*************************************************************************
ShapeCommand - Header file of the class <ShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:38:08
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ShapeCommand> (file ShapeCommand.h)
#if ! defined ( ShapeCommand_H )
#define ShapeCommand_H

//-------------------------------------------------------- Used interfaces 
#include "Command.h"
//-------------------------------------------------------------- Constants
#include <string>
using namespace std;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <ShapeCommand>
// Abstract class that allows to create a command objet that we can excute to
// interract with Shape object (and redo) or undo the action command.
//
//------------------------------------------------------------------------

//------------------------------------------------------------------- enum

enum CreateOrDelete
{
    Create,
    Delete
};


class ShapeCommand : public Command
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

//------------------------------------------------- Operators overloading 

//--------------------------------------------- Constructors - destructor

ShapeCommand(const ShapeCommand & oneShapeCommand);
// Manual : Copy constructor.
//
// Contract : None.
//

ShapeCommand(string name);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ShapeCommand();
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
    string shapeName;
private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <ShapeCommand>

#endif // ShapeCommand_H


