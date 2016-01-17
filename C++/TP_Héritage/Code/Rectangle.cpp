/*************************************************************************
Rectangle - Implementation file of the class <Rectangle>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:56:27
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Rectangle> (file Rectangle.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "Rectangle.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods


bool Rectangle::Include(Point P)
// Algorithm :
//
{
    Point d1=points[0];
    Point d2=points[1];
    int xmax=d1.MaxX(d2);
        int ymax=d1.MaxY(d2);
        int xmin=d1.MinX(d2);
        int ymin=d1.MinY(d2);
    if((xmin<=P.GetX() && P.GetX()<=xmax) && (ymin<=P.GetY() && P.GetY()<=ymax))
    {
        return true;
    }
    return false;// ou pas du tout?
} //----- End of Include

string Rectangle::ToString()
// Algorithm :
//
{
    string s;
    s = "R ";
    s+= name;
    for(vector<Point>::iterator it = points.begin(); it != points.end(); it++)
    {
        s += " ";
        s += to_string((*it).GetX());
        s += " ";
        s += to_string((*it).GetY());
    }
    return s;
} //----- End of ToString

//------------------------------------------------- Operators overloading

Rectangle & Rectangle::operator = (const Rectangle & oneRectangle)
// Algorithm :
//
{
    name = oneRectangle.name;
    type = oneRectangle.type;
    points = oneRectangle.points;
    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Rectangle::Rectangle(const Rectangle & oneRectangle) :
    SimpleShape(oneRectangle)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- End of Rectangle


Rectangle::Rectangle(string oneName, Point p1, Point p2) :
    SimpleShape(oneName,ShapeType::RectangleType)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
    points.push_back(p1);
    points.push_back(p2);
} //----- End of Rectangle


Rectangle::~Rectangle()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- End of ~Rectangle


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
