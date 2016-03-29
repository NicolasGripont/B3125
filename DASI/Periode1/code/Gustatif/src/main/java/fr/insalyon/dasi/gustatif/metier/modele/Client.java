package fr.insalyon.dasi.gustatif.metier.modele;

import com.google.maps.model.LatLng;
import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Client implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    @Column(nullable = false)
    private String nom;
    @Column(nullable = false)
    private String prenom;
    @Column(nullable = false,unique = true)
    private String mail;
    @Column(nullable = false)
    private String motDePasse;
    @Column(nullable = false)
    private String adresse;
    @Column(nullable = false)
    private String telephone;
    @Column(nullable = false)
    private Double longitude;
    @Column(nullable = false)
    private Double latitude;

    public Client() {
    }

    public Client(String nom, String prenom, String adresse, String mail, String motDePasse, String telephone) {
        this.nom = nom;
        this.prenom = prenom;
        this.mail = mail;
        this.adresse = adresse;
        this.motDePasse = motDePasse;
        this.telephone = telephone;
    }

    public Long getId() {
        return id;
    }

    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public String getMail() {
        return mail;
    }

    public String getMotDePasse() {
        return motDePasse;
    }

    public String getTelephone() {
        return telephone;
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
    
    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public void setMotDePasse(String motDePasse) {
        this.motDePasse = motDePasse;
    }

    public void setTelephone(String telephone) {
        this.telephone = telephone;
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
        return "Client{" + "id=" + id + ", nom=" + nom + ", prenom=" + prenom + ", mail=" + mail + ", motDePasse=" + motDePasse + ", telephone=" + telephone + ", adresse=" + adresse + ", longitude=" + longitude + ", latitude=" + latitude + '}';
    }

}
