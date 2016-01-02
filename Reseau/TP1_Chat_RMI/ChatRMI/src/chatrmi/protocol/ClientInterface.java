package chatrmi.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Interface permettant de définir les methodes necessaire pour un client d'un chat developper en RMI
 * @author Nico
 */
public interface ClientInterface extends Remote {

    /**
     * Methode permettant d'afficher un message.
     * @param m Message à afficher.
     * @throws RemoteException
     */
    void displayMessage(MessageInterface m) throws RemoteException;

    /**
     * Getter
     * @return Nom de l'utilisateur.
     * @throws RemoteException
     */
    String getUserName() throws RemoteException;

    /**
     * Methode notifiant la connexion d'un autre utilisateur.
     * @param c Client.
     * @throws RemoteException
     */
    void newUserConnected(ClientInterface c) throws RemoteException;

    /**
     * Methode notifiant la déconnexion d'un autre utilisateur.
     * @param c Client.
     * @throws RemoteException
     */
    void userDisconnected(ClientInterface c) throws RemoteException;
}
