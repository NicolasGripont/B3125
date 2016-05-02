/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier.modele;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Temporal;


@Entity
public class Demande implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    @Temporal(javax.persistence.TemporalType.DATE)
    private Date dateDemande;
    @ManyToOne
    @JoinColumn(nullable = false)
    private Evenement evenement;
    @ManyToOne
    @JoinColumn(nullable = false)
    private Activite activite;
    @ManyToOne
    @JoinColumn(nullable = false)
    private Adherent adherent;
    
    /**
     *Constructeur par défaut de demande 
     */
    public Demande(){
        
    }
    
    /**
     *Constructeur de demande 
     * @param dateDemande
     * @param evenement
     * @param activite
     * @param adherent
     */
    public Demande(Date dateDemande, Evenement evenement,Activite activite, Adherent adherent){
      
        this.dateDemande=dateDemande;
        this.evenement=evenement;
        this.activite=activite;
        this.adherent=adherent;
    }
    
    /**
     *
     * @return
     */
    public Long getId() {
        return id;
    }

    /**
     *
     * @param id
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     *
     * @return
     */
    public Date getDateDemande() {
        return dateDemande;
    }

    /**
     *
     * @param dateDemande
     */
    public void setDateDemande(Date dateDemande) {
        this.dateDemande = dateDemande;
    }

    /**
     *
     * @return
     */
    public Evenement getEvenement() {
        return evenement;
    }

    /**
     *
     * @param evenement
     */
    public void setEvenement(Evenement evenement) {
        this.evenement = evenement;
    }

    /**
     *
     * @return
     */
    public Activite getActivite() {
        return activite;
    }

    /**
     *
     * @param activite
     */
    public void setActivite(Activite activite) {
        this.activite = activite;
    }
   
    @Override
    public String toString(){
        return("Demande { id : "+id+"Activité : "+activite.getDenomination());
    }
}
