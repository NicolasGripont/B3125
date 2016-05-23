package fr.insalyon.dasi.collectif.action;

import java.io.PrintWriter;
import javax.servlet.http.HttpServletRequest;
import metier.service.ServiceMetier;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Nico
 */
public abstract class Action {

    public abstract Boolean execute(HttpServletRequest request);
    
    public Action(){
    }
    
}