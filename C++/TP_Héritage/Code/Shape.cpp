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

ShapeType Shape::GetType() const
// Algorithm :
//
{
    return type;
} //----- End of GetType

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
    type = unShape.type;
    return *this;
} //----- End of operator =


//--------------------------------------------- Constructors - destructor

Shape::Shape(const Shape & oneShape) :
    name(oneShape.name), type(oneShape.type)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Shape>" << endl;
#endif
} //----- End of Shape


Shape::Shape(string oneName,ShapeType oneType) :
    name(oneName), type(oneType)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Shape>" << endl;
#endif
} //----- End of Shape

Shape::Shape(ShapeType oneType) :
    name(""), type(oneType)
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
