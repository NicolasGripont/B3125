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
#include <sstream>
#include <cstring>
#include <fstream>
#include <deque>
#include <string>
using namespace std;

//------------------------------------------------------ Personnal include

#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"
//#include "MoveShapeCommand.h"
//#include "DeleteShapesCommand.h"
//#include "CreateShapeCommand.h"
#include "ShapeManager.h"

//-------------------------------------------------------------- Constants

//------------------------------------------------------------------ Types

#if ! defined ( DequeString )
#define DequeString
template class std::deque<string>;
#endif

//---------------------------------------------------- Method declarations

void createSegment(const deque<string> & params);
void createRectangle(const deque<string> & params);
void createConvexPolygon(const deque<string> & params);
void createReunion(const deque<string> & params);
void createIntersection(const deque<string> & params);
void include(const deque<string> & params);
void deleteShapes(const deque<string> & params);
void moveShape(const deque<string> & params);
void showShapes(const deque<string> & params);
void undo(const deque<string> & params);
void redo(const deque<string> & params);
void load(const deque<string> & params);
void save(const deque<string> & params);
void clear(const deque<string> & params);
deque<string> splitCommand(string cmd);

//----------------------------------------------------- Method definitions

int main()
{
#ifdef TEST
    Point p1(1,2);
    Point p2(2,4);
    Point p3(3,6);
    Point p4(4,8);
    cout << p1.GetX() << " " << p1.GetY() << endl;
    cout << p2.GetX() << " " << p2.GetY() << endl;
    cout << p3.GetX() << " " << p3.GetY() << endl;
    cout << p4.GetX() << " " << p4.GetY() << endl;

    Segment seg1("seg1",p1,p2);
    Segment seg2(seg1);
    cout << seg1.ToString() << endl;
    cout << seg2.ToString() << endl;
    seg2.Move(2,3);
    cout << seg1.ToString() << endl;
    cout << seg2.ToString() << endl;

    Rectangle rect1("rect1",p3,p4);
    Rectangle rect2(rect1);
    cout << rect1.ToString() << endl;
    cout << rect2.ToString() << endl;
    rect2.Move(2,3);
    cout << rect1.ToString() << endl;
    cout << rect2.ToString() << endl;

    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    ConvexPolygon pc1("pc1",points);
    ConvexPolygon pc2(pc1);
    cout << pc1.ToString() << endl;
    cout << pc2.ToString() << endl;
    pc2.Move(2,3);
    cout << pc1.ToString() << endl;
    cout << pc2.ToString() << endl;

    vector<Shape*> shapes;
    shapes.push_back(&seg1);
    shapes.push_back(&rect1);
    shapes.push_back(&pc1);
    Reunion or1("or1",shapes);
    Reunion or2(or1);
    cout << or1.ToString() << endl;
    cout << or2.ToString() << endl;
    cout << seg1.ToString() << endl;
    cout << rect1.ToString() << endl;
    cout << pc1.ToString() << endl;
    or2.Move(2,3);
    cout << or1.ToString() << endl;
    cout << or2.ToString() << endl;
    cout << seg1.ToString() << endl;
    cout << rect1.ToString() << endl;
    cout << pc1.ToString() << endl;

    ShapeManager::GetInstance().CreateSegment("segment",p1,p2);
    if(ShapeManager::GetInstance().GetShape("segment") != nullptr)
    {
        cout << ShapeManager::GetInstance().GetShape("segment")->ToString() << endl;
    }
    else
    {
        cout << "no shape named 'segment'" << endl;
    }
    ShapeManager::GetInstance().MoveShape("segment",2,3);
    if(ShapeManager::GetInstance().GetShape("segment") != nullptr)
    {
        cout << ShapeManager::GetInstance().GetShape("segment")->ToString() << endl;
    }
    else
    {
        cout << "no shape named 'segment'" << endl;
    }
    ShapeManager::GetInstance().Undo();
    if(ShapeManager::GetInstance().GetShape("segment") != nullptr)
    {
        cout << ShapeManager::GetInstance().GetShape("segment")->ToString() << endl;
    }
    else
    {
        cout << "no shape named 'segment'" << endl;
    }
    vector<string> names;
    names.push_back("segment");
    ShapeManager::GetInstance().DeleteShape(names);
    if(ShapeManager::GetInstance().GetShape("segment") != nullptr)
    {
        cout << ShapeManager::GetInstance().GetShape("segment")->ToString() << endl;
    }
    else
    {
        cout << "no shape named 'segment'" << endl;
    }

    ShapeManager::GetInstance().Undo();

    if(ShapeManager::GetInstance().GetShape("segment") != nullptr)
    {
        cout << ShapeManager::GetInstance().GetShape("segment")->ToString() << endl;
    }
    else
    {
        cout << "no shape named 'segment'" << endl;
    }

//    Point a(0,2);
//    Point b(1,4);
//    Point c(4,5);
//    Point d(6,3);
//    Point e(4,0);
//    Point f(1,1);

//    vector<Point> points2;
//    points2.push_back(a);
//    points2.push_back(b);
//    points2.push_back(c);
//    points2.push_back(d);
//    points2.push_back(e);
//    points2.push_back(f);

//    ConvexPolygon cp("ConvPoly",points2);
//    cout << cp << endl;
//    if(cp.IsValid())
//    {
//        cout << "Valid" << endl;
//    }
//    else
//    {
//        cout << "Invalid" << endl;
//    }
//    if(cp.Include(Point(4,3)))
//    {
//        cout << "Included" << endl;
//    }
//    else
//    {
//        cout << "Not Included" << endl;
//    }

//    if(cp.Include(Point(0,0)))
//    {
//        cout << "Included" << endl;
//    }
//    else
//    {
//        cout << "Not Included" << endl;
//    }

//    Point a(0,2);
//    Point b(1,4);
//    Point c(4,5);
//    Point d(6,3);
//    Point e(4,0);
//    Point f(1,1);
//    Point g(4,3);

//    vector<Point> points2;
//    points2.push_back(a);
//    points2.push_back(b);
//    points2.push_back(c);
//    points2.push_back(d);
//    points2.push_back(e);
//    points2.push_back(f);
//    points2.push_back(g);

//    ConvexPolygon cp("ConvPoly",points2);
//    cout << cp << endl;
//    if(cp.IsValid())
//    {
//        cout << "Valid" << endl;
//    }
//    else
//    {
//        cout << "Invalid" << endl;
//    }



    Point a(1,1);
    Point b(3,4);
    Point c(4,5);
    Point d(6,7);

    vector<Point> points2;
    points2.push_back(a);
    points2.push_back(b);
    points2.push_back(c);
    points2.push_back(d);


    ConvexPolygon cp("ConvPoly",points2);
    cout << cp << endl;
    if(cp.IsValid())
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;

#endif

    string cmdLine;
    string cmd;
    deque<string> splittedCmd;

    getline(cin, cmdLine);
    splittedCmd = splitCommand(cmdLine);


    while ( (splittedCmd.size() == 0) || (splittedCmd.size() > 0 && splittedCmd.front()!="EXIT") )
    {
        if((splittedCmd.size() > 0))
        {
            cmd = splittedCmd.front();
            splittedCmd.pop_front();

            if ( cmd == "S" )
            {
                createSegment(splittedCmd);
            }
            else if ( cmd == "R" )
            {
                createRectangle(splittedCmd);
            }
            else if ( cmd == "PC" )
            {
                createConvexPolygon(splittedCmd);
            }
            else if ( cmd == "OR" )
            {
                createReunion(splittedCmd);
            }
            else if ( cmd == "OI" )
            {
                createIntersection(splittedCmd);
            }
            else if ( cmd == "HIT" )
            {
                include(splittedCmd);
            }
            else if ( cmd == "DELETE" )
            {
                deleteShapes(splittedCmd);
            }
            else if ( cmd == "MOVE" )
            {
                moveShape(splittedCmd);
            }
            else if ( cmd == "LIST" )
            {
                showShapes(splittedCmd);
            }
            else if ( cmd == "UNDO" )
            {
                undo(splittedCmd);
            }
            else if ( cmd == "REDO" )
            {
                redo(splittedCmd);
            }
            else if ( cmd == "LOAD" )
            {
                load(splittedCmd);
            }
            else if ( cmd == "SAVE" )
            {
                save(splittedCmd);
            }
            else if ( cmd == "CLEAR" )
            {
                clear(splittedCmd);
            }
        }
        getline(cin, cmdLine);
        splittedCmd = splitCommand(cmdLine);
    }

    return 0;

}


