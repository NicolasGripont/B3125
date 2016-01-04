package chatrmi.protocol;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;

/**
 *
 * @author Nico
 */
public class Message implements MessageInterface{
    
    /**
     * Date de l'envoi du message.
     */
    private final Date date;
    
    /**
     * Nom de l'expediteur.
     */
    private final String userName;
    
    /**
     * Texte du message.
     */
    private final String textMessage;

    /**
     * Constructeur.
     * @param d Date de l'envoi du message.
     * @param usr Nom de l'expediteur.
     * @param msg Texte du message.
     */
    public Message(Date d, String usr, String msg) {
        date = d;
        userName = usr;
        textMessage = msg;
    }
    
    /**
     * Getter.
     * @return Date de l'envoi du message.
     */
    @Override
    public Date getDate() {
        return date;
    }
    
    /**
     * Getter.
     * @return Date de l'envoi du message en String.
     */
    @Override
    public String getDateToString() {
        DateFormat formatter = new SimpleDateFormat("MM/dd/yy h:m:s");
        return formatter.format(date);
    }
    
    /**
     * Getter.
     * @return Nom de l'expediteur.
     */
    @Override
    public String getUserName() {
        return userName;
    }
    
    /**
     * Getter 
     * @return Texte du message.
     */
    @Override
    public String getTextMessage() {
        return textMessage;
    }
}
