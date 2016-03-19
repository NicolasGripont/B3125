package fr.insalyon.dasi.gustatif.dao;

import fr.insalyon.dasi.gustatif.metier.modele.Commande;
import fr.insalyon.dasi.gustatif.metier.modele.LigneDeCommande;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Nico
 */
public class LigneDeCommandeDao {
    
    public void create(LigneDeCommande ligneDeCommande) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            em.persist(ligneDeCommande);
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    public LigneDeCommande update(LigneDeCommande ligneDeCommande) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            ligneDeCommande = em.merge(ligneDeCommande);
        }
        catch(Exception e){
            throw e;
        }
        return ligneDeCommande;
    }
    
    public LigneDeCommande findById(Long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        LigneDeCommande ligneDeCommande = null;
        try {
            ligneDeCommande = em.find(LigneDeCommande.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        return ligneDeCommande;
    }
    
    public List<LigneDeCommande> findByCommandeID(Long commandeId) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LigneDeCommande> lignesDeCommande = null;
        
        try {
            Commande c = em.find(Commande.class, commandeId);
            if(c != null)
            {
                lignesDeCommande = c.getLignesDeCommande();
                if(lignesDeCommande.isEmpty())
                {
                    lignesDeCommande = null;
                }
            }
        }
        catch(Exception e) {
            throw e;
        }
        return lignesDeCommande;
    }
    
    public List<LigneDeCommande> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LigneDeCommande> lignesDeCommande = null;
        try {
            Query q = em.createQuery("SELECT l FROM LigneDeCommande l");
            lignesDeCommande = (List<LigneDeCommande>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return lignesDeCommande;
    }
}
