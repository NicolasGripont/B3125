/*************************************************************************
CreateOrDeleteComplexShapeCommand - Implementation file of the class <CreateOrDeleteComplexShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:14
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <CreateOrDeleteComplexShapeCommand> (file CreateOrDeleteComplexShapeCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "CreateOrDeleteComplexShapeCommand.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool CreateOrDeleteComplexShapeCommand::Execute()
// Algorithm :
//
{
    bool result = false;
    switch (action) {
    case CreateOrDelete::Create:
        result = CreateComplexShape();
        break;
    case CreateOrDelete::Delete:
        result = DeleteComplexShape();
        break;
    default:
        break;
    }
    return result;
} //----- End of Execute

void CreateOrDeleteComplexShapeCommand::Undo()
// Algorithm :
//
{
    switch (action) {
    case CreateOrDelete::Create:
        DeleteComplexShape();
        break;
    case CreateOrDelete::Delete:
        CreateComplexShape();
        break;
    default:
        break;
    }
} //----- End of Undo


//------------------------------------------------- Operators overloading

//CreateOrDeleteComplexShapeCommand & CreateOrDeleteComplexShapeCommand::operator = (const CreateOrDeleteComplexShapeCommand & unCreateOrDeleteComplexShapeCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//CreateOrDeleteComplexShapeCommand::CreateOrDeleteComplexShapeCommand(const CreateOrDeleteComplexShapeCommand & unCreateOrDeleteComplexShapeCommand)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <CreateOrDeleteComplexShapeCommand>" << endl;
//#endif
//} //----- End of CreateOrDeleteComplexShapeCommand


CreateOrDeleteComplexShapeCommand::CreateOrDeleteComplexShapeCommand(string name, vector<string> someShapeNames, ShapeType oneType, CreateOrDelete oneAction):
    ShapeCommand(name), shapeNames(someShapeNames), type(oneType), action(oneAction)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CreateOrDeleteComplexShapeCommand>" << endl;
#endif
} //----- End of CreateOrDeleteComplexShapeCommand


CreateOrDeleteComplexShapeCommand::~CreateOrDeleteComplexShapeCommand()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CreateOrDeleteComplexShapeCommand>" << endl;
#endif
} //----- End of ~CreateOrDeleteComplexShapeCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods

bool CreateOrDeleteComplexShapeCommand::CreateComplexShape()
// Algorithm :
//
{
    bool result = false;
    switch (type) {
    case ShapeType::ReunionType:
        result = ShapeManager::GetInstance().CreateReunion(shapeName,shapeNames);
        break;
    case ShapeType::IntersectionType:
        result = ShapeManager::GetInstance().CreateIntersection(shapeName,shapeNames);
        break;
    default:
        break;
    }
    return result;

} //----- End of CreateComplexShape

bool CreateOrDeleteComplexShapeCommand::DeleteComplexShape()
// Algorithm :
//
{
    return ShapeManager::GetInstance().DeleteShape(shapeName);
} //----- End of DeleteComplexShape
