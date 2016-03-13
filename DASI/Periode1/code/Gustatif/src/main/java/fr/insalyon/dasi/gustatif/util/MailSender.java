/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.util;

import java.util.*;
import javax.mail.*;
import javax.mail.internet.*;

/**
 *
 * @author Nico
 */
public class MailSender {
   
    public static void main(String [] args)
    {
        MailSender ms = new MailSender("gustatif.b3125@gmail.com","B3125-2016");
        ms.sendMail("n.gripont@gmail.com","Java Test Code","Does it work?");
    }
   
    final String username;
    final String password;
       
    public MailSender(String username, String password)
    {
        this.username = username;
        this.password = password;
    }
    public void sendMail(String recipientMail, String subject, String body)
    {    
        Properties props = new Properties();
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.host", "smtp.gmail.com");
        props.put("mail.smtp.port", "587");

        Session session = Session.getInstance(props,
        new javax.mail.Authenticator() {
              protected PasswordAuthentication getPasswordAuthentication() {
                      return new PasswordAuthentication(username, password);
              }
        });

        try {
            Message message = new MimeMessage(session);
            message.setFrom(new InternetAddress());
            message.setRecipients(Message.RecipientType.TO,
                    InternetAddress.parse(recipientMail));
            message.setSubject(subject);
            message.setText(body);

            Transport.send(message);

        } catch (MessagingException e) {
            throw new RuntimeException(e);
        }
    }
}
