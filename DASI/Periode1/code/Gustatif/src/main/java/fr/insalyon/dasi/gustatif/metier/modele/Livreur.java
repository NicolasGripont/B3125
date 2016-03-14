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
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Inheritance;
import javax.persistence.InheritanceType;
import javax.persistence.OneToMany;

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
    private Float chargeMax;
    @OneToMany(mappedBy = "livreur")
    private List<Commande> commandes = new ArrayList<>();
    
    public Livreur(){
    }

    public Livreur(String mail, String motDePasse, String adresse, Float chargeMax) {
        this.mail = mail;
        this.motDePasse = motDePasse;
        this.adresse = adresse;
        this.chargeMax = chargeMax;
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
    
    public Float getChargeMax() {
        return chargeMax;
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
    
    public void setChargeMax(Float chargeMax) {
        this.chargeMax = chargeMax;
    }
    
    public void addCommande(Commande commande) {
        this.commandes.add(commande);
    }
    
    @Override
    public String toString() {
        return "Livreur{" + "id=" + id + ", mail=" + mail + ", motDePasse=" + motDePasse + ", adresse=" + adresse + ", longitude=" + longitude + ", latitude=" + latitude + ", chargeMax=" + chargeMax + ", commandes=[" + commandes + "]" + '}';
    }
}