/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.Date;

/**
 *
 * @author Nico
 */
public interface MessageInterface extends Remote{
    Date getDate() throws RemoteException;

    String getUserName() throws RemoteException;

    String getTextMessage() throws RemoteException;
}
