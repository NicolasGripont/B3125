/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.service;

import com.google.maps.model.LatLng;
import fr.insalyon.dasi.gustatif.dao.ClientDao;
import fr.insalyon.dasi.gustatif.dao.JpaUtil;
import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.util.GeoTest;

/**
 *
 * @author Nico
 */
public class ServiceMetier {
 
    public static boolean InscrireClient(String nom, String prenom, String adresse, String mail, String motDePasse)
    {
        boolean result = false;
        
        //aucun argument ne doit être égale à null
        if(nom != null && prenom != null && adresse != null && mail != null && motDePasse != null)
        {
            //tous les champs doivent être renseignés
            if(!nom.isEmpty() && !prenom.isEmpty() && !adresse.isEmpty() && !mail.isEmpty() && !motDePasse.isEmpty())
            {
                Client client = new Client(nom, prenom, adresse, mail, motDePasse);

                try {
                    JpaUtil.creerEntityManager();
                    
                    ClientDao clientDao = new ClientDao();

                    //Si le mail n'est pas deja utilisé
                    if(clientDao.findByMail(mail) == null)
                    {
                        LatLng latLng = GeoTest.getLatLng(adresse);

                        //adresse invalide car ne permet pas de calculer une LatLng
                        if(latLng != null) {
                            client.setCoordonnees(latLng);
                            
                            JpaUtil.ouvrirTransaction();
                            clientDao.create(client);
                            JpaUtil.validerTransaction();
                            
                            result = true;
                        }
                    }
                } catch(Throwable e) {
                    JpaUtil.annulerTransaction();
                } finally {
                    JpaUtil.fermerEntityManager();
                }
            }
        }
        
        //tester le mail
       
        // envoi du mail
        if(result)
        {
            //envoyer mail succes
        } else {
            //envoyer mail echec
        }
        
        return result;
    }
    
    public static boolean IdentifierClient(String mail, String motDePasse) {
        boolean result = false;
        
        //aucun argument ne doit être égale à null
        if(mail != null && motDePasse != null)
        {
            //tous les champs doivent être renseignés
            if(!mail.isEmpty() && !motDePasse.isEmpty())
            {
                ClientDao clientDao = new ClientDao();
                
                 try {
                    JpaUtil.creerEntityManager();
                    //si le client existe en BD
                    if(clientDao.findByMailAndPassword(mail, motDePasse) != null)
                    {
                        result = true;
                    }
                } catch(Throwable e) {
                    
                } finally {
                    JpaUtil.fermerEntityManager();
                }
            }
        }
        
        return result;
    }

    
    
    
}
