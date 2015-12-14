package chat;


import chat.protocol.MessageInterface;
import java.util.*;


public class Message implements MessageInterface{
    private final Date date;
    private final String userName;
    private final String textMessage;

    public Message(Date d, String usr, String msg) {
        date = d;
        userName = usr;
        textMessage = msg;
    }
    
    @Override
    public Date getDate() {
        return date;
    }
    
    @Override
    public String getUserName() {
        return userName;
    }
    
    @Override
    public String getTextMessage() {
        return textMessage;
    }

//    @Override
//    public String toString() {
//        return String.format("[%1] %2 : %3", date.toString(),userName,textMessage); //To change body of generated methods, choose Tools | Templates.
//    }
    
    
}
