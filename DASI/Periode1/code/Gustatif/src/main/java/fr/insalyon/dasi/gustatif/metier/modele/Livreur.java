/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import com.google.maps.model.LatLng;
import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

/**
 *
 * @author Nico
 */
@Entity
public abstract class Livreur implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    protected Long id;
    protected String mail;
    protected String motDePasse;
    protected String adresse;
    protected Double longitude;
    protected Double latitude;
    protected float chargeMax;
    
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
    
    @Override
    public String toString() {
        return "Client{" + "id=" + id + ", mail=" + mail + ", motDePasse=" + motDePasse + ", adresse=" + adresse + ", longitude=" + longitude + ", latitude=" + latitude + '}';
    }
}