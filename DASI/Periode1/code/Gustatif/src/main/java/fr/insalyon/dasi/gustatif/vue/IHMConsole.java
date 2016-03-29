/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.vue;

import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.LigneDeCommande;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import fr.insalyon.dasi.gustatif.metier.modele.Produit;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import fr.insalyon.dasi.gustatif.metier.service.ServiceMetier;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Nico
 */
public class IHMConsole {
    
    private static final Scanner scanner = new Scanner(System.in);
    private static final ServiceMetier serviceMetier = new ServiceMetier();

    
    public static void main(String[] args) {   
        String cmd;
        Client client = null;
        LivreurVelo livreur = null;
        do {
            System.out.println("Connexion client : c, Connexion livreur velo : l, Gestionionnaire drones : d, Inscription : i ou Quitter : q");
            cmd = scanner.nextLine();
            
            if(cmd.equals("c")) {
                client = connexion();
                if(client != null) {
                    vueRestaurants(client);
                }
            } else if(cmd.equals("l")) {
                livreur = connexionLivreurVelo();
                if(livreur != null) {
                    vueLivreurVelo(livreur);
                }
            } else if(cmd.equals("i")) {
                inscription();
            } else if(cmd.equals("d")) {
                List<LivreurDrone> drones = serviceMetier.findAllLivreursDrones();
                if(!drones.isEmpty()) {
                    vueLivreursDrones(drones);
                }
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
        client.setMotDePasse(null);
        System.out.println("Entrez votre adresse : ");
        client.setAdresse(scanner.nextLine());
        System.out.println("Entrez votre numéro de téléphone : ");
        client.setTelephone(scanner.nextLine());
        
        serviceMetier.createClient(client);
    }
    
    private static LivreurVelo connexionLivreurVelo()
    {
        String mail;
        String motDePasse;
        
        System.out.println("Entrez votre mail : ");
        mail = scanner.nextLine();
        System.out.println("Entrez votre mot de passe : ");
        motDePasse = scanner.nextLine();

        return serviceMetier.findLivreurVeloByMailAndPassword(mail,motDePasse);
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
            System.out.println("Choisir un restaurant : r, Retour/Déconnexion : d, quitter : q");
            input = scanner.nextLine();
            
            if(input.equals("r")) {
                System.out.println("Entrez le numéro du restaurant pour le selectionner :");
                for(int i = 0; i < restaurants.size(); i++) {
                    Restaurant r = restaurants.get(i);
                    System.out.println("\t" + r.getId() + " - " + r.getDenomination());
                }
                numR = scanner.nextLine();
                
                try {
                    Restaurant restaurant = serviceMetier.findRestaurantById(new Long(Integer.parseInt(numR)));
                    if(restaurant != null) {
                        vueRestaurant(restaurant, client);
                    }
                } catch(NumberFormatException e) {
                    
                }
            } else if(input.equals("q")) {
                System.exit(0);
            }  
        } while(!input.equals("d"));
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
            System.out.println("Récapitulatif commande : prix = " + commande.getPrix() + ", poids = " + commande.getPoidsEnGrammes());
            for (LigneDeCommande ligneDeCommande : commande.getLignesDeCommande()) {
                System.out.println("\t " + ligneDeCommande.getProduit().getDenomination() + " : prix unitaire = " + ligneDeCommande.getPrixUnitaire() + "€, poids unitaire = " + ligneDeCommande.getPoidsUnitaireEnGrammes() + "g, quantité = " + ligneDeCommande.getQuantite());
            }
            System.out.println("Ajouter un produit : p, valider : v, annuler/retour : a, quitter q");
            
            input = scanner.nextLine();
            
            if(input.equals("p")) {
                System.out.println("Entrez le numéro du produit pour le selectionner :");
                for(int i = 0; i < produits.size(); i++) {
                    Produit produit = produits.get(i);
                    System.out.println("\t" + produit.getId() + " - " + produit.getDenomination() + ", prix = " + produit.getPrix() + "€, poids = " + produit.getPoids() + "g");
                } 
                p = scanner.nextLine();
                
                System.out.println("Entrez la quatité :");
                q = scanner.nextLine();
                try {
                    Produit prod = serviceMetier.findProduitById(new Long(Integer.parseInt(p)));
                    if(prod != null) {
                        int n =  Integer.parseInt(q);
                        commande.addLigneDeCommande(prod,n);
                    }
                } catch(NumberFormatException e) {
                    
                }
                
            } else if (input.equals("a")) {
                //valider : 
                if(commande.getLignesDeCommande().size() > 0) {
                    commande.setDateDebut(new Date());
                    serviceMetier.createCommande(commande);
                }
                return;
            } else if(input.equals("q")) {
                System.exit(0);
            }  
        } while(!input.equals("r"));
                
    }

