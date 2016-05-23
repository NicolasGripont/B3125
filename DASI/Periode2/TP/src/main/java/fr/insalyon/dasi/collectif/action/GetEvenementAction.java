/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import javax.servlet.http.HttpServletRequest;
import metier.modele.Evenement;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class GetEvenementAction extends Action{

    Evenement evenement;
    
    public GetEvenementAction() {
        evenement = null;
    }

    public Evenement getEvenement() {
        return evenement;
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        evenement = ServiceMetier.getEvenement(Long.parseLong(request.getParameter("id")));
        
        if(evenement != null) {
            result = Boolean.TRUE;
        }
        return result;
    }
    
}