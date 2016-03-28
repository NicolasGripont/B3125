/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.dao;

import fr.insalyon.dasi.gustatif.metier.modele.LivreurVelo;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;

/**
 *
 * @author Nico
 */
public class LivreurVeloDao extends LivreurDao {
    
    public List<LivreurVelo> findAllLivreursVelos() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LivreurVelo> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM LivreurVelo l");
            livreurs = (List<LivreurVelo>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
        
    public List<LivreurVelo> findAllLivreursVelosDisponibles() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LivreurVelo> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM LivreurVelo l WHERE l.disponible = TRUE");
            livreurs = (List<LivreurVelo>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
    
    public List<LivreurVelo> findAllLivreursVelosDisponibles(Double commandeWeight) throws Throwable
    {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LivreurVelo> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM LivreurDrone l WHERE l.disponible = TRUE AND l.chargeMax >= :commandeWeight");
            q.setParameter("commandeWeight", commandeWeight);
            livreurs = (List<LivreurVelo>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
    
    public LivreurVelo findLivreurVeloByMailAndPassword(String mail, String password) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LivreurVelo> livreurs = null;
        LivreurVelo lv = null;
        try {
//            Query q = em.createQuery("SELECT l FROM LivreurVelo l WHERE l.mail = '" + mail + "' AND l.motDePasse = '" + password + "'");
            Query q = em.createQuery("SELECT l FROM LivreurVelo l WHERE l.mail = :mail AND l.motDePasse = :password");
            q.setParameter("mail", mail);
            q.setParameter("password", password);
            livreurs = (List<LivreurVelo>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        try {
            lv = livreurs.get(0);
        } catch (Exception e){
        }
        return lv;
    }
}
