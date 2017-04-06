/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

/**
 *
 * @author arame
 */
public class Saisie {

    /**
     *
     * @param invite
     * @return
     */
    public static String lireChaine(String invite) {
        String chaineLue = null;
        System.out.print(invite);
        try {
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            chaineLue = br.readLine();
        } catch (IOException exception) {
            exception.printStackTrace(System.err);
        }
        return chaineLue;

    }

    /**
     *
     * @param invite
     * @return
     */
    public static Integer lireInteger(String invite) {
        Integer valeurLue = null;
        try {
            valeurLue = new Integer(lireChaine(invite));
        } catch (java.lang.NumberFormatException e) {
            System.out.println("erreur de saisie");
            valeurLue = lireInteger(invite);
        }
        return valeurLue;
    }

    /**
     *
     * @param invite
     * @param valeursPossibles
     * @return
     */
    public static Integer lireInteger(String invite, List<Integer> valeursPossibles) {
        Integer valeurLue = null;
        try {
            valeurLue = new Integer(lireChaine(invite));
            if (!(valeursPossibles.contains(valeurLue))) {
                throw new Exception();
            }
        } catch (Exception e) {
            System.out.println("erreur de saisie");
            valeurLue = lireInteger(invite, valeursPossibles);
        }
        return valeurLue;
    }

    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        System.out.println("Bonjour !");
        String nom = Saisie.lireChaine("Entrez votre nom: ");
        System.out.println("Bonjour, " + nom + " !");
        Integer age = Saisie.lireInteger("Entrez votre âge: ");
        System.out.println("Vous avez " + age + " ans.");
        System.out.println("Au revoir !");
    }
}
