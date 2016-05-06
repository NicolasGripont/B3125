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
import java.util.List;
import metier.modele.Activite;

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
}
