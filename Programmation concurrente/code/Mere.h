/*************************************************************************
                           Mere  -  Application Parking
                             -------------------
debut     : 16/03/16
copyright : (C) 2016 par Nicolas Gripont
e-mail    :  nicolas.gripont@insa-lyon.fr

*************************************************************************/

//---------- Interface du module <Mere> (fichier Mere.h) ---------
#if ! defined ( MERE_H )
#define MERE_H

//------------------------------------------------------------------------
// Rôle du module <Mere>
// Ce module permet de mettre en place les ressources et de lancer les
// différent processus qui interviennent dans la gestion du parking.
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

int main ();
// Mode d'emploi :
// Fonction main permettant de créer mettre en place les différents
// processus permettant le fonctionnement de l'application Parking
// Contrat :
// Si l'application n'est pas quitter de manière classique (commande e/E
// de simulation), il faut supprimer les IPCs crées (4 boites aux lettres,
// 5 sémaphores et 3 mémoires partagées)
//

#endif // MERE_H

