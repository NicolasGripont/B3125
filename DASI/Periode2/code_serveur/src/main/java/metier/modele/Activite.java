/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier.modele;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Activite implements Serializable  {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String denomination;
    private Boolean parEquipe;
    private Integer nbParticipants;

    /**
     *Constructeur par défaut d'activité
     */
    public Activite() {
    }

    /**
     *Constructeur d'activite
     * @param denomination
     * @param parEquipe
     * @param nbParticipants
     */
    public Activite(String denomination, Boolean parEquipe, Integer nbParticipants) {
        this.denomination = denomination;
        this.parEquipe = parEquipe;
        this.nbParticipants = nbParticipants;
    }

    /**
     *
     * @return
     */
    public long getId() {
        return id;
    }

    /**
     *
     * @return
     */
    public String getDenomination() {
        return denomination;
    }

    /**
     *
     * @return
     */
    public Boolean isParEquipe() {
        return parEquipe;
    }

    /**
     *
     * @return
     */
    public Integer getNbParticipants() {
        return nbParticipants;
    }

    /**
     *
     * @param denomination
     */
    public void setDenomination(String denomination) {
        this.denomination = denomination;
    }

    /**
     *
     * @param parEquipe
     */
    public void setParEquipe(Boolean parEquipe) {
        this.parEquipe = parEquipe;
    }

    /**
     *
     * @param nbParticipants
     */
    public void setNbParticipants(Integer nbParticipants) {
        this.nbParticipants = nbParticipants;
    }

    @Override
    public String toString() {
        return "Activite{" + "id=" + id + ", denomination=" + denomination + ", parEquipe=" + parEquipe + ", nbParticipants=" + nbParticipants + '}';
    }
       
}
