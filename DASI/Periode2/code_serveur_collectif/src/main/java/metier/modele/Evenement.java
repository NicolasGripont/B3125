/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier.modele;

import java.io.Serializable;
import java.util.Date;
import java.util.List;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Temporal;


@Entity
public class Evenement implements Serializable  {

    /**
     *
     */
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    protected Long id;

    /**
     *
     */
    @Temporal(javax.persistence.TemporalType.DATE)
    protected Date dateEvenement;

    /**
     *
     */
    protected int nombreParticipants;

    /**
     *
     */
    @ManyToOne
    @JoinColumn(nullable = true)
    protected Lieu lieu;

    /**
     *
     */
    @ManyToOne
    @JoinColumn(nullable = false)
    protected Activite activite;

    /**
     *-1 non complet, 0 à planifier , 1 planifié
     */
    protected int statut; 

    /**
     *Constructeur par défaut de Evenement 
     */
    public Evenement ()
    {
        
    } 

    /**
     *Constructeur de évenement, lieu est défini à null par défaut et statut à -1
     * @param dateEvenement
     * @param nombreParticipants
     * @param activite
     */
    public Evenement (Date dateEvenement, int nombreParticipants,  Activite activite)
    {
        this.dateEvenement=dateEvenement;
        this.nombreParticipants=nombreParticipants;
        this.lieu=null;
        this.activite=activite;
        this.statut=-1;
    } 
    
    /**
     *
     * @return
     */
    public int getStatut() {
        return statut;
    }

    /**
     *
     * @param statut
     */
    public void setStatut(int statut) {
        this.statut = statut;
    }
    
    /**
     *
     * @return
     */
    public Lieu getLieu() {
        return lieu;
    }

    /**
     *
     * @param lieu
     */
    public void setLieu(Lieu lieu) {
        this.lieu = lieu;
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
    
    /**
     *
     * @param id
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     *
     * @param dateEvenement
     */
    public void setDateEvenement(Date dateEvenement) {
        this.dateEvenement = dateEvenement;
    }

    /**
     *
     * @param nombreParticipants
     */
    public void setNombreParticipants(int nombreParticipants) {
        this.nombreParticipants = nombreParticipants;
    }

    /**
     *
     * @return
     */
    public int incrementerParticipants(){
        return ++nombreParticipants;
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
     * @return
     */
    public Date getDateEvenement() {
        return dateEvenement;
    }

    /**
     *
     * @return
     */
    public int getNombreParticipants() {
        return nombreParticipants;
    }

    /**
     *Permet de redéfinir la méthode 
     * @return
     */
    public  List<Adherent> getParticipants(){return null;}

    /**
     *Permet de redéfinir la méthode
     * @return
     */
    public  List<Adherent> getEquipeA(){return null;}

    /**
     *Permet de redéfinir la méthode
     * @return
     */
    public  List<Adherent> getEquipeB(){return null;}
    
    @Override
    public String toString()
    {
        return("Evenement id : "+id);
    }
}
