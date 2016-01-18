/*************************************************************************
Intersection - Implementation file of the class <Intersection>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:55:08
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Intersection> (file Intersection.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include

#include "Intersection.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool Intersection::Include(Point p)
// Algorithm :
//
{
    bool result = true;
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        if(!(*it)->Include(p))
        {
            result = false;
            break;
        }
    }
    return result;
} //----- End of Include

string Intersection::ToString()
// Algorithm :
//
{
    string s;
    s = "OI ";
    s += name;
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        s += "\n  ";
        s += (*it)->ToString();
    }
    return s;
} //----- End of ToString


//------------------------------------------------- Operators overloading

Intersection & Intersection::operator = (const Intersection & oneIntersection)
// Algorithm :
//
{
    name = oneIntersection.name;
    type = oneIntersection.type;

    for(vector<Shape*>::const_iterator it = oneIntersection.children.begin(); it != oneIntersection.children.end(); it++)
    {
        ShapeType t = (*it)->GetType();
        if(t == ShapeType::SegmentType)
        {
            Segment* shape = (Segment*)*it;
            children.push_back(new Segment(*shape));
        }
        else if (t == ShapeType::RectangleType)
        {
            Rectangle* shape = (Rectangle*)*it;
            children.push_back(new Rectangle(*shape));
        }
        else if (t == ShapeType::ConvexPolygonType)
        {
            ConvexPolygon* shape = (ConvexPolygon*)*it;
            children.push_back(new ConvexPolygon(*shape));
        }
        else if (t == ShapeType::ReunionType)
        {
            Reunion* shape = (Reunion*)*it;
            children.push_back(new Reunion(*shape));
        }
        else if (t == ShapeType::IntersectionType)
        {
            Intersection* shape = (Intersection*)*it;
            children.push_back(new Intersection(*shape));
        }
    }

    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Intersection::Intersection(const Intersection & oneIntersection) :
    ComplexShape(oneIntersection)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Intersection>" << endl;
#endif
} //----- End of Intersection


Intersection::Intersection(string oneName, vector<Shape *> someShapes) :
    ComplexShape(oneName,ShapeType::IntersectionType,someShapes)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Intersection>" << endl;
#endif
} //----- End of Intersection


Intersection::~Intersection()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Intersection>" << endl;
#endif
} //----- End of ~Intersection


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
