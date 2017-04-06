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
public class GetStatutsAction extends Action{

    List<String> statuts;
    
    public GetStatutsAction() {
        statuts = null;
    }
    
    public List<String> getStatuts() {
        return statuts;
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        statuts = ServiceMetier.AfficheStatut();
        
        if(statuts != null) {
            result = Boolean.TRUE;
        }
        return result;
    }
}