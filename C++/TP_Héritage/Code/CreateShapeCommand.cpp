/*************************************************************************
CreateShapeCommand - Implementation file of the class <CreateShapeCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:33
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <CreateShapeCommand> (file CreateShapeCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "CreateShapeCommand.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool CreateShapeCommand::Execute()
// Algorithm :
//
{
    bool result = false;

    if(shape->GetType() == ShapeType::SegmentType)
    {
        Segment *s = new Segment(*((Segment*)shape));
        shapes->insert(make_pair(s->GetName(),s));
        result = true;
    }
    else if(shape->GetType() == ShapeType::RectangleType)
    {
        Rectangle *s = new Rectangle(*((Rectangle*)shape));
        shapes->insert(make_pair(s->GetName(),s));
        result = true;
    }
    else if(shape->GetType() == ShapeType::ConvexPolygonType)
    {
        ConvexPolygon *s = new ConvexPolygon(*((ConvexPolygon*)shape));
        shapes->insert(make_pair(s->GetName(),s));
        result = true;
    }
    else if(shape->GetType() == ShapeType::ReunionType)
    {
        Reunion *s = new Reunion(*((Reunion*)shape));
        shapes->insert(make_pair(s->GetName(),s));
        result = true;
    }
    else if(shape->GetType() == ShapeType::IntersectionType)
    {
        Intersection *s = new Intersection(*((Intersection*)shape));
        shapes->insert(make_pair(s->GetName(),s));
        result = true;
    }

    return result;
} //----- End of Execute

void CreateShapeCommand::Undo()
// Algorithm :
//
{
    map<string,Shape*>::iterator it;
    it = shapes->find(shape->GetName());
    if (it != shapes->end())
    {
        shapes->erase(shape->GetName());
        delete it->second;
    }
} //----- End of Undo

//------------------------------------------------- Operators overloading

//CreateShapeCommand & CreateShapeCommand::operator = (const CreateShapeCommand & oneCreateShapeCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//CreateShapeCommand::CreateShapeCommand(const CreateShapeCommand & oneCreateShapeCommand)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <CreateShapeCommand>" << endl;
//#endif
//} //----- End of CreateShapeCommand


CreateShapeCommand::CreateShapeCommand(map<string, Shape *> *someShapes,Shape *oneShape) :
    ShapeCommand(someShapes), shape(oneShape)
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CreateShapeCommand>" << endl;
#endif
} //----- End of CreateShapeCommand


CreateShapeCommand::~CreateShapeCommand()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CreateShapeCommand>" << endl;
#endif
} //----- End of ~CreateShapeCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
