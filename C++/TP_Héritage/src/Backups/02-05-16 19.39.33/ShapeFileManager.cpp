/*************************************************************************
ShapeFileManager - Implementation file of the class <ShapeFileManager>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:45:34
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <ShapeFileManager> (file ShapeFileManager.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include
#include <iostream>
using namespace std;

//------------------------------------------------------ Personnal include
#include "ShapeFileManager.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Reunion.h"
#include "Intersection.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

int ShapeFileManager::Load(const string & filePath,vector<Shape*> & shapes)
// Algorithm :
//
{
    int result = 0;
    Shape *shape;
    string line;
    deque<string> splittedLine;
    string type;

    ifstream file(filePath,ios::in);
    if(file)
    {
        while(!file.eof())
        {
            getline(file,line);
            splittedLine = SplitLine(line);

            if(splittedLine.size() > 0)
            {
                type = splittedLine[0];
                shape = nullptr;
                if(type == "S")
                {
                    shape = CreateSegment(splittedLine);
                }
                else if(type == "R")
                {
                    shape = CreateRectangle(splittedLine);
                }
                else if(type == "PC")
                {
                    shape = CreateConvexPolygon(splittedLine);
                }
                else if(type == "OI" || type == "OR")
                {
                    shape = CreateComplexShape(file,splittedLine);
                }

                if(shape != nullptr)
                {
                    shapes.push_back(shape);
                }
                else
                {
                    for (vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
                    {
                        delete *it;
                    }
                    shapes.clear();
                    result = 2;
                    break;
                }
            }
        }

        file.close();
    }
    else
    {
        result = 1;
    }
    return result;
} //----- End of Load



int ShapeFileManager::Save(const string & filePath, const unordered_map<string,Shape*> & shapes)
// Algorithm :
//
{
    bool result = 0;

    ofstream file(filePath,ios::out | ios::trunc);
    if(file)
    {
        for(unordered_map<string,Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            file << *(it->second) <<endl;
        }
        file.close();
    }
    else
    {
        result = 1;
    }

    return result;
} //----- End of Save

//------------------------------------------------- Operators overloading

//ShapeFileManager & ShapeFileManager::operator = (const ShapeFileManager & unShapeFileManager)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

ShapeFileManager::ShapeFileManager(const ShapeFileManager & unShapeFileManager)
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ShapeFileManager>" << endl;
#endif
} //----- End of ShapeFileManager


ShapeFileManager::ShapeFileManager()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ShapeFileManager>" << endl;
#endif
} //----- End of ShapeFileManager


ShapeFileManager::~ShapeFileManager()
// Algorithm :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ShapeFileManager>" << endl;
#endif
} //----- End of ~ShapeFileManager


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods

deque<string> ShapeFileManager::SplitLine(string line)
// Algorithm :
//
{
    stringstream ss(line);
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
} //----- End of SplitLine


Shape* ShapeFileManager::CreateComplexShape(ifstream & file, deque<string> params)
// Algorithm :
//
{
    Shape* shape = nullptr;

    string complexType = params[0];
    string name = params[1];
    int nbShapes = 0;
    try
    {
        nbShapes = stoi(params[2]);
    }
    catch ( const std::invalid_argument & )
    {
    }
    vector<Shape*> someShapes;
    Shape * s;

    for(int i = 0; i < nbShapes && !file.eof(); )
    {
        string line;
        getline(file,line);

        deque<string> splittedLine = SplitLine(line);

        if(splittedLine.size() > 0)
        {
            string type = splittedLine[0];

            s = nullptr;
            if(type[type.size()-1] == 'S')
            {
                s = CreateSegment(splittedLine);
            }
            else if(type[type.size()-2] != 'O'&& type[type.size()-1] == 'R')
            {
                s = CreateRectangle(splittedLine);
            }
            else if(type[type.size()-2] == 'P' && type[type.size()-1] == 'C')
            {
                s = CreateConvexPolygon(splittedLine);
            }
            else if(type[type.size()-2] == 'O' && (type[type.size()-1] == 'R' || type[type.size()-1] == 'I'))
            {
                s = CreateComplexShape(file,splittedLine);
            }

            if(s != nullptr)
            {
                someShapes.push_back(s);
            }
            else
            {
                for (vector<Shape*>::iterator it = someShapes.begin(); it != someShapes.end(); it++)
                {
                    delete *it;
                }
                someShapes.clear();
            }
            i++;
        }
    }

    if(someShapes.size() >= 2)
    {
        if(complexType[complexType.size()-2] == 'O' && complexType[complexType.size()-1] == 'I')
        {
            shape = new Intersection(name,someShapes);
        }
        else if(complexType[complexType.size()-2] == 'O' && complexType[complexType.size()-1] == 'R')
        {
            shape = new Reunion(name,someShapes);
        }
    }
    for (vector<Shape*>::iterator it = someShapes.begin(); it != someShapes.end(); it++)
    {
        delete *it;
    }

    return shape;
} //----- End of CreateComplexShape



Shape* ShapeFileManager::CreateSegment(const deque<string> & params)
// Algorithm :
//
{
    Shape* shape = nullptr;

    string name;
    int x1,x2,y1,y2;

    if(params.size() == 6)
    {
        name = params[1];
        try
        {
            x1 = stoi(params[2]);
            y1 = stoi(params[3]);
            x2 = stoi(params[4]);
            y2 = stoi(params[5]);
            shape = new Segment(name,Point(x1,y1),Point(x2,y2));
            if(!shape->IsValid())
            {
                delete shape;
                shape = nullptr;
            }
        }
        catch ( const std::invalid_argument & )
        {
        }
    }
    return shape;
} //----- End of CreateSegment

Shape* ShapeFileManager::CreateRectangle(const deque<string> & params)
// Algorithm :
//
{
    Shape* shape = nullptr;

    string name;
    int x1,x2,y1,y2;

    if(params.size() == 6)
    {
        name = params[1];
        try
        {
            x1 = stoi(params[2]);
            y1 = stoi(params[3]);
            x2 = stoi(params[4]);
            y2 = stoi(params[5]);
            shape = new Rectangle(name,Point(x1,y1),Point(x2,y2));
            if(!shape->IsValid())
            {
                delete shape;
                shape = nullptr;
            }
        }
        catch ( const std::invalid_argument & )
        {
        }
    }
    return shape;
} //----- End of CreateRectangle

Shape* ShapeFileManager::CreateConvexPolygon(const deque<string> & params)
// Algorithm :
//
{
    Shape* shape = nullptr;

    string name;
    int x,y;
    int nbParams = params.size();

    vector<Point> points;

    if((nbParams % 2 == 0) &&  (nbParams >= 8))
    {
        name = params[1];
        try
        {
            for(int i=2; i < nbParams; i+=2)
            {
                x = stoi(params[i]);
                y = stoi(params[i+1]);
                points.push_back(Point(x,y));
            }
            shape = new ConvexPolygon(name,points);
            if(!shape->IsValid())
            {
                delete shape;
                shape = nullptr;
            }
        }
        catch ( const std::invalid_argument & )
        {
        }
    }
    return shape;
} //----- End of CreateConvexPolygon


//-------------------------------------------------------- Private methods
