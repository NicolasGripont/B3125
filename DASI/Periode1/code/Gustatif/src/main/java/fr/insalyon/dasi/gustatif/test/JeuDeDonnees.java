/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.test;

import fr.insalyon.dasi.gustatif.dao.JpaUtil;
import fr.insalyon.dasi.gustatif.dao.LivreurDao;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import fr.insalyon.dasi.gustatif.util.GeoTest;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Nico
 */
public class JeuDeDonnees {
        public static void main(String[] args) { 
            //créer des livreurs drones et velos, des commandes, cloturées non cloturées
            //lancer le script sql??    
            Livreur lv1 = new LivreurVelo("Dupond", "Arthur", "arthur@livreur.com",
                    "mdp", "145 Rue Anatole France, 69628 Villeurbanne", new Double(30000.F));
            lv1.setCoordonnees(GeoTest.getLatLng(lv1.getAdresse()));
            Livreur lv2 = new LivreurVelo("Durant", "Bob", "bob@livreur.com", "mdp",
                    "30 Avenue Albert Einstein, 69100 Villeurbanne", new Double(40000.F));
            lv2.setCoordonnees(GeoTest.getLatLng(lv2.getAdresse()));
            Livreur lv3 = new LivreurVelo("Petit", "Charlie", "charlie@livreur.com",
                    "mdp", "Domaine de la Doua, 20 Avenue Gaston Berger, 69100 Villeurbanne",
                    new Double(50000.F));
            lv3.setCoordonnees(GeoTest.getLatLng(lv3.getAdresse()));
            Livreur lv4 = new LivreurVelo("Martin", "Damien", "estelle@livreur.com",
                    "mdp", "200 Rue Léon Blum, 69100 Villeurbanne", new Double(20000.F));
            lv4.setCoordonnees(GeoTest.getLatLng(lv4.getAdresse()));
            Livreur lv5 = new LivreurVelo("Roux", "Estelle", "estelle@livreur.com",
                    "mdp", "146 Boulevard Pinel, 69008 Lyon", new Double(10000.F));
            lv5.setCoordonnees(GeoTest.getLatLng(lv5.getAdresse()));
            
            Livreur ld1 = new LivreurDrone(new Double(10.F), "drone@gmail.com", "mdp",
                    "17 Rue du Dr Bouchut, 69003 Lyon", new Double(1000.F));
            ld1.setCoordonnees(GeoTest.getLatLng(ld1.getAdresse()));
            Livreur ld2 = new LivreurDrone(new Double(10.F), "drone@gmail.com", "mdp",
                    "17 Rue du Dr Bouchut, 69003 Lyon", new Double(1000.F));
            ld2.setCoordonnees(GeoTest.getLatLng(ld2.getAdresse()));
            Livreur ld3 = new LivreurDrone(new Double(10.F), "drone@gmail.com", "mdp",
                    "17 Rue du Dr Bouchut, 69003 Lyon", new Double(1000.F));
            ld3.setCoordonnees(GeoTest.getLatLng(ld3.getAdresse()));
            Livreur ld4 = new LivreurDrone(new Double(10.F), "drone@gmail.com", "mdp",
                    "17 Rue du Dr Bouchut, 69003 Lyon", new Double(1000.F));
            ld4.setCoordonnees(GeoTest.getLatLng(ld4.getAdresse()));
            Livreur ld5 = new LivreurDrone(new Double(10.F), "drone@gmail.com", "mdp",
                    "17 Rue du Dr Bouchut, 69003 Lyon", new Double(1000.F));
            ld5.setCoordonnees(GeoTest.getLatLng(ld5.getAdresse()));
            
            LivreurDao livreurDao = new LivreurDao();
            try{ 
                JpaUtil.creerEntityManager();
                JpaUtil.ouvrirTransaction();

                livreurDao.create(lv1);
                livreurDao.create(lv2);
                livreurDao.create(lv3);
                livreurDao.create(lv4);
                livreurDao.create(lv5);
                
                livreurDao.create(ld1);
                livreurDao.create(ld2);
                livreurDao.create(ld3);
                livreurDao.create(ld4);
                livreurDao.create(ld5);

                JpaUtil.validerTransaction();
                JpaUtil.fermerEntityManager();
            } catch (Throwable ex) {
                Logger.getLogger(
                        JeuDeDonnees.class.getName()).log(Level.SEVERE, null, ex);
            }        
        }
}
