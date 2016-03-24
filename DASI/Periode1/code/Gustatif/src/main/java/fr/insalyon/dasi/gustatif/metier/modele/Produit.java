package fr.insalyon.dasi.gustatif.metier.modele;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Produit implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String denomination;
    private String description;
    private Double prix;
    private Double poidsEnGrammes;

    public Produit() {
    }

    public Produit(String denomination, String description, Double prix, Double poidsEnGrammes) {
        this.denomination = denomination;
        this.description = description;
        this.prix = prix;
        this.poidsEnGrammes = poidsEnGrammes;
    }

    public Long getId() {
        return id;
    }

    public String getDenomination() {
        return denomination;
    }

    public String getDescription() {
        return description;
    }

    public Double getPoids() {
        return poidsEnGrammes;
    }

    public Double getPrix() {
        return prix;
    }

    public void setPrix(Double prix) {
        this.prix = prix;
    }

    public void setDenomination(String denomination) {
        this.denomination = denomination;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setPoids(Double poidsEnGrammes) {
        this.poidsEnGrammes = poidsEnGrammes;
    }

    @Override
    public String toString() {
        return "Produit{" + "id=" + id + ", denomination=" + denomination + ", description=" + description + ", prix=" + prix + ", poids=" + poidsEnGrammes + '}';
    }
   
    
}
