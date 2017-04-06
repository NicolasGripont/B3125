/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.collectif;

import fr.insalyon.dasi.collectif.action.GetEvenementAction;
import fr.insalyon.dasi.collectif.action.GetEvenementsAction;
import fr.insalyon.dasi.collectif.action.GetLieuxEvenementAction;
import fr.insalyon.dasi.collectif.action.GetNomsActivitesAction;
import fr.insalyon.dasi.collectif.action.GetNomsLieuxAction;
import fr.insalyon.dasi.collectif.action.GetStatutsAction;
import fr.insalyon.dasi.collectif.action.ValiderLieuEvenementAction;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Nico
 */
@WebServlet(name = "ResponsableServlet", urlPatterns = {"/ResponsableServlet"})
public class ResponsableServlet extends HttpServlet {

    
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
            out.println("<title>Servlet ResponsableServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet ResponsableServlet at " + request.getContextPath() + "</h1>");
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
        if (request.getParameter("action").compareTo("getNomsActivites")==0) {
            getNomsActivites(request, response);
        } else if (request.getParameter("action").compareTo("getEvenements")==0) {
            getEvenements(request, response);
        } else if (request.getParameter("action").compareTo("getNomsLieux")==0) {
            getNomsLieux(request, response);
        } else if (request.getParameter("action").compareTo("getStatuts")==0) {
            getStatuts(request, response);
        } else if (request.getParameter("action").compareTo("getLieuxEvenement")==0) {
            getLieuxEvenement(request, response);
        } else if (request.getParameter("action").compareTo("getEvenement")==0) {
            getEvenement(request, response);
        } else if (request.getParameter("action").compareTo("validerLieuEvenement")==0) {
            validerLieuEvenement(request, response);
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
    
    private void getEvenements(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        GetEvenementsAction action = new GetEvenementsAction();
        if(action.execute(request)) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printListeEvenements(out, action.getEvenements());
            }
        }
    }
    
    private void getNomsLieux(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        GetNomsLieuxAction action = new GetNomsLieuxAction();
        if(action.execute(request)) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printListeNomLieux(out,action.getNomsLieux());
            }
        }
    }
    
    private void getStatuts(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        GetStatutsAction action = new GetStatutsAction();
        if(action.execute(request)) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printListeStatuts(out,action.getStatuts());
            }
        }
    }
    
    private void getLieuxEvenement(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        GetLieuxEvenementAction action = new GetLieuxEvenementAction();
        if(action.execute(request)) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printListeLieux(out, action.getLieux());
            }
        }
    }
    
    private void getEvenement(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        GetEvenementAction action = new GetEvenementAction();
        if(action.execute(request)) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            try (PrintWriter out = response.getWriter()) {
                Serialisation.printEvenement(out, action.getEvenement());
            }
        }
    }
    
    private void validerLieuEvenement(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int result = 1;
        ValiderLieuEvenementAction action = new ValiderLieuEvenementAction();
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
