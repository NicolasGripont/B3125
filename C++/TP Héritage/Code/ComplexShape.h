/*************************************************************************
ComplexShape - Header file of the class <ComplexShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:49:47
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ComplexShape> (file ComplexShape.h)
#if ! defined ( ComplexShape_H )
#define ComplexShape_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <ComplexShape>
//
//
//------------------------------------------------------------------------

class ComplexShape : public Ancetre
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

ComplexShape & operator = (const ComplexShape & unComplexShape);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

ComplexShape(const ComplexShape & unComplexShape);
// Manual : Copy constructor.
//
// Contract : None.
//

ComplexShape();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ComplexShape();
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

//---------------------------- Other definition depend on <ComplexShape>

#endif // ComplexShape_H


