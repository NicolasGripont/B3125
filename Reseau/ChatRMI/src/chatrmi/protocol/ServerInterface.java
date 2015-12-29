package chatrmi.protocol;


import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ServerInterface extends Remote {

    void sendMessageToAll(MessageInterface m) throws RemoteException;

    boolean addClient(ClientInterface c) throws RemoteException;

    void deleteClient(ClientInterface c) throws RemoteException;
}
