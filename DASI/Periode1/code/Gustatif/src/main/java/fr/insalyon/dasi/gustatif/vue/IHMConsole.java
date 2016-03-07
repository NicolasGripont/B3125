/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.vue;

import fr.insalyon.dasi.gustatif.dao.ClientDao;
import fr.insalyon.dasi.gustatif.dao.JpaUtil;
import fr.insalyon.dasi.gustatif.metier.modele.Client;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Nico
 */
public class IHMConsole {
    
    public static void main(String[] args) {
    // TODO code application logic here    public static void main(String[] args) {
    // TODO code application logic here
        
        testClient();
        

    } 

    public static void testClient(){
        try{
            
            Client c1 = new Client("Nicolas", "Gripont","195 avenue Roger Salengro, 69100 Villeurbanne", "n.gripont@gmail.com","mdp");
            
            ClientDao cd = new ClientDao();

            System.out.println(c1);

            
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();
            cd.create(c1);
            JpaUtil.validerTransaction();
            
            Client c2 = cd.findByMailAndPassword("n.gripont@gmail.com", "mdp");
            
            System.out.println(c2);   
            
            JpaUtil.fermerEntityManager();
        } catch (Throwable ex) {
            Logger.getLogger(IHMConsole.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
