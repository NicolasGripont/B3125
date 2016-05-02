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


public class AdherentDao {

    /**
     *Permet de persister un nouvel adhérent 
     * @param adherent
     * @throws Throwable
     */
    public void create(Adherent adherent) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
          
            em.persist(adherent);
               
        }
        catch(Exception e) {
        
            throw e;
        }
        //
    }
    
    /**
     *Permet de mettre à jour un adhérent 
     * @param adherent
     * @return
     * @throws Throwable
     */
    public Adherent update(Adherent adherent) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
          
            adherent = em.merge(adherent);
           
        }
        catch(Exception e){
            
            throw e;
        }
        //
        return adherent;
    }
    
    /**
     *Renvoie un adhérent dont l'identifiant est celui passé en parametre 
     * @param id
     * @return
     * @throws Throwable
     */
    public Adherent findById(long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Adherent adherent = null;
        try {
            adherent = em.find(Adherent.class, id);
       
        }
        catch(Exception e) {
            throw e;
        }
        
        return adherent;
    }
    
    /**
     *Retourne tous les adhérents stockés triés par ordre alphabétique sur le nom puis sur le prénom
     * @return
     * @throws Throwable
     */
    public List<Adherent> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Adherent> adherents = null;
        try {
            Query q = em.createQuery("SELECT a FROM Adherent a ORDER BY a.nom,a.prenom");
            adherents = (List<Adherent>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        //
        return adherents;
    }

    /**
     *Renvoie l'adhérent dont le mail est celui passé en paramètre. 
     * La méthode ne renvoie qu'un adhérent car pour chaque ajout d'adhérent on vérifie qu'il ne duplique pas un mail existant 
     * @param mail
     * @return
     * @throws Throwable
     */
    public Adherent findByMail(String mail) throws Throwable {
                EntityManager em = JpaUtil.obtenirEntityManager();
                List<Adherent> adherents = null;
        try {
            Query q = em.createQuery("SELECT a FROM Adherent a where a.mail =:mail" );
            q.setParameter("mail",mail);
            adherents = (List<Adherent>) q.getResultList();
            if(!adherents.isEmpty())
            {
                //
             return adherents.get(0);
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
     *Renvoie une liste d'adhérent triée par alphabétique des adhérents dont le nom commence par la String passée en paramètre 
     * @param name
     * @return
     * @throws Throwable
     */
    public List<Adherent> nameLike(String name) throws Throwable {
                EntityManager em = JpaUtil.obtenirEntityManager();
                List<Adherent> adherents = null;
        try {
            Query q = em.createQuery("SELECT a FROM Adherent a where a.nom LIKE :name ORDER BY a.nom, a.prenom" );
            q.setParameter("name",name+"%");
            adherents = (List<Adherent>) q.getResultList();
            //
            return adherents;
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    /**
     *Permet de retourner l'adhérent dont le nom est passé en paramètre 
     * @param name
     * @return
     * @throws Throwable
     */
    public Adherent findByName(String name) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Adherent> adherent;
        try {
            Query q = em.createQuery("SELECT a FROM Adherent a where a.nom =:name" );
            q.setParameter("name",name);
            adherent = (List<Adherent>) q.getResultList();
            if(!adherent.isEmpty())
            {
                //
            return adherent.get(0);
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
     *Vérifie l'existence d'un adhérent avec le mail passé en paramètre
     * Retourne true s'il existe false sinon 
     * @param mail
     * @return
     * @throws Throwable
     */
    public boolean mailExist(String mail) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            Query q = em.createQuery("SELECT count(a) FROM Adherent a where a.mail =:mail" );
            q.setParameter("mail",mail);
            long nb = (long) q.getSingleResult();
            //
            return nb !=0;
        }
        catch(Exception e) {
            throw e;
        }
        
        
    }
}