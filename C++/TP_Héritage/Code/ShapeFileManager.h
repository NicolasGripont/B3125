/*************************************************************************
ShapeFileManager - Header file of the class <ShapeFileManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:42:53
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <ShapeFileManager> (file ShapeFileManager.h)
#if ! defined ( ShapeFileManager_H )
#define ShapeFileManager_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <ShapeFileManager>
//
//
//------------------------------------------------------------------------

class ShapeFileManager
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

//ShapeFileManager & operator = (const ShapeFileManager & unShapeFileManager);
//// Manual :
////
//// Contract :
////


//--------------------------------------------- Constructors - destructor

ShapeFileManager(const ShapeFileManager & unShapeFileManager);
// Manual : Copy constructor.
//
// Contract : None.
//

ShapeFileManager();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~ShapeFileManager();
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

//---------------------------- Other definition depend on <ShapeFileManager>

#endif // ShapeFileManager_H


