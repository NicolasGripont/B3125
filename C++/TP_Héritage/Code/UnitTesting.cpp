/*************************************************************************
UnitTesting - Implementation file of the class <UnitTesting>
--------------------------------------------------------------------------
beginning : 12/01/2016 20:52:12
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <UnitTesting> (file UnitTesting.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include

#include <iostream>
using namespace std;

#include "UnitTesting.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"
#include "ShapeManager.h"
#include "AddShapesCommand.h"
#include "RemoveShapesCommand.h"
#include "MoveShapeCommand.h"
#include "ShapeFileManager.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void UnitTesting::TestSegmentConstructor()
// Algorithm :
//
{
    cout << "Begnning of TestSegmentConstructor" << endl;

    Point p1(1,2);
    Point p2(2,4);

    Segment seg1("seg1",p1,p2);
    Segment seg2(seg1);
    Segment *seg3 = seg1.Clone();
    Segment seg4("seg4",p2,p1);

    if(seg1.GetName() != "seg1" ||
            seg1.GetPoints()[0] != p1 ||
            seg1.GetPoints()[1] != p2)
    {
        cout << "Error1 : constructor" << endl;
    }

    if(seg1.GetPoints()[0] != seg2.GetPoints()[0] ||
            seg1.GetPoints()[1] != seg2.GetPoints()[1] ||
            seg1.GetName() != seg2.GetName())
    {
        cout << "Error2 : constructor copy" << endl;
    }

    if(seg1.GetPoints()[0] != seg3->GetPoints()[0] ||
            seg1.GetPoints()[1] != seg3->GetPoints()[1] ||
            seg1.GetName() != seg3->GetName())
    {
        cout << "Error3 : Clone method" << endl;
    }

    if(seg4.GetName() != "seg4" ||
            seg4.GetPoints()[0] != p2 ||
            seg4.GetPoints()[1] != p1)
    {
        cout << "Error1 : constructor" << endl;
    }

    delete seg3;

    cout << "End of TestSegmentConstructor" << endl;
} //----- End of TestSegmentConstructor


void UnitTesting::TestSegmentInclude()
// Algorithm :
//
{
    cout << "Begnning of TestSegmentInclude" << endl;

    Point p1(1,2);
    Point p2(5,4);
    Point p3(3,3);
    Point p4(0,2);
    Point p5;
    Point p6(0,0);

    Segment seg1("seg1",p1,p2);
    Segment seg2("seg2",Point(),Point());
    Segment seg3("seg3",p2,p1);

    if(!seg1.Include(p3))
    {
        cout << "Error1 : Include method" << endl;
    }
    if(!seg1.Include(p1))
    {
        cout << "Error2 : Include method" << endl;
    }
    if(seg1.Include(p4))
    {
        cout << "Error3 : Include method" << endl;
    }
    if(!seg2.Include(p5))
    {
        cout << "Error4 : Include method" << endl;
    }
    if(!seg2.Include(p6))
    {
        cout << "Error5 : Include method" << endl;
    }
    if(seg2.Include(p3))
    {
        cout << "Error6 : Include method" << endl;
    }
    if(!seg3.Include(p3))
    {
        cout << "Error7 : Include method" << endl;
    }
    if(!seg3.Include(p1))
    {
        cout << "Error8 : Include method" << endl;
    }
    if(seg3.Include(p4))
    {
        cout << "Error9 : Include method" << endl;
    }

    cout << "End of TestSegmentInclude" << endl;
} //----- End of TestSegmentInclude

void UnitTesting::TestRectangleConstructor()
// Algorithm :
//
{
    cout << "Begnning of TestRectangleConstructor" << endl;

    Point p1(1,2);
    Point p2(2,4);

    Rectangle rect1("rect1",p1,p2);
    Rectangle rect2(rect1);
    Rectangle *rect3 = rect1.Clone();
    Rectangle rect4("rect4",p2,p1);

    if(rect1.GetName() != "rect1"
            || rect1.GetPoints()[0] != p1
            || rect1.GetPoints()[1] != p2)
    {
        cout << "Error1 : constructor" << endl;
    }

    if(rect1.GetPoints()[0] != rect2.GetPoints()[0] ||
            rect1.GetPoints()[1] != rect2.GetPoints()[1] ||
            rect1.GetName() != rect2.GetName())
    {
        cout << "Error2 : constructor copy" << endl;
    }

    if(rect1.GetPoints()[0] != rect3->GetPoints()[0] ||
            rect1.GetPoints()[1] != rect3->GetPoints()[1] ||
            rect1.GetName() != rect3->GetName())
    {
        cout << "Error3 : Clone method" << endl;
    }
    if(rect4.GetName() != "rect4"
            || rect4.GetPoints()[0] != p2
            || rect4.GetPoints()[1] != p1)
    {
        cout << "Error4 : constructor" << endl;
    }

    delete rect3;

    cout << "End of TestRectangleConstructor" << endl;
} //----- End of TestRectangleConstructor


void UnitTesting::TestRectangleInclude()
// Algorithm :
//
{
    cout << "Begnning of TestRectangleInclude" << endl;

    Point p1(1,2);
    Point p2(5,4);
    Point p3(3,3);
    Point p4(0,2);
    Point p5;
    Point p6(0,0);

    Rectangle rect1("rect1",p1,p2);
    Rectangle rect2("rect4",p2,p1);
    Rectangle rect3("rect3",Point(),Point());


    if(!rect1.Include(p3))
    {
        cout << "Error1 : Include method" << endl;
    }
    if(!rect1.Include(p1))
    {
        cout << "Error2 : Include method" << endl;
    }
    if(rect1.Include(p4))
    {
        cout << "Error3 : Include method" << endl;
    }
    if(!rect2.Include(p3))
    {
        cout << "Error4 : Include method" << endl;
    }
    if(!rect2.Include(p1))
    {
        cout << "Error5 : Include method" << endl;
    }
    if(rect2.Include(p4))
    {
        cout << "Error6 : Include method" << endl;
    }
    if(!rect3.Include(p5))
    {
        cout << "Error7 : Include method" << endl;
    }
    if(!rect3.Include(p6))
    {
        cout << "Error8 : Include method" << endl;
    }
    if(rect3.Include(p4))
    {
        cout << "Error9 : Include method" << endl;
    }


    cout << "End of TestRectangleInclude" << endl;
} //----- End of TestRectangleInclude


void UnitTesting::TestConvexPolygonConstructor()
// Algorithm :
//
{
    cout << "Begnning of TestConvexPolygonConstructor" << endl;

    Point a(0,2);
    Point b(1,4);
    Point c(4,5);
    Point d(6,3);
    Point e(4,0);
    Point f(1,1);

    vector<Point> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    points.push_back(e);
    points.push_back(f);

    ConvexPolygon cp1("cp1",points);
    ConvexPolygon cp2(cp1);
    ConvexPolygon * cp3 = cp1.Clone();

    if(cp1.GetName() != "cp1")
    {
        cout << "Error1 : constructor" << endl;
    }
    for(int i = 0; i < points.size(); i++)
    {
        if(cp1.GetPoints()[i] != points[i])
        {
            cout << "Error2 : constructor" << endl;
        }
    }

    if(cp2.GetName() != cp1.GetName())
    {
        cout << "Error3 : constructor" << endl;
    }
    for(int i = 0; i < points.size(); i++)
    {
        if(cp2.GetPoints()[i] != cp1.GetPoints()[i])
        {
            cout << "Error4 : constructor" << endl;
        }
    }

    if(cp3->GetName() != cp1.GetName())
    {
        cout << "Error5 : constructor" << endl;
    }
    for(int i = 0; i < points.size(); i++)
    {
        if(cp3->GetPoints()[i] != cp1.GetPoints()[i])
        {
            cout << "Error6 : constructor" << endl;
        }
    }
    delete cp3;
    cout << "End of TestConvexPolygonConstructor" << endl;
} //----- End of TestConvexPolygonConstructor


void UnitTesting::TestConvexPolygonIsValid()
// Algorithm :
//
{
    cout << "Begnning of TestConvexPolygonIsValid" << endl;

    Point a(0,2);
    Point b(1,4);
    Point c(4,5);
    Point d(6,3);
    Point e(4,0);
    Point f(1,1);
    Point g(4,3);

    vector<Point> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    points.push_back(e);
    points.push_back(f);

    ConvexPolygon cp1("cp1",points);
    points.push_back(g);
    ConvexPolygon cp2("cp2",points);

    if(!cp1.IsValid())
    {
        cout << "Error1 : IsValid" << endl;
    }

    if(cp2.IsValid())
    {
        cout << "Error2 : IsValid" << endl;
    }

    cout << "End of TestConvexPolygonIsValid" << endl;
} //----- End of TestConvexPolygonIsValid



void UnitTesting::TestConvexPolygonInclude()
// Algorithm :
//
{
    cout << "Begnning of TestConvexPolygonInclude" << endl;

    Point a(0,2);
    Point b(1,4);
    Point c(4,5);
    Point d(6,3);
    Point e(4,0);
    Point f(1,1);
    Point g(4,3);
    Point h(0,0);

    vector<Point> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    points.push_back(e);
    points.push_back(f);

    ConvexPolygon cp1("cp1",points);

    if(!cp1.Include(a))
    {
        cout << "Error1 : Include method" << endl;
    }
    if(!cp1.Include(b))
    {
        cout << "Error2 : Include method" << endl;
    }
    if(!cp1.Include(c))
    {
        cout << "Error3 : Include method" << endl;
    }
    if(!cp1.Include(d))
    {
        cout << "Error4 : Include method" << endl;
    }
    if(!cp1.Include(e))
    {
        cout << "Error5 : Include method" << endl;
    }
    if(!cp1.Include(f))
    {
        cout << "Error6 : Include method" << endl;
    }
    if(!cp1.Include(g))
    {
        cout << "Error7 : Include method" << endl;
    }
    if(cp1.Include(h))
    {
        cout << "Error8 : Include method" << endl;
    }

    cout << "End of TestConvexPolygonInclude" << endl;
} //----- End of TestConvexPolygonInclude


void UnitTesting::TestReunionConstructor()
// Algorithm :
//
{
    cout << "Begnning of TestReunionConstructor" << endl;

//    Point p1(1,2);
//    Point p2(2,4);

//    Point a(0,2);
//    Point b(1,4);
//    Point c(4,5);
//    Point d(6,3);
//    Point e(4,0);
//    Point f(1,1);

//    vector<Point> points;
//    points.push_back(a);
//    points.push_back(b);
//    points.push_back(c);
//    points.push_back(d);
//    points.push_back(e);
//    points.push_back(f);

//    ConvexPolygon cp1("cp1",points);
//    Segment seg1("seg1",p1,p2);
//    Rectangle rect1("rect1", Point(10,8),Point(4,5));

//    Reunion or1("or1",vector<Shape*>());
//    vector<Shape*> shapes;
//    shapes.push_back(cp1);
//    shapes.push_back(seg1);
//    Reunion or2("or2",shapes);

//    vector<Shape*> shapes2;
//    shapes2.push_back(or2);
//    shapes2.push_back(rect1);
//    Reunion or3("or3",shapes2);

//    Reunion or4(or3);

//    if(or1.GetName() != "or1" || or1.GetChildren().size() != 0)
//    {
//        cout << "Error1 : constructor" << endl;
//    }
//    if(or2.GetName() != "or2" || or2.GetChildren().size() == 0)
//    {
//        cout << "Error1 : constructor" << endl;
//    }
//    for(int i = 0; i < or2.GetChildren().size(); i++)
//    {

//    }



    cout << "End of TestReunionConstructor" << endl;
} //----- End of TestReunionConstructor


void UnitTesting::TestReunionInclude()
// Algorithm :
//
{
    cout << "Begnning of TestReunionInclude" << endl;

//    Point p1(1,2);
//    Point p2(5,4);
//    Point p3(3,3);
//    Point p4(0,2);
//    Point p5;
//    Point p6(0,0);

//    Segment seg1("seg1",p1,p2);
//    Segment seg2("seg2",Point(),Point());
//    Segment seg3("seg3",p2,p1);

//    if(!seg1.Include(p3))
//    {
//        cout << "Error1 : Include method" << endl;
//    }
//    if(!seg1.Include(p1))
//    {
//        cout << "Error2 : Include method" << endl;
//    }
//    if(seg1.Include(p4))
//    {
//        cout << "Error3 : Include method" << endl;
//    }
//    if(!seg2.Include(p5))
//    {
//        cout << "Error4 : Include method" << endl;
//    }
//    if(!seg2.Include(p6))
//    {
//        cout << "Error5 : Include method" << endl;
//    }
//    if(seg2.Include(p3))
//    {
//        cout << "Error6 : Include method" << endl;
//    }
//    if(!seg3.Include(p3))
//    {
//        cout << "Error7 : Include method" << endl;
//    }
//    if(!seg3.Include(p1))
//    {
//        cout << "Error8 : Include method" << endl;
//    }
//    if(seg3.Include(p4))
//    {
//        cout << "Error9 : Include method" << endl;
//    }

    cout << "End of TestReunionInclude" << endl;
} //----- End of TestReunionInclude



//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test


//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test


//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//void UnitTesting::Test()
//// Algorithm :
////
//{
//cout << "Begnning of Test" << endl;

//cout << "End of Test" << endl;
//} //----- End of Test

//------------------------------------------------- Operators overloading


//--------------------------------------------- Constructors - destructor

UnitTesting::UnitTesting(const UnitTesting & oneUnitTesting)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <UnitTesting>" << endl;
#endif
} //----- End of UnitTesting


UnitTesting::UnitTesting()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <UnitTesting>" << endl;
#endif
} //----- End of UnitTesting


UnitTesting::~UnitTesting()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <UnitTesting>" << endl;
#endif
} //----- End of ~UnitTesting


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods
