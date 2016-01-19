/*************************************************************************
RemoveShapesCommand - Header file of the class <RemoveShapesCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:41:11
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <RemoveShapesCommand> (file RemoveShapesCommand.h)
#if ! defined ( RemoveShapesCommand_H )
#define RemoveShapesCommand_H

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
// Role of the class <RemoveShapesCommand>
//
//
//------------------------------------------------------------------------


class RemoveShapesCommand : public ShapeCommand
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

//RemoveShapesCommand & operator = (const RemoveShapesCommand & oneRemoveShapesCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//RemoveShapesCommand(const RemoveShapesCommand & oneRemoveShapesCommand);
//// Manual : Copy constructor.
////
//// Contract : None.
////

RemoveShapesCommand(map<string, Shape *> *someShapes, vector<Shape*> someDeletedShapes);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~RemoveShapesCommand();
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

vector<Shape*> deletedShapes;
bool deleted;

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <RemoveShapesCommand>

#endif // RemoveShapesCommand_H


