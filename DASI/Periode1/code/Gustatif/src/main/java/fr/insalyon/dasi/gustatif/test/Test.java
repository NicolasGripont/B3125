/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.test;

import fr.insalyon.dasi.gustatif.dao.ClientDao;
import fr.insalyon.dasi.gustatif.dao.CommandeDao;
import fr.insalyon.dasi.gustatif.dao.JpaUtil;
import fr.insalyon.dasi.gustatif.dao.LigneDeCommandeDao;
import fr.insalyon.dasi.gustatif.dao.LivreurDao;
import fr.insalyon.dasi.gustatif.dao.LivreurDroneDao;
import fr.insalyon.dasi.gustatif.dao.LivreurVeloDao;
import fr.insalyon.dasi.gustatif.dao.ProduitDao;
import fr.insalyon.dasi.gustatif.dao.RestaurantDao;
import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.LigneDeCommande;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import fr.insalyon.dasi.gustatif.metier.modele.Produit;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import java.time.Instant;
import java.util.Date;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Nico
 */
public class Test {
    
    public static void main(String[] args) {
    // TODO code application logic here    public static void main(String[] args) {
    // TODO code application logic here
        
//        testClient();
//        testRestaurant();
//        testLivreurVelo();
//        testCommande();
//        testChoixLivreur();
    } 

