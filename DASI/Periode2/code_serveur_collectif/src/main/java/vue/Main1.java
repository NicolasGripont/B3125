/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vue;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import metier.modele.Adherent;
import metier.modele.Demande;
import metier.modele.Evenement;
import metier.service.ServiceMetier;
import static metier.service.ServiceMetier.AffichageDetail;
import static metier.service.ServiceMetier.creerAdherent;
import static metier.service.ServiceMetier.finaliserEvenement;
import static metier.service.ServiceMetier.selectAdherentByMail;
import static metier.service.ServiceMetier.AffichageEvenementsFiltres;
import static metier.service.ServiceMetier.AfficheNomActivites;
import static metier.service.ServiceMetier.AfficheNomLieux;
import static metier.service.ServiceMetier.selectDemandeByIdAdherent;

/**
 *
 * @author Florian
 */
public class Main1 {

    /**
     *
     * @param args
     * @throws Throwable
     */
    public static void main(String[] args) throws Throwable
    {
        int valSelect;
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        long id;
        Scanner lecture = new Scanner(System.in);
        do{
            System.out.println("===================================================");
            System.out.println("|                       MENU                       |");
            System.out.println("===================================================");
            System.out.println("|      Options:                                    |");
            System.out.println("|             1. Liste des activités               |");
            System.out.println("|             2. Liste des lieux                   |");
            System.out.println("|             3. Afficher les evenements           |");
            System.out.println("|             4. Afficher participants evenement   |");
            System.out.println("|             5. Liste historique demandes         |");
            System.out.println("|             6. Se connecter                      |");
            System.out.println("|             7. Affecter Lieu                     |"); 
            System.out.println("|             8. Creer adherent                    |");            
            System.out.println("|             9. Exit                              |");
            System.out.println("===================================================");
            valSelect= lecture.nextInt();

            switch (valSelect) {
            case 1:
                List<String> activites=AfficheNomActivites();
                for(String s: activites)
                {
                    System.out.println(s);
                }
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();lecture.nextLine();//Methode peu orthodoxe mais qui empeche le retour direct au menu
              break;
            case 2:
                List<String> lieux=AfficheNomLieux();
                for(String s: lieux)
                {
                    System.out.println(s);
                }
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();lecture.nextLine();
              break;
            case 3:
                Date date=sdf.parse("01/01/1970");
                List<Evenement> evt=AffichageEvenementsFiltres("Statut","Activité","Lieu",date);
                for(Evenement e: evt)
                {
                    System.out.println("Evenement numero : "+e.getId()+ " : "+e.getActivite().getDenomination());
                    System.out.println("Date : "+sdf.format(e.getDateEvenement()));
                    if(e.getStatut()==1)
                    {
                        System.out.println("Lieu : "+e.getLieu().getDenomination());
                    }
                }
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();lecture.nextLine();               
              break;
            case 4:
                System.out.println("Veuillez indiquer le numero de l'evenement : ");
                id=lecture.nextLong();
                List<Adherent> ad=AffichageDetail(id);
                for(Adherent a : ad)
                {
                    System.out.println(a);
                }
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();lecture.nextLine(); 
              break;
            case 5:
                System.out.println("Veuillez indiquer le numero de l'adherent : ");
                id=lecture.nextLong();
                List<Demande> dem=selectDemandeByIdAdherent((int)id);
                for(Demande d :dem)
                {
                    System.out.println("Demande numero : "+ d.getId());
                    System.out.println("Activite : "+d.getActivite().getDenomination()+ "Date : "+sdf.format(d.getDateDemande()));
                }
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();lecture.nextLine(); 
              break;
            case 6:
                String mail;
                System.out.println("Veuillez entrer une adresse mail : ");
                lecture.nextLine();
                mail=lecture.nextLine();
                Adherent aa=selectAdherentByMail(mail);
                if(aa==null)
                {
                    System.out.println("Mauvaise adresse ! ");
                }
                else
                {
                    System.out.println("Bienvenue "+aa.getPrenom());
                    System.out.println("Votre numero d'adherent est le "+aa.getId());
                }
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();
              break;
            case 7:
                String nomLieu;
                System.out.println("Veuillez entrer le nom du lieu : ");
                lecture.nextLine();
                nomLieu=lecture.nextLine();
                System.out.println("Veuillez entrer le numero de l'evenement : ");
                id=lecture.nextLong();
                finaliserEvenement(nomLieu,id);
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();
              break;
            case 8:
                lecture=new Scanner(System.in);
                System.out.println("Veuillez saisir un nom :");
                String nom = lecture.nextLine();

                System.out.println("Veuillez saisir un prenom :");
                String prenom = lecture.nextLine();

                System.out.println("Veuillez saisir une adresse postale :");
                String adresse = lecture.nextLine();

                System.out.println("Veuillez saisir une adresse mail :");
                String adresseMail = lecture.nextLine();
                creerAdherent(nom, prenom, adresse, adresseMail);
                System.out.println("Adherent cree");
                System.out.println("Retour au menu : Veuillez appuyer sur entrée :");
                lecture.nextLine();
              break;
            case 9 : break;
            default:
              System.out.println("Numero invalide, recommencez");
              break;
            }
        }while(valSelect!=9);
    }
}
