/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import javax.servlet.http.HttpServletRequest;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class ValiderLieuEvenementAction extends Action{

    public ValiderLieuEvenementAction() {
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.TRUE;
        ServiceMetier.finaliserEvenement(request.getParameter("lieu"), Long.parseLong(request.getParameter("id")));
        return result;
    }
    
}