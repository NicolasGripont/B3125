/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.seance1;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import metier.modele.Activite;
import metier.modele.Demande;
import metier.modele.Evenement;
import metier.service.ServiceMetier;

/**
 *
 * @author Nico
 */
@WebServlet(name = "ActionServlet", urlPatterns = {"/ActionServlet"})
public class ActionServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet ActionServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet ActionServlet at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
            
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        if(request.getParameter("action").compareTo("getActivites")==0) {
            printAllActivitesInJson(request, response);
        } else if (request.getParameter("action").compareTo("getDemandes")==0){
            printDemandesInJson(request, response);
        } else if (request.getParameter("action").compareTo("getNomsActivites")==0){
            printAllNomActivitesInJson(request, response);
        } else if (request.getParameter("action").compareTo("createDemande")==0){
            createDemande(request, response);
        } else if (request.getParameter("action").compareTo("getEvenements")==0){
            printEventsInJson(request, response);
        } else if (request.getParameter("action").compareTo("getNomsLieux")==0){
            printAllNomLieuxInJson(request, response);
        } else if (request.getParameter("action").compareTo("getStatuts")==0){

        } else {
            
        }
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //
        // /!\ remplacer param 'id' par une valeur dans la session pour getDemandes createDemande
        //
        if(request.getParameter("action").compareTo("getActivites")==0) {
            printAllActivitesInJson(request, response);
        } else if (request.getParameter("action").compareTo("getDemandes")==0){
            printDemandesInJson(request, response);
        } else if (request.getParameter("action").compareTo("getNomsActivites")==0){
            printAllNomActivitesInJson(request, response);
        } else if (request.getParameter("action").compareTo("createDemande")==0){
            createDemande(request, response);
        } else if (request.getParameter("action").compareTo("getEvenements")==0){
            printEventsInJson(request, response);
        } else if (request.getParameter("action").compareTo("getNomsLieux")==0){
            printAllNomLieuxInJson(request, response);
        } else if (request.getParameter("action").compareTo("getStatuts")==0){
            printAllStatusInJson(request, response);
        } else {
            
        }
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

    
    private void printAllActivitesInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        
        List<Activite> activites = ServiceMetier.getAllActivites();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeActivites(out, activites);
        }
    }
    
    private void printDemandesInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        
        List<Demande> demandes = ServiceMetier.selectDemandeByIdAdherent(Integer.parseInt(request.getParameter("id")));//a modifier avec l'id stockée dans la session
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeDemandes(out,demandes);
        }
    }
    
    private void printAllNomActivitesInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        
        List<String> noms = ServiceMetier.AfficheNomActivites();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeNomActivites(out, noms);
        }
    }
    
    private void createDemande(HttpServletRequest request, HttpServletResponse response) {
        ServiceMetier.CreerDemande(request.getParameter("activite"), new Date(Long.parseLong(request.getParameter("date"))), Integer.parseInt(request.getParameter("id")));
        
    }
    
    private void printAllNomLieuxInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        
        List<String> noms = ServiceMetier.AfficheNomLieux();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeNomLieux(out, noms);
        }
    }
    
    private void printAllStatusInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        
        List<String> noms = ServiceMetier.AfficheStatut();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeStatuts(out, noms);
        }
    }
    
    private void printEventsInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        Date d = null;
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            d = sdf.parse("01/01/1970");
        } catch(ParseException e){
            
        }
        List<Evenement> evenements = ServiceMetier.AffichageEvenementsFiltres("Statut","Activité","Lieu",d);
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeEvenements(out, evenements);
        }
    }
}