    private static void vueLivreurVelo(LivreurVelo livreur) {
        String cmd;
        String noC;
        do {
            System.out.println("Afficher détails d'une commande : c, Retour : r ou Quitter : q");
            cmd = scanner.nextLine();
            
            if(cmd.equals("c")) {
                List<Commande> commandes = serviceMetier.findCommandesByLivreurId(livreur.getId());
                System.out.println("Entrez le numéro d'une commande pour le selectionner :");
                for(Commande c : commandes)
                {
                    String l = "\t" + c.getId();
                    if(c.getDateFin() == null) {
                        l += " - non cloturée";
                    } else {
                        l += " - cloturée";
                    }
                    System.out.println(l);
                }
                noC = scanner.nextLine();
                try {
                    Commande commande = serviceMetier.findCommandeById(new Long(Integer.parseInt(noC)));
                    if(commande != null) {
                        detailsCommande(commande);
                    }
                } catch(NumberFormatException e) {
                    
                }
            } else if(cmd.equals("q")) {
                System.exit(0);
            }     
        } while(!cmd.equals("r"));
    }
    
    private static void vueLivreursDrones(List<LivreurDrone> livreurs) {
        String cmd;
        String noC;
        do {
            System.out.println("Afficher détails d'une commande : c, Retour : r ou Quitter : q");
            cmd = scanner.nextLine();
            
            if(cmd.equals("c")) {
                List<Commande> commandes = new ArrayList<>();
                for(LivreurDrone l : livreurs) {
                    commandes.addAll(serviceMetier.findCommandesByLivreurId(l.getId()));
                }
                System.out.println("Entrez le numéro d'une commande pour le selectionner :");
                for(Commande c : commandes)
                {
                    String l = "\t" + c.getId();
                    if(c.getDateFin() == null) {
                        l += " - non cloturée";
                    } else {
                        l += " - cloturée";
                    }
                    System.out.println(l);
                }
                noC = scanner.nextLine();
                    
                try{
                    Commande commande = serviceMetier.findCommandeById(new Long(Integer.parseInt(noC)));
                    if(commande != null) {
                        detailsCommande(commande);
                    }
                } catch(NumberFormatException e) {
                    
                }
            } else if(cmd.equals("q")) {
                System.exit(0);
            }     
        } while(!cmd.equals("r"));
       
    }
    
    private static void detailsCommande(Commande commande) {
        String cmd;
        String body = "Détails de la commande n°" + commande.getId()
                + "\n   - Date/heure creation : " + commande.getDateDebut().toString()
                + "\n   - Date/heure cloture : "; 
        if(commande.getDateFin() != null) {
            body += commande.getDateFin().toString();
        }
        body += "\n   - Livreur : " + commande.getLivreur().getId()
                + "\n   - Restaurant : " + commande.getRestaurant().getDenomination()
                + "\n   - Client :"
                + "\n       " + commande.getClient().getPrenom() + " " + commande.getClient().getNom().toUpperCase()
                + "\n       " + commande.getClient().getAdresse()
                + "\n       " + commande.getClient().getTelephone()
                + "\n   - Produits :";

        for (LigneDeCommande ligne : commande.getLignesDeCommande()) {
            body += "\n        - " + ligne.getQuantite() + " " + ligne.getProduit().getDenomination() + " " + ligne.getQuantite() + " x " + ligne.getPrixUnitaire() + "€"; 
        }
        body += "\n   - TOTAL : " + commande.getPrix() + "€";        
        System.out.println(body);
           
        if(commande.getDateFin() ==null)
        {
            System.out.println("Cloturer commande : c, Retour : r ou Quitter : q");
            cmd = scanner.nextLine();
            
            if(cmd.equals("c")) {
                commande.setDateFin(new Date());
                commande.getLivreur().setDisponible(Boolean.TRUE);
                serviceMetier.updateCommande(commande);
                serviceMetier.updateLivreur(commande.getLivreur());
            } else if(cmd.equals("q")) {
                System.exit(0);
            }     
        }
    }
}
