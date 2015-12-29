package chatrmi.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ClientInterface extends Remote {
	void displayMessage(MessageInterface m) throws RemoteException;
        String getUserName() throws RemoteException;
        void newUserConnected(ClientInterface c) throws RemoteException;
        void userDisconnected(ClientInterface c) throws RemoteException;
}
