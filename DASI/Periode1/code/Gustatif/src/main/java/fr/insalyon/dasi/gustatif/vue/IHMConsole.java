/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.vue;

import fr.insalyon.dasi.gustatif.dao.ClientDao;
import fr.insalyon.dasi.gustatif.dao.JpaUtil;
import fr.insalyon.dasi.gustatif.dao.ProduitDao;
import fr.insalyon.dasi.gustatif.dao.RestaurantDao;
import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.metier.modele.Produit;
import fr.insalyon.dasi.gustatif.metier.modele.Restaurant;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Nico
 */
public class IHMConsole {
    
    public static void main(String[] args) {
    // TODO code application logic here    public static void main(String[] args) {
    // TODO code application logic here
        
//        testClient();
        testRestaurant();
        testLivreur();
       
    } 

    public static void testClient(){
        try{
            
            Client c1 = new Client("Nicolas", "Gripont","195 avenue Roger Salengro, 69100 Villeurbanne", "n.gripont@gmail.com","mdp");
            
            ClientDao cd = new ClientDao();

            System.out.println(c1);

            
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();
            cd.create(c1);
            JpaUtil.validerTransaction();
            
            Client c2 = cd.findByMailAndPassword("n.gripont@gmail.com", "mdp");
            
            System.out.println(c2);   
            
            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(IHMConsole.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void testRestaurant(){
        try{
            
            Restaurant r1 = new Restaurant("Le boeuf d'argent", "Plats traditionnels...", "12 rue Einstein, 69000 Lyon");
            Produit p1 = new Produit("Andouillette", "decs andouillette", new Float(16.0),new Float(127.0));
            Produit p2 = new Produit("Opéra", "decs opéra", new Float(7.0),new Float(445.0));
            Produit p3 = new Produit("Ile flottante", "decs ile", new Float(7.0),new Float(223.0));

          
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
            
            rd.create(r1);
            
            JpaUtil.validerTransaction();
            
            Restaurant r2 = rd.findById(new Long(4));
            
            System.out.println(r2);   
            
            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(IHMConsole.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void testLivreur() {
        
    }
}
