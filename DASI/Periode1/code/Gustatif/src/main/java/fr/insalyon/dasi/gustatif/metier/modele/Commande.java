/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
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
    @ManyToOne
    private Restaurant restaurant;
    @ManyToOne
    private Client client;
    @ManyToMany
    private List<LigneDeCommande> lignesDeCommande = new ArrayList<>();
    @ManyToOne
    private Livreur livreur;
    
    
    public Commande() {
    }

    public Commande(String numeroCommande, Restaurant restaurant, Client client, Date dateDebut) {
        this.numeroCommande = numeroCommande;
        this.restaurant = restaurant;
        this.client = client;
        this.dateDebut = dateDebut;
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
    
    public Restaurant getRestaurant() {
        return restaurant;
    }
    
    public Client getClient() {
        return client;
    }

    public Livreur getLivreur() {
        return livreur;
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
    
    public void setRestaurant(Restaurant restaurant) {
        this.restaurant = restaurant;
    }
    
    public void setClient(Client client) {
        this.client = client;
    }
    
    public void setLivreur(Livreur livreur) {
        this.livreur = livreur;
    }
    
    public void addLigneDeCommande(Produit produit, Float quantite) {
        this.lignesDeCommande.add(new LigneDeCommande(produit,quantite));
    }
    
    @Override
    public String toString() {
        return "Commande{" + "numeroCommande=" + numeroCommande + ", dateDebut=" + dateDebut + ", dateFin=" + dateFin + "client=[" + client + "], restaurant=[" + restaurant + "], lignesDeCommande=[" + lignesDeCommande + "], livreur=[" + livreur + "]"+'}';
    }
}
