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

#define PARKING_EXE  "./Parking" // Fichier utilisé pour créer la clé publique
#define TEMPO 1                  // Temps en seconde pour garer une voiture
#define TYPE_TERMINAL TypeTerminal::XTERM // Terminal utilisé
#define DROITS_BOITE_AU_LETTRE 0660 // Droit d'accès aux boites aux lettres de demandes d'entrée
#define DROITS_MEMOIRE_PARTAGEE 0660 // Droit d'accès aux boites aux lettres de demandes de sortie
#define DROITS_SEMAPHORE 0660 // Droit d'accès aux sémaphores

// Indices des entrée dans le tableau de requete de la mémoire partégée contenant les requetes
#define INDICE_ENTREE_BLAISE_PASCALE_PROF 0
#define INDICE_ENTREE_BLAISE_PASCALE_AUTRE 1
#define INDICE_ENTREE_GASTON_BERGER 2

//------------------------------------------------------------------ Types

// structure permettant de stocker les informations relatives à une voiture
typedef struct voiture {
    TypeUsager typeUsager;
    unsigned int numero;
    time_t arrivee;
} Voiture;


// structure representant un message envoyé dans le boite aux lettres de
// demandes d'entrée
typedef struct messsageDemandeEntree {
    long type;
    Voiture voiture;
} MessageDemandeEntree;

// structure representant un message envoyé dans le boite aux lettres de
// demandes de sortie
typedef struct messsageDemandeSortie {
    long type;
    int numeroPlace;
} MessageDemandeSortie;

// structure de la mémoire partagée stockant les informations relatives
// aux voitures garées dans le parking
typedef struct memoirePartageeVoitures {
    Voiture voitures[NB_PLACES];
} MemoirePartageeVoitures;


//// structure de la mémoire partagée stockant les informations relatives
//// aux requetes d'entrée
typedef struct memoirePartageeRequetes {
    Voiture requetes[NB_BARRIERES_ENTREE];
} MemoirePartageeRequetes;


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

#endif // CONFIG_H

