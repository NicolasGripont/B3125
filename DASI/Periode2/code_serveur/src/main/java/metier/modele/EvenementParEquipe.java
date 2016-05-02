/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier.modele;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.OneToMany;


@Entity
public class EvenementParEquipe extends Evenement {
    @OneToMany
    @JoinTable(name ="equipeA")
    private List<Adherent> equipeA;
    @OneToMany
   @JoinTable(name ="equipeB")
    private List<Adherent> equipeB;

    /**
     *Constructeur par défaut de EvenementParEquipe
     */
    public EvenementParEquipe(){
        
    }

    /**
     *Constructeur de EvenementParEquipe, l'adhérent est ajouté dans l'équipe A 
     * @param adherent
     * @param dateEvenement
     * @param nombreParticipants
     * @param activite
     */
    public EvenementParEquipe(Adherent adherent, Date dateEvenement, int nombreParticipants, Activite activite) {
    super( dateEvenement,  nombreParticipants,   activite);
    this.equipeA=new ArrayList();
    equipeA.add(adherent);
    this.equipeB=new ArrayList();
    }
    
    /**
     *
     * @return
     */
    public List<Adherent> getEquipeA() {
        return equipeA;
    }

    /**
     *
     * @param equipeA
     */
    public void setEquipeA(List<Adherent> equipeA) {
        this.equipeA = equipeA;
    }

    /**
     *
     * @param adherent
     */
    public void ajouterDansEquipeA(Adherent adherent) {
        this.equipeA.add(adherent);
    }

    /**
     *
     * @return
     */
    public List<Adherent> getEquipeB() {
        return equipeB;
    }

    /**
     *
     * @param equipeB
     */
    public void setEquipeB(List<Adherent> equipeB) {
        this.equipeB = equipeB;
    }
    
    /**
     *
     * @param adherent
     */
    public void ajouterDansEquipeB(Adherent adherent) {
        this.equipeA.add(adherent);
    }
       

}
