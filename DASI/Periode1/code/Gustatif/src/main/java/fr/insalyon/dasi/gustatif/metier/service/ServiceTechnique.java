/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.service;

import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import fr.insalyon.dasi.gustatif.util.GeoTest;
import fr.insalyon.dasi.gustatif.util.MailSender;
import java.util.List;

/**
 *
 * @author Nico
 */
public class ServiceTechnique {
    
    public boolean sendRealMail(String recipientMail, String subject, String body) {
        MailSender ms = new MailSender("gustatif.b3125@gmail.com","B3125-2016");
        return ms.sendMail(recipientMail,subject,body);
    }
    
    public void sendFakeMail(String recipientMail, String subject, String body) {
        System.out.println("");
        System.out.println("********* Mail envoyé **********");
        System.out.println("From : gustatif.b3125@gmail.com");
        System.out.println("To : " + recipientMail);
        System.out.println("Subject : " + subject);
        System.out.println(body);
        System.out.println("********************************");
        System.out.println("");
    }
   
    
    public Livreur chooseBestLivreur(Commande commande,List<Livreur> livreurs ) 
            throws Throwable {
        Livreur livreurChoisi = null;
        double temps;
        double tempsFinal;
        
        if(!livreurs.isEmpty()) {
            livreurChoisi = livreurs.get(0);
            if(livreurChoisi instanceof LivreurVelo){
                tempsFinal = GeoTest.getTripDurationByBicycleInMinute(
                        livreurChoisi.getLatLng(),commande.getClient().getLatLng(),
                        commande.getRestaurant().getLatLng());
            } else if (livreurChoisi instanceof LivreurDrone){
                tempsFinal = ( (GeoTest.getFlightDistanceInKm(livreurChoisi.getLatLng(), 
                        commande.getRestaurant().getLatLng()) 
                        + GeoTest.getFlightDistanceInKm(commande.getRestaurant().getLatLng(),
                                commande.getClient().getLatLng())) 
                        / ((LivreurDrone)livreurChoisi).getVitesseMoyenneDeVolEnKmH()) * 60;
            } else {
                return null;
            }
            for (int i=1; i < livreurs.size(); i++) {
                if(livreurs.get(i) instanceof LivreurVelo){
                    temps = GeoTest.getTripDurationByBicycleInMinute(
                            livreurs.get(i).getLatLng(), commande.getClient().getLatLng(),
                            commande.getRestaurant().getLatLng());
                } else if (livreurs.get(i) instanceof LivreurDrone){
                    temps = ( (GeoTest.getFlightDistanceInKm(livreurs.get(i).getLatLng(),
                            commande.getRestaurant().getLatLng()) 
                            + GeoTest.getFlightDistanceInKm(commande.getRestaurant().getLatLng(),
                                    commande.getClient().getLatLng()) ) 
                            / ((LivreurDrone)livreurs.get(i)).getVitesseMoyenneDeVolEnKmH()) * 60;
                } else {
                    return null;
                }
                if(temps < tempsFinal) {
                    tempsFinal = temps;
                    livreurChoisi = livreurs.get(i);
                }
            }
        }
        
        return livreurChoisi;
    } 
}