    public static void testClient(){
        try{
            
            Client c1 = new Client("Nicolas", "Gripont","195 avenue Roger Salengro, 69100 Villeurbanne", "n.gripont@gmail.com","mdp", "0678901234");
            Client c4 = new Client("Nicolas", "Gripont","195 avenue Roger Salengro, 69100 Villeurbanne", "n.gripont@gmail.com","mdp","0678901234");

            ClientDao cd = new ClientDao();

            System.out.println(c1);

            
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();
            cd.create(c1);
            JpaUtil.validerTransaction();
            
            Client c2 = cd.findByMailAndPassword("n.gripont@gmail.com", "mdp");
            
            System.out.println(c2);   
            
            Client c3 = cd.findByMail("n.gripont@gmail.com");
            
            System.out.println(c3);
            
//            JpaUtil.ouvrirTransaction();
//            cd.create(c4);
//            JpaUtil.validerTransaction();//error car unique sur mail
            System.out.println(c4);
            
            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void testRestaurant(){
        try{
            
            Restaurant r1 = new Restaurant("Le boeuf d'argent", "Plats traditionnels...", "12 rue Einstein, 69000 Lyon");
            Produit p1 = new Produit("Andouillette", "decs andouillette", new Double(16.0F),new Double(127.0F));
            Produit p2 = new Produit("Opéra", "decs opéra", new Double(7.0F),new Double(445.0F));
            Produit p3 = new Produit("Ile flottante", "decs ile", new Double(7.0F),new Double(223.0F));

          
            RestaurantDao rd = new RestaurantDao();
            ProduitDao pd = new ProduitDao();
            
            
            System.out.println(r1);

            
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();
            
            pd.create(p1);
            pd.create(p2);
            pd.create(p3);
            
            List<Produit> p = pd.findAll();
            
            r1.addProduit(p.get(0));
            r1.addProduit(p.get(1));
            r1.addProduit(p.get(2));
//            r1.addProduit(p1);
//            r1.addProduit(p2);
//            r1.addProduit(p3);
            
            rd.create(r1);
            
            JpaUtil.validerTransaction();
            
            Restaurant r2 = rd.findById(new Long(4));
            
            System.out.println(r2);   
            
            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void testLivreurVelo() {
        try{ 
            Livreur l1 = new LivreurVelo("nomLivreurVelo", "prenomLivreurVelo", "mailLivreurVelo@gmail.com", "mdp", "adresse", new Double(30000.F));
            Livreur l2 = new LivreurDrone(new Double(10000.F), "mailLivreurDrone@gmail.com", "mdp", "adresseDrone", new Double(1000.F));
            LivreurDao ld = new LivreurDao();
            LivreurVeloDao lvd = new LivreurVeloDao();
            LivreurDroneDao ldd = new LivreurDroneDao();

            System.out.println(l1);
            System.out.println(l2);

            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();

            ld.create(l1);
            ld.create(l2);
            
            JpaUtil.validerTransaction();

            Livreur l3 = ld.findById(new Long(1));
            Livreur l4 = ld.findById(new Long(2));
            
            List<LivreurVelo> list1 = lvd.findAllLivreursVelos();
            List<LivreurDrone> list2 = ldd.findAllLivreursDrones();

            System.out.println(l3);  
            System.out.println(l4); 
            System.out.println(list1.size());
            System.out.println(list1.get(0));
            System.out.println(list2.size());
            System.out.println(list2.get(0));

            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public static void testCommande() {
        try{ 
            Livreur l1 = new LivreurVelo("nomLivreurVelo", "prenomLivreurVelo", "mailLivreurVelo@gmail.com", "mdp", "adresse", new Double(30000.F));
            LivreurDao ld = new LivreurDao();
            
            Client c1 = new Client("Nicolas", "Gripont","195 avenue Roger Salengro, 69100 Villeurbanne", "n.gripont@gmail.com","mdp","0678901234");
            ClientDao cd = new ClientDao();  

            Restaurant r1 = new Restaurant("Le boeuf d'argent", "Plats traditionnels...", "12 rue Einstein, 69000 Lyon");
            RestaurantDao rd = new RestaurantDao();

            Produit p1 = new Produit("Andouillette", "decs andouillette", new Double(16.0F),new Double(127.0F));
            Produit p2 = new Produit("Opéra", "decs opéra", new Double(7.0F),new Double(445.0F));
            Produit p3 = new Produit("Ile flottante", "decs ile", new Double(7.0F),new Double(223.0F));
            ProduitDao pd = new ProduitDao();
            
            Commande cmd = new Commande(/*"C00001",*/ r1, c1, Date.from(Instant.now()));
            CommandeDao cmdd = new CommandeDao();
//            LigneDeCommande ldc1 = new LigneDeCommande(p1, new Integer(2));
//            LigneDeCommande ldc2 = new LigneDeCommande(p3, new Integer(3));
            cmd.addLigneDeCommande(p1, new Integer(2));
            cmd.addLigneDeCommande(p3, new Integer(3));
            cmd.setLivreur(l1);
            l1.addCommande(cmd);

            LigneDeCommandeDao ldcd = new LigneDeCommandeDao();
            
            
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();

            //Ajout restaurant et produits en BD
            pd.create(p1);
            pd.create(p2);
            pd.create(p3);
            List<Produit> p = pd.findAll();
            r1.addProduit(p.get(0));
            r1.addProduit(p.get(1));
            r1.addProduit(p.get(2));            
            rd.create(r1);
            
            //Ajout livreur et client en BD
            ld.create(l1);
            cd.create(c1);
            
            cmdd.create(cmd);
            
            JpaUtil.validerTransaction();

            System.out.println(cmd);
            
            List<LigneDeCommande> list1 = ldcd.findAll();
            System.out.println(list1.size());

            List<LigneDeCommande> list2 = ldcd.findByCommandeID(new Long(7));
            System.out.println(list2.size());
            
            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
//    public static void testChoixLivreur() {
//        try{ 
//            //les livreurs
//            Livreur lv1 = new LivreurVelo("nomLivreurVelo1", "prenomLivreurVelo1", "mailLivreurVelo1@gmail.com", "mdp", "145 Rue Anatole France, 69628 Villeurbanne", new Double(30000.F));
//            lv1.setCoordonnees(GeoTest.getLatLng(lv1.getAdresse()));
//            Livreur ld1 = new LivreurDrone(new Double(10.F), "mailLivreurDrone@gmail.com", "mdp", "110 Boulevard du 11 Novembre 1918, 69100 Villeurbanne", new Double(1000.F));
//            ld1.setCoordonnees(GeoTest.getLatLng(ld1.getAdresse()));
//            Livreur lv2 = new LivreurVelo("nomLivreurVelo2cimetiere", "prenomLivreurVelo2", "mailLivreurVelo2@gmail.com", "mdp", "30 Avenue Albert Einstein, 69100 Villeurbanne", new Double(40000.F));
//            lv2.setCoordonnees(GeoTest.getLatLng(lv2.getAdresse()));
//            Livreur ld2 = new LivreurDrone(new Double(12.F), "mailLivreurDrone@gmail.com", "mdp", "61 Avenue Roger Salengro, 69100 Villeurbanne", new Double(1000.F));
//            ld2.setCoordonnees(GeoTest.getLatLng(ld2.getAdresse()));
//            Livreur lv3 = new LivreurVelo("nomLivreurVelo3", "prenomLivreurVelo3", "mailLivreurVelo3@gmail.com", "mdp", "Domaine de la Doua, 20 Avenue Gaston Berger, 69100 Villeurbanne", new Double(50000.F));
//            lv3.setCoordonnees(GeoTest.getLatLng(lv3.getAdresse()));
//            Livreur ld3 = new LivreurDrone(new Double(10.F), "mailLivreurDrone@gmail.com", "mdp", "61 Avenue Roger Salengro, 69100 Villeurbanne", new Double(2000.F));
//            ld3.setCoordonnees(GeoTest.getLatLng(ld3.getAdresse()));
//            LivreurDao ld = new LivreurDao();
//            LivreurVeloDao lvd = new LivreurVeloDao();
//            LivreurDroneDao ldd = new LivreurDroneDao();
//            
//            //le client 
//            Client c1 = new Client("Nicolas", "Gripont","195 avenue Roger Salengro, 69100 Villeurbanne", "n.gripont@gmail.com","mdp");
//            ClientDao cd = new ClientDao(); 
//            c1.setCoordonnees(GeoTest.getLatLng(c1.getAdresse()));
//            
//            //Le restaurant, ses produits, la commande 
//            Restaurant r1 = new Restaurant("Le boeuf d'argent", "Plats traditionnels...", "12 rue Einstein, 69000 Lyon");
//            RestaurantDao rd = new RestaurantDao();
//
//            Produit p1 = new Produit("Andouillette", "decs andouillette", new Double(16.0F),new Double(127.0F));
//            Produit p2 = new Produit("Opéra", "decs opéra", new Double(7.0F),new Double(445.0F));
//            Produit p3 = new Produit("Ile flottante", "decs ile", new Double(7.0F),new Double(223.0F));
//            ProduitDao pd = new ProduitDao();
//            
//            //commande 
//
//            Commande cmd = new Commande(r1, c1);
//            Commande cmd2 = new Commande(r1, c1);
//            CommandeDao cmdd = new CommandeDao();
//            cmd.addLigneDeCommande(p1, new Integer(2));
//            cmd.addLigneDeCommande(p3, new Integer(3));
//            cmd.addLigneDeCommande(p1, new Integer(2));
//            cmd.addLigneDeCommande(p3, new Integer(3));
//
//            //LigneDeCommandeDao ldcd = new LigneDeCommandeDao();
//            
//       
//            
//            
//            //persistence livreurs, clients, restaurant.  
//            JpaUtil.creerEntityManager();
//            JpaUtil.ouvrirTransaction();
//            //livreurs
//            ld.create(lv1);
//            ld.create(ld1);
//            ld.create(lv2);
//            ld.create(ld2);
//            ld.create(lv3);
//            ld.create(ld3);
//            //clients
//            cd.create(c1);
//            //restaurante et produits 
//            pd.create(p1);
//            pd.create(p2);
//            pd.create(p3);
//
//            List<Produit> p = pd.findAll();
//
//            r1.addProduit(p.get(0));
//            r1.addProduit(p.get(1));
//            r1.addProduit(p.get(2));
//
//            rd.create(r1);	
//
//
//            JpaUtil.validerTransaction();
//            
//            System.out.println(lv1);
//
//            //créer la commande après affectation du livreur : 
//
//            JpaUtil.ouvrirTransaction();
//            //choix du livreur à l'interieur de la transaction pour assurer la synchro.
//            ServiceMetier sm = new ServiceMetier();
//            Livreur l1 = sm.chooseLivreur(cmd);	
//            System.out.println("livreur choisi : " + l1);
//
//            cmd.setLivreur(l1);
//            l1.addCommande(cmd);
//
//            ld.update(l1);
//            cmdd.create(cmd);
//
//            JpaUtil.validerTransaction();
//
//            JpaUtil.fermerEntityManager();
//            
//        }
//        catch (Exception e) {
//            Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, e);
//        } catch (Throwable t){
//            
//        }
//    }
}


