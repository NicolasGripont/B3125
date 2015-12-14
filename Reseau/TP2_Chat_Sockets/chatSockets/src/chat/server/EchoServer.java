/***
 * EchoServer
 * Example of a TCP server
 * Date: 10/01/04
 * Authors:
 */

package chat.server;

import java.io.*;
import java.net.*;
import javax.net.ServerSocketFactory;

public class EchoServer  {

 	/**
  	* receives a request from client then sends an echo to the client
  	* @param clientSocket the client socket
  	**/
	static void doService(Socket clientSocket) {
    	  try {
    		BufferedReader socIn = null;
    		socIn = new BufferedReader(
    			new InputStreamReader(clientSocket.getInputStream()));    
    		PrintStream socOut = new PrintStream(clientSocket.getOutputStream());
    		while (true) {
    		  String line = socIn.readLine();
    		  socOut.println(line);
    		}
    	} catch (Exception e) {
        	System.err.println("Error in EchoServer:" + e); 
        }
       }
  
 	/**
  	* main method
	* @param EchoServer port
  	* 
  	**/
        public static void main(String args[]){ 
            
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
            
            
        ServerSocketFactory serverSocketFactory = ServerSocketFactory.getDefault();
        ServerSocket listenSocket;


	try {
            
		listenSocket = serverSocketFactory.createServerSocket(port); //port
                
		while (true) {
			Socket clientSocket = listenSocket.accept();
			System.out.println("connexion from:" + clientSocket.getInetAddress());
			doService(clientSocket);
		}
        } catch (Exception e) {
            System.err.println("Error in EchoServer:" + e);
        }
      }
  }

  
