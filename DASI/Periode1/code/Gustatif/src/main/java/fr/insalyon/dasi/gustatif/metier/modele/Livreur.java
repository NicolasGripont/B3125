/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import com.google.maps.model.LatLng;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Inheritance;
import javax.persistence.InheritanceType;
import javax.persistence.OneToMany;
import javax.persistence.OrderBy;

/**
 *
 * @author Nico
 */
@Entity
@Inheritance (strategy = InheritanceType.JOINED)
public abstract class Livreur implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String mail;
    private String motDePasse;
    private String adresse;
    private Double longitude;
    private Double latitude;
//    @Column(nullable = false)
    private Double chargeMaxEnGrammes;
    private Boolean disponible;
    @OneToMany(mappedBy = "livreur")
    @OrderBy("dateDebut DESC")
    private List<Commande> commandes;
    
    public Livreur(){
        this.commandes = new ArrayList<>();
    }

    public Livreur(String mail, String motDePasse, String adresse, Double chargeMaxEnGrammes) {
        this.commandes = new ArrayList<>();
        this.mail = mail;
        this.motDePasse = motDePasse;
        this.adresse = adresse;
        this.chargeMaxEnGrammes = chargeMaxEnGrammes;
        this.disponible = true;
    }
    
    public Long getId() {
        return id;
    }
    
    public String getMail() {
        return mail;
    }
    
    public String getMotDePasse() {
        return motDePasse;
    }
    
    public String getAdresse() {
        return adresse;
    }

    public Double getLongitude() {
        return longitude;
    }

    public Double getLatitude() {
        return latitude;
    }
    
    public LatLng getLatLng() {
        return new LatLng(latitude, longitude);
    }
    
    public Double getChargeMaxEnGrammes() {
        return chargeMaxEnGrammes;
    }

    public List<Commande> getCommandes() {
        return commandes;
    }

    public Boolean getDisponible() {
        return disponible;
    }
    
    public void setMail(String mail) {
        this.mail = mail;
    }
    
    public void setMotDePasse(String motDePasse) {
        this.motDePasse = motDePasse;
    }
    
    public void setAdresse(String adresse) {
        this.adresse = adresse;
    }

    public void setCoordonnees(LatLng latLng) {
        this.longitude = latLng.lng;
        this.latitude = latLng.lat;
    }
    
    public void setChargeMaxEnGrammes(Double chargeMaxEnGrammes) {
        this.chargeMaxEnGrammes = chargeMaxEnGrammes;
    }

    public void setDisponible(Boolean disponible) {
        this.disponible = disponible;
    }
    
    public void addCommande(Commande commande) {
        this.commandes.add(commande);
    }
    
    @Override
    public String toString() {
        return "Livreur{" + "id=" + id + ", mail=" + mail + ", motDePasse=" + motDePasse + ", adresse=" + adresse + ", longitude=" + longitude + ", latitude=" + latitude + ", chargeMaxEnGrammes=" + chargeMaxEnGrammes + ", disponible " + disponible +", commandes=[" + commandes + "]" + '}';
    }
}