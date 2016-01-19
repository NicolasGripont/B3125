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
using namespace std;

//------------------------------------------------------ Personnal include
#include "ConvexPolygon.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

bool ConvexPolygon::Include(const Point & p) const
// Algorithm :
//
{
//    int i, j=0, k, cpt=0, fmin=points[0].GetX();
//    for(i=1;i<nbrPoints-1; i++)
//    {
//        int min=points[i].MinX(points[i+1]);
//        if (min<fmin){ fmin=min; }
//    }
//    Point outsidePoint(fmin-10, P.GetY());//to be on the horizontal axis.
//    Segment stest(P, outsidePoint, "segmentest");
//    //construction of the polygon's segments
//    vector<Segment> vs;
//    while(j<nbrPoints-1)
//    {
//        Segment seg(points[j],points[j+1],"polygon_segment_n");
//        vs.push_back(seg);
//        j++;
//    }
//    Segment fseg(points[j],points[0],"polygon_last_seg");
//    vs.push_back(fseg);
//    //find out how many intersections we've got
//    for(k=0; k<vs.size(); k++)
//    {
//        if(stest.Intersection(vs[k]))
//        {
//            cpt++;
//        }
//    }
//    if(cpt==1)
//    {
//        return true;
//    }
    return false;
} //----- End of Include

string ConvexPolygon::ToString() const
// Algorithm :
//
{
    string s;
    s = "PC ";
    s+= name;
    for(vector<Point>::const_iterator it = points.begin(); it != points.end(); it++)
    {
        s += " ";
        s += to_string((*it).GetX());
        s += " ";
        s += to_string((*it).GetY());
    }

    return s;
} //----- End of ToString

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
