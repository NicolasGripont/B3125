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
static int mutex_MemoirePartageeRequetes;
static int shmId_MemoirePartageeRequetes;
static int semSyc_MemoirePartageeRequetes;
static MemoirePartageeVoitures* memoirePartageeVoitures;
static MemoirePartageeRequetes* memoirePartageeRequetes;
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

static bool isV1Prio(Voiture v1, Voiture v2);
// Mode d'emploi :
//
// Contrat :
//



static void finVoiturier(int numSignal)
// Algorithme :
//
{
    // PHASE MOTEUR :
    sembuf prendreMutex = {(short unsigned int)0, (short)-1, (short)0};
    sembuf vendreMutex = {(short unsigned int)0, (short)1, (short)0};
    pid_t pid_Voiturier;
    int statut_Voiturier;
    int numeroPlace;
    Voiture voiture;
    int indiceRequete;

    if(numSignal == SIGCHLD)
    {
        pid_Voiturier = wait(&statut_Voiturier);
        numeroPlace = WEXITSTATUS(statut_Voiturier);

        while(semop(mutex_MemoirePartageeVoitures,&prendreMutex,1) == -1 && errno == EINTR);

        voiture = memoirePartageeVoitures->voitures[numeroPlace-1];
        memoirePartageeVoitures->voitures[numeroPlace-1] = {TypeUsager::AUCUN,0,0};
        semop(mutex_MemoirePartageeVoitures,&vendreMutex,1);

        Effacer((TypeZone)numeroPlace);
        AfficherSortie(voiture.typeUsager,voiture.numero,voiture.arrivee,time(NULL));
        voituriers.erase(pid_Voiturier);


        while(semop(mutex_MemoirePartageeRequetes,&prendreMutex,1) == -1 && errno == EINTR);

        if( (indiceRequete = choixRequete()) != -1 )
        {
            memoirePartageeRequetes->requetes[indiceRequete] = {TypeUsager::AUCUN,0,0};
            Effacer((TypeZone)(TypeZone::REQUETE_R1 + indiceRequete));
            sembuf vendreSemSync = {(short unsigned int)indiceRequete, (short)1, (short)0};
            while(semop(semSyc_MemoirePartageeRequetes,&vendreSemSync,1) == -1 && errno == EINTR);
        }
        semop(mutex_MemoirePartageeRequetes,&vendreMutex,1);
    }
} //----- fin de finVoiturier


static void fin(int numSignal)
// Algorithme :
//
{
    // PHASE DESTRUCTION :
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
        shmdt(memoirePartageeRequetes);

        exit(0);
    }
} //----- fin de fin


static bool isV1Prio(Voiture v1, Voiture v2)
{
    if(v1.typeUsager == v2.typeUsager) { return (v1.arrivee <= v2.arrivee); }
    if(v1.typeUsager == TypeUsager::PROF && v2.typeUsager == TypeUsager::AUTRE) { return true; }
    if(v1.typeUsager == TypeUsager::AUTRE && v2.typeUsager == TypeUsager::PROF) { return false; }
    if(v1.typeUsager > v2.typeUsager) { return true; }
//    if(v1.typeUsager < v2.typeUsager) { return false; }
    return false;
}

static int choixRequete()
// Algorithme :
//
{
    Voiture v1 = memoirePartageeRequetes->requetes[INDICE_ENTREE_BLAISE_PASCALE_PROF];
    Voiture v2 = memoirePartageeRequetes->requetes[INDICE_ENTREE_BLAISE_PASCALE_AUTRE];
    Voiture v3 = memoirePartageeRequetes->requetes[INDICE_ENTREE_GASTON_BERGER];

    if(isV1Prio(v1,v2) && isV1Prio(v1,v3) && v1.typeUsager != TypeUsager::AUCUN)
    {
        return 0;
    }
    if(isV1Prio(v2,v1) && isV1Prio(v2,v3) && v2.typeUsager != TypeUsager::AUCUN)
    {
        return 1;
    }
    if(isV1Prio(v3,v2) && isV1Prio(v3,v1) && v3.typeUsager != TypeUsager::AUCUN)
    {
        return 2; 
    }

    return -1;
} //----- fin de choixRequete

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


void Sortie(int msgid_BAL, int mutex_MPR, int semSyc_MPR, int shmId_MPR, int mutex_MPV, int shmId_MPV)
// Algorithme :
//
{
    pid_t pid_Voiturier;
    int msgid_BoiteAuxLettres;
    MessageDemandeSortie demande;

    // PHASE INITIALISATION
    struct sigaction action;
    action.sa_handler = SIG_IGN ;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0 ;
    sigaction(SIGUSR1,&action,NULL);
    sigaction(SIGUSR2,&action,NULL);
    sigaction(SIGCHLD,&action,NULL);

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

    msgid_BoiteAuxLettres = msgid_BAL;
    semSyc_MemoirePartageeRequetes = semSyc_MPR;
    mutex_MemoirePartageeRequetes = mutex_MPR;
    shmId_MemoirePartageeRequetes = shmId_MPR;
    mutex_MemoirePartageeVoitures = mutex_MPV;
    shmId_MemoirePartageeVoitures = shmId_MPV;


    memoirePartageeVoitures = (MemoirePartageeVoitures*) shmat(shmId_MemoirePartageeVoitures,NULL,0);
    memoirePartageeRequetes = (MemoirePartageeRequetes*) shmat(shmId_MemoirePartageeRequetes,NULL,0);

    // PHASE MOTEUR
    for(;;)
    {
        while(msgrcv(msgid_BoiteAuxLettres,&demande,sizeof(MessageDemandeSortie),0,0) == -1 && errno == EINTR); //sans block

        if( (pid_Voiturier = SortirVoiture(demande.numeroPlace)) != -1 )
        {
            voituriers.insert(pid_Voiturier);
        }
    }
} //----- fin de Sortie

