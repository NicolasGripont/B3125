/*************************************************************************
MoveShapeCommand - Header file of the class <MoveShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:38:36
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <MoveShapeCommand> (file MoveShapeCommand.h)
#if ! defined ( MoveShapeCommand_H )
#define MoveShapeCommand_H

//-------------------------------------------------------- Used interfaces 

#include "ShapeCommand.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <MoveShapeCommand>
//
//
//------------------------------------------------------------------------

class MoveShapeCommand : public ShapeCommand
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Execute();
// Manual :
// Method that allows to execute the action command (Do and redo)
//
// Contract : none.
//

virtual void Undo();
// Manual :
// Method that allows to undo the action command
//
// Contract : none.
//


//------------------------------------------------- Operators overloading 

MoveShapeCommand & operator = (const MoveShapeCommand & unMoveShapeCommand);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

MoveShapeCommand(const MoveShapeCommand & unMoveShapeCommand);
// Manual : Copy constructor.
//
// Contract : None.
//

MoveShapeCommand(map<string, Shape *> *someShapes, string name, int dx, int dy);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~MoveShapeCommand();
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

    string shapeName;   //
    int dX;             //
    int dY;             //
private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <MoveShapeCommand>

#endif // MoveShapeCommand_H


