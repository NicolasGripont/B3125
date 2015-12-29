package chatrmi.protocol;

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
    public String getDateToString() {
        return String.format("%d/%d/%d %d:%d:%d", date.getDay(), date.getMonth(), date.getYear() + 1900, date.getHours(), date.getMinutes(), date.getSeconds());
    }
    
    @Override
    public String getUserName() {
        return userName;
    }
    
    @Override
    public String getTextMessage() {
        return textMessage;
    }
}
