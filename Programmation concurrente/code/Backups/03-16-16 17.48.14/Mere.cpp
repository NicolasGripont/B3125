/*************************************************************************
                           Mere  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Mere par Mere
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

*************************************************************************/

//---------- Realisation du module <Mere> (fichier Mere.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include systeme
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//------------------------------------------------------ Include personnel
#include "Mere.h"
#include "Outils.h"
#include "Simulation.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privees
//static type nom ( liste de parametres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

int main ( int argc, char** argv)
// Algorithme :
//
{
    pid_t pidGestionClavier;
    int statusGestionClavier;


    InitialiserApplication(TypeTerminal::XTERM);

    if( (pidGestionClavier = fork()) == 0 )
    {
        //Fils
        GestionClavier();
    }
    else
    {
        //Mere
        waitpid(pidGestionClavier,&statusGestionClavier,0);
        TerminerApplication();
        exit(0);
    }


} //----- fin de main

