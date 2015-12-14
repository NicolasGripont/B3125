package chat.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ClientInterface extends Remote {
	void displayMessage(MessageInterface m) throws RemoteException;
        String getUserName() throws RemoteException;
}
