/*************************************************************************
Shape - Implementation file of the class <Shape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:45:53
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <Shape> (file Shape.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "Shape.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

string Shape::GetName() const
// Algorithm :
//
{
    return name;
} //----- End of GetType

//------------------------------------------------- Operators overloading

Shape & Shape::operator = (const Shape & unShape)
// Algorithm :
//
{
    name = unShape.name;
    return *this;
} //----- End of operator =

ostream & operator << (ostream & os, const Shape & shape)
// Algorithm :
//
{
    os << shape.ToString();
    return os;
} //----- End of operator =

//--------------------------------------------- Constructors - destructor

Shape::Shape(const Shape & oneShape) :
    name(oneShape.name)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Shape>" << endl;
#endif
} //----- End of Shape


Shape::Shape(const string & oneName) :
    name(oneName)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Shape>" << endl;
#endif
} //----- End of Shape

Shape::Shape() :
    name("")
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Shape>" << endl;
#endif
} //----- End of Shape

Shape::~Shape()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Shape>" << endl;
#endif
} //----- End of ~Shape


//---------------------------------------------------------------- PRIVATE

//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
