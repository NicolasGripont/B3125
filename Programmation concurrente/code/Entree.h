/*************************************************************************
                           Entree  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) 2016 par Nicolas Gripont
e-mail    :  nicolas.gripont@insa-lyon.fr

*************************************************************************/

//---------- Interface de la tache <Entree> (fichier Entree.h) -------
#if ! defined ( ENTREE_H )
#define ENTREE_H

//------------------------------------------------------------------------
// Rôle de la tache <Entree>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisees
#include "Outils.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


void Entree(TypeBarriere type, int indiceBarriere, int msgid_BAL, int mutex_MPR, int semSyc_MPR, int shmId_MPR, int mutex_MPV, int shmId_MPV);
// Mode d'emploi :
//
// Contrat :
//


#endif // ENTREE_H

