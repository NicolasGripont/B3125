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
#include "ShapeFileManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

ShapeManager& ShapeManager::GetInstance()
// Algorithm :
//
{
    return instance;
} //----- End of GetInstance

const unordered_map<string,Shape*> & ShapeManager::GetShapes() const
// Algorithm :
//
{
    return shapes;
} //----- End of GetShapes

const Shape* ShapeManager::GetShape(const string & name) const
// Algorithm :
//
{
    unordered_map<string,Shape*>::const_iterator it;
    it = shapes.find(name);
    if (it == shapes.end())
    {
        return nullptr;
    }
    return it->second;
} //----- End of GetShape

int ShapeManager::CreateRectangle(const string & name, const Point & p1, const Point & p2)
// Algorithm :
//
{
    int result = 0;
    if(GetShape(name) == nullptr)
    {
        vector<Point> somePoints;
        somePoints.push_back(p1);
        somePoints.push_back(p2);
        vector<Shape*>createdShapes;
        Shape* shape = new Rectangle(name,p1,p2);
        if(shape->IsValid())
        {
            createdShapes.push_back(shape);
            Execute(new AddShapesCommand(&shapes,createdShapes));
        }
        else
        {
            delete shape;
            result = 2;
        }
    }
    else
    {
        result = 1;
    }
    return result;
} //----- End of CreateRectangle

int ShapeManager::CreateSegment(const string & name, const Point & p1, const Point & p2)
// Algorithm :
//
{
    bool result = 0;
    if(GetShape(name) == nullptr)
    {
        vector<Point> somePoints;
        somePoints.push_back(p1);
        somePoints.push_back(p2);
        vector<Shape*>createdShapes;
        Shape* shape = new Segment(name,p1,p2);
        if(shape->IsValid())
        {
            createdShapes.push_back(shape);
            Execute(new AddShapesCommand(&shapes,createdShapes));
        }
        else
        {
            delete shape;
            result = 2;
        }
    }
    else
    {
        result = 1;
    }
    return result;
} //----- End of CreateSegment

int ShapeManager::CreateConvexPolygon(const string & name, const vector<Point> & somePoints)
// Algorithm :
//
{
    bool result = 0;
    if(GetShape(name) == nullptr)
    {
        vector<Shape*>createdShapes;
        Shape* shape = new ConvexPolygon(name,somePoints);
        if(shape->IsValid())
        {
            createdShapes.push_back(shape);
            Execute(new AddShapesCommand(&shapes,createdShapes));
        }
        else
        {
            delete shape;
            result = 2;
        }
    }
    else
    {
        result = 1;
    }
    return result;
} //----- End of CreateConvexPolygon

int ShapeManager::CreateIntersection(const string & name,const vector<string> & someShapeNames)
// Algorithm :
//
{
    bool result = 0;
    unordered_map<string,Shape*>::iterator itm;
    vector<Shape*> someShapes;
    if(GetShape(name) == nullptr)
    {
        for(vector<string>::const_iterator it = someShapeNames.begin(); it != someShapeNames.end(); it++)
        {
            itm = shapes.find(*it);
            if (itm != shapes.end())
            {
                someShapes.push_back(itm->second);
            }
        }

        if(someShapeNames.size() == someShapes.size())
        {

            vector<Shape*>createdShapes;
            Shape* shape = new Intersection(name,someShapes);
            if(shape->IsValid())
            {
                createdShapes.push_back(shape);
                Execute(new AddShapesCommand(&shapes,createdShapes));
            }
            else
            {
                delete shape;
                result = 2;
            }
        }
        else
        {
            result = 3;
        }
    }
    else
    {
        result = 1;
    }
    return result;
} //----- End of CreateIntersection

