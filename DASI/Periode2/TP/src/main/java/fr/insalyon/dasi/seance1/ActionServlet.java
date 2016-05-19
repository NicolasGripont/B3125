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
import javax.servlet.http.HttpSession;
import metier.modele.Activite;
import metier.modele.Adherent;
import metier.modele.Demande;
import metier.modele.Evenement;
import metier.modele.Lieu;
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
        traiterRequete(request,response);
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
        traiterRequete(request,response);
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

    
    private void traiterRequete(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //
        // /!\ remplacer param 'id' par une valeur dans la session pour getDemandes createDemande
        //
        if(request.getParameter("action").compareTo("getActivites")==0) {
            printAllActivitesInJson(request, response);
        } else if (request.getParameter("action").compareTo("getDemandes")==0) {
            printDemandesInJson(request, response);
        } else if (request.getParameter("action").compareTo("getNomsActivites")==0) {
            printAllNomActivitesInJson(request, response);
        } else if (request.getParameter("action").compareTo("createDemande")==0) {
            createDemande(request, response);
        } else if (request.getParameter("action").compareTo("getEvenements")==0) {
            printEventsInJson(request, response);
        } else if (request.getParameter("action").compareTo("getNomsLieux")==0) {
            printAllNomLieuxInJson(request, response);
        } else if (request.getParameter("action").compareTo("getStatuts")==0) {
            printAllStatusInJson(request, response);
        }  else if (request.getParameter("action").compareTo("getLieuxEvent")==0) {
            printNomsLieuxEventInJson(request,response);
        } else if (request.getParameter("action").compareTo("connexion")==0) {
            creerSessionAdherent(request,response);
        } else if (request.getParameter("action").compareTo("deconnexion")==0) {
            supprimerSessionAdherent(request,response);
        } else if (request.getParameter("action").compareTo("creerDemande")==0) {
            createDemande(request,response);
        } else if (request.getParameter("action").compareTo("inscription")==0) {
            inscription(request,response);
        } else if (request.getParameter("action").compareTo("getEvenementEtLieux")==0) {
            printEvenementEtLieux(request,response);
        }
    }
    
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
        if(isSessionAdherentValide(request)) {
            List<Demande> demandes = ServiceMetier.selectDemandeByIdAdherent(Integer.parseInt(request.getSession().getAttribute("id").toString()));
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printListeDemandes(out,demandes);
            }
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
    
    private void createDemande(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        if(isSessionAdherentValide(request)) {
//            ServiceMetier.CreerDemande(request.getParameter("activite"), new Date(Long.parseLong(request.getParameter("date"))), Integer.parseInt(request.getSession().getAttribute("id").toString()));
            try {
                SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                ServiceMetier.CreerDemande(request.getParameter("activite"), sdf.parse(request.getParameter("date")),  Integer.parseInt(request.getSession().getAttribute("id").toString()));
                
            } catch(Exception e){

            }
//            request.getRequestDispatcher("menuPrincipalAdherent.html").forward(request, response);
//            response.sendRedirect("menuPrincipalAdherent.html");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printResult(out, 0, "");
            }
        }
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
            d = sdf.parse(request.getParameter("date"));
        } catch(ParseException e){
            
        }
        List<Evenement> evenements = ServiceMetier.AffichageEvenementsFiltres(request.getParameter("statut"),request.getParameter("activite"),request.getParameter("lieu"),d);
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeEvenements(out, evenements);
        }
    }
    
    
    private void printNomsLieuxEventInJson(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException{
        Evenement event = ServiceMetier.getEvenement(Long.parseLong(request.getParameter("id")));
        List<Lieu> lieux = ServiceMetier.obtenirLieux(event);
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printListeLieux(out, lieux);
        }
    }
    
    private void creerSessionAdherent(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        Adherent adherent = ServiceMetier.selectAdherentByMail(request.getParameter("mail"));
        int result = 1;
        if(adherent != null) {
            HttpSession session = request.getSession(true);
            session.setAttribute("id", adherent.getId());
            //rborrotimatiasdantas4171@free.fr
            
//            request.getRequestDispatcher("menuPrincipalAdherent.html").forward(request, response);
//           response.sendRedirect("menuPrincipalAdherent.html");
            result = 0;
        }
//        } else {
////           request.getRequestDispatcher("accueilAdherent.html").forward(request, response);
////           response.sendRedirect("accueilAdherent.html");
//        }
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, result, "");
        }
    }
    
    private void supprimerSessionAdherent(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        Adherent adherent = ServiceMetier.selectAdherentByMail(request.getParameter("mail"));
       
        HttpSession session = request.getSession();
        session.invalidate();
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, 0, "");
        }
//        request.getRequestDispatcher("accueilAdherent.html").forward(request, response);
//        response.sendRedirect("accueilAdherent.html");
    }
    
    private Boolean isSessionAdherentValide(HttpServletRequest request) {
        HttpSession session = request.getSession();
        if(session.getAttribute("id") == null) {
            session.invalidate();
            return Boolean.FALSE;
        }
        return Boolean.TRUE;
    }
    
    private void inscription(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        Adherent adherent = ServiceMetier.creerAdherent(request.getParameter("nom"),request.getParameter("prenom"),request.getParameter("adresse"),request.getParameter("mail"));
        int result = 1;
        if(adherent != null) {
            result = 0;
        }
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, result, "");
        }
        
    }
    
    private void printEvenementEtLieux(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        Evenement event = ServiceMetier.getEvenement(Long.parseLong(request.getParameter("id")));
        List<Lieu> lieux = ServiceMetier.obtenirLieux(event);
        
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printEventEtLieux(out, event, lieux);
        }
    }
}


