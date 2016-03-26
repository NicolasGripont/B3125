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
#define TYPE_TERMINAL TypeTerminal::XTERM
#define DROITS_BOITE_AU_LETTRE 0660
#define DROITS_MEMOIRE_PARTAGEE 0660
#define DROITS_SEMAPHORE 0660

#define INDICE_ENTREE_BLAISE_PASCALE_PROF 0
#define INDICE_ENTREE_BLAISE_PASCALE_AUTRE 1
#define INDICE_ENTREE_GASTON_BERGER 2

//------------------------------------------------------------------ Types
typedef struct voiture {
    TypeUsager typeUsager;
    unsigned int numero;
    time_t arrivee;
} Voiture;

typedef struct messsageDemandeEntree {
    long type;
    Voiture voiture;
} MessageDemandeEntree;

typedef struct messsageDemandeSortie {
    long type;
    int numeroPlace;
} MessageDemandeSortie;


typedef struct memoirePartageeVoitures {
    Voiture voitures[NB_PLACES];
} MemoirePartageeVoitures;


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques



#endif // CONFIG_H

