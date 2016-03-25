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
static int mutex_NbVoituresGarees;
static int shmId_NbVoituresGarees;
static int mutex_Requetes;
static int semSyc_Requetes;
static int shmId_Requetes;
static int* nbVoituresGarees;
static Voiture* requetes;
static map<pid_t,Voiture> voituriers;

void Entree(TypeBarriere type, int msgid_FDE_P_BP, int msgid_FDE_A_BP, int msgid_FDE_GB, int mutex_R, int semSyc_R, int shmId_R, int mutex_NVG, int shmId_NBV)
// Algorithme :
//
{
    pid_t pid_Voiturier;
    TypeBarriere typeBarriere = type;
    msgid_FileDemandeEntree_Prof_BlaisePacal = msgid_FDE_P_BP;
    msgid_FileDemandeEntree_Autre_BlaisePacal = msgid_FDE_A_BP;
    msgid_FileDemandeEntree_GastonBerger = msgid_FDE_GB;
    mutex_NbVoituresGarees = mutex_NVG;
    shmId_NbVoituresGarees = shmId_NBV;
    mutex_Requetes = mutex_R;
    semSyc_Requetes = semSyc_R;
    shmId_Requetes = shmId_R;

    nbVoituresGarees = (int*) shmat(shmId_NbVoituresGarees,NULL,0);
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

        demande.voiture.typeUsager = TypeUsager::AUCUN;
        while(msgrcv(msgid_FileDemandeEntree_Prof_BlaisePacal,&demande,sizeof(MessageDemandeEntree),0,0) == -1); //sans block
            //si egale -1 on reteste car on a peut etre recu signal SIGCHLD (errno == EINTR)
        if( (pid_Voiturier = GarerVoiture(typeBarriere)) != -1 )
        {
            voituriers.insert(make_pair(pid_Voiturier,demande.voiture));
            int status;
            waitpid(pid_Voiturier,&status,0);
        }
        else
        {
            //requete
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
    pid_t pid_Voiturier;
    int statutVoiturier;
    if(numSignal == SIGCHLD) {
        pid_Voiturier = wait(&statutVoiturier);
        //mettre voiture dans place memoire partagé
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

            AfficherSortie((it->second).typeUsager, it->first, time(NULL),time(NULL));
        }
        for(map<pid_t,Voiture>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            waitpid(it->first,NULL,0);
        }

        shmdt(nbVoituresGarees);
        shmdt(requetes);

        exit(0);
    }
} //----- fin de fin

//const char* message = "FIN";
//Afficher(TypeZone::MESSAGE,message);
