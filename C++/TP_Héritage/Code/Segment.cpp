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
    int dx1 = p.GetX() - points[0].GetX();
    int dx2 = p.GetX() - points[1].GetX();
    int dy1 = p.GetY() - points[0].GetY();
    int dy2 = p.GetY() - points[1].GetY();

    int vProd = dx1 * dy2 - dx2 * dy1;

    int xMax = points[0].MaxX(points[1]);
    int yMax = points[0].MaxY(points[1]);
    int xMin = points[0].MinX(points[1]);
    int yMin = points[0].MinY(points[1]);

    if(vProd == 0 && p.GetX() >= xMin && p.GetX() <= xMax && p.GetY() >= yMin && p.GetY() <= yMax )
    {
        b = true;
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

Segment *Segment::Clone() const
// Algorithm :
//
{
    Segment* clone = new Segment(*this);
    return clone;
} //----- End of Clone


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