int ShapeManager::CreateReunion(const string & name, const vector<string> & someShapeNames)
// Algorithm :
//
{
    bool result = 0;
    unordered_map<string,Shape*>::iterator itm;
    vector<Shape*> someShapes;
    if(GetShape(name) == nullptr)
    {
        for(vector<string>::const_iterator it = someShapeNames.begin(); it != someShapeNames.end(); it++)
        {
            itm = shapes.find(*it);
            if (itm != shapes.end())
            {
                someShapes.push_back(itm->second);
            }
        }
        if(someShapeNames.size() == someShapes.size())
        {

            vector<Shape*>createdShapes;
            Shape* shape = new Reunion(name,someShapes);
            if(shape->IsValid())
            {
                createdShapes.push_back(shape);
                Execute(new AddShapesCommand(&shapes,createdShapes));
            }
            else
            {
                delete shape;
                result = 2;
            }
        }
        else
        {
            result = 3;
        }
    }
    else
    {
        result = 1;
    }
    return result;
} //----- End of CreateReunion

int ShapeManager::DeleteShape(const vector<string> & names)
// Algorithm :
//
{
    int result = 0;
    vector<Shape*> someShapes;
    unordered_map<string,Shape*>::iterator itm;

    for(vector<string>::const_iterator it = names.begin(); it != names.end(); it++)
    {
        itm = shapes.find(*it);
        if (itm != shapes.end())
        {
            someShapes.push_back(itm->second);
        }
        else
        {
            result = 1;
        }
    }
    if(result == 0)
    {
        Execute(new RemoveShapesCommand(&shapes,someShapes));
    }
    return result;
} //----- End of DeleteShape

int ShapeManager::MoveShape(const string & name, int dx, int dy)
// Algorithm :
//
{
    int result = 0;
    unordered_map<string,Shape*>::iterator it;
    it = shapes.find(name);
    if (it != shapes.end())
    {
        Execute(new MoveShapeCommand(&shapes,name,dx,dy));
    }
    else
    {
        result = 1;
    }
    return result;
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

int ShapeManager::Include(const string & name, const Point & p) const
// Algorithm :
//
{
    int result = 0;
    unordered_map<string,Shape*>::const_iterator it;
    it = shapes.find(name);
    if (it != shapes.end())
    {
        if(!it->second->Include(p))
        {
            result = 1;
        }
    }
    else
    {
        result = 2;
    }
    return result;
} //----- End of Redo

void ShapeManager::Clear()
// Algorithm :
//
{
    vector<Shape*> someShapes;

    if(shapes.size())
    {
        for( unordered_map<string,Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            someShapes.push_back(it->second);
        }

        Execute(new RemoveShapesCommand(&shapes,someShapes));
    }
} //----- End of Clear

int ShapeManager::Load(const string & filePath)
// Algorithm :
//
{
    int result = 0;

    vector<Shape*> someShapes;
    set<string> names;
    result = ShapeFileManager::Load(filePath,someShapes);

    if(result == 0)
    {
        for(vector<Shape*>::iterator it = someShapes.begin(); it != someShapes.end(); it++)
        {
            if(GetShape((*it)->GetName()) != nullptr)
            {
                result = 3;
                break;
            }
        }
        if(result == 0)
        {
            for(vector<Shape*>::iterator it = someShapes.begin(); it != someShapes.end(); it++)
            {
                if(names.find((*it)->GetName()) != names.end())
                {
                    result = 4;
                    break;
                }
                else
                {
                    names.insert((*it)->GetName());
                }
            }
        }
    }

    if(result == 0)
    {
        Execute(new AddShapesCommand(&shapes,someShapes));
    }
    else
    {
        for(vector<Shape*>::iterator it = someShapes.begin(); it != someShapes.end(); it++)
        {
            delete *it;
        }
    }

    return result;
} //----- End of Load


int ShapeManager::Save(const string & filePath) const
// Algorithm :
//
{
    bool result = 0;

    result = ShapeFileManager::Save(filePath,shapes);

    return result;
} //----- End of Save

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
    for(unordered_map<string,Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
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

