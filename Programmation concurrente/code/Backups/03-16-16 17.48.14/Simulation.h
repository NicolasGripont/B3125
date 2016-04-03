/*************************************************************************
                           Simulation  -  description
                             -------------------
debut     : 16/03/16
copyright : (C) Simulation par Simulation
e-mail    :  nicolas.gripont@insa-lyon.fr rim.el-idrissi-mokdad@insa-lyon.fr

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


void GestionClavier();
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

