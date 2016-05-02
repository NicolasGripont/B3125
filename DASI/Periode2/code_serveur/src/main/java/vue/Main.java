/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vue;

import dao.EvenementDao;
import dao.JpaUtil;
import dao.LieuDao;
import dao.TypeLieuDao;
import java.util.List;
import metier.modele.Lieu;
import metier.modele.TypeLieu;
import metier.service.ServiceMetier;
import static metier.service.ServiceMetier.obtenirLieux;

/**
 *
 * @author arame
 */
public class Main {

    /**
     * @param args the command line arguments
     * @throws java.lang.Throwable
     */
    public static void main(String[] args) throws Throwable
    {
       /* EvenementDao evmtM = new EvenementDao();
        LieuDao LM = new LieuDao();
        AdherentDao AM = new AdherentDao();
        ActiviteDao AcM = new ActiviteDao();

        creerAdherent("virsolvy", "mathieu", "8 rue Francis de Pressensé", "agnes.rame@insa-lyon.fr");
        System.out.println("selectAdherentByMail : " + selectAdherentByMail("agnes.rame@insa-lyon.fr"));
        System.out.println("MailExist : " + MailExist("agnes.rame@insa-lyon.fr"));
        
        System.out.println("selectDemandeByIdAdherent : ");
        List<Demande> liste = selectDemandeByIdAdherent( 1);
        for (Demande de : liste )
        {
            System.out.println(de);
        }
        
        System.out.println("AfficheNomActivites : ");
        List<String> listeA = AfficheNomActivites();
        for (String de : listeA )
        {
            System.out.println(de);
        }
        
        System.out.println("AfficheStatut : ");
        listeA = AfficheStatut();
        for (String de : listeA )
        {
            System.out.println(de);
        }
        
        System.out.println("AfficheNomLieux : ");
        listeA = AfficheNomLieux();
        for (String de : listeA )
        {
            System.out.println(de);
        }
        
        System.out.println("AfficheAdherentLike(A) : ");
        listeA = AfficheAdherentLike("A");
        for (String de : listeA )
        {
            System.out.println(de);
        }
        
        CreerDemande("Belote",  new Date(),  105);
        CreerDemande("Belote",  new Date(),  79);
        CreerDemande("Belote",  new Date(),  110);
        CreerDemande("Belote",  new Date(),  121);

        
        System.out.println("AffichageEvenementsFiltres() : ");
        List<Evenement> listeE = AffichageEvenementsFiltres("Non complet",  "Football", "Gymnase Colette Besson",new Date());
        for (Evenement de : listeE )
        {
            System.out.println(de);
        }
        JpaUtil.creerEntityManager();
        
        Adherent adh = AM.findById(1051);
        
       
        Activite activite= AcM.findById(14);
        
        
        
        

        List<Adherent> list;
         list =AffichageDetail( 1051 );
         System.out.println("liste participants evenements");
         for(Adherent ad : list){
             System.out.println(ad );
         }
         
        finaliserEvenement("Gymnase Leo Lagrange", 1051);*/
        JpaUtil.creerEntityManager();
       TypeLieuDao TL=new TypeLieuDao();
        EvenementDao a=new EvenementDao();
        TypeLieu ab= new  TypeLieu();
        List<Lieu> li=obtenirLieux(a.findById(2451));
        for(Lieu l:li)
        {
            System.out.println(l.getDenomination());
        }
    }

}