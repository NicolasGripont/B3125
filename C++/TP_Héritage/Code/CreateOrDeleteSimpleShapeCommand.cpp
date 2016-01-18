/*************************************************************************
CreateOrDeleteSimpleShapeCommand - Implementation file of the class <CreateOrDeleteSimpleShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:33
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <CreateOrDeleteSimpleShapeCommand> (file CreateOrDeleteSimpleShapeCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "CreateOrDeleteSimpleShapeCommand.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool CreateOrDeleteSimpleShapeCommand::Execute()
// Algorithm :
//
{
    bool result = false;
    switch (action) {
    case CreateOrDelete::Create:
        result = CreateSimpleShape();
        break;
    case CreateOrDelete::Delete:
        result = DeleteSimpleShape();
        break;
    default:
        break;
    }
    return result;
} //----- End of Execute

void CreateOrDeleteSimpleShapeCommand::Undo()
// Algorithm :
//
{
    switch (action) {
    case CreateOrDelete::Create:
        DeleteSimpleShape();
        break;
    case CreateOrDelete::Delete:
        CreateSimpleShape();
        break;
    default:
        break;
    }
} //----- End of Undo

//------------------------------------------------- Operators overloading

//CreateOrDeleteSimpleShapeCommand & CreateOrDeleteSimpleShapeCommand::operator = (const CreateOrDeleteSimpleShapeCommand & unCreateOrDeleteSimpleShapeCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//CreateOrDeleteSimpleShapeCommand::CreateOrDeleteSimpleShapeCommand(const CreateOrDeleteSimpleShapeCommand & unCreateOrDeleteSimpleShapeCommand)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <CreateOrDeleteSimpleShapeCommand>" << endl;
//#endif
//} //----- End of CreateOrDeleteSimpleShapeCommand


CreateOrDeleteSimpleShapeCommand::CreateOrDeleteSimpleShapeCommand(string name, map<string, Shape *> *someShapes, vector<Point> somePoints, ShapeType oneType, CreateOrDelete oneAction) :
    ShapeCommand(name,someShapes), points(somePoints),type(oneType),action(oneAction)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CreateOrDeleteSimpleShapeCommand>" << endl;
#endif
} //----- End of CreateOrDeleteSimpleShapeCommand


CreateOrDeleteSimpleShapeCommand::~CreateOrDeleteSimpleShapeCommand()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CreateOrDeleteSimpleShapeCommand>" << endl;
#endif
} //----- End of ~CreateOrDeleteSimpleShapeCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods

bool CreateOrDeleteSimpleShapeCommand::CreateSimpleShape()
// Algorithm :
//
{
    bool result = false;
    if(type == ShapeType::SegmentType)
    {
        Segment *shape = new Segment(shapeName,points[0],points[1]);
        shapes->insert(make_pair(shapeName,shape));
        result = true;
    }
    else if(type == ShapeType::RectangleType)
    {
        Rectangle *shape = new Rectangle(shapeName,points[0],points[1]);
        shapes->insert(make_pair(shapeName,shape));
        result = true;
    }
    else if(type == ShapeType::ConvexPolygonType)
    {
        ConvexPolygon *shape = new ConvexPolygon(shapeName,points);
        shapes->insert(make_pair(shapeName,shape));
        result = true;
    }

    return result;

} //----- End of CreateSimpleShape

bool CreateOrDeleteSimpleShapeCommand::DeleteSimpleShape()
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
} //----- End of DeleteSimpleShape
