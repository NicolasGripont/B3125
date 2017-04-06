/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;
import metier.modele.Lieu;


public class LieuDao {

    /**
     *Permet de persister un lieu
     * @param lieu
     * @throws Throwable
     */
    public void create(Lieu lieu) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
           
            em.persist(lieu);
             
        }
        catch(Exception e) {
     
            throw e;
        }
        
    }
    
    /**
     *Permet de mettre à jour un lieu
     * @param lieu
     * @return
     * @throws Throwable
     */
    public Lieu update(Lieu lieu) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            
            lieu = em.merge(lieu);
            
        }
        catch(Exception e){
        
            throw e;
        }
       
        return lieu;
    }
    
    /**
     *Retourne le lieu dont la dénomination est le nom passé en paramètre 
     * @param name
     * @return
     * @throws Throwable
     */
    public Lieu findByName(String name) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Lieu> lieu;
        try {
            Query q = em.createQuery("SELECT a FROM Lieu a where a.denomination =:name " );
            q.setParameter("name",name);
            lieu = (List<Lieu>) q.getResultList();
            if(!lieu.isEmpty())
            {
                
                return lieu.get(0);
            }
            else
            {
                
                return null;
            }
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    /**
     *Renvoie le lieu identifié par son id 
     * @param id
     * @return
     * @throws Throwable
     */
    public Lieu findById(int id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Lieu lieu = null;
        try {
            lieu = em.find(Lieu.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        
        return lieu;
    }
    
    /**
     *Renvoei l'ensemble des lieux triés par odre alphabétique 
     * @return
     * @throws Throwable
     */
    public List<Lieu> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Lieu> lieux = null;
        try {
            Query q = em.createQuery("SELECT l FROM Lieu l ORDER BY l.denomination");
            lieux = (List<Lieu>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        
        return lieux;
    }

    /**
     *Permet de renvoyer les lieux dont la description correspond à celle passée en paramètre, triés par ordre alphabétique
     * @param description
     * @return
     * @throws Throwable
     */
    public List<Lieu> findByDescription(String description) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Lieu> lieu = null;
        try {
            Query q = em.createQuery("SELECT l FROM Lieu l WHERE l.description=:description ORDER BY l.denomination");
	q.setParameter("description",description);
            lieu = (List<Lieu>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        
        return lieu;
    }
}
