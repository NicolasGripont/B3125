/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import java.util.Date;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import metier.modele.Evenement;
import metier.modele.Lieu;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class GetLieuxEvenementAction extends Action{

    List<Lieu> lieux;
    
    public GetLieuxEvenementAction() {
        lieux = null;
    }

    public List<Lieu> getLieux() {
        return lieux;
    }
    
    

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        Evenement event = ServiceMetier.getEvenement(Long.parseLong(request.getParameter("id")));
        lieux = ServiceMetier.obtenirLieux(event);
        
        if(lieux != null && event.getLieu() == null && event.getDateEvenement().after(new Date())) {
            result = Boolean.TRUE;
        }
        return result;
    }
    
}