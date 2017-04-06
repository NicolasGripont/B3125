/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier.service;

import com.google.maps.model.LatLng;
import java.text.SimpleDateFormat;
import java.util.List;
import metier.modele.Adherent;
import metier.modele.Evenement;
import metier.modele.EvenementParEquipe;
import metier.modele.EvenementSansEquipe;
import static util.GeoTest.getFlightDistanceInKm;
import static util.GeoTest.getLatLng;


public class ServiceTechnique {
    private static Object em;

    /**
     *Service technique envoyant un mail à l'adhérent en cas de succès lors de l'inscription 
     * @param adherent
     */
    public static void mailInscriptionSucces(Adherent adherent)
    {
        System.out.println(
        "Expediteur : collectif@collectif.org\n" +
        "Pour : " + adherent.getMail() +"\n" +
        "Sujet : Bienvenue chez Collect'IF\n" +
        "Bonjour " + adherent.getPrenom() +",\n" +
        "Nous vous confirmons votre adhésion à l'association COLLECT’IF. Votre numéro d'adhérent est : "+ adherent.getId() +".");
    }

    /**
     *Service technique envoyant un mail à l'adhérent en cas de l'échec lors de l'inscription 
     * @param mail
     * @param prenom
     */
    public static void mailInscriptionEchec(String mail, String prenom)
    {
        System.out.println(
        "Expediteur : collectif@collectif.org\n" +
        "Pour : " +mail +"\n" +
        "Sujet : Bienvenue chez Collect'IF\n" +
        "Bonjour "+prenom+",\n" +
        "Votre adhésion à l'association COLLECT’IF a malencontreusement échoué... Merci de recommencer " +
        "ultérieurement.");
    }
    
    /**
     *Service technique envoyant un mail à l'adhérent lorsqu'un événement auquel il est inscrit est finalisé 
     * @param adherent
     * @param evenement
     */
    public static void mailEvenementPlanifie(Adherent adherent, Evenement evenement)
    {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        LatLng coordonneesAdherent = getLatLng(adherent.getAdresse());
        LatLng coordonneesLieu = getLatLng(evenement.getLieu().getAdresse());
        System.out.println("Expediteur : collectif@collectif.org\n" +
        "Pour : " + adherent.getMail() + "\n" +
        "Sujet : Nouvel Évènement Collect'IF\n" +
        "Corps :\n" +
        "Bonjour " + adherent.getPrenom() + ",\n" +
        "Comme vous l'aviez souhaité, COLLECT’IF organise un évènement de " + evenement.getActivite().getDenomination() + " le " + sdf.format(evenement.getDateEvenement()) + ".\n" +
        "Vous trouverez ci-dessous les détails de cet évènement.\n" +
        "Associativement vôtre,\n" +
        "Le Responsable de l'Association\n" +
        "Evénement : " + evenement.getActivite().getDenomination() +" \n" +
        "Date : " + evenement.getDateEvenement().toString() + "\n" +
        "Lieu : " + evenement.getLieu().getAdresse() + "\n" +
        "(à " + getFlightDistanceInKm(coordonneesAdherent, coordonneesLieu) + " km de chez vous)\n" + // calcul distance entre adresse de lieu et adresse de l'adherant
        "Vous jouerez avec :\n");
        
        if(evenement instanceof EvenementSansEquipe)
        {
            List<Adherent> participansSansEquipe = evenement.getParticipants();
            for (final Adherent adherents : participansSansEquipe)
            {
                if(adherents.getId()!=adherent.getId())
                System.out.println(adherents.getPrenom() +" "+ adherents.getNom().toUpperCase() + " \n");
            }

        }
        else if(evenement instanceof EvenementParEquipe)
        {
            List<Adherent> participansParEquipe = evenement.getEquipeA();
            boolean equi=false;
            for (final Adherent adherents : participansParEquipe)
            {
                if(adherents.getId()==adherent.getId())
                    equi=true;
            }
                if (equi)
                {
                    afficherEquipeA(evenement,adherent);
                    System.out.println("Contre :\n");
                    afficherEquipeB(evenement,adherent);
                }
                else
                {
                    afficherEquipeB(evenement,adherent);
                    System.out.println("Contre :\n");
                    afficherEquipeA(evenement,adherent);
                }
        }

    }
    
    /**
     *Service technique permettant d'affichr les joueurs de l'équipe A
     * @param evenement
     * @param adherent
     */
    public static void afficherEquipeA(Evenement evenement,Adherent adherent)
    {
        List<Adherent> participansEquipeA = evenement.getEquipeA();
        for (final Adherent adherents : participansEquipeA)
        {
            if(adherents.getId()!=adherent.getId())
            System.out.println(adherents.getPrenom() +" "+ adherents.getNom().toUpperCase() + "\n");
        }
    }
    
    /**
     *Service technique permettant d'affichr les joueurs de l'équipe A
     * @param evenement
     * @param adherent
     */
    public static void afficherEquipeB(Evenement evenement,Adherent adherent)
    {
        List<Adherent> participansEquipeB = evenement.getEquipeB();
        for (final Adherent adherents : participansEquipeB)
        {
            if(adherents.getId()!=adherent.getId())
            System.out.println(adherents.getPrenom() +" "+ adherents.getNom().toUpperCase() + "\n");
        }
    }


}
