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

bool createSegment(deque<string> params);
bool createRectangle(deque<string> params);
bool createConvexPolygon(deque<string> params);
bool createReunion(deque<string> params);
bool createIntersection(deque<string> params);
bool include(deque<string> params);
bool deleteShapes(deque<string> params);
bool moveShape(deque<string> params);
bool showShapes(deque<string> params);
bool undo(deque<string> params);
bool redo(deque<string> params);
bool load(deque<string> params);
bool save(deque<string> params);
bool clear(deque<string> params);
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
    ShapeManager::GetInstance().DeleteShape("segment");
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

#endif

    string cmdLine;
    string cmd;
    deque<string> splitedCmd;

    getline(cin, cmdLine);
    splitedCmd = splitCommand(cmdLine);


    while ( (splitedCmd.size() == 0) || (splitedCmd.size() > 0 && splitedCmd.front()!="EXIT") )
    {
        if((splitedCmd.size() > 0))
        {
            cmd = splitedCmd.front();
            splitedCmd.pop_front();

            if ( cmd == "S" )
            {
                createSegment(splitedCmd);
            }
            else if ( cmd == "R" )
            {
                createRectangle(splitedCmd);
            }
            else if ( cmd == "PC" )
            {
                createConvexPolygon(splitedCmd);
            }
            else if ( cmd == "OR" )
            {
                createReunion(splitedCmd);
            }
            else if ( cmd == "OI" )
            {
                createIntersection(splitedCmd);
            }
            else if ( cmd == "HIT" )
            {
                include(splitedCmd);
            }
            else if ( cmd == "DELETE" )
            {
                deleteShapes(splitedCmd);
            }
            else if ( cmd == "MOVE" )
            {
                moveShape(splitedCmd);
            }
            else if ( cmd == "LIST" )
            {
                showShapes(splitedCmd);
            }
            else if ( cmd == "UNDO" )
            {
                undo(splitedCmd);
            }
            else if ( cmd == "REDO" )
            {
                redo(splitedCmd);
            }
            else if ( cmd == "LOAD" )
            {
                load(splitedCmd);
            }
            else if ( cmd == "SAVE" )
            {
                save(splitedCmd);
            }
            else if ( cmd == "CLEAR" )
            {
                clear(splitedCmd);
            }
        }
        getline(cin, cmdLine);
        splitedCmd = splitCommand(cmdLine);
    }

    return 0;

}

//for(deque<string>::iterator it = params.begin(); it != params.end(); it++)
//{
//    cout << *it << endl;
//}

bool createSegment(deque<string> params)
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

    return result;
}

bool createRectangle(deque<string> params)
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

    return result;
}

bool createConvexPolygon(deque<string> params)
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

    return result;
}

bool createReunion(deque<string> params)
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

    return result;
}

bool createIntersection(deque<string> params)
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

    return result;
}

bool include(deque<string> params)
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

    return result;
}

bool deleteShapes(deque<string> params)
{
    bool result = false;

    vector<string> names;
    if(params.size() > 0)
    {
        for(deque<string>::iterator it = params.begin(); it != params.end(); it++)
        {
            names.push_back(*it);
        }
        result = ShapeManager::GetInstance().DeleteShape(names);
    }

    return result;
}

bool moveShape(deque<string> params)
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

    return result;
}

bool showShapes(deque<string> params)
{
    bool result = false;

    if(params.size() == 0)
    {
        map<string,Shape*> shapes = ShapeManager::GetInstance().GetShapes();
        for(map<string,Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            cout << ">" <<it->second->ToString() << endl;
        }
    }

    return result;
}

bool undo(deque<string> params) // si parametre apres UNDO -> false, si pas de undo à exec -> true
{
    bool result = false;

    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Undo();
        result = true;
    }

    return result;
}

bool redo(deque<string> params) // idem que undo
{
    bool result = false;

    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Redo();
        result = true;
    }

    return result;
}

bool load(deque<string> params)
{
    bool result = false;

    return result;
}

bool save(deque<string> params)
{
    bool result = false;

    return result;
}

bool clear(deque<string> params)
{
    bool result = false;

    return result;
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
