/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.service;

import fr.insalyon.dasi.gustatif.metier.modele.Client;
import fr.insalyon.dasi.gustatif.util.GeoTest;

/**
 *
 * @author Nico
 */
public class ServiceMetier {
 
    public static boolean InscriptionClient(String nom, String prenom, String adresse, String mail, String motDePasse)
    {
        Client client = new Client(nom, prenom, adresse, mail, motDePasse);
        
        GeoTest.getLatLng(adresse);
        
        return false;
    }
}
