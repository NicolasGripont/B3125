/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import javax.servlet.http.HttpServletRequest;
import metier.modele.Adherent;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class ValiderMailAction extends Action{

    public ValiderMailAction() {
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        Adherent adherent = ServiceMetier.selectAdherentByMail(request.getParameter("mail"));
        if(adherent == null) {
            result = Boolean.TRUE;
        }
        return result;
    }
    
}