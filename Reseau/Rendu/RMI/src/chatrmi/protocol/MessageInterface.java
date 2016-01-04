/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatrmi.protocol;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.Date;

/**
 * Interface permettant de définir les methodes necessaire pour un message d'un chat developper en RMI
 * 
 * @author Nico
 */
public interface MessageInterface extends Remote{
    
    /**
     * Getter
     * @return Date de l'envoi du message
     * @throws RemoteException
     */
    Date getDate() throws RemoteException;
    
    /**
     * Getter
     * @return Date en String.
     * @throws RemoteException
     */
    String getDateToString() throws RemoteException;
            
    /**
     * Getter
     * @return Nom de l'expediteur.
     * @throws RemoteException
     */
    String getUserName() throws RemoteException;

    /**
     * Getter
     * @return Text du message .
     * @throws RemoteException
     */
    String getTextMessage() throws RemoteException;
}
