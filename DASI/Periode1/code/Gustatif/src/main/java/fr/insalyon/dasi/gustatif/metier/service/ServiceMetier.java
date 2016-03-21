/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.service;

import com.google.maps.model.LatLng;
import fr.insalyon.dasi.gustatif.dao.ClientDao;
import fr.insalyon.dasi.gustatif.dao.CommandeDao;
import fr.insalyon.dasi.gustatif.dao.JpaUtil;
import fr.insalyon.dasi.gustatif.dao.LivreurDao;
import fr.insalyon.dasi.gustatif.dao.LivreurDroneDao;
import fr.insalyon.dasi.gustatif.dao.LivreurVeloDao;
import fr.insalyon.dasi.gustatif.dao.ProduitDao;
import fr.insalyon.dasi.gustatif.dao.RestaurantDao;
import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.Produit;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
import fr.insalyon.dasi.gustatif.util.GeoTest;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Nico
 */
public class ServiceMetier {
 
    private final ClientDao clientDao = new ClientDao();
    private final RestaurantDao restaurantDao = new RestaurantDao();
    private final ProduitDao produitDao = new ProduitDao();
    private final CommandeDao commandeDao = new CommandeDao();
    private final LivreurDao livreurDao = new LivreurDao();
    private final LivreurVeloDao livreurVeloDao = new LivreurVeloDao();
    private final LivreurDroneDao livreurDroneDao = new LivreurDroneDao();
    private final ServiceTechnique serviceTechnique = new ServiceTechnique();

    public ServiceMetier() {
    }
    
    public boolean createClient(Client client)
    {
        boolean result = false;
        
        LatLng latLng = GeoTest.getLatLng(client.getAdresse());

        //adresse invalide car ne permet pas de calculer une LatLng
        if(latLng != null) {
            client.setCoordonnees(latLng);
            JpaUtil.creerEntityManager();
            try {
                
                JpaUtil.ouvrirTransaction();
                clientDao.create(client);
                JpaUtil.validerTransaction();
                
                result = true;
            } catch (Exception e) {
                System.out.println(e);
            } catch (Throwable ex) {
                Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            }
            JpaUtil.fermerEntityManager();
        }
        
        // envoi du mail
        String recipient = client.getMail();
        String subject = null;
        String body = null;
        if(result)
        {
            //envoyer mail succes
            subject = "Bienvenue chez Gustat'IF";
            body = "Bonjour <prenom>,\n" 
                + "\n" 
                + "       Nous vous confirmons votre inscription au service Gustat'IF.";
        } else {
            //envoyer mail echec
            subject = "Bienvenue chez Gustat'IF";
            body = "Bonjour <prenom>,\n" 
                + "\n" 
                + "       Votre inscription au service Gustat'IF a malencontreusement échoué... Merci de recommencer ultérieurement.";
        }
        serviceTechnique.sendFakeMail(recipient, subject, body);
        serviceTechnique.sendRealMail(recipient, subject, body);
       
        return result;
    }
    
    public boolean clientExists(String mail, String motDePasse) {
        boolean result = false;
        
        //aucun argument ne doit être égale à null
        if(mail != null && motDePasse != null)
        {
            //tous les champs doivent être renseignés
            if(!mail.isEmpty() && !motDePasse.isEmpty())
            {   
                JpaUtil.creerEntityManager();
                 try {
                   
                    //si le client existe en BD
                    if(clientDao.findByMailAndPassword(mail, motDePasse) != null)
                    {
                        result = true;
                    }
                } catch(Throwable e) {
                    
                }
                JpaUtil.fermerEntityManager();
            }
        }
        
        return result;
    }
    
    
     public Client updateClient(Client client) {
        JpaUtil.creerEntityManager();
       
        try {
            JpaUtil.ouvrirTransaction();
            client = clientDao.update(client);
            JpaUtil.annulerTransaction();
        } catch (Exception e) {
            System.out.println(e);
            client = null;
            JpaUtil.annulerTransaction();
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            client =  null;
            JpaUtil.annulerTransaction();
        }
        
        JpaUtil.fermerEntityManager();
        
       return client;
    }
     
