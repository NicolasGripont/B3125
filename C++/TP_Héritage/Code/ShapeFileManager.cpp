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
using namespace std;
//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

vector<Shape*> ShapeFileManager::Load(const string & filePath)
{
    vector<Shape*> shapes;
    string line;
    deque<string> splittedLine;
    string type;

    ifstream file(filePath,ios::in);
    if(file)
    {
        int nbShapes;
        file >> nbShapes;
        getline(file,line);
        for(int i = 0; i < nbShapes; i++)
        {
            getline(file,line);
            splittedLine = SplitLine(line);
            type = splittedLine[0];

            if(type == "S")
            {
                shapes.push_back(CreateSegment(splittedLine));
            }
            else if(type == "R")
            {
                shapes.push_back(CreateRectangle(splittedLine));
            }
            else if(type == "PC")
            {
                shapes.push_back(CreateConvexPolygon(splittedLine));
            }
            else if(type == "OI" || type == "OR")
            {
                shapes.push_back(CreateComplexShape(file,splittedLine));
            }
        }
        file.close();
    }

    return shapes;
} //----- End of Load

deque<string> ShapeFileManager::SplitLine(string line)
{
    stringstream ss(line);
    string item;
    deque<string> tokens;
    while (getline(ss, item, ' '))
    {
        tokens.push_back(item);
    }

    return tokens;
} //----- End of SplitLine


Shape* ShapeFileManager::CreateComplexShape(ifstream & file, deque<string> params)
{
    Shape* shape = nullptr;

    string complexType = params[0];
    string name = params[1];
    int nbShapes = stoi(params[2]);
    vector<Shape*> someShapes;

    for(int i = 0; i < nbShapes; i++)
    {
        string line;
        getline(file,line);

        deque<string> splittedLine = SplitLine(line);
        string type = splittedLine[0];

        if(type.back() == 'S')
        {
            someShapes.push_back(CreateSegment(splittedLine));
        }
        else if(type.back() == 'R')
        {
            someShapes.push_back(CreateRectangle(splittedLine));
        }
        else if(type[type.size()-2] == 'C' && type[type.size()-1] == 'C')
        {
            someShapes.push_back(CreateConvexPolygon(splittedLine));
        }
        else if(type[type.size()-2] == 'O' && (type[type.size()-1] == 'R' || type[type.size()-1] == 'I'))
        {
            someShapes.push_back(CreateComplexShape(file,splittedLine));
        }
    }

    if(complexType[complexType.size()-2] == 'O' && complexType[complexType.size()-1] == 'I')
    {
        shape = new Intersection(name,someShapes);
    }
    else if(complexType[complexType.size()-2] == 'O' && complexType[complexType.size()-1] == 'R')
    {
        shape = new Reunion(name,someShapes);
    }

    return shape;
} //----- End of CreateComplexShape



Shape* ShapeFileManager::CreateSegment(const deque<string> & params)
{
    string name;
    int x1,x2,y1,y2;

    name = params[1];

    x1 = stoi(params[2]);
    y1 = stoi(params[3]);
    x2 = stoi(params[4]);
    y2 = stoi(params[5]);

    return new Segment(name,Point(x1,y1),Point(x2,y2));
}

Shape* ShapeFileManager::CreateRectangle(const deque<string> & params)
{
    string name;
    int x1,x2,y1,y2;

    name = params[1];

    x1 = stoi(params[2]);
    y1 = stoi(params[3]);
    x2 = stoi(params[4]);
    y2 = stoi(params[5]);

    return new Rectangle(name,Point(x1,y1),Point(x2,y2));
}

Shape* ShapeFileManager::CreateConvexPolygon(const deque<string> & params)
{
    string name;
    int x,y;
    int nbParams = params.size();

    vector<Point> points;

    name = params[1];
    for(int i=2; i < nbParams; i+=2)
    {
        x = stoi(params[i]);
        y = stoi(params[i+1]);
        points.push_back(Point(x,y));
    }


    return new ConvexPolygon(name,points);
}

bool ShapeFileManager::Save(const string & filePath, const map<string,Shape*> & shapes)
{
    bool result = false;

    ofstream file(filePath,ios::out | ios::trunc);
    if(file)
    {
        file << shapes.size();
        file << "\n";
        for(map<string,Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            file << *(it->second) <<endl;
        }
        file.close();
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


//-------------------------------------------------------- Private methods
