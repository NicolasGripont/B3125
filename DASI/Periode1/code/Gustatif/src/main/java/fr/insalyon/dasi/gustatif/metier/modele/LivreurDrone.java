/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import javax.persistence.Column;
import javax.persistence.Entity;

/**
 *
 * @author Nico
 */
@Entity
public class LivreurDrone extends Livreur{
    @Column(nullable = false)
    private Double vitesseMoyenneDeVolEnKmH; // en km/h
    
    public LivreurDrone() {
    }

    public LivreurDrone(Double vitesseMoyenneDeVolEnKmH, String mail, 
            String motDePasse, String adresse, Double chargeMaxEnGrammes) {
        super(mail, motDePasse, adresse, chargeMaxEnGrammes);
        this.vitesseMoyenneDeVolEnKmH = vitesseMoyenneDeVolEnKmH;
    }
    
    
    
    public Double getVitesseMoyenneDeVolEnKmH() {
        return vitesseMoyenneDeVolEnKmH;
    }
    
    public void setVitesseMoyenneDeVolEnKmH(Double vitesseMoyenneDeVolEnKmH) {
        this.vitesseMoyenneDeVolEnKmH = vitesseMoyenneDeVolEnKmH;
    }
    
    @Override
    public String toString() {
        return "LivreurDrone{" + super.toString() 
                + ", vitesseMoyenneDeVolEnKmH=" 
                + vitesseMoyenneDeVolEnKmH + '}';
    }
}
