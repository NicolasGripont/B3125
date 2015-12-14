/***
 * EchoClient
 * Example of a TCP client 
 * Date: 10/01/04
 * Authors:
 */
package chat.client;

import java.io.*;
import java.net.*;



public class EchoClient {

 
  /**
  *  main method
  *  accepts a connection, receives a message from client then sends an echo to the client
  **/
    public static void main(String[] args) throws IOException {

        Socket echoSocket = null;
        PrintStream socOut = null;
        BufferedReader stdIn = null;
        BufferedReader socIn = null;
        String host;
        int port;

        
        if (args.length < 2) {
//          System.out.println("Usage: java EchoClient <EchoServer host> <EchoServer port>");
//          System.exit(1);
            host = "localhost";
            port = new Integer("1099").intValue();
        }
        else
        {
            host = args[0];
            port = new Integer(args[1]).intValue();
        }

        try {
      	    // creation socket ==> connexion
      	    echoSocket = new Socket(host,port);
	    socIn = new BufferedReader(
	    		          new InputStreamReader(echoSocket.getInputStream()));    
	    socOut= new PrintStream(echoSocket.getOutputStream());
	    stdIn = new BufferedReader(new InputStreamReader(System.in));
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host:" + host);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for "
                               + "the connection to:"+ host);
            System.exit(1);
        }
                             
        String line;
        while (true) {
        	line=stdIn.readLine();
        	if (line.equals(".")) break;
        	socOut.println(line);
        	System.out.println("echo: " + socIn.readLine());
        }
      socOut.close();
      socIn.close();
      stdIn.close();
      echoSocket.close();
    }
}


