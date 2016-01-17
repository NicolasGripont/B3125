/*************************************************************************
Moveable - Header file of the class <Moveable>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:48:57
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <Moveable> (file Moveable.h)
#if ! defined ( Moveable_H )
#define Moveable_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Moveable>
//
//
//------------------------------------------------------------------------

class Moveable
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Move(int dx, int dy) = 0;
// Manual :
//
// Contract :
//


//------------------------------------------------- Operators overloading 

Moveable & operator = (const Moveable & unMoveable);
// Manual :
//
// Contract :
//


//--------------------------------------------- Constructors - destructor

Moveable(const Moveable & unMoveable);
// Manual : Copy constructor.
//
// Contract : None.
//

Moveable();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~Moveable();
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

//---------------------------- Other definition depend on <Moveable>

#endif // Moveable_H


