/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.dao;

import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;

/**
 *
 * @author Nico
 */
public class CommandeDao {
        public void create(Commande commande) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            em.persist(commande);
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    public Commande update(Commande commande) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            commande = em.merge(commande);
        }
        catch(Exception e){
            throw e;
        }
        return commande;
    }
    
    public Commande findById(Long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Commande commande = null;
        try {
            commande = em.find(Commande.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        return commande;
    }
    
        
    public Commande findNotEndedByLivreur(Livreur livreur) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Commande commande = null;
        List<Commande> commandes = null;
        try {
            Query q = em.createQuery("SELECT c FROM Commande c WHERE c.dateFin IS NULL AND c.livreur = :livreur");
            
            q.setParameter("livreur", livreur);
            commandes = (List<Commande>) q.getResultList();
            if(!commandes.isEmpty()) {
                commande = commandes.get(0);
            }
        }
        catch(Exception e) {
            throw e;
        }     
        return commande;
    }
    
    public List<Commande> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Commande> commandes = null;
        try {
            Query q = em.createQuery("SELECT c FROM Commande c");
            commandes = (List<Commande>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return commandes;
    }
    
    public List<Commande> findByLivreurID(Long livreurId) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Commande> commandes = null;
        
        try {
            Livreur l = em.find(Livreur.class, livreurId);
            if(l != null)
            {
                commandes = l.getCommandes();
                if(commandes.isEmpty())
                {
                    commandes = null;
                }
            }
        }
        catch(Exception e) {
            throw e;
        }
        return commandes;
    }
    
    public List<Commande> findAllNotEnded() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Commande> commandes = null;
        try {
            Query q = em.createQuery("SELECT c FROM Commande c WHERE c.dateFin IS NULL");
            commandes = (List<Commande>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return commandes;
    }
}
