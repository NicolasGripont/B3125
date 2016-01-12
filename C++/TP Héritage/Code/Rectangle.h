/*************************************************************************
Rectangle - Header file of the class <Rectangle>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:50:09
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Rectangle> (file Rectangle.h)
#if ! defined ( Rectangle_H )
#define Rectangle_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Rectangle>
//
//
//------------------------------------------------------------------------

class Rectangle
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

Rectangle & operator = (const Rectangle & unRectangle);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

Rectangle(const Rectangle & unRectangle);
// Manual : Copy constructor.
//
// Contract : None.
//

Rectangle();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Rectangle();
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

//---------------------------- Other definition depend on <Rectangle>

#endif // Rectangle_H


