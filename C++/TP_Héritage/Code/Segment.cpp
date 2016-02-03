/*************************************************************************
Segment - Implementation file of the class <Segment>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:57:31
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Segment> (file Segment.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "Segment.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool Segment::Include(const Point & p) const
// Algorithm :
//
{
    bool b = false;
    Point p1 = points[0];
    Point p2 = points[1];
    if( p == p1 || p == p2)
    {
        b = true;
    }
    else
    {
        int xmax = p1.MaxX(p2);
        int ymax = p1.MaxY(p2);
        int xmin = p1.MinX(p2);
        int ymin = p1.MinY(p2);
        if( (xmin <= p.GetX() && p.GetX() <= xmax) && (ymin <= p.GetY() && p.GetY() <= ymax) )
            {
            //linear equation :
            int difx = points[0].GetX()-points[1].GetX();
            if(difx == 0)
            {
                int x = points[0].GetX();
                if(p.GetX() != x)
                {
                    b = false;
                }
                if(p.GetY()<ymin || p.GetY()>ymax)
                {
                    b = false;
                }
                else
                {
                    b = true;
                }
            }
            else
            {
                int yPoint = MatchingY(p);
                if(yPoint == p.GetY())
                {
                    b = true;
                }
            }
         }
    }
    return b;
} //----- End of Include

string Segment::ToString() const
// Algorithm :
//
{
    string s;
    for(int i = 0; i < nbTabs; i++)
    {
        s += "\t";
    }
    s += "S ";
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

Shape* Segment::Clone() const
// Algorithm :
//
{
    Segment* clone = new Segment(*this);
    return clone;
} //----- End of Clone

int Segment::MatchingY(Point p) const
{
    float coef = (points[0].GetY() - points[1].GetY()) / (points[0].GetX() - points[1].GetX());
    float b = points[0].GetY() - coef * points[0].GetX();
    float ypoint = coef * p.GetX() + b;
    return (int)ypoint;
}

//------------------------------------------------- Operators overloading

Segment & Segment::operator = (const Segment & oneSegment)
// Algorithm :
//
{
    name = oneSegment.name;
    points = oneSegment.points;
    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Segment::Segment(const Segment & oneSegment) :
    SimpleShape(oneSegment)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- End of Segment


Segment::Segment(const string & oneName, const Point & p1, const Point & p2) :
    SimpleShape(oneName)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Segment>" << endl;
#endif
    points.push_back(p1);
    points.push_back(p2);
} //----- End of Segment


Segment::~Segment()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Segment>" << endl;
#endif
} //----- End of ~Segment


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
