/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import javax.persistence.Entity;

/**
 *
 * @author Nico
 */
@Entity
public class LivreurVelo extends Livreur{
    
    private String nom;
    private String prenom;
    
    
    public LivreurVelo() {   
    }

    public LivreurVelo(String nom, String prenom, String mail, String motDePasse, String adresse, Float chargeMax) {
        super(mail, motDePasse, adresse, chargeMax);
        this.nom = nom;
        this.prenom = prenom;
    }
    
    
    
    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }
    
    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }
    
    @Override
    public String toString() {
        return "LivreurDrone{" + super.toString() + ", nom=" + nom + ", prenom=" + prenom + '}';
    }
}