void createSegment(const deque<string> & params)
{
    bool result = false;

    string name;
    int x1,x2,y1,y2;

    if(params.size() == 5)
    {
        name = params[0];
        try
        {
            x1 = stoi(params[1]);
            y1 = stoi(params[2]);
            x2 = stoi(params[3]);
            y2 = stoi(params[4]);
            result = ShapeManager::GetInstance().CreateSegment(name,Point(x1,y1),Point(x2,y2));
        }
        catch ( const std::invalid_argument & )
        {
        }
    }


}

void createRectangle(const deque<string> & params)
{
    bool result = false;

    string name;
    int x1,x2,y1,y2;

    if(params.size() == 5)
    {
        name = params[0];
        try
        {
            x1 = stoi(params[1]);
            y1 = stoi(params[2]);
            x2 = stoi(params[3]);
            y2 = stoi(params[4]);
            result = ShapeManager::GetInstance().CreateRectangle(name,Point(x1,y1),Point(x2,y2));
        }
        catch ( const std::invalid_argument & )
        {
        }
    }


}

void createConvexPolygon(const deque<string> & params)
{
    bool result = false;

    string name;
    int x,y;
    int nbParams = params.size();

    vector<Point> points;

    if((nbParams % 2 == 1) &&  (nbParams >= 7))
    {
        name = params[0];
        try
        {
            for(int i=1; i< nbParams; i+=2)
            {
                x = stoi(params[i]);
                y = stoi(params[i+1]);
                points.push_back(Point(x,y));
            }
            result = ShapeManager::GetInstance().CreateConvexPolygon(name,points);
        }
        catch ( const std::invalid_argument & )
        {
        }
    }


}

