/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.test;

import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.LigneDeCommande;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import fr.insalyon.dasi.gustatif.metier.service.ServiceMetier;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nico
 */
public class CreationLivraisonSansInteraction {
    private static final ServiceMetier serviceMetier = new ServiceMetier();

    public static void main(String[] args) { 
//        Créer une classe avec une méthode « main » permettant de tester la création d’une nouvelle livraison sans interaction avec l'utilisateur (valeurs des paramètres « en dur » dans le code).
        
        List<Client> clients = serviceMetier.findAllClients();
        if(clients == null) {
            System.err.println("Aucun client dans la base de donnée. Insérez en pour exécuter ce code.");
            return;
        }
        Client client = clients.get(0);
        
        List<Livreur> livreurs = serviceMetier.findAllLivreurs();
        if(livreurs == null) {
            System.err.println("Aucun livreur dans la base de donnée. Insérez en pour exécuter ce code.");
            return;
        }
        List<Restaurant> restaurants = serviceMetier.findAllRestaurants();
        if(restaurants == null) {
            System.err.println("Aucun restaurant dans la base de donnée. Insérez en pour exécuter ce code.");
            return;
        }
        Restaurant restaurant = restaurants.get(0);
        if(restaurant.getProduits().isEmpty()) {
            System.err.println("Aucun produits pour le restaurant (id=" + restaurant.getId() + " dans la base de donnée. Insérez en pour exécuter ce code.");
            return;
        } 
        
        Commande commande = new Commande(restaurant, client);
        
        List<LigneDeCommande> lignesDeCommande = new ArrayList<LigneDeCommande>();
                
        lignesDeCommande.add(new LigneDeCommande(restaurant.getProduits().get(0), new Integer(1)));
        commande.setLignesDeCommande(lignesDeCommande);
        
        livreurs = serviceMetier.findAllLivreursDisponibles();
        boolean result = false;
        for(Livreur l : livreurs) {
            if(l.getChargeMaxEnGrammes() >= commande.getPoidsEnGrammes()) {
                result = true;
            }
        }
        if(!result) {
            System.err.println("Aucun livreur disponible pouvant effectuer cette livraison (poids = " + commande.getPoidsEnGrammes() + "g)dans la base de donnée. Insérez en pour exécuter ce code.");
            return;
        }
        
        serviceMetier.createCommande(commande);
    }
}
