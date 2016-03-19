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
}
