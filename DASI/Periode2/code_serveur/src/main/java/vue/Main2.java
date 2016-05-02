/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vue;

import java.util.Date;
import java.util.Scanner;
import static metier.service.ServiceMetier.CreerDemande;

/**
 * @author ludiv
 */
public class Main2 {

    /**
     *
     * @param args
     * @throws Throwable
     */
    public static void main(String[] args) throws Throwable
    {

       Scanner scan=new Scanner(System.in);
        System.out.println("Entrez l'id de l'adherent");
        int id=scan.nextInt();
        CreerDemande("Belote",new Date(),id);
    }
}
