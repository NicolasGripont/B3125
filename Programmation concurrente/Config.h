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

//------------------------------------------------------------- Constantes

#define PARKING_EXE  "./Parking" //Fichier utilisé pour créer la clé publique



//------------------------------------------------------------------ Types

typedef struct messsageDemandeEntree {
    long type = 1;
    TypeUsager typeUsager;
    int numeroVoiture;
} MessageDemandeEntree;



//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques



#endif // CONFIG_H

