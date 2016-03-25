/*************************************************************************
                           Entree  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Entree par Entree
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

*************************************************************************/

//---------- Realisation de la tache <Entree> (fichier Entree.cpp) ---

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
#include <map>
#include <unistd.h>
#include <time.h>
//------------------------------------------------------ Include personnel
#include "Entree.h"
#include "Config.h"
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

static int msgid_FileDemandeEntree_Prof_BlaisePacal;
static int msgid_FileDemandeEntree_Autre_BlaisePacal;
static int msgid_FileDemandeEntree_GastonBerger;
static int mutex_MemoirePartageeVoitures;
static int shmId_MemoirePartageeVoitures;
static int mutex_Requetes;
static int semSyc_Requetes;
static int shmId_Requetes;
static MemoirePartageeVoitures* memoirePartageeVoitures;
static Voiture* requetes;
static map<pid_t,Voiture> voituriers;

void Entree(TypeBarriere type, int indiceBarriere, int msgid_FDE_P_BP, int msgid_FDE_A_BP, int msgid_FDE_GB, int mutex_R, int semSyc_R, int shmId_R, int mutex_MPV, int shmId_MPV)
// Algorithme :
//
{
    pid_t pid_Voiturier;
    TypeBarriere typeBarriere = type;
    msgid_FileDemandeEntree_Prof_BlaisePacal = msgid_FDE_P_BP;
    msgid_FileDemandeEntree_Autre_BlaisePacal = msgid_FDE_A_BP;
    msgid_FileDemandeEntree_GastonBerger = msgid_FDE_GB;
    mutex_MemoirePartageeVoitures = mutex_MPV;
    shmId_MemoirePartageeVoitures = shmId_MPV;
    mutex_Requetes = mutex_R;
    semSyc_Requetes = semSyc_R;
    shmId_Requetes = shmId_R;


    memoirePartageeVoitures = (MemoirePartageeVoitures*) shmat(shmId_MemoirePartageeVoitures,NULL,0);
    requetes = (Voiture*) shmat(shmId_Requetes,NULL,0);

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

    MessageDemandeEntree demande;

    for(;;)
    {
        while(msgrcv(msgid_FileDemandeEntree_Prof_BlaisePacal,&demande,sizeof(MessageDemandeEntree),0,0) == -1 && errno == EINTR); //sans block

        demande.voiture.arrivee = time(NULL);

        if( (pid_Voiturier = GarerVoiture(typeBarriere)) != -1 )
        {
            voituriers.insert(make_pair(pid_Voiturier,demande.voiture));
        }
        else
        {
            //requete
            sembuf prendre = {(short unsigned int)mutex_Requetes, (short)-1, (short)0};
            sembuf vendre = {(short unsigned int)mutex_Requetes, (short)1, (short)0};
            while(semop(mutex_Requetes,&prendre,1) == -1 && errno == EINTR);
            requetes[indiceBarriere] = demande.voiture;
            semop(mutex_MemoirePartageeVoitures,&vendre,1);
            AfficherRequete (typeBarriere,demande.voiture.typeUsager,demande.voiture.arrivee);
            DessinerVoitureBarriere(typeBarriere,demande.voiture.typeUsager);
        }
        sleep(1);
    }
} //----- fin de Entree


//recevoir msg
//    msgrcv(msgid_FileDemandeEntree_ProfBlaisePacal,&rcv,sizeof(MessageDemandeEntree),0,0);


//REVOIR VISIBILITE PORTEE
void finVoiturier(int numSignal)
// Algorithme :
//
{
    sembuf prendre = {(short unsigned int)mutex_MemoirePartageeVoitures, (short)-1, (short)0};
    sembuf vendre = {(short unsigned int)mutex_MemoirePartageeVoitures, (short)1, (short)0};
    pid_t pid_Voiturier;
    int statut_Voiturier;
    int numeroPlace;
    if(numSignal == SIGCHLD) {
        pid_Voiturier = wait(&statut_Voiturier);//pb sur le wait

        map<pid_t,Voiture>::iterator it = voituriers.find(pid_Voiturier);
        Voiture voiture = it->second;
        voituriers.erase(pid_Voiturier);
        numeroPlace = WEXITSTATUS(statut_Voiturier);
        AfficherPlace(numeroPlace,voiture.typeUsager,voiture.numeroVoiture,voiture.arrivee);

        //mettre voiture dans place memoire partagé
        while(semop(mutex_MemoirePartageeVoitures,&prendre,1) == -1 && errno == EINTR);

        memoirePartageeVoitures->nbVoituresGarees++;
        memoirePartageeVoitures->voitures[numeroPlace-1] = voiture;

        semop(mutex_MemoirePartageeVoitures,&vendre,1);

    }
} //----- fin de finVoiturier

//REVOIR VISIBILITE PORTEE
void fin(int numSignal)
// Algorithme :
//
{
    if(numSignal == SIGUSR2) {
        struct sigaction action;
        action.sa_handler = SIG_IGN ;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0 ;
        sigaction(SIGCHLD,&action,NULL);


        for(map<pid_t,Voiture>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            kill(it->first,SIGUSR2);
        }
        for(map<pid_t,Voiture>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            waitpid(it->first,NULL,0);
        }

        shmdt(memoirePartageeVoitures);
        shmdt(requetes);

        exit(0);
    }
} //----- fin de fin

//const char* message = "FIN";
//Afficher(TypeZone::MESSAGE,message);
