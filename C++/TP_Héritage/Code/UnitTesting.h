/*************************************************************************
UnitTesting - Header file of the class <UnitTesting>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:49:47
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Interface of the class <UnitTesting> (file UnitTesting.h)
#if ! defined ( UnitTesting_H )
#define UnitTesting_H

//-------------------------------------------------------- Used interfaces 

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role of the class <UnitTesting>
// Test Unitaires du programme
//------------------------------------------------------------------------

class UnitTesting 
{
//---------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------- Public methods

static void TestSegmentConstructor();
// Manual :
//
// Contract : None.
//

static void TestSegmentInclude();
// Manual :
//
// Contract : None.
//

static void TestRectangleConstructor();
// Manual :
//
// Contract : None.
//

static void TestRectangleInclude();
// Manual :
//
// Contract : None.
//

static void TestConvexPolygonConstructor();
// Manual :
//
// Contract : None.
//

static void TestConvexPolygonIsValid();
// Manual :
//
// Contract : None.
//

static void TestConvexPolygonInclude();
// Manual :
//
// Contract : None.
//

static void TestReunionConstructor();
// Manual :
//
// Contract : None.
//

static void TestReunionInclude();
// Manual :
//
// Contract : None.
//
//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//static void Test();
//// Manual :
////
//// Contract : None.
////

//------------------------------------------------- Operators overloading 

UnitTesting & operator = (const UnitTesting & unUnitTesting);
// Manual : Overload of = operator.
//
// Contract : None.
//


//---------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------ Protected methods

//--------------------------------------------- Constructors - destructor

UnitTesting(const UnitTesting & oneUnitTesting);
// Manual : Copy constructor.
//
// Contract : None.
//

UnitTesting();
// Manual : Constructor.
//
// Contract : None.
//

virtual ~UnitTesting();
// Manual : Destructor.
//
// Contract : None.
//

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes


private:
//------------------------------------------------------ Pivate attributes

};

//---------------------------- Other definition depend on <UnitTesting>

#endif // UnitTesting_H


