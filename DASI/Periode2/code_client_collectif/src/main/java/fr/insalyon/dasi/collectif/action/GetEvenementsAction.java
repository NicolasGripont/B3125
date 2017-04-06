/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif.action;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import metier.modele.Evenement;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
public class GetEvenementsAction extends Action{

    List<Evenement> evenements;
    
    public GetEvenementsAction() {
        evenements = null;
    }

    public List<Evenement> getEvenements() {
        return evenements;
    }

    @Override
    public Boolean execute(HttpServletRequest request) {
        Boolean result = Boolean.FALSE;
        Date d = null;
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            d = sdf.parse(request.getParameter("date"));
        } catch(ParseException e){
            
        }
        evenements = ServiceMetier.AffichageEvenementsFiltres(request.getParameter("statut"),request.getParameter("activite"),request.getParameter("lieu"),d);
        if(evenements != null) {
            result = Boolean.TRUE;
        }
        return result;
    }
    
}