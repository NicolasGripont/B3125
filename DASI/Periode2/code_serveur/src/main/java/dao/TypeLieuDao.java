
package dao;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;
import metier.modele.Activite;
import metier.modele.TypeLieu;

public class TypeLieuDao {

    /**
     *Permet de persister un type de lieu
     * @param typelieu
     * @throws Throwable
     */
    public void create(TypeLieu typelieu) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
           
            em.persist(typelieu);
             
        }
        catch(Exception e) {
     
            throw e;
        }
        
    }
    
    /**
     *Permet de mettre à jour un type de leieu
     * @param typelieu
     * @return
     * @throws Throwable
     */
    public TypeLieu update(TypeLieu typelieu) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            
            typelieu = em.merge(typelieu);
            
        }
        catch(Exception e){
        
            throw e;
        }
       
        return typelieu;
    }
    
    /**
     *Permet de trouver un type de lieu via sa description 
     * @param description
     * @return
     * @throws Throwable
     */
    public TypeLieu findByDescription(String description) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<TypeLieu> typelieu;
        try {
            Query q = em.createQuery("SELECT a FROM TypeLieu a where a.description =:description " );
            q.setParameter("description",description);
            typelieu = (List<TypeLieu>) q.getResultList();
            if(!typelieu.isEmpty())
            {
                
                return typelieu.get(0);
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
     *renvoie un type de lieu grâce à son id 
     * @param id
     * @return
     * @throws Throwable
     */
    public TypeLieu findById(int id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        TypeLieu typelieu = null;
        try {
            typelieu = em.find(TypeLieu.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        
        return typelieu;
    }
    
    /**
     *Renvoie l'ensemble des types de lieux triés par ordre alphabétique
     * @return
     * @throws Throwable
     */
    public List<TypeLieu> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<TypeLieu> typelieu = null;
        try {
            Query q = em.createQuery("SELECT l FROM TypeLieu l ORDER BY l.description");
            typelieu = (List<TypeLieu>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        
        return typelieu;
    }

    /**
     *Permet de renvoyer un type de lieu asocié à une activité 
     * @param activite
     * @return
     * @throws Throwable
     */
    public String findByActivite(Activite activite) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<String> typelieu = null;
        try {
            Query q = em.createQuery("SELECT l.description FROM TypeLieu l WHERE l.activite=:actId ");
	q.setParameter("actId",activite);
            typelieu = (List<String>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        
        return typelieu.get(0);
    }


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
}
