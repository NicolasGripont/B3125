/*************************************************************************
                           Simulation  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Simulation par Simulation
e-mail    : nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

*************************************************************************/

//---------- Realisation de la tache <Simulation> (fichier Simulation.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include systeme
#include <stdlib.h>
#include <time.h>
#include <sys/msg.h>
#include <signal.h>

//------------------------------------------------------ Include personnel
#include "Simulation.h"
#include "Menu.h"
#include "Config.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privees
static unsigned int GetNumeroVoiture()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
    static unsigned int numeroVoiture = 0; // variable remanente, initialisée au premier appel

    return (numeroVoiture = (numeroVoiture % 999 + 1));
} //----- fin de GetNumeroVoiture


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

    struct sigaction action;
    action.sa_handler = SIG_IGN ;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0 ;
    sigaction(SIGUSR1,&action,NULL);

    struct sigaction actionFin;
    actionFin.sa_handler = SIG_IGN;
    sigemptyset(&actionFin.sa_mask);
    actionFin.sa_flags = 0 ;
    sigaction(SIGUSR2,&actionFin,NULL);

    for(;;)
    {
        Menu();
    }

} //----- fin de GestionClavier


void Commande(char code, unsigned int valeur)
// Algorithme :
//
{
    MessageDemandeEntree demandeEntree;
    MessageDemandeSortie demandeSortie;

    switch (code) {
    case 'e':
    case 'E':
        exit(0);
        break;
    case 'p':
    case 'P':
        demandeEntree.voiture.arrivee = time(NULL);
        demandeEntree.voiture.numero = GetNumeroVoiture();
        demandeEntree.voiture.typeUsager = TypeUsager::PROF;
        demandeEntree.type = 1;

        switch (valeur) {
        case 1: // Blaise Pascal
            msgsnd(msgid_FileDemandeEntree_Prof_BlaisePacal,&demandeEntree,sizeof(MessageDemandeEntree),0);
            break;
        case 2: // Gaston Berger
            msgsnd(msgid_FileDemandeEntree_GastonBerger,&demandeEntree,sizeof(MessageDemandeEntree),0);
            break;
        default:
            break;
        }
        break;
    case 'a':
    case 'A':
        demandeEntree.voiture.arrivee = time(NULL);
        demandeEntree.voiture.numero = GetNumeroVoiture();
        demandeEntree.voiture.typeUsager = TypeUsager::AUTRE;
        demandeEntree.type = 1;

        switch (valeur) {
        case 1: // Blaise Pascal
            msgsnd(msgid_FileDemandeEntree_Autre_BlaisePacal,&demandeEntree,sizeof(MessageDemandeEntree),0);
            break;
        case 2: // Gaston Berger
            msgsnd(msgid_FileDemandeEntree_GastonBerger,&demandeEntree,sizeof(MessageDemandeEntree),0);
            break;
        default:
            break;
        }
        break;
        break;
    case 's':
    case 'S':
        demandeSortie.numeroPlace = valeur;
        demandeSortie.type = 1;
        msgsnd(msgid_FileDemandeSortie_GastonBerger,&demandeSortie,sizeof(MessageDemandeSortie),0);
        break;
    default:
        break;
    }
} //----- fin de GestionClavier



//file d'attente:
//envoyer msg
//    msgsnd(msgid_FileDemandeEntree_ProfBlaisePacal,&snd,sizeof(MessageDemandeEntree),0);
