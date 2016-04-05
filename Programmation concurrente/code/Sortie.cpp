/*************************************************************************
                           Sortie  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) 2016 par Nicolas Gripont
e-mail    :  nicolas.gripont@insa-lyon.fr

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
static set<pid_t> voituriers; // set contenant les pids des voiturierSortie
                              // en cours d'exécution

//------------------------------------------------------ Fonctions privees

static void finVoiturier(int numSignal);
// Mode d'emploi : fonction permettant de gérer la fin d'un processus
// SortieVoiture.
// A connecter au signal SIGCHLD
//
// Contrat : l'accès à la mémoire partagés requêtes et voitures
// doit être possible (memoirePartageeRequetes et memoirePartageeVoitures)
// L'accès aux différents sémaphores doit être possible
// (mutex_MemoirePartageeVoitures,mutex_MemoirePartageeRequetes
// semSyc_MemoirePartageeRequetes)
//

static void fin(int numSignal);
// Mode d'emploi : fonction permettant de Terminer le processus.
// A connecter au signal SIGUSR2
//
// Contrat : l'accès à la mémoire partagés requêtes et voitures
// doit être possible (memoirePartageeRequetes et memoirePartageeVoitures)


static int choixRequete();
// Mode d'emploi : Fonction permettant de choisir la requete d'entrée
// à traiter. Renvoie l'indice de la requete à traiter (dans la
// memoirePartageeRequetes) ou -1 si aucune requete.
//
// Contrat : l'accès à la mémoire partagés requêtes doit être possible
// (memoirePartageeRequetes)

static bool isV1Prio(Voiture v1, Voiture v2);
// Mode d'emploi : Renvoie true si v1 est prioritaire par rapport à v2,
// false sinon.
//
// Contrat : aucun



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
        //recuperation du pid du voiturier terminé
        pid_Voiturier = wait(&statut_Voiturier);
        numeroPlace = WEXITSTATUS(statut_Voiturier);

        //on prend le mutex memoire partagée voitures pour pouvoir y accéder (être seul à y accéder)
        while(semop(mutex_MemoirePartageeVoitures,&prendreMutex,1) == -1 && errno == EINTR);

        //recupération de la voiture sortie
        voiture = memoirePartageeVoitures->voitures[numeroPlace-1];
        //on efface la voiture sortie de la mémoire partagée
        memoirePartageeVoitures->voitures[numeroPlace-1] = {TypeUsager::AUCUN,0,0};
        //on rend l'accès à la mémoire partagée voitures
        semop(mutex_MemoirePartageeVoitures,&vendreMutex,1);

        //on efface les infos de la voiture sortie de la zone etat
        Effacer((TypeZone)numeroPlace);
        //on affiche les informations de la voiture sortie dans la zone sortie
        AfficherSortie(voiture.typeUsager,voiture.numero,voiture.arrivee,time(NULL));
        //on enleve le pid de du voiturierSortie terminé du set
        voituriers.erase(pid_Voiturier);

        //on prend le mutex memoire partagée requetes pour pouvoir y accéder (être seul à y accéder)
        while(semop(mutex_MemoirePartageeRequetes,&prendreMutex,1) == -1 && errno == EINTR);

        //s'il y a une requete a traiter
        if( (indiceRequete = choixRequete()) != -1 )
        {
            //on efface la requete à traiter de la mémoire partagée requetes
            memoirePartageeRequetes->requetes[indiceRequete] = {TypeUsager::AUCUN,0,0};
            //on efface la requete à traiter de la zone requetes
            Effacer((TypeZone)(TypeZone::REQUETE_R1 + indiceRequete));
            //on libere le processus entrée en donnant un jeton au semSync correspondant à la requête
            sembuf vendreSemSync = {(short unsigned int)indiceRequete, (short)1, (short)0};
            while(semop(semSyc_MemoirePartageeRequetes,&vendreSemSync,1) == -1 && errno == EINTR);
        }
        //on rend l'accès à la mémoire partagée requetes
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
        //on masque le signal SIGCHLD pour ne pas être interrompu par la fin
        //d'un voiturierSortie
        struct sigaction action;
        action.sa_handler = SIG_IGN ;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0 ;
        sigaction(SIGCHLD,&action,NULL);

        //on envoie le signal SIGUSR2 a tous les voiturierSortie en cours d'exécution
        for(set<pid_t>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            kill(*it,SIGUSR2);
        }
        //on attend la fin des voiturierSortie à qui on a envoyé SIGUSR2
        for(set<pid_t>::iterator it = voituriers.begin(); it != voituriers.end(); it++)
        {
            waitpid(*it,NULL,0);
        }

        //On se détache des mémoires partagées
        shmdt(memoirePartageeVoitures);
        shmdt(memoirePartageeRequetes);

        //On quitte le processus
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
    //masquage des signaux SIGUSR1, SIGUSR2, SIGCHLD
    struct sigaction action;
    action.sa_handler = SIG_IGN ;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0 ;
    sigaction(SIGUSR1,&action,NULL);
    sigaction(SIGUSR2,&action,NULL);
    sigaction(SIGCHLD,&action,NULL);

    //Positionnement du handler fin sur SIGUSR2
    struct sigaction actionFin;
    actionFin.sa_handler = fin;
    sigemptyset(&actionFin.sa_mask);
    actionFin.sa_flags = 0 ;
    sigaction(SIGUSR2,&actionFin,NULL);

    //Positionnement du handler finVoiturier sur SIGUSR2
    struct sigaction actionFinVoiturier;
    actionFinVoiturier.sa_handler = finVoiturier;
    sigemptyset(&actionFinVoiturier.sa_mask);
    actionFinVoiturier.sa_flags = 0 ;
    sigaction(SIGCHLD,&actionFinVoiturier,NULL);

    //récupération des paramètres
    msgid_BoiteAuxLettres = msgid_BAL;
    semSyc_MemoirePartageeRequetes = semSyc_MPR;
    mutex_MemoirePartageeRequetes = mutex_MPR;
    shmId_MemoirePartageeRequetes = shmId_MPR;
    mutex_MemoirePartageeVoitures = mutex_MPV;
    shmId_MemoirePartageeVoitures = shmId_MPV;

    //Attachement des mémoires partagées
    memoirePartageeVoitures = (MemoirePartageeVoitures*) shmat(shmId_MemoirePartageeVoitures,NULL,0);
    memoirePartageeRequetes = (MemoirePartageeRequetes*) shmat(shmId_MemoirePartageeRequetes,NULL,0);

    // PHASE MOTEUR
    for(;;)
    {
        //lecture de messages dans la boite aux lettres
        while(msgrcv(msgid_BoiteAuxLettres,&demande,sizeof(MessageDemandeSortie),0,0) == -1 && errno == EINTR); //sans block

        // si la création d'un voiturierSortie a fonctionnée
        if( (pid_Voiturier = SortirVoiture(demande.numeroPlace)) != -1 )
        {
            // ajout du pid au set
            voituriers.insert(pid_Voiturier);
        }
    }
} //----- fin de Sortie

