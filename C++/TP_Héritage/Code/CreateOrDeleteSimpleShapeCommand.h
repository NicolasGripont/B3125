/*************************************************************************
CreateOrDeleteSimpleShapeCommand - Header file of the class <CreateOrDeleteSimpleShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:40:50
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <CreateOrDeleteSimpleShapeCommand> (file CreateOrDeleteSimpleShapeCommand.h)
#if ! defined ( CreateOrDeleteSimpleShapeCommand_H )
#define CreateOrDeleteSimpleShapeCommand_H

//-------------------------------------------------------- Used interfaces 
#include "ShapeManager.h"
#include "ShapeCommand.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------- enum

//------------------------------------------------------------------------
// Role of the class <CreateOrDeleteSimpleShapeCommand>
//
//
//------------------------------------------------------------------------



class CreateOrDeleteSimpleShapeCommand : public ShapeCommand
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual bool Execute();
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

//CreateOrDeleteSimpleShapeCommand & operator = (const CreateOrDeleteSimpleShapeCommand & unCreateOrDeleteSimpleShapeCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//CreateOrDeleteSimpleShapeCommand(const CreateOrDeleteSimpleShapeCommand & unCreateOrDeleteSimpleShapeCommand);
//// Manual : Copy constructor.
////
//// Contract : None.
////

CreateOrDeleteSimpleShapeCommand(string name, vector<Point> somePoints, ShapeType oneType, CreateOrDelete oneAction);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~CreateOrDeleteSimpleShapeCommand();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods


private:
//-------------------------------------------------------- Private methods

bool CreateSimpleShape();
// Manual :
//
// Contract :
//

bool DeleteSimpleShape();
// Manual :
//
// Contract :
//

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes
vector<Point> points;
ShapeType type;
CreateOrDelete action;
};

//---------------------------- Other definition depend on <CreateOrDeleteSimpleShapeCommand>

#endif // CreateOrDeleteSimpleShapeCommand_H


