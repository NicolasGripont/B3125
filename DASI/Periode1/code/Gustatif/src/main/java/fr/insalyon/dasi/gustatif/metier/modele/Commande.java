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
import javax.persistence.JoinColumn;
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
    @Column(nullable = false)
    @Temporal(javax.persistence.TemporalType.TIMESTAMP)
    private Date dateDebut;
    @Temporal(javax.persistence.TemporalType.TIMESTAMP)
    private Date dateFin;
//    @JoinColumn(nullable = false)
    @ManyToOne
    private Restaurant restaurant;
//    @JoinColumn(nullable = false)
    @ManyToOne
    private Client client;
//    @JoinColumn(nullable = false)
    @OneToMany(cascade = CascadeType.ALL)
    private List<LigneDeCommande> lignesDeCommande;
//    @JoinColumn(nullable = false)
    @ManyToOne
    private Livreur livreur;
    
    public Commande() {
        this.lignesDeCommande = new ArrayList<>();
    }

    public Commande(Restaurant restaurant, Client client) {
        this.lignesDeCommande = new ArrayList<>();
        this.restaurant = restaurant;
        this.client = client;
    }
    
    public Commande(Restaurant restaurant, Client client, Date dateDebut) {
        this.lignesDeCommande = new ArrayList<>();
        this.restaurant = restaurant;
        this.client = client;
        this.dateDebut = dateDebut;
    }
    
    
    public Long getId() {
        return id;
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
    
    public Double getPoidsEnGrammes() {
        Double poids = new Double(0.F);
        for(LigneDeCommande l : lignesDeCommande)
        {
            poids += l.getPoidsEnGrammes();
        }
        return poids;
    }
    
    public Double getPrix() {
        Double prix = new Double(0.F);
        for(LigneDeCommande l : lignesDeCommande)
        {
            prix += l.getPrix();
        }
        return prix;
    }

    public List<LigneDeCommande> getLignesDeCommande() {
        return lignesDeCommande;
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
    
    public void setLignesDeCommande(List<LigneDeCommande> lignesDeCommande) {
//        this.lignesDeCommande.add(new LigneDeCommande(produit,quantite));
        this.lignesDeCommande = lignesDeCommande;
    }
    
    @Override
    public String toString() {
        return "Commande{ id=" + id + ", dateDebut=" + dateDebut + ", dateFin=" + dateFin + ", client=[" + client + "], restaurant=[" + restaurant + "], lignesDeCommande=[" + lignesDeCommande + "], livreur=[" + livreur.getMail() + "]"+'}';
    }
}
