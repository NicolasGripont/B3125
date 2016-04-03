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

//------------------------------------------------------ Include personnel
#include "Mere.h"
#include "Outils.h"


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
    InitialiserApplication(TypeTerminal::XTERM);

    sleep(10);

    TerminerApplication();

    return 0;
} //----- fin de main

