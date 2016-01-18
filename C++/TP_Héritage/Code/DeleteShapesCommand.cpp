/*************************************************************************
DeleteShapesCommand - Implementation file of the class <DeleteShapesCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:14
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <DeleteShapesCommand> (file DeleteShapesCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "DeleteShapesCommand.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Intersection.h"
#include "Reunion.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool DeleteShapesCommand::Execute()
// Algorithm :
//
{
    map<string,Shape*>::iterator itm;
    for(vector<Shape*>::iterator it = deletedShapes.begin(); it != deletedShapes.end(); it++)
    {
        itm = shapes->find((*it)->GetName());
        if (itm != shapes->end())
        {
            shapes->erase(itm->second->GetName());
            delete itm->second;
        }
    }
    return true;
} //----- End of Execute

void DeleteShapesCommand::Undo()
// Algorithm :
//
{
    for(vector<Shape*>::iterator it = deletedShapes.begin(); it != deletedShapes.end(); it++)
    {
        if((*it)->GetType() == ShapeType::SegmentType)
        {
            Segment *s = new Segment(*((Segment*)(*it)));
            shapes->insert(make_pair(s->GetName(),s));
        }
        else if((*it)->GetType() == ShapeType::RectangleType)
        {
            Rectangle *s = new Rectangle(*((Rectangle*)(*it)));
            shapes->insert(make_pair(s->GetName(),s));
        }
        else if((*it)->GetType() == ShapeType::ConvexPolygonType)
        {
            ConvexPolygon *s = new ConvexPolygon(*((ConvexPolygon*)(*it)));
            shapes->insert(make_pair(s->GetName(),s));
        }
        else if((*it)->GetType() == ShapeType::ReunionType)
        {
            Reunion *s = new Reunion(*((Reunion*)(*it)));
            shapes->insert(make_pair(s->GetName(),s));
        }
        else if((*it)->GetType() == ShapeType::IntersectionType)
        {
            Intersection *s = new Intersection(*((Intersection*)(*it)));
            shapes->insert(make_pair(s->GetName(),s));
        }
    }
} //----- End of Undo


//------------------------------------------------- Operators overloading

//DeleteShapesCommand & DeleteShapesCommand::operator = (const DeleteShapesCommand & oneDeleteShapesCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//DeleteShapesCommand::DeleteShapesCommand(const DeleteShapesCommand & oneDeleteShapesCommand)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <DeleteShapesCommand>" << endl;
//#endif
//} //----- End of DeleteShapesCommand


DeleteShapesCommand::DeleteShapesCommand(map<string, Shape *> *someShapes, vector<Shape*> someDeletedShapes):
    ShapeCommand(someShapes), deletedShapes()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DeleteShapesCommand>" << endl;
#endif
    for(vector<Shape*>::iterator it = someDeletedShapes.begin(); it != someDeletedShapes.end(); it++)
    {
        if((*it)->GetType() == ShapeType::SegmentType)
        {
            Segment *s = new Segment(*((Segment*)(*it)));
            deletedShapes.push_back(s);
        }
        else if((*it)->GetType() == ShapeType::RectangleType)
        {
            Rectangle *s = new Rectangle(*((Rectangle*)(*it)));
            deletedShapes.push_back(s);
        }
        else if((*it)->GetType() == ShapeType::ConvexPolygonType)
        {
            ConvexPolygon *s = new ConvexPolygon(*((ConvexPolygon*)(*it)));
            deletedShapes.push_back(s);
        }
        else if((*it)->GetType() == ShapeType::ReunionType)
        {
            Reunion *s = new Reunion(*((Reunion*)(*it)));
            deletedShapes.push_back(s);
        }
        else if((*it)->GetType() == ShapeType::IntersectionType)
        {
            Intersection *s = new Intersection(*((Intersection*)(*it)));
            deletedShapes.push_back(s);
        }
    }
} //----- End of DeleteShapesCommand


DeleteShapesCommand::~DeleteShapesCommand()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DeleteShapesCommand>" << endl;
#endif
    for(vector<Shape*>::iterator it = deletedShapes.begin(); it != deletedShapes.end(); it++)
    {
        delete *it;
    }
} //----- End of ~DeleteShapesCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods

