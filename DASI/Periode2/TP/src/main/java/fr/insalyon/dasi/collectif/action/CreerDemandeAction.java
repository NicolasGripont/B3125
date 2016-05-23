/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import java.text.SimpleDateFormat;
import javax.servlet.http.HttpServletRequest;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class CreerDemandeAction extends Action{

    public CreerDemandeAction() {
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            ServiceMetier.CreerDemande(request.getParameter("activite"), sdf.parse(request.getParameter("date")),  Integer.parseInt(request.getSession().getAttribute("id").toString()));
            result = Boolean.TRUE;
        } catch(Exception e){

        }
        return result;
    }
    
}