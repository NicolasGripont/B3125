/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

/**
 *
 * @author Nico
 */
public class LivreurDrone extends Livreur{
    
    private Float vitesseMoyenneDeVol;
    
    public LivreurDrone(){
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
