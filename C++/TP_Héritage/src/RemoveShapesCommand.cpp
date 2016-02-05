/*************************************************************************
RemoveShapesCommand - Implementation file of the class <RemoveShapesCommand>
--------------------------------------------------------------------------
beginning : 15/01/2016 20:44:14
copyright : (C) 2016 by Nicolas GRIPONT, Rim EL IDRISSI MOKDAD
e-mail    : nicolas.gripont@insa-lyon.fr , rim.el-idrissi-mokdad@insa-lyon.fr
*************************************************************************/

//---------- Implementation of the class <RemoveShapesCommand> (file RemoveShapesCommand.cpp)

//---------------------------------------------------------------- INCLUDE

//---------------------------------------------------------- Sytem include

//------------------------------------------------------ Personnal include
#include "RemoveShapesCommand.h"
#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include "Intersection.h"
#include "Reunion.h"

//-------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public methods

void RemoveShapesCommand::Execute()
// Algorithm :
//
{
    deleted = true;
    unordered_map<string,Shape*>::iterator itm;
    for(vector<Shape*>::iterator it = deletedShapes.begin(); it != deletedShapes.end(); it++)
    {
        itm = shapes->find((*it)->GetName());
        if (itm != shapes->end())
        {
            shapes->erase(itm->second->GetName());
        }
    }
} //----- End of Execute

void RemoveShapesCommand::Undo()
// Algorithm :
//
{
    deleted = false;
    unordered_map<string,Shape*>::iterator itm;
    for(vector<Shape*>::iterator it = deletedShapes.begin(); it != deletedShapes.end(); it++)
    {
        itm = shapes->find((*it)->GetName());
        if (itm == shapes->end())
        {
            shapes->insert(make_pair((*it)->GetName(),*it));
        }
    }
} //----- End of Undo


//------------------------------------------------- Operators overloading

//RemoveShapesCommand & RemoveShapesCommand::operator = (const RemoveShapesCommand & oneRemoveShapesCommand)
//// Algorithm :
////
//{
//} //----- End of operator =


//--------------------------------------------- Constructors - destructor

//RemoveShapesCommand::RemoveShapesCommand(const RemoveShapesCommand & oneRemoveShapesCommand)
//// Algorithm :
////
//{
//#ifdef MAP
//	cout << "Appel au constructeur de copie de <RemoveShapesCommand>" << endl;
//#endif
//} //----- End of RemoveShapesCommand


RemoveShapesCommand::RemoveShapesCommand(unordered_map<string, Shape *> *someShapes, const vector<Shape *> & someDeletedShapes):
    ShapeCommand(someShapes), deletedShapes(someDeletedShapes), deleted(false)
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <RemoveShapesCommand>" << endl;
#endif
} //----- End of RemoveShapesCommand


RemoveShapesCommand::~RemoveShapesCommand()
// Algorithm :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RemoveShapesCommand>" << endl;
#endif
    if(deleted)
    {
        for(vector<Shape*>::iterator it = deletedShapes.begin(); it != deletedShapes.end(); it++)
        {
            delete *it;
        }
    }

} //----- End of ~RemoveShapesCommand


//---------------------------------------------------------------- PRIVATE


//------------------------------------------------------ Protected methods


//-------------------------------------------------------- Private methods

