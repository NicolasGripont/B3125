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
public class GetNomsLieuxAction extends Action{

    List<String> nomsLieux;
    
    public GetNomsLieuxAction() {
        nomsLieux = null;
    }
    
    public List<String> getNomsLieux() {
        return nomsLieux;
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        nomsLieux = ServiceMetier.AfficheNomLieux();
        
        if(nomsLieux != null) {
            result = Boolean.TRUE;
        }
        return result;
    }
    
}