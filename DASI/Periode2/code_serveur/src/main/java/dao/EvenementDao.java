/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;
import metier.modele.Activite;
import metier.modele.Evenement;
import metier.modele.Lieu;


public class EvenementDao {

    /**
     *Permet de persister un événement
     * @param evenement
     * @throws Throwable
     */
    public void create(Evenement evenement) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            
            em.persist(evenement);
             
        }
        catch(Exception e) {
          
            throw e;
        }
        //
    }
    
    /**
     *Permet de mettre à jour un événement
     * @param evenement
     * @return
     * @throws Throwable
     */
    public Evenement update(Evenement evenement) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
       
            evenement = em.merge(evenement);
            
        }
        catch(Exception e){
          
            throw e;
        }
        //
        return evenement;
    }
    
    /**
     *Permet de supprimer un événénement
     * Cette méthode n'est pas utilisable à cause de l'absence d'implémentation de la contrainte "on delete set null" en JPA
     * @param evenement
     * @throws Throwable
     */
    public void delete(Evenement evenement) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
           
            em.remove(evenement);
            
        }
        catch(Exception e){
       
            throw e;
        }
        //
    }

    /**
     *Renvoie l'événement dont l'id est passé en paramètre 
     * @param id
     * @return
     * @throws Throwable
     */
    public Evenement findById(long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Evenement evenement = null;
        try {
            evenement = em.find(Evenement.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        //
        return evenement;
    }
    
    /**
     *Renvoie tous les événements stockés 
     * @return
     * @throws Throwable
     */
    public List<Evenement> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Evenement> evenements = null;
        try {
            Query q = em.createQuery("SELECT a FROM Evenement a ORDER BY a.dateEvenement");
            evenements = (List<Evenement>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        //
        return evenements;
    }
    
    /**
     *Renvoie un événement dont l'activité correspond à celle passée en paramètre et qui se déroule à la date choisie
     * Cet événement ne doit pas être complet, son statut est donc -1
     * @param activite
     * @param date
     * @return
     * @throws Throwable
     */
    public Evenement findEvenementbyActiviteDispo(Activite activite, Date date) throws Throwable {
    EntityManager em = JpaUtil.obtenirEntityManager();
    List<Evenement> evenements = null;
    try {
        int li=-1;
        Query q = em.createQuery("SELECT a FROM Evenement a WHERE a.activite=:activite AND a.dateEvenement=:date AND a.statut=:libre");
        q.setParameter("activite",activite);
        q.setParameter("date",date);
        q.setParameter("libre", li);
        evenements = (List<Evenement>) q.getResultList();
        
    }
    catch(Exception e) {
        throw e;
    }
    if(!evenements.isEmpty())
    {
        //
            return evenements.get(0);
    }
    //
       return null; 
    }
    
    /**
     *Permet de renvoyer l'ensemble des événements vérifiants un ensemble de critères passés en paramètre
     * L'événement doit être du statut précise, doit être associé à la bonne activité, au bon lieu et à la date souhaitée 
     * @param statut
     * @param activite
     * @param lieu
     * @param date
     * @return
     * @throws Throwable
     */
    public List<Evenement> findFiltered(int statut, String activite, String lieu,Date date) throws Throwable {
        
        EvenementDao evMan=new EvenementDao();
        ActiviteDao actMan=new ActiviteDao();
        Activite act = null;
        LieuDao lieuMan=new LieuDao();
        Lieu monlieu = null;
      

        List<Evenement> evenements;
        String requete = "SELECT a FROM Evenement a where '1'='1'";// la clause 1=1 permet de simplifier l'ajout de contraintes et assure la requete s'il n 'yen a pas
        if(statut >= -1 ){//Si la valeur n'est pas la valeur par défaut on ajoute le filtre 
            requete += " AND a.statut =:statut ";
        } 
        if(!activite.equals("Activité")){//Si la valeur n'est pas la valeur par défaut on ajoute le filtre 
            act=actMan.findByName(activite);
            requete+= "AND a.activite=:activite ";
        }
        if(!lieu.equals("Lieu")){//Si la valeur n'est pas la valeur par défaut on ajoute le filtre 
            monlieu=lieuMan.findByName(lieu);
            requete+= "AND a.lieu=:lieu ";
        }
        
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        if(!sdf.parse("01/01/1970").equals(date))//Si la valeur n'est pas la valeur par défaut on ajoute le filtre 
        {
            requete+= "AND a.dateEvenement=:date ";
        }
        
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
        Query q = em.createQuery(requete);
        
        
        if(statut >= -1 ){
            q.setParameter("statut",statut);
        } 
        if(!activite.equals("Activité")){
           q.setParameter("activite",act);
        }
        if(!lieu.equals("Lieu")){
            q.setParameter("lieu", monlieu);
        }
        if(!sdf.parse("01/01/1970").equals(date))
        {
            q.setParameter("date",date);
        }
        
        
        evenements = (List<Evenement>) q.getResultList();
        //
        return evenements;
        }
        catch(Exception e) {
            throw e;
        }

    }
        

}
