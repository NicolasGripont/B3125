/*************************************************************************
DeleteShapesCommand - Header file of the class <DeleteShapesCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:41:11
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <DeleteShapesCommand> (file DeleteShapesCommand.h)
#if ! defined ( DeleteShapesCommand_H )
#define DeleteShapesCommand_H

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
// Role of the class <DeleteShapesCommand>
//
//
//------------------------------------------------------------------------


class DeleteShapesCommand : public ShapeCommand
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

//DeleteShapesCommand & operator = (const DeleteShapesCommand & oneDeleteShapesCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//DeleteShapesCommand(const DeleteShapesCommand & oneDeleteShapesCommand);
//// Manual : Copy constructor.
////
//// Contract : None.
////

DeleteShapesCommand(map<string, Shape *> *someShapes, vector<Shape*> someDeletedShapes);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~DeleteShapesCommand();
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
vector<Shape*> deletedShapes;

};

//---------------------------- Other definition depend on <DeleteShapesCommand>

#endif // DeleteShapesCommand_H


