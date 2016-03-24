/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.vue;

import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.LigneDeCommande;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import fr.insalyon.dasi.gustatif.metier.modele.Produit;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import fr.insalyon.dasi.gustatif.metier.service.ServiceMetier;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Nico
 */
public class IHMConsole {
    
    private static final Scanner scanner = new Scanner(System.in);
    private static ServiceMetier serviceMetier = new ServiceMetier();

    
    public static void main(String[] args) {   
        String cmd;
        Client client = null;
        Livreur livreur = null;
        do {
            System.out.println("Connexion client : c, Connexion livreur: l Inscription : i ou Quitter : q");
            cmd = scanner.nextLine();
            
            if(cmd.equals("c")) {
                client = connexion();
                if(client != null) {
                    vueRestaurants(client);
                }
            } else if(cmd.equals("l")) {
                livreur = connexionLivreur();
                if(livreur != null) {
                    if(livreur instanceof LivreurVelo) {
                        vueLivreurVelo((LivreurVelo)livreur);
                    } else if(livreur instanceof LivreurVelo){
                        List<LivreurDrone> livreurs = serviceMetier.findAllLivreursDrones();
                        vueLivreursDrones(livreurs);
                    }
                }
            } else if(cmd.equals("i")) {
                inscription();
            }     
        } while(!cmd.equals("q"));
    }
    
    
    private static void inscription()
    {
        Client client = new Client();

        System.out.println("Entrez votre nom : ");
        client.setNom(scanner.nextLine());
        System.out.println("Entrez votre prénom : ");
        client.setPrenom(scanner.nextLine());
        System.out.println("Entrez votre mail : ");
        client.setMail(scanner.nextLine());
        System.out.println("Entrez votre mot de passe : ");
        client.setMotDePasse(scanner.nextLine());
        System.out.println("Entrez votre adresse : ");
        client.setAdresse(scanner.nextLine());
        
        serviceMetier.createClient(client);
    }
    
    private static Livreur connexionLivreur()
    {
        String mail;
        String motDePasse;
        
        System.out.println("Entrez votre mail : ");
        mail = scanner.nextLine();
        System.out.println("Entrez votre mot de passe : ");
        motDePasse = scanner.nextLine();

        return serviceMetier.findLivreurByMailAndPassword(mail,motDePasse);
    }
    
        private static Client connexion()
    {
        String mail;
        String motDePasse;
        
        System.out.println("Entrez votre mail : ");
        mail = scanner.nextLine();
        System.out.println("Entrez votre mot de passe : ");
        motDePasse = scanner.nextLine();

        return serviceMetier.findClientByMailAndPassword(mail,motDePasse);
    }
    
    private static void vueRestaurants(Client client)
    {
        List<Restaurant> restaurants = serviceMetier.findAllRestaurants();
        
        String input, numR;
        do {
            System.out.println("Choisir un restaurant : quitter : q");
            input = scanner.nextLine();
            
            if(input.equals("r")) {
                System.out.println("Entrez le numéro du restaurant pour le selectionner :");
                for(int i = 0; i < restaurants.size(); i++) {
                    Restaurant r = restaurants.get(i);
                    System.out.println("\t" + r.getId() + " - " + r.getDenomination());
                }
                numR = scanner.nextLine();
                Restaurant restaurant = serviceMetier.findRestaurantById(new Long(Integer.parseInt(numR)));
                vueRestaurant(restaurant, client);
            }
        } while(!input.equals("q"));
        System.exit(0);
    }
    
    private static void vueRestaurant(Restaurant restaurant, Client client)
    {
        Commande commande = new Commande(restaurant, client);
        List<Produit> produits = restaurant.getProduits();
        System.out.println("Restaurant : " + restaurant.getDenomination());
        System.out.println("Description : " + restaurant.getDescription());
        System.out.println("Adresse : " + restaurant.getAdresse());
        

        String input, p, q;

        do {            
            System.out.println("Récapitulatif commande : prix = " + commande.getPrix() + ", poids = " + commande.getPoids());
            for (LigneDeCommande ligneDeCommande : commande.getLignesDeCommande()) {
                System.out.println("\t " + ligneDeCommande.getProduit().getDenomination() + " : prix unitaire = " + ligneDeCommande.getPrixUnitaire() + " poids unitaire = " + ligneDeCommande.getPoidsUnitaire() + " quantité = " + ligneDeCommande.getQuantite());
            }
            System.out.println("Ajouter un produit : p, valider : v, annuler/retour : a, quitter q");
            
            input = scanner.nextLine();
            
            if(input.equals("p")) {
                System.out.println("Entrez le numéro du produit pour le selectionner :");
                for(int i = 0; i < produits.size(); i++) {
                    Produit produit = produits.get(i);
                    System.out.println("\t" + produit.getId() + " - " + produit.getDenomination());
                } 
                p = scanner.nextLine();
                
                System.out.println("Entrez la quatité :");
                q = scanner.nextLine();
                
                Produit prod = serviceMetier.findProduitById(new Long(Integer.parseInt(p)));
                commande.addLigneDeCommande(prod, Integer.parseInt(q));
                
            } else if (input.equals("a")) {
                return;
            } else if(input.equals("q")) {
                System.exit(0);
            }  
        } while(!input.equals("v"));
        
        //valider : 
        if(commande.getLignesDeCommande().size() > 0) {
            commande.setDateDebut(new Date());
            serviceMetier.createCommande(commande);
        }
        
    }

    private static void vueLivreurVelo(LivreurVelo livreur) {
    }
    
    private static void vueLivreursDrones(List<LivreurDrone> livreurs) {
    }
    
    private static void afficherCommandes(Livreur livreur) {
        
    }
    
    private static void cloturerCommande(Commande commande) {
    }
    
}
