/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.gustatif.metier.service;

import fr.insalyon.dasi.gustatif.util.MailSender;

/**
 *
 * @author Nico
 */
public class ServiceTechnique {
    
    public boolean sendRealMail(String recipientMail, String subject, String body) {
        MailSender ms = new MailSender("gustatif.b3125@gmail.com","B3125-2016");
        return ms.sendMail(recipientMail,subject,body);
    }
    
    public void sendFakeMail(String recipientMail, String subject, String body) {
        System.out.println("");
        System.out.println("********* Mail envoyé **********");
        System.out.println("From : gustatif.b3125@gmail.com");
        System.out.println("To : " + recipientMail);
        System.out.println("Subject : " + subject);
        System.out.println(body);
        System.out.println("********************************");
        System.out.println("");
    }
    
    
}
