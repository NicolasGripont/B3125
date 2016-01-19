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

#include <string>
using namespace std;

#include "Point.h"
#include "Moveable.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <Shape>
//
//
//------------------------------------------------------------------------

class Shape : public Moveable
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

virtual void Move(int dx, int dy) = 0;
// Manual :
//
// Contract :
//

virtual bool Include(Point p) = 0;
// Manual :
//
// Contract :
//

virtual string ToString() = 0;
// Manual :
//
// Contract :
//

virtual Shape* Clone() = 0;
// Manual :
//
// Contract :
//

string GetName() const;
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

Shape(const Shape & oneShape);
// Manual : Copy constructor.
//
// Contract : None.
//

Shape(string oneName);
// Manual : Constructor.
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

string name;

private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <Shape>

#endif // Shape_H


