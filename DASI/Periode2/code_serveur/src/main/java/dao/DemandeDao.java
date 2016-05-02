/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;
import metier.modele.Adherent;
import metier.modele.Demande;


public class DemandeDao {
    
    /**
     *Permet de persister une nouvelle demande
     * @param demande
     * @throws Throwable
     */
    public void create(Demande demande) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            
            em.persist(demande);
          
        }
        catch(Exception e) {
           
            throw e;
        }
        //
    }
    
    /**
     *Permet de mettre à jour une demande 
     * @param demande
     * @return
     * @throws Throwable
     */
    public Demande update(Demande demande) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();      
        try {
          
            demande = em.merge(demande);
            
        }
        catch(Exception e){
          
            throw e;
        }
        //
        return demande;
    }
    
    /**
     *Renvoie la demande dont l'id est passé en paramètre 
     * @param id
     * @return
     * @throws Throwable
     */
    public Demande findById(long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Demande demande = null;
        try {
            demande = em.find(Demande.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        //
        return demande;
    }
    
    /**
     *Renvoie l'ensemble des demandes 
     * @return
     * @throws Throwable
     */
    public List<Demande> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Demande> demandes = null;
        try {
            Query q = em.createQuery("SELECT a FROM Demande a ORDER BY a.dateDemande");
            demandes = (List<Demande>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        
        return demandes;
    }
    
    /**
     *Renvoie l'ensemble des demandes faites par un adhérent identifié par son numéro d'adhérent
     * @param idAdherent
     * @return
     * @throws Throwable
     */
    public List<Demande> findByIdAdherent(long idAdherent) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        AdherentDao adhMan=new AdherentDao();
        Adherent adh=adhMan.findById(idAdherent);
        List<Demande> demandes;
        try {
        Query q = em.createQuery("SELECT a FROM Demande a where a.adherent =:adherent ORDER BY a.dateDemande" );
        q.setParameter("adherent",adh);
        demandes = (List<Demande>) q.getResultList();
        //
        return demandes;
        }
        catch(Exception e) {
            throw e;
        }

    }
}