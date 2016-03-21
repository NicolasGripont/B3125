/*************************************************************************
                           Config  -  description
                             -------------------
debut     : 19/03/16
copyright : (C) Config par Config
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

*************************************************************************/

//---------- Interface de la tache <Config> (fichier Config.h) -------
#if ! defined ( CONFIG_H )
#define CONFIG_H

//------------------------------------------------------------------------
// Rôle de la tache <Config>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisees
#include "Outils.h"

//------------------------------------------------------------- Constantes

#define PARKING_EXE  "./Parking" //Fichier utilisé pour créer la clé publique
#define TEMPO 1                  // Temps en seconde pour garer une voiture


//------------------------------------------------------------------ Types
typedef struct voiture
{
    TypeUsager typeUsager;
    int numeroVoiture;
    time_t arrivee;
} Voiture;

typedef struct messsageDemandeEntree {
    long type = 1;
    Voiture voiture;
} MessageDemandeEntree;

typedef struct messsageDemandeSortie {
    long type = 1;
    int numeroPlace;
} MessageDemandeSortie;

typedef struct memoirePartageeStruct{
    int nbVoituresGarees = 0;
    Voiture requetes[3];
} MemoirePartagee;


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques



#endif // CONFIG_H

