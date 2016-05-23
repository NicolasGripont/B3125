/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import java.util.List;
import javax.servlet.http.HttpServletRequest;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class GetNomsActivitesAction extends Action{

    List<String> nomsActivites;
    
    public GetNomsActivitesAction() {
        nomsActivites = null;
    }
    
    public List<String> getNomsActivites() {
        return nomsActivites;
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        nomsActivites = ServiceMetier.AfficheNomActivites();;
        
        if(nomsActivites != null) {
            result = Boolean.TRUE;
        }
        return result;
    }



}