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
import javax.persistence.OneToMany;


@Entity
public class EvenementSansEquipe extends Evenement {
    @OneToMany
    private List<Adherent> participants;

    /**
     *
     * @return
     */
    public List<Adherent> getParticipants() {
        return participants;
    }

    /**
     *Constructeur par défaut   de EvenementSansEquipe
     */
    public EvenementSansEquipe(){
        
    }

    /**
     *Constructeur de EvenementSansEquipe, l'adhérent est ajouté dans la liste 
     * @param participant
     * @param dateEvenement
     * @param nombreParticipants
     * @param activite
     */
    public EvenementSansEquipe(Adherent participant, Date dateEvenement, int nombreParticipants, Activite activite) {
    super( dateEvenement,  nombreParticipants,  activite);
    this.participants=new ArrayList();
    participants.add(participant);
}

}
