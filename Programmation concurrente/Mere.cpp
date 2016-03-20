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
//------------------------------------------------------ Include personnel
#include "Mere.h"
#include "Outils.h"
#include "Simulation.h"
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





int main ( int argc, char** argv)
// Algorithme :
//
{
    pid_t pidGestionClavier;
    int statutGestionClavier;
    int msgid_FileDemandeEntree_ProfBlaisePacal;
    int msgid_FileDemandeEntree_AutreBlaisePacal;
    int msgid_FileDemandeEntree_GastonBerger;
    int msgid_FileDemandeSortie_GastonBerger;



    //creation des ressources
    InitialiserApplication(TypeTerminal::XTERM);
    msgid_FileDemandeEntree_ProfBlaisePacal = msgget(ftok(".",0),IPC_CREAT | 0660); // test errno?
    msgid_FileDemandeEntree_AutreBlaisePacal = msgget(ftok(".",1),IPC_CREAT | 0660);
    msgid_FileDemandeEntree_GastonBerger = msgget(ftok(".",2),IPC_CREAT | 0660);
    msgid_FileDemandeSortie_GastonBerger = msgget(ftok(".",2),IPC_CREAT | 0660);

    if( (pidGestionClavier = fork()) == 0 )
    {
        //Fils
        GestionClavier();
    }
    else
    {
        //Mere
        waitpid(pidGestionClavier,&statutGestionClavier,0);

        //liberation des ressources
        TerminerApplication();
        msgctl(msgid_FileDemandeEntree_ProfBlaisePacal,IPC_RMID,0);
        msgctl(msgid_FileDemandeEntree_AutreBlaisePacal,IPC_RMID,0);
        msgctl(msgid_FileDemandeEntree_GastonBerger,IPC_RMID,0);
        msgctl(msgid_FileDemandeSortie_GastonBerger,IPC_RMID,0);

        exit(0);
    }


} //----- fin de main


//file:
//envoyer msg
//    msgsnd(msgid_FileDemandeEntree_ProfBlaisePacal,&snd,sizeof(MessageDemandeEntree),0);

//recevoir msg
//    msgrcv(msgid_FileDemandeEntree_ProfBlaisePacal,&rcv,sizeof(MessageDemandeEntree),0,0);
