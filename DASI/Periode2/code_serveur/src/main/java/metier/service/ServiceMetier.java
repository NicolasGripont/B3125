/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier.service;

import com.google.maps.model.LatLng;
import dao.ActiviteDao;
import dao.AdherentDao;
import dao.DemandeDao;
import dao.EvenementDao;
import dao.JpaUtil;
import static dao.JpaUtil.annulerTransaction;
import static dao.JpaUtil.ouvrirTransaction;
import static dao.JpaUtil.validerTransaction;
import dao.LieuDao;
import dao.TypeLieuDao;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import metier.modele.Activite;
import metier.modele.Adherent;
import metier.modele.Demande;
import metier.modele.Evenement;
import metier.modele.EvenementParEquipe;
import metier.modele.EvenementSansEquipe;
import metier.modele.Lieu;
import static metier.service.ServiceTechnique.mailEvenementPlanifie;
import static util.GeoTest.getLatLng;

public class ServiceMetier {
    
    /**
     *Service non utilisé permettant la suppression d'un événement
     * @param idEvenement
     */
    public static void supprimerEvenement(int idEvenement) {
        EvenementDao evenementManager = new EvenementDao();
        
        JpaUtil.creerEntityManager();

        Evenement evenement;
        try {          
            evenement = evenementManager.findById(idEvenement); 
 
            ouvrirTransaction();
            evenementManager.delete(evenement);
            validerTransaction();
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            annulerTransaction();
        }
        
        JpaUtil.fermerEntityManager();
    } 

    /**
     *Service de création d'un adhérent grâce à son nom, prénom, adresse, mail
     * @param nom
     * @param prenom
     * @param adresse
     * @param mail

     */
    public static void creerAdherent(String nom, String prenom, String adresse, String mail)
    {
        AdherentDao adherentManager = new AdherentDao();
        boolean mailExist=true;
        Adherent nouvelAdherent = null;
        JpaUtil.creerEntityManager();
        
        try {          
            mailExist = adherentManager.mailExist(mail);
        } catch (Throwable ex) {
           ex.printStackTrace();
           ServiceTechnique.mailInscriptionEchec(mail,prenom);
           
        }
       
        
        if(mailExist){
            ServiceTechnique.mailInscriptionEchec(mail,prenom);
        }
        else {
            nouvelAdherent = new Adherent(nom,  prenom,  adresse,  mail);
           LatLng latLng = getLatLng(adresse);
           if(latLng!=null)
           nouvelAdherent.setCoordonnees(latLng);

           try {
              JpaUtil.ouvrirTransaction();
              adherentManager.create(nouvelAdherent);
              JpaUtil.validerTransaction();
              
              ServiceTechnique.mailInscriptionSucces(nouvelAdherent);
          } catch (Throwable ex) {
              ex.printStackTrace();
              ServiceTechnique.mailInscriptionEchec(mail,prenom);
              annulerTransaction();
          }
        }
        JpaUtil.fermerEntityManager();
    }

    /**
     *Service permettant d'obetnir une liste de lieux susceptibles d'accueillir l'évenement passé en paramètre 
     * @param evenement
     * @return
     */
    public static List<Lieu> obtenirLieux(Evenement evenement)  {
        LieuDao LieuManager = new LieuDao();
	TypeLieuDao TLManager = new TypeLieuDao();
	JpaUtil.creerEntityManager();
	List<Lieu> lieux = null;
	try{
		lieux = LieuManager.findByDescription(TLManager.findByActivite(evenement.getActivite()));
	} catch (Throwable ex) {
        	Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            
        }
	JpaUtil.fermerEntityManager();
	return lieux;
    }
   
    /**
     *Service de connexion qui permet de sélectionner un adhérent grâce à son mail, si le retour es null c'est que l'adresse mail est invalide 
     * Sinon la session sera identifiée par l'adhérent retourné. 
     * @param mail
     * @return
     */
    public static Adherent selectAdherentByMail(String mail)
    {
        AdherentDao adherentManager = new AdherentDao();
        Adherent adherent = null;
        JpaUtil.creerEntityManager();

        try {
            
            adherent = adherentManager.findByMail(mail);
            
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            
        }
        JpaUtil.fermerEntityManager();
        return adherent;
    }
    
