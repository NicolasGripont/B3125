package metier.modele;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import static metier.modele.Adherent_.adresse;


@Entity
public class TypeLieu implements Serializable {
   @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer id;
    private String description;
    @ManyToOne
    @JoinColumn(nullable=false)
    private Activite activite;

    /**
     *Constructeur par défaut  de TypeLieu
     */
    public TypeLieu() {
    }

    /**
     *Constructeur de TypeLieu
     * @param description
     * @param activite
     */
    public TypeLieu(String description, Activite activite){
        this.description = description;
        this.activite = activite;
    }

    /**
     *
     * @return
     */
    public Integer getId() {
        return id;
    }

    /**
     *
     * @return
     */
    public String getDescription() {
        return description;
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
     * @param description
     */
    public void setDescription(String description) {
        this.description = description;
    }

    /**
     *
     * @param activite
     */
    public void setActivite(Activite activite) {
        this.activite = activite;
    }
    
}
