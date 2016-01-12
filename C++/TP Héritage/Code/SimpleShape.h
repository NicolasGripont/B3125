/*************************************************************************
SimpleShape - Header file of the class <SimpleShape>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:49:37
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <SimpleShape> (file SimpleShape.h)
#if ! defined ( SimpleShape_H )
#define SimpleShape_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <SimpleShape>
//
//
//------------------------------------------------------------------------

class SimpleShape : public Ancetre
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

SimpleShape & operator = (const SimpleShape & unSimpleShape);
// Manual :
//
// Contract : 
//


//--------------------------------------------- Constructors - destructor

SimpleShape(const SimpleShape & unSimpleShape);
// Manual : Copy constructor.
//
// Contract : None.
//

SimpleShape();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~SimpleShape();
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

//---------------------------- Other definition depend on <SimpleShape>

#endif // SimpleShape_H


