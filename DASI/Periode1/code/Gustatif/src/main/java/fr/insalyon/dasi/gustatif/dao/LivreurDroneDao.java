package fr.insalyon.dasi.gustatif.dao;

import fr.insalyon.dasi.gustatif.metier.modele.LivreurDrone;
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
public class LivreurDroneDao extends LivreurDao {
            
    public List<LivreurDrone> findAllLivreursDrones() throws Throwable {
        EntityManager em = JpaUtil.obtenirEntityManager();
        List<LivreurDrone> livreurs = null;
        try {
            Query q = em.createQuery("SELECT l FROM LivreurDrone l");
            livreurs = (List<LivreurDrone>) q.getResultList();
        }
        catch(Exception e) {
            throw e;
        }     
        return livreurs;
    }
    
}
