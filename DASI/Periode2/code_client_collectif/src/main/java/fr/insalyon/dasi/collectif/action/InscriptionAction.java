/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import fr.insalyon.dasi.collectif.action.Action;
import javax.servlet.http.HttpServletRequest;
import metier.modele.Adherent;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class InscriptionAction extends Action{

    private Adherent adherent;
    
    public InscriptionAction() {
        adherent = null;
    }

    public Adherent getAdherent() {
        return adherent;
    }
    

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        adherent = ServiceMetier.creerAdherent(request.getParameter("nom"),request.getParameter("prenom"),request.getParameter("adresse"),request.getParameter("mail"));
        
        if(adherent != null){
            result = Boolean.TRUE;
        }
        
        return result;
    }
    
}
