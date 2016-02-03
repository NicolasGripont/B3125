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
#include <deque>
using namespace std;

//------------------------------------------------------ Personnal include

#include "ShapeManager.h"
#include "UnitTesting.h"

//-------------------------------------------------------------- Constants


//------------------------------------------------------------------ Types


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
inline void showMessage(string result, string message);
deque<string> splitCommand(string cmd);

//----------------------------------------------------- Method definitions

int main()
{
#ifdef TEST

    cout<<endl;
    UnitTesting::TestSegmentConstructor();
    cout<<endl;
    UnitTesting::TestSegmentInclude();
    cout<<endl;
    UnitTesting::TestRectangleConstructor();
    cout<<endl;
    UnitTesting::TestRectangleInclude();
    cout<<endl;
    UnitTesting::TestConvexPolygonConstructor();
    cout<<endl;
    UnitTesting::TestConvexPolygonIsValid();
    cout<<endl;
    UnitTesting::TestConvexPolygonInclude();
    cout<<endl;
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
            else
            {
                showMessage("ERR","Invalid command");
            }
        }
        getline(cin, cmdLine);
        splittedCmd = splitCommand(cmdLine);
    }

    return 0;

}


void createSegment(const deque<string> & params)
{
    int result = 0;

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
            result = 3;
        }
    }
    else
    {
        result = 4;
    }

    switch (result) {
    case 0:
        showMessage("OK","New object : " + params[0]);
        break;
    case 1:
        showMessage("ERR","Figure name \""+params[0]+"\" already used.");
        break;
    case 2:
        showMessage("ERR","Invalid segment");
        break;
    case 3:
        showMessage("ERR","Invalid parameters");
        break;
    case 4:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void createRectangle(const deque<string> & params)
{
    int result = 0;

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
            result = 3;
        }
    }
    else
    {
        result = 4;
    }

    switch (result) {
    case 0:
        showMessage("OK","New object : " + params[0]);
        break;
    case 1:
        showMessage("ERR","Figure name \""+params[0]+"\" already used.");
        break;
    case 2:
        showMessage("ERR","Invalid rectangle");
        break;
    case 3:
        showMessage("ERR","Invalid parameters");
        break;
    case 4:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void createConvexPolygon(const deque<string> & params)
{
    int result = 0;

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
            result = 3;
        }
    }
    else
    {
        result = 4;
    }

    switch (result) {
    case 0:
        showMessage("OK","New object : " + params[0]);
        break;
    case 1:
        showMessage("ERR","Figure name \""+params[0]+"\" already used.");
        break;
    case 2:
        showMessage("ERR","Invalid convex polygon");
        break;
    case 3:
        showMessage("ERR","Invalid parameters");
        break;
    case 4:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void createReunion(const deque<string> & params)
{
    int result = 0;
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
    else
    {
        result = 4;
    }

    switch (result) {
    case 0:
        showMessage("OK","New object : " + params[0]);
        break;
    case 1:
        showMessage("ERR","Figure name \""+params[0]+"\" already used.");
        break;
    case 2:
        showMessage("ERR","Invalid reunion");
        break;
    case 3:
        showMessage("ERR","Some shape names are unknown");
        break;
    case 4:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void createIntersection(const deque<string> & params)
{
    int result = 0;
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
    else
    {
        result = 4;
    }

    switch (result) {
    case 0:
        showMessage("OK","New object : " + params[0]);
        break;
    case 1:
        showMessage("ERR","Figure name \""+params[0]+"\" already used.");
        break;
    case 2:
        showMessage("ERR","Invalid intersection");
        break;
    case 3:
        showMessage("ERR","Some shape names are unknown");
        break;
    case 4:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void include(const deque<string> & params)
{
    int result = 0;
    string name;
    int x,y;

    if(params.size() == 3)
    {
        name = params[0];
        x = stoi(params[1]);
        y = stoi(params[2]);
        result = ShapeManager::GetInstance().Include(name,Point(x,y));
    }
    else
    {
        result = 3;
    }
    switch (result) {
    case 0:
        showMessage("YES","");
        break;
    case 1:
        showMessage("NO","");
        break;
    case 2:
        showMessage("ERR","Figure name \""+params[0]+"\" already used.");
        break;
    case 3:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }

}

void deleteShapes(const deque<string> & params)
{
    int result = 0;

    vector<string> names;
    if(params.size() > 0)
    {
        for(deque<string>::const_iterator it = params.begin(); it != params.end(); it++)
        {
            names.push_back(*it);
        }
        result = ShapeManager::GetInstance().DeleteShape(names);
    }
    else
    {
        result = 2;
    }
    switch (result) {
    case 0:
        showMessage("OK","Figures deleted.");
        break;
    case 1:
        showMessage("ERR","Some shape names are unknown");
        break;
    case 2:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void moveShape(const deque<string> & params)
{
    int result = 0;
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
            result = 2;
        }
    }
    else
    {
        result = 3;
    }
    switch (result) {
    case 0:
        showMessage("OK","Figure \""+params[0]+"\" moved.");
        break;
    case 1:
        showMessage("ERR","Figure name \""+params[0]+"\" unknown.");
        break;
    case 2:
        showMessage("ERR","Invalid parameters");
        break;
    case 3:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }


}

void showShapes(const deque<string> & params)
{
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
    int result = 0;

    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Undo();
    }
    else
    {
        result = 1;
    }
    switch (result) {
    case 0:
        showMessage("OK","");
        break;
    case 1:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void redo(const deque<string> & params) // idem que undo
{
    int result = 0;

    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Redo();
    }
    else
    {
        result = 1;
    }
    switch (result) {
    case 0:
        showMessage("OK","");
        break;
    case 1:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }
}

void load(const deque<string> & params)
{
    int result = 0;

    if(params.size() == 1)
    {
        result = ShapeManager::GetInstance().Load(params[0]);
    }
    else
    {
        result = 4;
    }
    switch (result) {
    case 0:
        showMessage("OK","");
        break;
    case 1:
        showMessage("ERR","File can't be opened");
        break;
    case 2:
        showMessage("ERR","Error in loading");
        break;
    case 3:
        showMessage("ERR","Some shape names already used");
        break;
    case 4:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }

}

void save(const deque<string> & params)
{
    int result = false;

    if(params.size() == 1)
    {
        result = ShapeManager::GetInstance().Save(params[0]);
        result = true;
    }
    else
    {
        result = 2;
    }
    switch (result) {
    case 0:
        showMessage("OK","");
        break;
    case 1:
        showMessage("ERR","File can't be opened");
        break;
    case 2:
        showMessage("ERR","Invalid number of parameters");
        break;
    default:
        break;
    }

}

void clear(const deque<string> & params)
{
    if(params.size() == 0)
    {
        ShapeManager::GetInstance().Clear();
    }
    showMessage("OK","");
}

deque<string> splitCommand(string cmd)
{
    stringstream ss(cmd);
    string item;
    deque<string> tokens;
    while (getline(ss, item, ' '))
    {
        if(item != " " && item != "")
        {
            tokens.push_back(item);
        }
    }

    return tokens;
}

inline void showMessage(string result, string message)
{
    cout << result << endl;
    if(message != "")
    {
        cout << "#" << message << endl;
    }
}

