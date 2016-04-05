/*************************************************************************
                           Simulation  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) 2016 par Nicolas Gripont
e-mail    :  nicolas.gripont@insa-lyon.fr

*************************************************************************/

//---------- Interface de la tache <Simulation> (fichier Simulation.h) -------
#if ! defined ( SIMULATION_H )
#define SIMULATION_H

//------------------------------------------------------------------------
// Rôle de la tache <Simulation>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


void GestionClavier(int msgid_FDE_P_BP, int msgid_FDE_A_BP, int msgid_FDE_GB, int msgid_FDS_GB);
// Mode d'emploi :
//
// Contrat :
//

void Commande(char code, unsigned int valeur);
// Mode d'emploi :
//
// Contrat :
//


#endif // SIMULATION_H