void createReunion(const deque<string> & params)
{
    bool result = false;
    string name;

    vector<string> names;
    int nbParams = params.size();

    if(nbParams >= 3)
    {
        name = params[0];
        for(int i=1; i< nbParams; i++)
        {
            names.push_back(params[i]);
        }
        result = ShapeManager::GetInstance().CreateReunion(name,names);
    }


}

void createIntersection(const deque<string> & params)
{
    bool result = false;
    string name;

    vector<string> names;
    int nbParams = params.size();

    if(nbParams >= 3)
    {
        name = params[0];
        for(int i=1; i< nbParams; i++)
        {
            names.push_back(params[i]);
        }
        result = ShapeManager::GetInstance().CreateIntersection(name,names);
    }


}

void include(const deque<string> & params)
{
    bool result = false;
    string name;
    int x,y;

    if(params.size() == 3)
    {
        name = params[0];
        x = stoi(params[1]);
        y = stoi(params[2]);
        result = ShapeManager::GetInstance().Include(name,Point(x,y));
    }


}

void deleteShapes(const deque<string> & params)
{
    bool result = false;

    vector<string> names;
    if(params.size() > 0)
    {
        for(deque<string>::const_iterator it = params.begin(); it != params.end(); it++)
        {
            names.push_back(*it);
        }
        result = ShapeManager::GetInstance().DeleteShape(names);
    }


}

void moveShape(const deque<string> & params)
{
    bool result = false;
    string name;
    int dx,dy;

    if(params.size() == 3)
    {
        try
        {
            name = params[0];
            dx = stoi(params[1]);
            dy = stoi(params[2]);
            ShapeManager::GetInstance().MoveShape(name,dx,dy);
        }
        catch ( const std::invalid_argument & )
        {
        }
    }


}

void showShapes(const deque<string> & params)
{
    bool result = false;

    if(params.size() == 0)
    {
        const map<string,Shape*> * shapes = &ShapeManager::GetInstance().GetShapes();
        for(map<string,Shape*>::const_iterator it = shapes->begin(); it != shapes->end(); it++)
        {
            cout << *(it->second) << endl;
        }
    }


}

void undo(const deque<string> & params) // si parametre apres UNDO -> false, si pas de undo à exec -> true
{
    bool result = false;

    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Undo();
        result = true;
    }


}

void redo(const deque<string> & params) // idem que undo
{
    bool result = false;

    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Redo();
        result = true;
    }


}

void load(const deque<string> & params)
{
    bool result = false;

    if(params.size() == 1)
    {
        result = ShapeManager::GetInstance().Load(params[0]);
        result = true;
    }


}

void save(const deque<string> & params)
{
    bool result = false;

    if(params.size() == 1)
    {
        result = ShapeManager::GetInstance().Save(params[0]);
        result = true;
    }


}

void clear(const deque<string> & params)
{
    bool result = false;

    if(params.size() == 0)
    {
        result = ShapeManager::GetInstance().Clear();
        result = true;
    }


}

deque<string> splitCommand(string cmd)
{
    stringstream ss(cmd);
    string item;
    deque<string> tokens;
    while (getline(ss, item, ' '))
    {
        tokens.push_back(item);
    }

    return tokens;
}
