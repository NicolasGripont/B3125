/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.modele;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;

/**
 *
 * @author Nico
 */
@Entity
public class LigneDeCommande implements Serializable {
    
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    @ManyToOne
    private Produit produit;
    private Float quantite;
    
    public LigneDeCommande() {
    }
    
    public LigneDeCommande(Produit produit, Float quantite) {
        this.produit = produit;
        this.quantite = quantite;
    }

    public Produit getProduit() {
        return produit;
    }

    public Float getQuantite() {
        return quantite;
    }
    
    public Float getPrix() {
        if(produit != null) {
            return new Float(quantite * produit.getPrix());
        }
        return new Float(0.f);
    }
    
    public Float getPoids() {
        if(produit != null) {
            return new Float(quantite * produit.getPoids());
        }
        return new Float(0.f);
    }
    
    public Float getPrixUnitaire() {
        if(produit != null) {
            return new Float(produit.getPrix());
        }
        return new Float(0.f);
    }
    
    public Float getPoidsUnitaire() {
        if(produit != null) {
            return new Float(produit.getPoids());
        }
        return new Float(0.f);
    }
    
    public void setProduit(Produit produit) {
        this.produit = produit;
    }

    public void setQuantite(Float quantite) {
        this.quantite = quantite;
    }

    @Override
    public String toString() {
        return "LigneDeCommande{" + "id=" + id + ", produit=[" + produit + "], quantite=" + quantite + '}';
    }
    
}
