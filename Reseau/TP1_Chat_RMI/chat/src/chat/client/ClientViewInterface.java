/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.client;

import chat.protocol.MessageInterface;
import java.rmi.RemoteException;

/**
 *
 * @author Nico
 */
public interface ClientViewInterface {
    public void displayMessage(MessageInterface m) throws RemoteException;
}
