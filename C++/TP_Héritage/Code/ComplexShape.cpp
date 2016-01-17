/*************************************************************************
ComplexShape - Implementation file of the class <ComplexShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:52:12
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ComplexShape> (file ComplexShape.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ComplexShape.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void ComplexShape::Move(int dx,int dy)
// Algorithm :
//
{
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        (*it)->Move(dx,dy);
    }
} //----- End of Move


//------------------------------------------------- Operators overloading

ComplexShape & ComplexShape::operator = (const ComplexShape & oneComplexShape)
// Algorithm :
//
{
    name = oneComplexShape.name;
    type = oneComplexShape.type;

    for(vector<Shape*>::const_iterator it = oneComplexShape.children.begin(); it != oneComplexShape.children.end(); it++)
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

ComplexShape::ComplexShape(const ComplexShape & oneComplexShape) :
    Shape(oneComplexShape), children()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ComplexShape>" << endl;
#endif

    for(vector<Shape*>::const_iterator it = oneComplexShape.children.begin(); it != oneComplexShape.children.end(); it++)
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
} //----- End of ComplexShape


ComplexShape::ComplexShape(string oneName, ShapeType oneType,vector<Shape *> someShapes):
    Shape(oneName,oneType), children()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ComplexShape>" << endl;
#endif

    for(vector<Shape*>::const_iterator it = someShapes.begin(); it != someShapes.end(); it++)
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
} //----- End of ComplexShape


ComplexShape::~ComplexShape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ComplexShape>" << endl;
#endif
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        delete *it;
    }
} //----- End of ~ComplexShape


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
