/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.insalyon.dasi.seance1;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.FieldPosition;
import java.text.ParsePosition;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import metier.modele.Activite;
import metier.modele.Demande;

/**
 *
 * @author Nico
 */
public class Serialisation {
    //voir 63 poly :gripay
    public static void printListeActivites(
        PrintWriter out, List<Activite> activites) {
        
        JsonArray jsonList = new JsonArray();
        
        for (Activite a : activites) {
            JsonObject jsonActivite = new JsonObject();
            
            jsonActivite.addProperty("id", a.getId());
            jsonActivite.addProperty("denomination", a.getDenomination());
            jsonActivite.addProperty("parEquipe", a.isParEquipe());
            jsonActivite.addProperty("nbParticipants", a.getNbParticipants());
            jsonList.add(jsonActivite);
        }
        
        // Objet Json "conteneur"
        JsonObject container = new JsonObject();
        container.add("activites", jsonList);
        
        // Serialisation & écriture sur le flux de sortie
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(container);
        out.write(json);
    }
    
    public static void printListeNomActivites(
        PrintWriter out, List<String> noms) {
        
        JsonArray jsonList = new JsonArray();
        
        for (String s : noms) {
            JsonObject jsonActivite = new JsonObject();
            
            jsonActivite.addProperty("nom", s);
            
            jsonList.add(jsonActivite);
        }
        
        // Objet Json "conteneur"
        JsonObject container = new JsonObject();
        container.add("nomsActivites", jsonList);
        
        // Serialisation & écriture sur le flux de sortie
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(container);
        out.write(json);
    }
    
    public static void printListeDemandes(
        PrintWriter out, List<Demande> demandes) {
        
        JsonArray jsonList = new JsonArray();
        
        for (Demande d : demandes) {
            JsonObject jsonDemande = new JsonObject();
            
            jsonDemande.addProperty("id", d.getId());
            jsonDemande.addProperty("activite", d.getActivite().getDenomination());
            jsonDemande.addProperty("date",dateToString(d.getDateDemande())); 
            if(d.getEvenement().getLieu() == null) {
                jsonDemande.addProperty("Lieu","null");
            } else {
                jsonDemande.addProperty("Lieu",d.getEvenement().getLieu().getDenomination());
            }
            jsonDemande.addProperty("dateEvenement",dateToString(d.getEvenement().getDateEvenement()));
            
            if(d.getEvenement().getDateEvenement().before(new Date())) {
                jsonDemande.addProperty("depasse",Boolean.TRUE);
            } else {
                jsonDemande.addProperty("depasse",Boolean.FALSE);
            }

            jsonList.add(jsonDemande);
        }
        
        // Objet Json "conteneur"
        JsonObject container = new JsonObject();
        container.add("demandes", jsonList);
        
        // Serialisation & écriture sur le flux de sortie
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(container);
        out.write(json);
    }
    
    public static String dateToString(Date date) {
        String d = "";
        DateFormat df = new SimpleDateFormat("dd/MM/yyyy");
        d += df.format(date);
        return d;
    }
}
