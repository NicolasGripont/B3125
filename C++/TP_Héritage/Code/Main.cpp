/*************************************************************************
					Main INSA1  -  Main file
--------------------------------------------------------------------------
beginning : 12/01/2016 20:44:25
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Personnal include

#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"
#include "MoveShapeCommand.h"
#include "CreateOrDeleteComplexShapeCommand.h"
#include "CreateOrDeleteSimpleShapeCommand.h"
#include "ShapeCommand.h"

//-------------------------------------------------------------- Constants

const int TAILLE = 10;

//---------------------------------------------------- Method declarations




//----------------------------------------------------- Method definitions

int main()
{
//#ifdef TEST
//    Point p1(1,2);
//    Point p2(2,4);
//    Point p3(3,6);
//    Point p4(4,8);
//    cout << p1.GetX() << " " << p1.GetY() << endl;
//    cout << p2.GetX() << " " << p2.GetY() << endl;
//    cout << p3.GetX() << " " << p3.GetY() << endl;
//    cout << p4.GetX() << " " << p4.GetY() << endl;

//    Segment seg1("seg1",p1,p2);
//    Segment seg2(seg1);
//    cout << seg1.ToString() << endl;
//    cout << seg2.ToString() << endl;
//    seg2.Move(2,3);
//    cout << seg1.ToString() << endl;
//    cout << seg2.ToString() << endl;

//    Rectangle rect1("rect1",p3,p4);
//    Rectangle rect2(rect1);
//    cout << rect1.ToString() << endl;
//    cout << rect2.ToString() << endl;
//    rect2.Move(2,3);
//    cout << rect1.ToString() << endl;
//    cout << rect2.ToString() << endl;

//    vector<Point> points;
//    points.push_back(p1);
//    points.push_back(p2);
//    points.push_back(p3);
//    points.push_back(p4);
//    ConvexPolygon pc1("pc1",points);
//    ConvexPolygon pc2(pc1);
//    cout << pc1.ToString() << endl;
//    cout << pc2.ToString() << endl;
//    pc2.Move(2,3);
//    cout << pc1.ToString() << endl;
//    cout << pc2.ToString() << endl;

//    vector<Shape*> shapes;
//    shapes.push_back(&seg1);
//    shapes.push_back(&rect1);
//    shapes.push_back(&pc1);
//    Reunion or1("or1",shapes);
//    Reunion or2(or1);
//    cout << or1.ToString() << endl;
//    cout << or2.ToString() << endl;
//    cout << seg1.ToString() << endl;
//    cout << rect1.ToString() << endl;
//    cout << pc1.ToString() << endl;
//    or2.Move(2,3);
//    cout << or1.ToString() << endl;
//    cout << or2.ToString() << endl;
//    cout << seg1.ToString() << endl;
//    cout << rect1.ToString() << endl;
//    cout << pc1.ToString() << endl;
//#endif
    char tmp[TAILLE];
    scanf("%s",tmp);

    while ( strcmp(tmp,"EXIT") != 0 )
    {
        if ( strcmp(tmp,"S") == 0 )
        {

        }
        else if ( strcmp(tmp,"R") == 0 )
        {

        }
        else if ( strcmp(tmp,"PC") == 0 )
        {

        }
        else if ( strcmp(tmp,"OR") == 0 )
        {

        }
        else if ( strcmp(tmp,"OI") == 0 )
        {

        }
        else if ( strcmp(tmp,"HIT") == 0 )
        {

        }
        else if ( strcmp(tmp,"DELETE") == 0 )
        {

        }
        else if ( strcmp(tmp,"MOVE") == 0 )
        {

        }
        else if ( strcmp(tmp,"LIST") == 0 )
        {

        }
        else if ( strcmp(tmp,"UNDO") == 0 )
        {

        }
        else if ( strcmp(tmp,"REDO") == 0 )
        {

        }
        else if ( strcmp(tmp,"LOAD") == 0 )
        {

        }
        else if ( strcmp(tmp,"SAVE") == 0 )
        {

        }
        else if ( strcmp(tmp,"CLEAR") == 0 )
        {

        }
        scanf("%s",tmp);
    }

    return 0;


}
