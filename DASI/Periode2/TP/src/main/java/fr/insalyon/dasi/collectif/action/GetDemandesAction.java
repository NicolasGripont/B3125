/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import java.util.List;
import javax.servlet.http.HttpServletRequest;
import metier.modele.Demande;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class GetDemandesAction extends Action{

    List<Demande> demandes;
    
    public GetDemandesAction() {
        demandes = null;
    }
    
    public List<Demande> getDemandes() {
        return demandes;
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        demandes = ServiceMetier.selectDemandeByIdAdherent(Integer.parseInt(request.getSession().getAttribute("id").toString()));
        
        if(demandes != null) {
            result = Boolean.TRUE;
        }
        return result;
    }
    
}