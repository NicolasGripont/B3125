package chat.protocol;

import chat.*;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ServerInterface extends Remote {

    void sendMessage(MessageInterface m) throws RemoteException;

    Boolean addClient(ClientInterface c) throws RemoteException;

    void deleteClient(ClientInterface c) throws RemoteException;
}
