package fr.insalyon.dasi.gustatif.dao;

import fr.insalyon.dasi.gustatif.metier.modele.Client;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.Query;


public class ClientDao {
    
    public void create(Client client) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            em.persist(client);
        }
        catch(Exception e) {
            throw e;
        }
    }
    
    public Client update(Client client) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        try {
            client = em.merge(client);
        }
        catch(Exception e){
            throw e;
        }
        return client;
    }
    
    public Client findById(Long id) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        Client client = null;
        try {
            client = em.find(Client.class, id);
        }
        catch(Exception e) {
            throw e;
        }
        return client;
    }
    
    public Client findByMailAndPassword(String mail, String password) 
            throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Client> clients = null;
        Client c = null;
        try {
            Query q = em.createQuery("SELECT c FROM Client c WHERE c.mail = "
                    + ":mail AND c.motDePasse = :password");
            q.setParameter("mail", mail);
            q.setParameter("password", password);
            clients = (List<Client>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        try {
            c = clients.get(0);
        } catch (Exception e){
        }
        return c;
    }
    
    public Client findByMail(String mail) throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Client> clients = null;
        Client c = null;
        try {
            Query q = em.createQuery("SELECT c FROM Client c "
                    + "WHERE c.mail = :mail");
            q.setParameter("mail", mail);
            clients = (List<Client>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }
        try {
            c = clients.get(0);
        } catch (Exception e){
        }
        return c;
    }
    
    public List<Client> findAll() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<Client> clients = null;
        try {
            Query q = em.createQuery("SELECT c FROM Client c ORDER BY c.nom");
            clients = (List<Client>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return clients;
    }
}
