/*************************************************************************
ShapeManager - Implementation file of the class <ShapeManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:36:35
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ShapeManager> (file ShapeManager.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "ShapeManager.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"
#include "MoveShapeCommand.h"
#include "CreateOrDeleteComplexShapeCommand.h"
#include "CreateOrDeleteSimpleShapeCommand.h"

#include <iostream>
using namespace std;

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

ShapeManager& ShapeManager::GetInstance()
{
    return instance;
} //----- End of GetInstance

map<string,Shape*>& ShapeManager::GetShapes()
{
    return shapes;
} //----- End of GetShapes

Shape* ShapeManager::GetShape(string name)
{
    map<string,Shape*>::iterator it;
    it = shapes.find(name);
    if (it == shapes.end())
    {
        return nullptr;
    }
    return it->second;
} //----- End of GetShape

bool ShapeManager::CreateRectangle(string name, Point p1, Point p2)
{
    bool result = false;
    if(GetShape(name) == nullptr)
    {
        vector<Point> somePoints;
        somePoints.push_back(p1);
        somePoints.push_back(p2);
        result = Execute(new CreateOrDeleteSimpleShapeCommand(name,&shapes,somePoints,ShapeType::RectangleType,CreateOrDelete::Create));
    }
    return result;
} //----- End of CreateRectangle

bool ShapeManager::CreateSegment(string name, Point p1, Point p2)
{
    bool result = false;
    if(GetShape(name) == nullptr)
    {
        vector<Point> somePoints;
        somePoints.push_back(p1);
        somePoints.push_back(p2);
        result = Execute(new CreateOrDeleteSimpleShapeCommand(name,&shapes,somePoints,ShapeType::SegmentType,CreateOrDelete::Create));
    }
    return result;
} //----- End of CreateSegment

bool ShapeManager::CreateConvexPolygon(string name, vector<Point> somePoints)
{
    bool result = false;
    if(GetShape(name) == nullptr)
    {
        result = Execute(new CreateOrDeleteSimpleShapeCommand(name,&shapes,somePoints,ShapeType::ConvexPolygonType,CreateOrDelete::Create));
    }
    return result;
} //----- End of CreateConvexPolygon

bool ShapeManager::CreateIntersection(string name, vector<string> someShapeNames)
{
    bool result = false;

    if(GetShape(name) == nullptr)
    {
        result = Execute(new CreateOrDeleteComplexShapeCommand(name,&shapes,someShapeNames,ShapeType::IntersectionType,CreateOrDelete::Create));
    }

    return result;
} //----- End of CreateIntersection

bool ShapeManager::CreateReunion(string name, vector<string> someShapeNames)
{
    bool result = false;

    if(GetShape(name) == nullptr)
    {
        result = Execute(new CreateOrDeleteComplexShapeCommand(name,&shapes,someShapeNames,ShapeType::ReunionType,CreateOrDelete::Create));
    }

    return result;
} //----- End of CreateReunion

bool ShapeManager::DeleteShape(string name)
{
    bool result = false;
    map<string,Shape*>::iterator it;
    it = shapes.find(name);
    if (it != shapes.end())
    {
        ShapeType type = it->second->GetType();
        if(type == ShapeType::SegmentType || type == ShapeType::RectangleType || type == ShapeType::ConvexPolygonType)
        {
            SimpleShape *s = (SimpleShape*)it->second;
            result = Execute(new CreateOrDeleteSimpleShapeCommand(name,&shapes,s->GetPoints(),s->GetType(),CreateOrDelete::Delete));
        }
        else if(type == ShapeType::IntersectionType || type == ShapeType::ReunionType)
        {
            ComplexShape *s = (ComplexShape*)it->second;
            result = Execute(new CreateOrDeleteComplexShapeCommand(name,&shapes,s->GetDirectChildrenName(),s->GetType(),CreateOrDelete::Delete));
        }
        result = true;
    }
    return result;
} //----- End of DeleteShape

void ShapeManager::MoveShape(string name,int dx, int dy)
{
    map<string,Shape*>::iterator it;
    it = shapes.find(name);
    if (it != shapes.end())
    {
        Execute(new MoveShapeCommand(name,&shapes,dx,dy));
    }
} //----- End of MoveShape

void ShapeManager::Undo()
// Algorithm :
//
{
    Command *c;
    c = undoStack.front();
    undoStack.pop_front();
    redoStack.push_front(c);
    c->Undo();
} //----- End of Undo

void ShapeManager::Redo()
// Algorithm :
//
{
    Command *c;
    c = redoStack.front();
    redoStack.pop_front();
    undoStack.push_front(c);
    c->Execute();
} //----- End of Redo


//------------------------------------------------- Operators overloading

//ShapeManager & ShapeManager::operator = (const ShapeManager & oneShapeManager)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//ShapeManager::ShapeManager(const ShapeManager & oneShapeManager)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <ShapeManager>" << endl;
//#endif
//} //----- End of ShapeManager


ShapeManager::ShapeManager() : shapes()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ShapeManager>" << endl;
#endif
} //----- End of ShapeManager


ShapeManager::~ShapeManager()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ShapeManager>" << endl;
#endif
    for(map<string,Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        delete it->second;
    }
    for(list<Command*>::iterator it = undoStack.begin(); it != undoStack.end(); it++)
    {
        delete *it;
    }

    for(list<Command*>::iterator it = redoStack.begin(); it != redoStack.end(); it++)
    {
        delete *it;
    }
} //----- End of ~ShapeManager


//---------------------------------------------------------------- PRIVATE

 ShapeManager ShapeManager::instance;

//------------------------------------------------------ Protected methods

bool ShapeManager::Execute(Command* c)
// Algorithm :
//
{
    bool result = c->Execute();

    if(result)
    {
        if(undoStack.size() == MAX_UNDO_REDO)
        {
            delete undoStack.back();
            undoStack.pop_back();
        }
        undoStack.push_front(c);
    }

    for(list<Command*>::iterator it = redoStack.begin(); it != redoStack.end(); it++)
    {
        delete *it;
    }
    redoStack.clear();

    return result;
} //----- End of Execute

//-------------------------------------------------------- Private methods