    /**
     *Service permettant de savoir si un Mail existe
     * @param mail
     * @return
     */
    public static boolean MailExist(String mail)
    {
        AdherentDao adherentManager = new AdherentDao();
        boolean retour = false;
        
        JpaUtil.creerEntityManager();
        
        
        try {
           
            retour = adherentManager.mailExist(mail);
          
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
           
        }
        JpaUtil.fermerEntityManager();
        return retour;
    }
    
    /**
     *Service retournant l'ensemble des demandes effectuées par un adhérent dont l'id est passé en paramètre
     * Les demandes sont triées par ordre chronologique 
     * @param idAdh
     * @return
     */
    public static List<Demande> selectDemandeByIdAdherent(int idAdh)
    {
        DemandeDao demandeManager =new DemandeDao();
        List<Demande> listAdherents = null;
        
        JpaUtil.creerEntityManager();
        
        try {
            
            listAdherents = demandeManager.findByIdAdherent(idAdh);
            
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            
        }
        JpaUtil.fermerEntityManager();
        return listAdherents;
    }
    
    /**
     *Service renvoyant une liste de String des noms d'activité
     * Ce service est utilisable pour afficher les activités dans un menu déroulant par exemple
     * @return
     */
    public static List<String> AfficheNomActivites()
    {
        ActiviteDao activiteManager= new ActiviteDao();
        List<Activite> listAct = null;
        
        JpaUtil.creerEntityManager();

        try {
            
            listAct = activiteManager.findAll();
            
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
           
        }
        
        JpaUtil.fermerEntityManager();
        
        List<String> listNoms = new ArrayList();
        if(listAct!=null)
        {
            for (Activite listAct1 : listAct) {
                listNoms.add(listAct1.getDenomination());
            }
        }
        else
        {
            
            return null;
        }
      
        return listNoms;
    }

    /**
     *Service renvoyant une liste de String desstatuts
     * Ce service est utilisable pour afficher les statuts dans un menu déroulant par exemple
     * @return
     */
    public static List<String> AfficheStatut()
     {
         
         List<String> status=new ArrayList();
         status.add("A planifier");
         status.add("Non complet");
         status.add("Planifié");
         return status;
     }
    
    /**
     *Service renvoyant une liste de String des noms de Lieux
     * Ce service est utilisable pour afficher les lieux dans un menu déroulant par exemple
     * @return
     */
    public static List<String> AfficheNomLieux()
    {
        LieuDao LieuManager= new LieuDao();
        List<Lieu> listLieu = null;
        
        JpaUtil.creerEntityManager();
        
        try {
          
            listLieu = LieuManager.findAll();
            
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            
        }
        JpaUtil.fermerEntityManager();
        
        List<String> listNoms = new ArrayList();
        if(listLieu!=null)
        {
            for (Lieu listLieu1 : listLieu) {
                listNoms.add(listLieu1.getDenomination());
            }
        }
        else
        {
            
            return null;
        }

        return listNoms;
    } 
     
    /**
     *Service qui renvoie une liste des noms des adhérents dont le nom commente par "nom"
     * @param nom
     * @return
     */
    public static List<String> AfficheAdherentLike(String nom)
     {
         AdherentDao adherentManager = new AdherentDao();
         List<Adherent> listAdh=null;
         
         JpaUtil.creerEntityManager();
         
   
        try {
            
            listAdh=adherentManager.nameLike(nom);
        
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
       
        }
        JpaUtil.fermerEntityManager();
        List<String> listNoms = new ArrayList();
                if(listAdh!=null)
        {
             for (Adherent listAdh1 : listAdh) {
                 listNoms.add(listAdh1.getNom());
             }
        }
        else
        {
            
            return null;
        }
              
        return listNoms;
         
     }
     
