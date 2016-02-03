/*************************************************************************
ConvexPolygon - Implementation file of the class <ConvexPolygon>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:54:12
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ConvexPolygon> (file ConvexPolygon.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ConvexPolygon.h"

//------------------------------------------------------------------ Types

#if ! defined ( StackPoint )
#define StackPoint
template class std::stack<Point>;
#endif

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool ConvexPolygon::Include(const Point & p) const
// Algorithm :
//
{
    bool result = true;

    int size = points.size();
    int vect = 0, newVect;

    Point a, b;
    int X1, Y1, X2, Y2;

    for( int i = 0; i < size; i++ )
    {
        a = points[i];
        b = points[(i+1)%size];

        X1 = a.GetX() - p.GetX();
        Y1 = a.GetY() - p.GetY();
        X2 = p.GetX() - b.GetX();
        Y2 = p.GetY() - b.GetY();

        newVect = X1 * Y2 - Y1 * X2;

        if(newVect != 0)
        {
            if(vect/newVect < 0)
            {
                result = false;
                break;
            }
            vect = newVect;
        }
    }

    return result;
} //----- End of Include

string ConvexPolygon::ToString() const
// Algorithm :
//
{
    string s;
    for(int i = 0; i < nbTabs; i++)
    {
        s += "\t";
    }
    s += "PC ";
    s += name;
    for(vector<Point>::const_iterator it = points.begin(); it != points.end(); it++)
    {
        s += " ";
        s += to_string((*it).GetX());
        s += " ";
        s += to_string((*it).GetY());
    }

    return s;
} //----- End of ToString


Point ConvexPolygon::pivot(0,0);

bool ConvexPolygon::IsValid() const
// Algorithm :
//
{
    bool result = true;

    int size = points.size();
    int vect = 0, newVect;

    Point a, b, c;
    int X1, Y1, X2, Y2;

    for( int i = 0; i < size; i++ )
    {
        a = points[i];
        b = points[(i+1)%size];
        c = points[(i+2)%size];

        X1 = a.GetX() - b.GetX();
        Y1 = a.GetY() - b.GetY();
        X2 = b.GetX() - c.GetX();
        Y2 = b.GetY() - c.GetY();

        newVect = X1 * Y2 - Y1 * X2;

        if(newVect != 0)
        {
            if(vect/newVect < 0)
            {
                result = false;
                break;
            }
            vect = newVect;
        }
    }

    return result;
} //----- End of IsValid

Shape* ConvexPolygon::Clone() const
// Algorithm :
//
{
    ConvexPolygon* clone = new ConvexPolygon(*this);
    return clone;
} //----- End of Clone

//------------------------------------------------- Operators overloading

ConvexPolygon & ConvexPolygon::operator = (const ConvexPolygon & oneConvexPolygon)
// Algorithm :
//
{
    name = oneConvexPolygon.name;
    points = oneConvexPolygon.points;
    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

ConvexPolygon::ConvexPolygon(const ConvexPolygon & oneConvexPolygon) :
    SimpleShape(oneConvexPolygon)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ConvexPolygon>" << endl;
#endif
} //----- End of ConvexPolygon


ConvexPolygon::ConvexPolygon(const string & oneName, const vector<Point> & somePoints) :
    SimpleShape(oneName,somePoints)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ConvexPolygon>" << endl;
#endif
} //----- End of ConvexPolygon


ConvexPolygon::~ConvexPolygon()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ConvexPolygon>" << endl;
#endif
} //----- End of ~ConvexPolygon


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
