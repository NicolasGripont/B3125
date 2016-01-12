/*************************************************************************
Shape - Header file of the class <Shape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:45:37
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Shape> (file Shape.h)
#if ! defined ( Shape_H )
#define Shape_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Shape>
//
//
//------------------------------------------------------------------------

class Shape
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

// type Method ( parameter liste );
// Manual :
//
// Contract :
//


//------------------------------------------------- Operators overloading 

Shape & operator = (const Shape & unShape);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

Shape(const Shape & unShape);
// Manual : Copy constructor.
//
// Contract : None.
//

Shape();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Shape();
// Manual : Destructor.
//
// Contract : None.
//

//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods


private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Shape>

#endif // Shape_H