    /**
     *Service permettant la création d'une demande 
     * Il vérifie tout d'abord si un événement existe déjà et correspond à la demande
     * Si c'est le cas l'adhérent est ajouté à la liste des participants
     * Sinon l'événement correspondant est créé et l'adhérent est le premier participant
     * @param activite
     * @param dateEvenement
     * @param idAdherent
     */
    public static void CreerDemande(String activite, Date dateEvenement, int idAdherent) 
     {
         DemandeDao demandeManager=new DemandeDao();
         ActiviteDao activiteManager=new ActiviteDao();
         AdherentDao adherentManager=new AdherentDao();
         EvenementDao evenementManager=new EvenementDao();
          Activite monActivite = null;
          
         JpaUtil.creerEntityManager();
         
        
        try {
            monActivite = activiteManager.findByName(activite);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
         Adherent monAdherent = null;
        try {
            monAdherent = adherentManager.findById(idAdherent);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
         
         //Recherche d'un evenement correspondant ou creation d'un nouvel evenement
         
         Evenement evenementDispo= null;
        try {
            evenementDispo = evenementManager.findEvenementbyActiviteDispo(monActivite, dateEvenement);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
         Evenement aEnvoyer;
         
         /* association Demande Evenement */
         if (evenementDispo!=null)
         {
             aEnvoyer=evenementDispo;
             if((aEnvoyer.incrementerParticipants())==monActivite.getNbParticipants())
             {
                 aEnvoyer.setStatut(0); // evenement à planifier
             }
             
             /* MAJ de l'evenement */
             if(monActivite.isParEquipe())
             {
                 aEnvoyer.getEquipeA().add(monAdherent);
             }
             else
             {
                 aEnvoyer.getParticipants().add(monAdherent);
             }
             
             try {
                 ouvrirTransaction();
                 evenementManager.update(aEnvoyer);
                 validerTransaction();
             } catch (Throwable ex) {
                 Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
                 annulerTransaction();
             }
         }
         else
         {
             if(monActivite.isParEquipe()){
                aEnvoyer=new EvenementParEquipe(monAdherent,dateEvenement,  1,  monActivite);    
             }
             else
             {
                 aEnvoyer=new EvenementSansEquipe( monAdherent,  dateEvenement,  1,  monActivite);
             }
             try {
                 /* persistence de evenement */
                 ouvrirTransaction();
                 evenementManager.create(aEnvoyer);
                 validerTransaction();
             } catch (Throwable ex) {
                 Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
                 annulerTransaction();
             }
         }
         
         /* creation demande */
         Demande maDemande =new Demande(new Date(), aEnvoyer,monActivite, monAdherent);
         
        try {
            /* persistence de demande*/
            ouvrirTransaction();
            demandeManager.create(maDemande);
            validerTransaction();
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
            annulerTransaction();
        }
         
         JpaUtil.fermerEntityManager();
  
     }
     
    /**
     *Service peermettant d'obtenir une liste d'événements correspondants aux différents filtres
     *Statut prend les valeurs A planifier Non complet ou Planifié, sa valeur par défaut est "Statut" ou n'importe quel autre String
     * Activite prend comme valeur le nom d'une activité et sa valeur par défaut est "Activité"
     * Lieu prend comme valeur le nom d'un lieu et sa valeur par défaut est "Lieu"
     * Date prend comme valeur la date de l'évenement recherché et sa valeur par défaut est 01/01/1970
     * Si les paramètres ont leurs valeurs par défaut alors ils ne sont pas pris en compte dans la requête
     * Si tous les paramètres sont par défaut, tous les événements sont retournés
     * @param statut
     * @param activite
     * @param lieu
     * @param date
     * @return
     */
    public static List<Evenement> AffichageEvenementsFiltres(String statut, String activite, String lieu,Date date){

         EvenementDao evenementManager = new EvenementDao();
         int stat = -3;
         switch (statut)//transformation du nom de statut en un int utilisable en jpql
         {
             case "A planifier" :
                 stat = 0;
                 break;
             case "Non complet":
                 stat = -1;
                 break;
             case "Planifié":
                 stat = 1;
                 break;
        
         }
        
        JpaUtil.creerEntityManager();
        List<Evenement> listEvenement = null; 
        try {
            
            listEvenement= evenementManager.findFiltered(stat,  activite,  lieu, date);
 
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
           
        }
        JpaUtil.fermerEntityManager();
        return listEvenement;
     }
     
    /**
     *Permet d'obtenir la liste des adhérents participants à un événement 
     * @param noEvent
     * @return
     */
    public static List<Adherent> AffichageDetail(long noEvent)
     {
         EvenementDao evtMan= new EvenementDao();
         Evenement evt = null;
         
         JpaUtil.creerEntityManager();
   
        try {
          
            evt = evtMan.findById(noEvent);
            
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
           
        }
         JpaUtil.fermerEntityManager();
         if(evt == null){
             return null;
         } else {
         }
         if (evt instanceof EvenementParEquipe)
         {
             List<Adherent> newList = new ArrayList() ;
             newList.addAll(evt.getEquipeA());
             newList.addAll(evt.getEquipeB());
             
             return newList;
         }
         else
         {
             return evt.getParticipants();
         }
     }
     
    /**
     *Permet d'obetnir l'événement grâce à son identifiant 
     * @param noEvenement
     * @return
     */
    public static Evenement getEvenement(long noEvenement)
     {
         EvenementDao evtMan= new EvenementDao();
         Evenement evt = null;
         
         JpaUtil.creerEntityManager();
         
        try {
            evt=evtMan.findById(noEvenement);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
         JpaUtil.fermerEntityManager();
         return evt;
     }
     
    /**
     *Service permettant de finaliser un événement, c'est à dire de lui attribuer un lieu et d'envoyer les mails 
     * Il affecte tout d'abord le lieu à l'événement puis change le statut de l'événement à "Planifié" (valeur 1)
     * Ensuite il envoie un mail à chacun des participants de l'événement
     * @param lieu
     * @param idEvt
     */
    public static void finaliserEvenement(String lieu, long idEvt)
     {
         EvenementDao evtMan= new EvenementDao();
         Evenement evt = null;
         LieuDao lieuDao=new LieuDao();
         Lieu li=null;
         JpaUtil.creerEntityManager();

         
         try {
            evt=evtMan.findById(idEvt);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            System.out.println("Recherche du lieu " + lieu + " affecter");
            li=lieuDao.findByName(lieu);
        } catch (Throwable ex) {
            Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
        }
        if((li!=null)&&(evt!=null))
        {
            evt.setStatut(1);//Evenement complet
            System.out.println("Affectation du lieu");
            evt.setLieu(li);
            JpaUtil.ouvrirTransaction();
             try {
                 evtMan.update(evt);
             } catch (Throwable ex) {
                 Logger.getLogger(ServiceMetier.class.getName()).log(Level.SEVERE, null, ex);
                 JpaUtil.annulerTransaction();
             }
             JpaUtil.validerTransaction();
        }
        if(evt instanceof EvenementParEquipe)
        {
            int nbeq=evt.getNombreParticipants()/2;
            for(int i=0;i<nbeq;i++)
            {
                evt.getEquipeB().add(evt.getEquipeA().get(i));
                evt.getEquipeA().remove(i);
                
            }
            for(Adherent a : evt.getEquipeA())
            {
                mailEvenementPlanifie(a,evt);
            }
            for(Adherent a : evt.getEquipeB())
            {
                mailEvenementPlanifie(a,evt);
            }
        }
        else
        {
            for(Adherent a: evt.getParticipants())
            {
                mailEvenementPlanifie(a,evt);
            }
        }
        
        JpaUtil.fermerEntityManager();
  
     }
    
}
