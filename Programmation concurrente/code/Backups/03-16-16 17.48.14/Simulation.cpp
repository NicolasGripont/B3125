/*************************************************************************
                           Simulation  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Simulation par Simulation
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

*************************************************************************/

//---------- Realisation de la tache <Simulation> (fichier Simulation.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include systeme
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Simulation.h"
#include "Menu.h"

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


void GestionClavier()
// Algorithme :
//
{
    for(;;)
    {
        Menu();
    }
} //----- fin de GestionClavier

void Commande(char code, unsigned int valeur)
// Algorithme :
//
{
    switch (code) {
    case 'e':
    case 'E':
        exit(0);
        break;
    default:
        //afficher message
        break;
    }
} //----- fin de GestionClavier
