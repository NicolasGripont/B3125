/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.dao;

import fr.insalyon.dasi.gustatif.metier.modele.Livreur;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;

/**
 *
 * @author Nico
 */
public class LivreurDao {
    public void create(Livreur livreur) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            em.persist(livreur);
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    public Livreur update(Livreur livreur) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            livreur = em.merge(livreur);
        }
        catch(Exception e){
            throw e;
        }
        return livreur;
    }
    
    public Livreur findById(Long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Livreur livreur = null;
        try {
            livreur = em.find(Livreur.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        return livreur;
    }
    
    public Livreur findByMailAndPassword(String mail, String password) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Livreur> livreurs = null;
        Livreur c = null;
        try {
//            Query q = em.createQuery("SELECT l FROM Livreur l WHERE l.mail = '" + mail + "' AND l.motDePasse = '" + password + "'");
            Query q = em.createQuery("SELECT l FROM Livreur l WHERE l.mail = :mail AND l.motDePasse = :password");
            q.setParameter("mail", mail);
            q.setParameter("password", password);
            livreurs = (List<Livreur>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        try {
            c = livreurs.get(0);
        } catch (Exception e){
        }
        return c;
    }
    
    public List<Livreur> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Livreur> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM Livreur l");
            livreurs = (List<Livreur>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
    
    public List<Livreur> findAllDisponible() throws Throwable
    {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Livreur> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM Livreur l WHERE l.disponible = TRUE");
            livreurs = (List<Livreur>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
    
    public List<Livreur> findAllDisponible(Double commandeWeight) throws Throwable
    {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Livreur> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM Livreur l WHERE l.disponible = TRUE AND l.chargeMaxEnGrammes >= :commandeWeight");
            q.setParameter("commandeWeight", commandeWeight);
            livreurs = (List<Livreur>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
}
