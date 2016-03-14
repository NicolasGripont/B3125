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
public class LivreurDrone extends Livreur{
    
    private Float vitesseMoyenneDeVol;

    public LivreurDrone() {
    }

    public LivreurDrone(Float vitesseMoyenneDeVol, String mail, String motDePasse, String adresse, Float chargeMax) {
        super(mail, motDePasse, adresse, chargeMax);
        this.vitesseMoyenneDeVol = vitesseMoyenneDeVol;
    }
    
    
    
    public float getVitesseMoyenneDeVol() {
        return vitesseMoyenneDeVol;
    }
    
    public void setVitesseMoyenneDeVol(Float vitesseMoyenneDeVol) {
        this.vitesseMoyenneDeVol = vitesseMoyenneDeVol;
    }
    
    @Override
    public String toString() {
        return "LivreurDrone{" + super.toString() + ", vitesseMoyenneDeVol=" + vitesseMoyenneDeVol + '}';
    }
}
