/*************************************************************************
                           Sortie  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Sortie par Sortie
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

*************************************************************************/

//---------- Realisation de la tache <Sortie> (fichier Sortie.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include systeme
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <signal.h>
#include <set>
#include <unistd.h>
#include <time.h>

//------------------------------------------------------ Include personnel
#include "Config.h"
#include "Outils.h"
#include "Sortie.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static int mutex_MemoirePartageeVoitures;
static int shmId_MemoirePartageeVoitures;
static int mutex_Requetes;
static int shmId_Requetes;
static int semSyc_Requetes;
static MemoirePartageeVoitures* memoirePartageeVoitures;
static Voiture* requetes;
static set<pid_t> voituriers;

//------------------------------------------------------ Fonctions privees
static void finVoiturier(int numSignal);
// Mode d'emploi :
//
// Contrat :
//

static void fin(int numSignal);
// Mode d'emploi :
//
// Contrat :
//

static int choixRequete();
// Mode d'emploi :
//
// Contrat :
//

static bool operator > (Voiture v1, Voiture v2);
// Mode d'emploi :
//
// Contrat :
//

static bool operator > (TypeUsager type1, TypeUsager type2);
// Mode d'emploi :
//
// Contrat :
//

static void finVoiturier(int numSignal)
// Algorithme :
//
{
    //moteur
    sembuf prendreMutex = {(short unsigned int)0, (short)-1, (short)0};
    sembuf vendreMutex = {(short unsigned int)0, (short)1, (short)0};
    pid_t pid_Voiturier;
    int statut_Voiturier;
    int numeroPlace;
    int nbVoituresGarees;
    Voiture voiture;
    int indiceRequete;

    if(numSignal == SIGCHLD)
    {
        pid_Voiturier = wait(&statut_Voiturier);
        numeroPlace = WEXITSTATUS(statut_Voiturier);

        while(semop(mutex_MemoirePartageeVoitures,&prendreMutex,1) == -1 && errno == EINTR);

        nbVoituresGarees = memoirePartageeVoitures->nbVoituresGarees--;
        voiture = memoirePartageeVoitures->voitures[numeroPlace-1];
        memoirePartageeVoitures->voitures[numeroPlace-1] = {TypeUsager::AUCUN,0,0};
        semop(mutex_MemoirePartageeVoitures,&vendreMutex,1);

        Effacer((TypeZone)numeroPlace);
        AfficherSortie(voiture.typeUsager,voiture.numero,voiture.arrivee,time(NULL));
        voituriers.erase(pid_Voiturier);

        if(nbVoituresGarees == NB_PLACES)
        {
            while(semop(mutex_Requetes,&prendreMutex,1) == -1 && errno == EINTR);

            if( (indiceRequete = choixRequete()) != -1 )
            {
                requetes[indiceRequete] = {TypeUsager::AUCUN,0,0};
                Effacer((TypeZone)(TypeZone::REQUETE_R1 + indiceRequete));
                sembuf vendreSemSync = {(short unsigned int)indiceRequete, (short)1, (short)0};
                while(semop(semSyc_Requetes,&vendreSemSync,1) == -1 && errno == EINTR);
                Afficher(TypeZone::MESSAGE, indiceRequete);
            }
            semop(mutex_Requetes,&vendreMutex,1);
        }
    }
} //----- fin de finVoiturier


static void fin(int numSignal)
// Algorithme :
//
{
    //destruction
    if(numSignal == SIGUSR2)
    {
        struct sigaction action;
        action.sa_handler = SIG_IGN ;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0 ;
        sigaction(SIGCHLD,&action,NULL);


        for(set<pid_t>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            kill(*it,SIGUSR2);
        }
        for(set<pid_t>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            waitpid(*it,NULL,0);
        }

        shmdt(memoirePartageeVoitures);
        shmdt(requetes);

        exit(0);
    }
} //----- fin de fin

static bool operator > (TypeUsager type1, TypeUsager type2)
// Algorithme :
//
{
    // on veut : PROF > AUTRE > AUCUN
    // propriété enum : AUTRE(2) > PROF(1) > AUCUN (0)
    if(type1 == TypeUsager::PROF && type2 == TypeUsager::AUTRE) { return true; }
    if(type1 == TypeUsager::AUTRE && type2 == TypeUsager::PROF) { return false; }
    return (type1 > type2);
} //----- fin de operator >

static bool operator > (Voiture v1, Voiture v2)
// Algorithme :
//
{
    if(v1.typeUsager > v2.typeUsager) { return true; }
    if(v1.typeUsager < v2.typeUsager) { return false; }
//  if(v1.typeUsager == v2.typeUsager)
    return v1.arrivee < v2.arrivee;
} //----- fin de operator >

static int choixRequete()
// Algorithme :
//
{
    Voiture v1 = requetes[INDICE_ENTREE_BLAISE_PASCALE_PROF];
    Voiture v2 = requetes[INDICE_ENTREE_BLAISE_PASCALE_AUTRE];
    Voiture v3 = requetes[INDICE_ENTREE_GASTON_BERGER];

    if(v1 > v2 && v1 > v3) { return INDICE_ENTREE_BLAISE_PASCALE_PROF; }
    if(v2 > v1 && v2 > v3) { return INDICE_ENTREE_BLAISE_PASCALE_AUTRE; }
    if(v3 > v1 && v3 > v2) { return INDICE_ENTREE_GASTON_BERGER; }

    return -1;//pas de requete
} //----- fin de choixRequete

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques



void Sortie(int msgid_BAL, int mutex_R, int semSyc_R, int shmId_R, int mutex_MPV, int shmId_MPV)
// Algorithme :
//
{
    //initialisation
    pid_t pid_Voiturier;
    int msgid_BoiteAuxLettres = msgid_BAL;
    semSyc_Requetes = semSyc_R;
    mutex_Requetes = mutex_R;
    shmId_Requetes = shmId_R;
    mutex_MemoirePartageeVoitures = mutex_MPV;
    shmId_MemoirePartageeVoitures = shmId_MPV;

    memoirePartageeVoitures = (MemoirePartageeVoitures*) shmat(shmId_MemoirePartageeVoitures,NULL,0);
    requetes = (Voiture*) shmat(shmId_Requetes,NULL,0);

    struct sigaction action;
    action.sa_handler = SIG_IGN ;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0 ;
    sigaction(SIGUSR1,&action,NULL);

    struct sigaction actionFin;
    actionFin.sa_handler = fin;
    sigemptyset(&actionFin.sa_mask);
    actionFin.sa_flags = 0 ;
    sigaction(SIGUSR2,&actionFin,NULL);

    struct sigaction actionFinVoiturier;
    actionFinVoiturier.sa_handler = finVoiturier;
    sigemptyset(&actionFinVoiturier.sa_mask);
    actionFinVoiturier.sa_flags = 0 ;
    sigaction(SIGCHLD,&actionFinVoiturier,NULL);

    MessageDemandeSortie demande;

    //moteur
    for(;;)
    {
        while(msgrcv(msgid_BoiteAuxLettres,&demande,sizeof(MessageDemandeSortie),0,0) == -1 && errno == EINTR); //sans block

        if( (pid_Voiturier = SortirVoiture(demande.numeroPlace)) != -1 )
        {
            voituriers.insert(pid_Voiturier);
        }

        sleep(TEMPO);
    }
} //----- fin de Sortie

