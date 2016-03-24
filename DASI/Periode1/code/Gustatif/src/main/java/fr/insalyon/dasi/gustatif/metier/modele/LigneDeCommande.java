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
    private Integer quantite;

    
    public LigneDeCommande() {
    }
    
    public LigneDeCommande(Produit produit, Integer quantite) {
        this.produit = produit;
        this.quantite = quantite;
    }
    
    public Long getId() {
        return id;
    }
    
    public Produit getProduit() {
        return produit;
    }

    public Integer getQuantite() {
        return quantite;
    }
    
    public Double getPrix() {
        if(produit != null) {
            return new Double(quantite * produit.getPrix());
        }
        return new Double(0.f);
    }
    
    public Double getPoidsEnGrammes() {
        if(produit != null) {
            return new Double(quantite * produit.getPoids());
        }
        return new Double(0.F);
    }
    
    public Double getPrixUnitaire() {
        if(produit != null) {
            return new Double(produit.getPrix());
        }
        return new Double(0.F);
    }
    
    public Double getPoidsUnitaireEnGrammes() {
        if(produit != null) {
            return new Double(produit.getPoids());
        }
        return new Double(0.F);
    }
    
    public void setProduit(Produit produit) {
        this.produit = produit;
    }

    public void setQuantite(Integer quantite) {
        this.quantite = quantite;
    }

    @Override
    public String toString() {
        return "LigneDeCommande{" + "id=" + id + ", produit=[" + produit + "], quantite=" + quantite + '}';
    }
    
}
