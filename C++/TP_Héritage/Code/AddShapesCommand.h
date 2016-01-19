/*************************************************************************
AddShapesCommand - Header file of the class <AddShapesCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:41:11
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <AddShapesCommand> (file AddShapesCommand.h)
#if ! defined ( AddShapesCommand_H )
#define AddShapesCommand_H

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
// Role of the class <AddShapesCommand>
//
//
//------------------------------------------------------------------------


class AddShapesCommand : public ShapeCommand
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

//AddShapesCommand & operator = (const AddShapesCommand & oneAddShapesCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//AddShapesCommand(const AddShapesCommand & oneAddShapesCommand);
//// Manual : Copy constructor.
////
//// Contract : None.
////

AddShapesCommand(map<string, Shape *> *someShapes, const vector<Shape*> & someDeletedShapes);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~AddShapesCommand();
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

vector<Shape*> createdShapes;

bool created;

private:
//------------------------------------------------------ Pivate attributes


};

//---------------------------- Other definition depend on <AddShapesCommand>

#endif // AddShapesCommand_H


