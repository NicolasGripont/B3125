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
#include "Config.h"

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

static int msgid_FileDemandeEntree_Prof_BlaisePacal;
static int msgid_FileDemandeEntree_Autre_BlaisePacal;
static int msgid_FileDemandeEntree_GastonBerger;
static int msgid_FileDemandeSortie_GastonBerger;

void GestionClavier(int msgid_FDE_P_BP, int msgid_FDE_A_BP, int msgid_FDE_GB, int msgid_FDS_GB)
// Algorithme :
//
{
    msgid_FileDemandeEntree_Prof_BlaisePacal = msgid_FDE_P_BP;
    msgid_FileDemandeEntree_Autre_BlaisePacal = msgid_FDE_A_BP;
    msgid_FileDemandeEntree_GastonBerger = msgid_FDE_GB;
    msgid_FileDemandeSortie_GastonBerger = msgid_FDS_GB;

    for(;;)
    {
        Menu();
    }

} //----- fin de GestionClavier

int GetNumeroVoiture()
{
    static int numeroVoiture = 0; // variable remanente, initialisée au premier appel

    if(numeroVoiture == 999)
    {
        numeroVoiture = 1;
    }
    else
    {
        numeroVoiture ++;
    }

    return numeroVoiture;
}


void Commande(char code, unsigned int valeur)
// Algorithme :
//
{
    switch (code) {
    case 'e':
    case 'E':
        exit(0);
        break;
    case 'p':
    case 'P':
        switch (valeur) {
        case 1: // Blaise Pascal
            break;
        case 2: // Gaston Berger
            break;
        default:
            break;
        }
        break;
    case 'a':
    case 'A':
        switch (valeur) {
        case 1: // Blaise Pascal
            break;
        case 2: // Gaston Berger
            break;
        default:
            break;
        }
        break;
    case 's':
    case 'S':
        //valeur = numPlace (entre 1 et 8, déjà traité dans Menu())
        break;
    default:
        break;
    }
} //----- fin de GestionClavier



//file d'attente:
//envoyer msg
//    msgsnd(msgid_FileDemandeEntree_ProfBlaisePacal,&snd,sizeof(MessageDemandeEntree),0);

//recevoir msg
//    msgrcv(msgid_FileDemandeEntree_ProfBlaisePacal,&rcv,sizeof(MessageDemandeEntree),0,0);
