/*************************************************************************
Reunion - Implementation file of the class <Reunion>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:56:58
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Reunion> (file Reunion.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include

#include "Reunion.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool Reunion::Include(Point p)
// Algorithm :
//
{
    bool result = false;
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        if((*it)->Include(p))
        {
            result = true;
            break;
        }
    }
    return result;
} //----- End of Include

string Reunion::ToString()
// Algorithm :
//
{
    string s;
    s = "OR ";
    s += name;
    for(vector<Shape*>::iterator it = children.begin(); it != children.end(); it++)
    {
        s += "\n  ";
        s += (*it)->ToString();
    }
    return s;
} //----- End of ToString

Shape* Reunion::Clone()
// Algorithm :
//
{
    Reunion* clone = new Reunion(*this);
    return clone;
} //----- End of Clone

//------------------------------------------------- Operators overloading

Reunion & Reunion::operator = (const Reunion & oneReunion)
// Algorithm :
//
{
    name = oneReunion.name;

    for(vector<Shape*>::const_iterator it = oneReunion.children.begin(); it != oneReunion.children.end(); it++)
    {
        children.push_back((*it)->Clone());
    }

    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Reunion::Reunion(const Reunion & oneReunion) :
    ComplexShape(oneReunion)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Reunion>" << endl;
#endif
} //----- End of Reunion


Reunion::Reunion(string oneName, vector<Shape *> someShapes) :
    ComplexShape(oneName,someShapes)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Reunion>" << endl;
#endif
} //----- End of Reunion


Reunion::~Reunion()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Reunion>" << endl;
#endif
} //----- End of ~Reunion


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
