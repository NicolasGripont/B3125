/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif;

import fr.insalyon.dasi.collectif.action.ConnexionAction;
import fr.insalyon.dasi.collectif.action.CreerDemandeAction;
import fr.insalyon.dasi.collectif.action.GetDemandesAction;
import fr.insalyon.dasi.collectif.action.GetNomsActivitesAction;
import fr.insalyon.dasi.collectif.action.InscriptionAction;
import fr.insalyon.dasi.collectif.action.ValiderMailAction;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author Nico
 */
@WebServlet(name = "AdherentServlet", urlPatterns = {"/AdherentServlet"})
public class AdherentServlet extends HttpServlet {

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
            out.println("<title>Servlet AdherentServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet AdherentServlet at " + request.getContextPath() + "</h1>");
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
        traiterRequete(request, response);
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
        traiterRequete(request, response);
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
        if (request.getParameter("action").compareTo("getDemandes")==0) {
            getDemandes(request, response);
        } else if (request.getParameter("action").compareTo("getNomsActivites")==0) {
            getNomsActivites(request, response);
        } else if (request.getParameter("action").compareTo("connexion")==0) {
            connexion(request, response);
        } else if (request.getParameter("action").compareTo("deconnexion")==0) {
            deconnexion(request, response);
        } else if (request.getParameter("action").compareTo("creerDemande")==0) {
            creerDemande(request, response);
        } else if (request.getParameter("action").compareTo("inscription")==0) {
            inscription(request, response);
        } else if (request.getParameter("action").compareTo("validerMail")==0) {
            validerMail(request, response);
        } 
    }
    
    private void getDemandes(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        if(isSessionAdherentValide(request)) {
            GetDemandesAction action = new GetDemandesAction();
            if(action.execute(request)) {
                response.setContentType("application/json");
                response.setCharacterEncoding("UTF-8");
                try (PrintWriter out = response.getWriter()) {
                    Serialisation.printListeDemandes(out,action.getDemandes());
                }
            }
        }
    }
    
    private void getNomsActivites(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        GetNomsActivitesAction action = new GetNomsActivitesAction();
        if(action.execute(request)) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printListeNomActivites(out,action.getNomsActivites());
            }
        }
    }
    
    private void connexion(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int result = 1;
        ConnexionAction action = new ConnexionAction();
        if(action.execute(request)){
            HttpSession session = request.getSession(true);
            session.setAttribute("id", action.getAdherent().getId());
            result = 0;
        }
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, result);
        }
    }
    
    private void deconnexion(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.invalidate();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, 0);
        }
    }
    
    private void inscription(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int result = 1;
        InscriptionAction action = new InscriptionAction();
        if(action.execute(request)) {
            result = 0;
        }
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, result);
        }
    }
    
    private void creerDemande(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        if(isSessionAdherentValide(request)) {
            int result = 1;
            CreerDemandeAction action = new CreerDemandeAction();
            if(action.execute(request)) {
                result = 0;
            }
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printResult(out, result);
            }
        }
    }

    private Boolean isSessionAdherentValide(HttpServletRequest request) {
        Boolean result = Boolean.TRUE;
        HttpSession session = request.getSession();
//        if(!session.isNew()) {
        if(session.getAttribute("id") == null) {
            session.invalidate();
            result = Boolean.FALSE;
        }
        return result;
    }

    private void validerMail(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        int result = 1;
        ValiderMailAction action = new ValiderMailAction();
        if(action.execute(request)) {
            result = 0;
        }
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        try (PrintWriter out = response.getWriter()) {
            Serialisation.printResult(out, result);
        }
    }
}
