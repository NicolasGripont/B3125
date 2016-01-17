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
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ShapeManager.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"

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
//        Rectangle *shape = new Rectangle(name,p1,p2);
//        shapes.insert(make_pair(name,shape));
        result = true;
    }
    return result;
} //----- End of CreateRectangle

bool ShapeManager::CreateSegment(string name, Point p1, Point p2)
{
    bool result = false;
    if(GetShape(name) == nullptr)
    {
//        Segment *shape = new Segment(name,p1,p2);
//        shapes.insert(make_pair(name,shape));
        result = true;
    }
    return result;
} //----- End of CreateSegment

bool ShapeManager::CreateConvexPolygon(string name, vector<Point> somePoints)
{
    bool result = false;
    if(GetShape(name) == nullptr)
    {
//        ConvexPolygon *shape = new ConvexPolygon(name,somePoints);
//        shapes.insert(make_pair(name,shape));
        result = true;
    }
    return result;
} //----- End of CreateConvexPolygon

bool ShapeManager::CreateIntersection(string name, vector<string> someShapeNames)
{
    bool result = true;
    vector<Shape*> someShapes;
    for(vector<string>::iterator it = someShapeNames.begin(); it != someShapeNames.end() && result; it++)
    {
        if(GetShape(*it) != nullptr)
        {
            someShapes.push_back(shapes.find(*it)->second);
        }
        else
        {
            result = false;
        }
    }

    if(result && GetShape(name) == nullptr)
    {
//        Intersection *shape = new Intersection(name,someShapes);
//        shapes.insert(make_pair(name,shape));
        result = true;
    }
    return result;
} //----- End of CreateIntersection

bool ShapeManager::CreateReunion(string name, vector<string> someShapeNames)
{
    bool result = true;
    vector<Shape*> someShapes;
    for(vector<string>::iterator it = someShapeNames.begin(); it != someShapeNames.end() && result; it++)
    {
        if(GetShape(*it) != nullptr)
        {
            someShapes.push_back(shapes.find(*it)->second);
        }
        else
        {
            result = false;
        }
    }

    if(result && GetShape(name) == nullptr)
    {
//        Reunion *shape = new Reunion(name,someShapes);
//        shapes.insert(make_pair(name,shape));
        return true;
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
        shapes.erase(name);
        delete it->second;
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
//        it->second->Move(dx,dy);
    }
} //----- End of MoveShape

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
} //----- End of ~ShapeManager


//---------------------------------------------------------------- PRIVATE

 ShapeManager ShapeManager::instance;

//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
