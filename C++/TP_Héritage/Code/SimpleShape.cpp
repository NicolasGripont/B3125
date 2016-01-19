/*************************************************************************
SimpleShape - Implementation file of the class <SimpleShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:58:00
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <SimpleShape> (file SimpleShape.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "SimpleShape.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void SimpleShape::Move(int dx, int dy)
// Algorithm :
//
{
    for(vector<Point>::iterator it = points.begin(); it != points.end(); it++)
    {
        it->Move(dx,dy);
    }
} //----- End of Move

vector<Point> SimpleShape::GetPoints()
// Algorithm :
//
{
    return points;
} //----- End of GetPoints

//------------------------------------------------- Operators overloading

SimpleShape & SimpleShape::operator = (const SimpleShape & oneSimpleShape)
// Algorithm :
//
{
    name = oneSimpleShape.name;
    points = oneSimpleShape.points;
    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

SimpleShape::SimpleShape(const SimpleShape & oneSimpleShape) :
    Shape(oneSimpleShape), points(oneSimpleShape.points)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <SimpleShape>" << endl;
#endif
} //----- End of SimpleShape


SimpleShape::SimpleShape(string oneName,vector<Point> somePoints) :
    Shape(oneName), points(somePoints)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <SimpleShape>" << endl;
#endif
} //----- End of SimpleShape

SimpleShape::SimpleShape(string oneName) :
    Shape(oneName), points()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SimpleShape>" << endl;
#endif
} //----- End of SimpleShape


SimpleShape::~SimpleShape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <SimpleShape>" << endl;
#endif
} //----- End of ~SimpleShape


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
