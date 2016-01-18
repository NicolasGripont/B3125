/*************************************************************************
CreateOrDeleteComplexShapeCommand - Header file of the class <CreateOrDeleteComplexShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:41:11
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <CreateOrDeleteComplexShapeCommand> (file CreateOrDeleteComplexShapeCommand.h)
#if ! defined ( CreateOrDeleteComplexShapeCommand_H )
#define CreateOrDeleteComplexShapeCommand_H

//-------------------------------------------------------- Used interfaces
#include <vector>
#include <string>
using namespace std;

#include "Shape.h"
#include "ShapeCommand.h"
//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types
#if ! defined ( VectorString )
#define VectorString
template class std::vector<string>;
#endif
#if ! defined ( VectorShapePtr )
#define VectorShapePtr
template class std::vector<Shape*>;
#endif
//------------------------------------------------------------------- enum


//------------------------------------------------------------------------
// Role of the class <CreateOrDeleteComplexShapeCommand>
//
//
//------------------------------------------------------------------------


class CreateOrDeleteComplexShapeCommand : public ShapeCommand
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

//CreateOrDeleteComplexShapeCommand & operator = (const CreateOrDeleteComplexShapeCommand & unCreateOrDeleteComplexShapeCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//CreateOrDeleteComplexShapeCommand(const CreateOrDeleteComplexShapeCommand & unCreateOrDeleteComplexShapeCommand);
//// Manual : Copy constructor.
////
//// Contract : None.
////

CreateOrDeleteComplexShapeCommand(string name, map<string, Shape *> *someShapes, vector<string> someShapeNames, ShapeType oneType, CreateOrDelete oneAction);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~CreateOrDeleteComplexShapeCommand();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods


private:
//-------------------------------------------------------- Private methods

bool CreateComplexShape();
// Manual :
//
// Contract :
//

bool DeleteComplexShape();
// Manual :
//
// Contract :
//

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes
vector<string> shapeNames;
ShapeType type;
CreateOrDelete action;
};

//---------------------------- Other definition depend on <CreateOrDeleteComplexShapeCommand>

#endif // CreateOrDeleteComplexShapeCommand_H


