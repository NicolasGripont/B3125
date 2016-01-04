package chatrmi.protocol;


import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Interface permettant de définir les methodes necessaire pour un server d'un chat developper en RMI
 * @author Nico
 */
public interface ServerInterface extends Remote {

    /**
     * Methode permettant d'envoyer un message à tous les clients connectés au serveur.
     * @param m Message à envoyer.
     * @throws RemoteException
     */
    void sendMessageToAll(MessageInterface m) throws RemoteException;

    /**
     * Methode permettant d'ajouter un nouveau client à liste de clients connectés. (Connecter le client)
     * @param c Client
     * @return True si l'ajout a pu se faire, false sinon.
     * @throws RemoteException
     */
    boolean addClient(ClientInterface c) throws RemoteException;

    /**
     * Methode permettant d'enlever un client à liste de clients connectés. (Deconnecter le client)
     * @param c Client.
     * @throws RemoteException
     */
    void deleteClient(ClientInterface c) throws RemoteException;
}
