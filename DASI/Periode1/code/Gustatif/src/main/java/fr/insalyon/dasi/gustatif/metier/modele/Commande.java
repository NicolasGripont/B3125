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
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
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
    @Column(unique=true)
    private String numeroCommande;
    @Temporal(javax.persistence.TemporalType.DATE)
    private Date dateDebut;
    @Temporal(javax.persistence.TemporalType.DATE)
    private Date dateFin;
    @ManyToOne
    private Restaurant restaurant;
    @ManyToOne
    private Client client;
    @OneToMany(cascade = CascadeType.ALL)
    private List<LigneDeCommande> lignesDeCommande;
    @ManyToOne
    private Livreur livreur;
    
    
    public Commande() {
        this.lignesDeCommande = new ArrayList<>();
    }

    public Commande(String numeroCommande, Restaurant restaurant, Client client, Date dateDebut) {
        this.lignesDeCommande = new ArrayList<>();
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
    
    public Float getPoids() {
        Float poids = new Float(0.f);
        for(LigneDeCommande l : lignesDeCommande)
        {
            poids += l.getPoids();
        }
        return poids;
    }
    
    public Float getPrix() {
        Float prix = new Float(0.f);
        for(LigneDeCommande l : lignesDeCommande)
        {
            prix += l.getPrix();
        }
        return prix;
    }

    public List<LigneDeCommande> getLignesDeCommande() {
        return lignesDeCommande;
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
    
    public void addLigneDeCommande(Produit produit, Integer quantite) {
        this.lignesDeCommande.add(new LigneDeCommande(produit,quantite));
    }
    
    @Override
    public String toString() {
        return "Commande{ id=" + id + ", numeroCommande=" + numeroCommande + ", dateDebut=" + dateDebut + ", dateFin=" + dateFin + ", client=[" + client + "], restaurant=[" + restaurant + "], lignesDeCommande=[" + lignesDeCommande + "], livreur=[" + livreur.getMail() + "]"+'}';
    }
}
