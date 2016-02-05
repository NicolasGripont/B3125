/*************************************************************************
AddShapesCommand - Implementation file of the class <AddShapesCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:14
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <AddShapesCommand> (file AddShapesCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "AddShapesCommand.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Intersection.h"
#include "Reunion.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void AddShapesCommand::Execute()
// Algorithm :
//
{
    created = true;
    for(vector<Shape*>::iterator it = createdShapes.begin(); it != createdShapes.end(); it++)
    {
        shapes->insert(make_pair((*it)->GetName(),*it));
    }
} //----- End of Execute

void AddShapesCommand::Undo()
// Algorithm :
//
{
    created = false;
    unordered_map<string,Shape*>::iterator itm;
    for(vector<Shape*>::iterator it = createdShapes.begin(); it != createdShapes.end(); it++)
    {
        itm = shapes->find((*it)->GetName());
        if (itm != shapes->end())
        {
            shapes->erase(itm->second->GetName());
        }
    }
} //----- End of Undo


//------------------------------------------------- Operators overloading

//AddShapesCommand & AddShapesCommand::operator = (const AddShapesCommand & oneAddShapesCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//AddShapesCommand::AddShapesCommand(const AddShapesCommand & oneAddShapesCommand)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <AddShapesCommand>" << endl;
//#endif
//} //----- End of AddShapesCommand


AddShapesCommand::AddShapesCommand(unordered_map<string, Shape *> *someShapes, const vector<Shape *> & someCreatedShapes):
    ShapeCommand(someShapes), createdShapes(someCreatedShapes), created(true)
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddShapesCommand>" << endl;
#endif
} //----- End of AddShapesCommand


AddShapesCommand::~AddShapesCommand()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DeleteShapesCommand>" << endl;
#endif
    if(!created)
    {
        for(vector<Shape*>::iterator it = createdShapes.begin(); it != createdShapes.end(); it++)
        {
            delete *it;
        }
    }
} //----- End of ~AddShapesCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods

