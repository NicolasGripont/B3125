/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.test;

import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.service.ServiceMetier;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Nico
 */
public class ClotureLivraisonAvecInteraction {
        
    private static final ServiceMetier serviceMetier = new ServiceMetier();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) { 
        //Créer une classe avec une méthode « main »  permettant de tester la clôture d’une livraison avec interaction avec l'utilisateur (saisie de l'id du livreur ou de la livraison)
        List<Commande> commandes = serviceMetier.findAllCommandesNotEnded();
        
        if(commandes == null) {
            System.err.println("Aucune commande a cloturer.");
            return;
        }
        
        String cmd;
        
        do {
            System.out.println("Cloturer une commande par id commande : ic, Cloturer une commande par id livreur : il , lister commande non cloturée : lnc, quitter : q");
            cmd = scanner.nextLine();
            try {
                if(cmd.equals("ic")) {
                    System.out.println("Saisir id commande : ");
                    Long id = Long.parseLong(scanner.nextLine());
                    Commande c = serviceMetier.findCommandeById(id);
                    if(c != null) {
                        c.setDateFin(new Date());
                        serviceMetier.validateCommande(c);
                        Commande v = serviceMetier.findCommandeById(id);
                        System.out.println(v);
                    }
                } else if(cmd.equals("il")) {
                    System.out.println("Saisir id livreur : ");
                    Long id = Long.parseLong(scanner.nextLine());
                    Livreur l = serviceMetier.findLivreurById(id);
                    Commande c = serviceMetier.findNotEndedByLivreur(l);
                    if(c != null) {
                        id = c.getId();
                        c.setDateFin(new Date());
                        serviceMetier.validateCommande(c);
                        Commande v = serviceMetier.findCommandeById(id);
                        System.out.println(v);
                    }
                } else if(cmd.equals("lnc")) {
                    commandes = serviceMetier.findAllCommandesNotEnded();
                    for (Commande commande : commandes) {
                        System.out.println("\tCommande n°" + commande.getId() + " - livreur n°" + commande.getLivreur().getId());
                    }
                }
            } catch (NumberFormatException e)
            {
                
            }
        } while(!cmd.equals("q"));
    }
}
