#!/bin/bash

backup="Backups" #nom du dossier où on enregistre les backups

if [ ! -e $backup ]; then  #si aucun fichier/dossier nommé $backup existe alors on créer le dossier $backup
	mkdir "$backup"
else 
 	if [ ! -d $backup ]; then #si un fichier $backup existe deja et que se n'est pas un dossier alors erreur
		echo "Erreur: `pwd`/$backup existe déjà et n'est pas un dossier." >&2
		exit 1
 	fi
fi

d=`date +"%m-%d-%y %H.%M.%S"`
dossier="$backup/$d" #Nom du dossier ou on enregistre les fichiers
mkdir "$dossier" # creation de ce dossier

if [ $# -gt 0 ]; then #si on donne des fichiers à sauvegarder en arguments alors on enregistre que ceux-la
	for i in $(seq 1 $#)
	do
		cp ${!i} "$dossier"	
	done
else #sinon on enregistre ceux qui sont dans $fichiers
	fichiers=(*.cpp *.h *.c *.sh ?akefile)
	cp ${fichiers[*]} "$dossier"
fi
