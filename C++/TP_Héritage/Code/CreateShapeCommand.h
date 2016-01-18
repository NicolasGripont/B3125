/*************************************************************************
CreateShapeCommand - Header file of the class <CreateShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:40:50
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <CreateShapeCommand> (file CreateShapeCommand.h)
#if ! defined ( CreateShapeCommand_H )
#define CreateShapeCommand_H

//-------------------------------------------------------- Used interfaces 
#include <vector>
using namespace std;

#include "ShapeCommand.h"
#include "Point.h"
//-------------------------------------------------------------- Constants


//------------------------------------------------------------------ Types
#if ! defined ( VectorPoint )
#define VectorPoint
template class std::vector<Point>;
#endif
//------------------------------------------------------------------- enum

//------------------------------------------------------------------------
// Role of the class <CreateShapeCommand>
//
//
//------------------------------------------------------------------------



class CreateShapeCommand : public ShapeCommand
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

//CreateShapeCommand & operator = (const CreateShapeCommand & oneCreateShapeCommand);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

//CreateShapeCommand(const CreateShapeCommand & oneCreateShapeCommand);
//// Manual : Copy constructor.
////
//// Contract : None.
////

CreateShapeCommand(map<string, Shape *> *someShapes,Shape *oneShape);
// Manual : Constructor.
//
// Contract : None.
//

virtual ~CreateShapeCommand();
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
Shape *shape;
};

//---------------------------- Other definition depend on <CreateShapeCommand>

#endif // CreateShapeCommand_H


