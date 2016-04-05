/*************************************************************************
                           Sortie  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) 2016 par Nicolas Gripont
e-mail    :  nicolas.gripont@insa-lyon.fr

*************************************************************************/

//---------- Interface de la tache <Sortie> (fichier Sortie.h) -------
#if ! defined ( SORTIE_H )
#define SORTIE_H

//------------------------------------------------------------------------
// Rôle de la tache <Sortie>
// Module permettant de gérer la sortie de voitures du Parking
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


void Sortie(int msgid_BAL, int mutex_MPR, int semSyc_MPR, int shmId_MPR,
            int mutex_MPV, int shmId_MPV);
// Mode d'emploi : Fonction permettant de gérer es sortie du parking
//
// Contrat : les différents paramètres doivent être correctes.
// (les id des IPCs)
//

#endif // SORTIE_H

