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

bool Intersection::Include(const Point & p) const
// Algorithm :
//
{
    bool result = true;
    for(vector<Shape*>::const_iterator it = children.begin(); it != children.end(); it++)
    {
        if(!(*it)->Include(p))
        {
            result = false;
            break;
        }
    }
    return result;
} //----- End of Include

string Intersection::ToString() const
// Algorithm :
//
{
    string s;
    for(int i = 0; i < nbTabs; i++)
    {
        s += "\t";
    }
    s += "OI ";
    s += name;
    s += " ";
    s += to_string(children.size());
    nbTabs++;
    for(vector<Shape*>::const_iterator it = children.begin(); it != children.end(); it++)
    {
        s += "\n";
        s += (*it)->ToString();
    }
    nbTabs--;
    return s;
} //----- End of ToString

Shape* Intersection::Clone() const
// Algorithm :
//
{
    Intersection* clone = new Intersection(*this);
    return clone;
} //----- End of Clone

//------------------------------------------------- Operators overloading

Intersection & Intersection::operator = (const Intersection & oneIntersection)
// Algorithm :
//
{
    name = oneIntersection.name;

    for(vector<Shape*>::const_iterator it = oneIntersection.children.begin(); it != oneIntersection.children.end(); it++)
    {
        children.push_back((*it)->Clone());
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


Intersection::Intersection(const string & oneName, const vector<Shape *> & someShapes) :
    ComplexShape(oneName,someShapes)
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
