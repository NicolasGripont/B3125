/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;
import metier.modele.Activite;


public class ActiviteDao {

    /**
     *Permet la persistance d'une nouvelle activité
     * @param activite
     * @throws Throwable
     */
    public void create(Activite activite) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();        
        try {
            
            em.persist(activite);
             
        }
        catch(Exception e) {
            
            throw e;
        }
        //
    }
    
    /**
     *Permet la mise à jour dans la base d'une activité
     * @param activite
     * @return 
     * @throws Throwable
     */
    public Activite update(Activite activite) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            
            activite = em.merge(activite);
            
        }
        catch(Exception e){
            
            throw e;
        }
        //
        return activite;
    }
    
    /**
     *Permet de trouver une activite possedant l'identifiant passe en parametre
     * @param id
     * @return 
     * @throws Throwable
     */
    public Activite findById(long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Activite activite = null;
        try {
            activite = em.find(Activite.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        //
        return activite;
    }
    
    /**
     *Permet de trouver une activité grâce à sa dénomination
     * @param name
     * @return
     * @throws Throwable
     */
    public Activite findByName(String name) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Activite> activite;
        try {
            Query q = em.createQuery("SELECT a FROM Activite a where a.denomination =:name" );
            q.setParameter("name",name);
            activite = (List<Activite>) q.getResultList();
            if(!activite.isEmpty())
            {
                //
              return activite.get(0);
            }
            else
            {
                //
                return null;
            }
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    /**
     *Renvoie toutes les activités stockées triées par ordre alphabétique
     * @return
     * @throws Throwable
     */
    public List<Activite> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Activite> activites = null;
        try {
            Query q = em.createQuery("SELECT a FROM Activite a ORDER BY a.denomination");
            activites = (List<Activite>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        //
        return activites;
    }
}