    public Client findClientById(Long id) {
        JpaUtil.creerEntityManager();
        
        Client client = null;
        
        try {
            client = clientDao.findById(id);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return client;
    }

    
    public Client findClientByMailAndPassword(String mail, String password) {
        JpaUtil.creerEntityManager();
        
        Client client = null;
        
        try {
            client = clientDao.findByMailAndPassword(mail, password);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return client;
    }
    
    public Client findClientByMail(String mail) {
        JpaUtil.creerEntityManager();
        
        Client client = null;
        
        try {
            client = clientDao.findByMail(mail);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return client;
    }
    
    public List<Client> findAllClients() {
        JpaUtil.creerEntityManager();
        
        List<Client> clients = null;
        
        try {
            clients = clientDao.findAll();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return clients;
    }
     
    public Restaurant findRestaurantById(Long id) {
        JpaUtil.creerEntityManager();
        
        Restaurant restaurant = null;
        
        try {
            restaurant = restaurantDao.findById(id);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return restaurant;
    }
    
    public List<Restaurant> findAllRestaurants() {
        JpaUtil.creerEntityManager();
        
        List<Restaurant> restaurants = null;
        
        try {
            restaurants = restaurantDao.findAll();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return restaurants;
    }
    
    public Produit findProduitById(Long id) {
        JpaUtil.creerEntityManager();
        
        Produit produit = null;
        
        try {
            produit = produitDao.findById(id);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return produit;
    }
    
    public List<Produit> findAllProduits() {
        JpaUtil.creerEntityManager();
        
        List<Produit> produits = null;
        
        try {
            produits = produitDao.findAll();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return produits;
    }
    
    public boolean createCommande(Commande commande) {
        JpaUtil.creerEntityManager();
        
        boolean result = false;
        
        try {
            //Chercher un livreur
            //Envoyer un mail
            JpaUtil.ouvrirTransaction();
            commandeDao.create(commande);
            JpaUtil.validerTransaction();
            result = true;
        } catch (Exception e) {
            System.out.println(e);
            JpaUtil.annulerTransaction();
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            JpaUtil.annulerTransaction();
        }
        
        JpaUtil.fermerEntityManager();
        
        return result;
    }    
    
    public Commande updateCommande(Commande commande) {  
        JpaUtil.creerEntityManager();
        
        try {
            JpaUtil.ouvrirTransaction();
            commandeDao.create(commande);
            JpaUtil.validerTransaction();
        } catch (Exception e) {
            System.out.println(e);
            commande = null;
            JpaUtil.annulerTransaction();
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            commande = null;
            JpaUtil.annulerTransaction();
        }
        
        JpaUtil.fermerEntityManager();
        
        return commande;
    }    
    
    public List<Commande> findAllCommande() {
        JpaUtil.creerEntityManager();
        
        List<Commande> commandes = null;
        
        try {
            commandes = commandeDao.findAll();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return commandes;
    }    
    
    public List<Commande> findAllCommandeNotEnded() {
        JpaUtil.creerEntityManager();
        
        List<Commande> commandes = null;
        
        try {
            commandes = commandeDao.findAllNotEnded();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return commandes;
    }
    
    
    public Livreur updateLivreurById(Livreur livreur) { 
        JpaUtil.creerEntityManager();
        
        try {
            JpaUtil.ouvrirTransaction();
            livreur = livreurDao.update(livreur);
            JpaUtil.validerTransaction();
        } catch (Exception e) {
            System.out.println(e);
            livreur = null;
            JpaUtil.annulerTransaction();
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            livreur = null;
            JpaUtil.annulerTransaction();
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreur;
    }
    
    public Livreur findLivreurByMailAndPassword(String mail, String password) {
        JpaUtil.creerEntityManager();
        
        Livreur livreur = null;
        
        try {
            livreur = livreurDao.findByMailAndPassword(mail, password);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreur;
    }
    
    public Livreur findLivreurById(Long id) {
        JpaUtil.creerEntityManager();
        
        Livreur livreur = null;
        
        try {
            livreur = livreurDao.findById(id);
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreur;
    }
    
    public List<Livreur> findAllLivreurs() {
        JpaUtil.creerEntityManager();
        
        List<Livreur> livreurs = null;
        
        try {
            livreurs = livreurDao.findAll();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreurs;
    }
    
    public List<LivreurDrone> findAllLivreursDrones() {
        JpaUtil.creerEntityManager();
        
        List<LivreurDrone> livreurs = null;
        
        try {
            livreurs = livreurDroneDao.findAllLivreursDrones();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreurs;
    }
    
    public List<LivreurVelo> findAllLivreursVelos() {
        JpaUtil.creerEntityManager();
        
        List<LivreurVelo> livreurs = null;
        
        try {
            livreurs = livreurVeloDao.findAllLivreursVelos();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreurs;
    }

    public List<Livreur> findAllLivreursDisponible() {      
        JpaUtil.creerEntityManager();
        
        List<Livreur> livreurs = null;
        
        try {
            livreurs = livreurDao.findAllDisponible();
        } catch (Exception e) {
            System.out.println(e);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        JpaUtil.fermerEntityManager();
        
        return livreurs;
    }
            
    
}
