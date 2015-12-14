package chat;


import java.util.*;


public class Message{
    private final Date date;
    private final String userName;
    private final String textMessage;

    public Message(Date d, String usr, String msg) {
        date = d;
        userName = usr;
        textMessage = msg;
    }

    public Date getDate() {
        return date;
    }

    public String getUserName() {
        return userName;
    }

    public String getTextMessage() {
        return textMessage;
    }

    @Override
    public String toString() {
        return String.format("[%1] %2 : %3", date.toString(),userName,textMessage); //To change body of generated methods, choose Tools | Templates.
    }
    
    
}
