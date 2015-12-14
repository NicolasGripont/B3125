/***
 * EchoServer
 * Example of a TCP server
 * Date: 10/01/04
 * Authors:
 */

package chat.server;

import chat.client.ClientThread;
import java.io.*;
import java.net.*;

public class EchoServerMultiThreaded  {
  
 	/**
  	* main method
	* @param EchoServer port
  	* 
  	**/
       public static void main(String args[]){ 
        ServerSocket listenSocket;
        
        int port;
        
  	if (args.length < 1) {
          //System.out.println("Usage: java EchoServer <EchoServer port>");
          //System.exit(1);
          port = new Integer("1099").intValue();
  	}
        else
        {
            port = new Integer(args[0]).intValue();;
        }
        
	try {
		listenSocket = new ServerSocket(port); //port
		System.out.println("Server ready..."); 
		while (true) {
			Socket clientSocket = listenSocket.accept();
			System.out.println("Connexion from:" + clientSocket.getInetAddress());
			ClientThread ct = new ClientThread(clientSocket);
			ct.start();
		}
        } catch (Exception e) {
            System.err.println("Error in EchoServer:" + e);
        }
      }
  }

  
