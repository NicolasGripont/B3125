/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Temporal;

/**
 *
 * @author Nico
 */
@Entity
public class Commande implements Serializable{
  
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String numeroCommande;
    @Temporal(javax.persistence.TemporalType.DATE)
    private Date dateDebut;
    @Temporal(javax.persistence.TemporalType.DATE)
    private Date dateFin;

    public Commande() {
    }

    public Commande(String numeroCommande, Date dateDebut) {
        this.numeroCommande = numeroCommande;
        this.dateDebut = dateDebut;
    }
    
    
    public Commande(String numeroCommande, Date dateDebut, Date dateFin) {
        this.numeroCommande = numeroCommande;
        this.dateDebut = dateDebut;
        this.dateFin = dateFin;
    }
    
    public String getNumeroCommande() {
        return numeroCommande;
    }

    public Date getDateDebut() {
        return dateDebut;
    }

    public Date getDateFin() {
        return dateFin;
    }
    
    public void setNumeroCommande(String numeroCommande) {
        this.numeroCommande = numeroCommande;
    }

    public void setDateDebut(Date dateDebut) {
        this.dateDebut = dateDebut;
    }
    
    public void setDateFin(Date dateFin) {
        this.dateFin = dateFin;
    }
    
    @Override
    public String toString() {
        return "Commande{" + "numeroCommande=" + numeroCommande + ", dateDebut=" + dateDebut + ", dateFin=" + dateFin + '}';
    }
}
