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

//------------------------------------------------------ Personnal include
#include "CreateOrDeleteComplexShapeCommand.h"
#include "Intersection.h"
#include "Reunion.h"

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


CreateOrDeleteComplexShapeCommand::CreateOrDeleteComplexShapeCommand(string name, map<string, Shape *> *someShapes, vector<string> someShapeNames, ShapeType oneType, CreateOrDelete oneAction):
    ShapeCommand(name,someShapes), shapeNames(someShapeNames), type(oneType), action(oneAction)
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
    bool result = true;
    vector<Shape*> someShapes;
    for(vector<string>::iterator it = shapeNames.begin(); it != shapeNames.end(); it++)
    {
        map<string,Shape*>::iterator itm;
        itm = shapes->find(*it);
        if (itm == shapes->end())
        {
            someShapes.push_back(itm->second);
        }
        else
        {
            result = false;
            break;
        }
    }

    if(result && (type == ShapeType::ReunionType))
    {
        Reunion *shape = new Reunion(shapeName,someShapes);
        shapes->insert(make_pair(shapeName,shape));
    }
    else if(result && (type == ShapeType::IntersectionType))
    {
        Intersection *shape = new Intersection(shapeName,someShapes);
        shapes->insert(make_pair(shapeName,shape));
    }

    return result;

} //----- End of CreateComplexShape

bool CreateOrDeleteComplexShapeCommand::DeleteComplexShape()
// Algorithm :
//
{
    bool result = false;
    map<string,Shape*>::iterator it;
    it = shapes->find(shapeName);
    if (it != shapes->end())
    {
        shapes->erase(shapeName);
        delete it->second;
        result = true;
    }
    return result;
} //----- End of DeleteComplexShape
