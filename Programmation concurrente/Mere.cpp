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
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <signal.h>
//------------------------------------------------------ Include personnel
#include "Mere.h"
#include "Outils.h"
#include "Simulation.h"
#include "Config.h"
#include "Heure.h"
#include "Entree.h"
#include "Sortie.h"

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
    pid_t pid_GestionClavier;
    int statut_GestionClavier;
    pid_t pid_Heure;
    int statut_Heure;
    pid_t pid_EntreeGastonBerger;
    int statut_EntreeGastonBerger;
    pid_t pid_EntreeBlaisePascalProf;
    int statut_EntreeBlaisePascalProf;
    pid_t pid_EntreeBlaisePascalAutre;
    int statut_EntreeBlaisePascalAutre;
    pid_t pid_Sortie;
    int statut_Sortie;

    int msgid_FileDemandeEntree_Prof_BlaisePacal;
    int msgid_FileDemandeEntree_Autre_BlaisePacal;
    int msgid_FileDemandeEntree_GastonBerger;
    int msgid_FileDemandeSortie_GastonBerger;

    int mutex_MemoirePartageeVoitures;
    int shmId_MemoirePartageeVoitures;
    MemoirePartageeVoitures* memoirePartageeVoitures;

    int mutex_Requetes;
    int semSyc_Requetes;
    int shmId_Requetes;
    Voiture* requetes;

    struct sigaction action;

    //creation des ressources
    // /!\ TODO : tester erreur (-1) pour chaque allocation de ressource
    InitialiserApplication(TYPE_TERMINAL);

    //boites aux lettres
    msgid_FileDemandeEntree_Prof_BlaisePacal = msgget(ftok(PARKING_EXE,0),IPC_CREAT | DROITS_BOITE_AU_LETTRE);
    msgid_FileDemandeEntree_Autre_BlaisePacal = msgget(ftok(PARKING_EXE,1),IPC_CREAT | DROITS_BOITE_AU_LETTRE);
    msgid_FileDemandeEntree_GastonBerger = msgget(ftok(PARKING_EXE,2),IPC_CREAT | DROITS_BOITE_AU_LETTRE);
    msgid_FileDemandeSortie_GastonBerger = msgget(ftok(PARKING_EXE,3),IPC_CREAT | DROITS_BOITE_AU_LETTRE);

    //semaphores
    mutex_MemoirePartageeVoitures = semget(ftok(PARKING_EXE,4),1,IPC_CREAT | DROITS_SEMAPHORE);
    semctl(mutex_MemoirePartageeVoitures,0,SETVAL,1);

    mutex_Requetes = semget(ftok(PARKING_EXE,5),1,IPC_CREAT | DROITS_SEMAPHORE);
    semctl(mutex_Requetes,0,SETVAL,1);

    semSyc_Requetes = semget(ftok(PARKING_EXE,6),3,IPC_CREAT | DROITS_SEMAPHORE);
    semctl(semSyc_Requetes,3,SETALL,0);

    //Memoires partagées
    shmId_MemoirePartageeVoitures = shmget(ftok(PARKING_EXE,7),sizeof(MemoirePartageeVoitures), IPC_CREAT | DROITS_MEMOIRE_PARTAGEE);
    memoirePartageeVoitures = (MemoirePartageeVoitures*) shmat(shmId_MemoirePartageeVoitures,NULL,0);

    for(int i=0; i < (int) NB_PLACES ; i++)
    {
        memoirePartageeVoitures->voitures[i] = {TypeUsager::AUCUN,0,0};
    }

    shmId_Requetes = shmget(ftok(PARKING_EXE,8),NB_BARRIERES_ENTREE*sizeof(Voiture), IPC_CREAT | DROITS_MEMOIRE_PARTAGEE);
    requetes = (Voiture*) shmat(shmId_Requetes,NULL,0);
    for(int i=0; i < (int) NB_BARRIERES_ENTREE ; i++)
    {
        requetes[i] = {TypeUsager::AUCUN,0,0};
    }


    //masquage signauc SIGUSR1 et SIGUSR2
    action.sa_handler = SIG_IGN;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);


    if( (pid_GestionClavier = fork()) == 0 )
    {
        //Fils
        GestionClavier(msgid_FileDemandeEntree_Prof_BlaisePacal,msgid_FileDemandeEntree_Autre_BlaisePacal,msgid_FileDemandeEntree_GastonBerger,msgid_FileDemandeSortie_GastonBerger);
    }
    else if( (pid_EntreeBlaisePascalProf = fork()) == 0 )
    {
        Entree(TypeBarriere::PROF_BLAISE_PASCAL,INDICE_ENTREE_BLAISE_PASCALE_PROF,msgid_FileDemandeEntree_Prof_BlaisePacal,mutex_Requetes,semSyc_Requetes,shmId_Requetes,mutex_MemoirePartageeVoitures,shmId_MemoirePartageeVoitures);
    }
    else if( (pid_EntreeBlaisePascalAutre = fork()) == 0 )
    {
        Entree(TypeBarriere::AUTRE_BLAISE_PASCAL,INDICE_ENTREE_BLAISE_PASCALE_AUTRE,msgid_FileDemandeEntree_Autre_BlaisePacal,mutex_Requetes,semSyc_Requetes,shmId_Requetes,mutex_MemoirePartageeVoitures,shmId_MemoirePartageeVoitures);
    }
    else if( (pid_EntreeGastonBerger = fork()) == 0 )
    {
        Entree(TypeBarriere::ENTREE_GASTON_BERGER,INDICE_ENTREE_GASTON_BERGER,msgid_FileDemandeEntree_GastonBerger,mutex_Requetes,semSyc_Requetes,shmId_Requetes,mutex_MemoirePartageeVoitures,shmId_MemoirePartageeVoitures);
    }
    else if( (pid_Sortie = fork()) == 0 )
    {
        Sortie(msgid_FileDemandeSortie_GastonBerger,mutex_Requetes,semSyc_Requetes,shmId_Requetes,mutex_MemoirePartageeVoitures,shmId_MemoirePartageeVoitures);
    }
    else
    {
        pid_Heure = ActiverHeure();

        //Phase Moteur
        waitpid(pid_GestionClavier,&statut_GestionClavier,0);

        //Phase Destruction
        kill(pid_Heure,SIGUSR2);//test valeur retour -1 error
        kill(pid_EntreeBlaisePascalProf,SIGUSR2);//test valeur retour -1 error
        kill(pid_EntreeBlaisePascalAutre,SIGUSR2);//test valeur retour -1 error
        kill(pid_EntreeGastonBerger,SIGUSR2);//test valeur retour -1 error
        kill(pid_Sortie,SIGUSR2);//test valeur retour -1 error

        waitpid(pid_Heure,&statut_Heure,0);
        waitpid(pid_EntreeBlaisePascalProf,&statut_EntreeBlaisePascalProf,0);
        waitpid(pid_EntreeBlaisePascalAutre,&statut_EntreeBlaisePascalAutre,0);
        waitpid(pid_EntreeGastonBerger,&statut_EntreeGastonBerger,0);
        waitpid(pid_Sortie,&statut_Sortie,0);

        //liberation des ressources
        TerminerApplication();
        //boites aux lettres
        msgctl(msgid_FileDemandeEntree_Prof_BlaisePacal,IPC_RMID,0);
        msgctl(msgid_FileDemandeEntree_Autre_BlaisePacal,IPC_RMID,0);
        msgctl(msgid_FileDemandeEntree_GastonBerger,IPC_RMID,0);
        msgctl(msgid_FileDemandeSortie_GastonBerger,IPC_RMID,0);
        //memoires partages
        shmctl(shmId_MemoirePartageeVoitures, IPC_RMID, 0);
        shmctl(shmId_Requetes, IPC_RMID, 0);
        //semaphores
        semctl(mutex_MemoirePartageeVoitures, IPC_RMID, 0);
        semctl(semSyc_Requetes, IPC_RMID, 0);
        semctl(mutex_Requetes, IPC_RMID, 0);
        exit(0);
    }


} //----- fin de main

