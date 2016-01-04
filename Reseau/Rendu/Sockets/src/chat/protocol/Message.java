package chat.protocol;

/**
 * Classe permettant de modéliser un message.
 * @author Nico
 */
public class Message{
    /**
     * Nom de l'expediteur du message.
     */
    private final String sender;
    
    /**
     * Nom du destinataire du message.
     */
    private final String receiver;
        
    /**
     * Texte du meassage.
     */
    private final String textMessage;

    /**
     * Constructeur.
     * @param s Nom de l'expéditeur.
     * @param r Nom du destinataire.
     * @param tm Texte du meassage.
     */
    public Message(String s, String r, String tm) {
        receiver = r;
        sender = s;
        textMessage = tm;
    }
    
    /**
     * Getter.
     * @return Nom de l'envoyeur du message.
     */
    public String getSender() {
        return sender;
    }
    
    /**
     * Getter.
     * @return
     */
    public String getReceiver() {
        return receiver;
    }
    
    /**
     * Getter.
     * @return Texte du meassage.
     */
    public String getTextMessage() {
        return textMessage;
    }
}
