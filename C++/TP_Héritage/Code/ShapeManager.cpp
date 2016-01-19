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
#include "RemoveShapesCommand.h"
#include "AddShapesCommand.h"


#include <iostream>
using namespace std;

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

ShapeManager& ShapeManager::GetInstance()
{
    return instance;
} //----- End of GetInstance

const map<string,Shape*> & ShapeManager::GetShapes() const
{
    return shapes;
} //----- End of GetShapes

const Shape* ShapeManager::GetShape(const string & name) const
{
    map<string,Shape*>::const_iterator it;
    it = shapes.find(name);
    if (it == shapes.end())
    {
        return nullptr;
    }
    return it->second;
} //----- End of GetShape

bool ShapeManager::CreateRectangle(const string & name, const Point & p1, const Point & p2)
{
    bool result = true;
    if(GetShape(name) == nullptr)
    {
        vector<Point> somePoints;
        somePoints.push_back(p1);
        somePoints.push_back(p2);
        vector<Shape*>createdShapes;
        createdShapes.push_back(new Rectangle(name,p1,p2));
        Execute(new AddShapesCommand(&shapes,createdShapes));
    }
    return result;
} //----- End of CreateRectangle

bool ShapeManager::CreateSegment(const string & name, const Point & p1, const Point & p2)
{
    bool result = true;
    if(GetShape(name) == nullptr)
    {
        vector<Point> somePoints;
        somePoints.push_back(p1);
        somePoints.push_back(p2);
        vector<Shape*>createdShapes;
        createdShapes.push_back(new Segment(name,p1,p2));
        Execute(new AddShapesCommand(&shapes,createdShapes));
    }
    return result;
} //----- End of CreateSegment

bool ShapeManager::CreateConvexPolygon(const string & name, const vector<Point> & somePoints)
{
    bool result = true;
    if(GetShape(name) == nullptr)
    {
        vector<Shape*>createdShapes;
        createdShapes.push_back(new ConvexPolygon(name,somePoints));
        Execute(new AddShapesCommand(&shapes,createdShapes));
    }
    return result;
} //----- End of CreateConvexPolygon

bool ShapeManager::CreateIntersection(const string & name,const vector<string> & someShapeNames)
{
    bool result = true;
    map<string,Shape*>::iterator itm;
    vector<Shape*> someShapes;

    for(vector<string>::const_iterator it = someShapeNames.begin(); it != someShapeNames.end(); it++)
    {
        itm = shapes.find(*it);
        if (itm != shapes.end())
        {
            someShapes.push_back(itm->second);
        }
    }

    if(GetShape(name) == nullptr)
    {
        vector<Shape*>createdShapes;
        createdShapes.push_back(new Intersection(name,someShapes));
        Execute(new AddShapesCommand(&shapes,createdShapes));
    }

    return result;
} //----- End of CreateIntersection

bool ShapeManager::CreateReunion(const string & name, const vector<string> & someShapeNames)
{
    bool result = true;
    map<string,Shape*>::iterator itm;
    vector<Shape*> someShapes;
    for(vector<string>::const_iterator it = someShapeNames.begin(); it != someShapeNames.end(); it++)
    {
        itm = shapes.find(*it);
        if (itm != shapes.end())
        {
            someShapes.push_back(itm->second);
        }
    }

    if(GetShape(name) == nullptr)
    {
        vector<Shape*>createdShapes;
        createdShapes.push_back(new Reunion(name,someShapes));
        Execute(new AddShapesCommand(&shapes,createdShapes));
    }

    return result;
} //----- End of CreateReunion

bool ShapeManager::DeleteShape(const vector<string> & names)
{
    bool result = true;
    vector<Shape*> someShapes;
    map<string,Shape*>::iterator itm;

    for(vector<string>::const_iterator it = names.begin(); it != names.end(); it++)
    {
        itm = shapes.find(*it);
        if (itm != shapes.end())
        {
            someShapes.push_back(itm->second);
        }
    }

    Execute(new RemoveShapesCommand(&shapes,someShapes));

    return result;
} //----- End of DeleteShape

void ShapeManager::MoveShape(const string & name, int dx, int dy)
{
    map<string,Shape*>::iterator it;
    it = shapes.find(name);
    if (it != shapes.end())
    {
        Execute(new MoveShapeCommand(&shapes,name,dx,dy));
    }
} //----- End of MoveShape

void ShapeManager::Undo()
// Algorithm :
//
{
    Command *c;
    if(undoStack.size() > 0)
    {
        c = undoStack.front();
        undoStack.pop_front();
        redoStack.push_front(c);
        c->Undo();
    }
} //----- End of Undo

void ShapeManager::Redo()
// Algorithm :
//
{
    Command *c;
    if(redoStack.size() > 0)
    {
        c = redoStack.front();
        redoStack.pop_front();
        undoStack.push_front(c);
        c->Execute();
    }
} //----- End of Redo

bool ShapeManager::Include(const string & name, const Point & p) const
// Algorithm :
//
{
    bool result = true;
    map<string,Shape*>::const_iterator it;
    it = shapes.find(name);
    if (it != shapes.end())
    {
        it->second->Include(p);
    }
    return result;
} //----- End of Redo

bool ShapeManager::Clear()
{
    bool result = true;
    vector<Shape*> someShapes;

    for( map<string,Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        someShapes.push_back(it->second);
    }

    Execute(new RemoveShapesCommand(&shapes,someShapes));

    return result;
} //----- End of DeleteShape

bool ShapeManager::Load(const string & filePath)
{
    bool result = false;

    return result;
} //----- End of DeleteShape

bool ShapeManager::Save(const string & filePath) const
{
    bool result = false;

    return result;
} //----- End of DeleteShape

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

void ShapeManager::Execute(Command* c)
// Algorithm :
//
{
    c->Execute();
    if(undoStack.size() == MAX_UNDO_REDO)
    {
        delete undoStack.back();
        undoStack.pop_back();
    }
    undoStack.push_front(c);

    for(list<Command*>::iterator it = redoStack.begin(); it != redoStack.end(); it++)
    {
        delete *it;
    }
    redoStack.clear();
} //----- End of Execute

//-------------------------------------------------------- Private methods
