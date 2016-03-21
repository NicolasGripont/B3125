/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.vue;

import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import fr.insalyon.dasi.gustatif.metier.service.ServiceMetier;
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
        
        do {
            System.out.println("Connexion : c, Inscription : i ou Quitter : q");
            cmd = scanner.nextLine();
            
            if(cmd.equals("c"))
            {
                client = connexion();
                if(client != null)
                {
                    vueRestaurant();
                }
            } else if(cmd.equals("i")) {
                inscription();
            }      
        } while(cmd.equals("q") == false);
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
    
    private static void vueRestaurant()
    {
        List<Restaurant> restaurants = serviceMetier.findAllRestaurants();
        System.out.println("Entrez le numéro du restaurant pour le selectionner :");
        for(int i = 0; i < restaurants.size(); i++)
        {
            Restaurant r = restaurants.get(i);
            System.out.println("\t" + i + " - " + r.getDenomination());
        }
    }
}
