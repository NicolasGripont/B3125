/*************************************************************************
                           Entree  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Entree par Entree
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

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


void Entree(TypeBarriere type, int indiceBarriere, int msgid_FDE_P_BP, int msgid_FDE_A_BP, int msgid_FDE_GB, int mutex_R, int semSyc_R, int shmId_R, int mutex_MPV, int shmId_MPV);
// Mode d'emploi :
//
// Contrat :
//

void finVoiturier(int numSignal);
// Mode d'emploi :
//
// Contrat :
//

void fin(int numSignal);
// Mode d'emploi :
//
// Contrat :
//


#endif // ENTREE_H

