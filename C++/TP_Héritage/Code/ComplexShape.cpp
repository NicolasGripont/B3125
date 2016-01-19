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

vector<string> ComplexShape::GetDirectChildrenName()
// Algorithm :
//
{
    vector<string> names;
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        names.push_back((*it)->GetName());
    }
    return names;
} //----- End of GetDirectChildrenName

//------------------------------------------------- Operators overloading

ComplexShape & ComplexShape::operator = (const ComplexShape & oneComplexShape)
// Algorithm :
//
{
    name = oneComplexShape.name;

    for(vector<Shape*>::const_iterator it = oneComplexShape.children.begin(); it != oneComplexShape.children.end(); it++)
    {
        children.push_back((*it)->Clone());
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
        children.push_back((*it)->Clone());
    }
} //----- End of ComplexShape


ComplexShape::ComplexShape(string oneName, vector<Shape *> someShapes):
    Shape(oneName), children()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ComplexShape>" << endl;
#endif
    for(vector<Shape*>::const_iterator it = someShapes.begin(); it != someShapes.end(); it++)
    {
        children.push_back((*it)->Clone());
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
