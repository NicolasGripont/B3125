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
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import metier.modele.Activite;
import metier.modele.Adherent;
import metier.modele.Demande;
import metier.modele.Evenement;

/**
 *
 * @author Nico
 */
public class Serialisation {

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
    
    public static void printListeNomLieux(
        PrintWriter out, List<String> noms) {
        
        JsonArray jsonList = new JsonArray();
        
        for (String s : noms) {
            JsonObject jsonActivite = new JsonObject();
            
            jsonActivite.addProperty("nomLieu", s);
            
            jsonList.add(jsonActivite);
        }
        
        // Objet Json "conteneur"
        JsonObject container = new JsonObject();
        container.add("nomsLieux", jsonList);
        
        // Serialisation & écriture sur le flux de sortie
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(container);
        out.write(json);
    }
    
    public static void printListeStatuts(
        PrintWriter out, List<String> noms) {
        
        JsonArray jsonList = new JsonArray();
        
        for (String s : noms) {
            JsonObject jsonActivite = new JsonObject();
            
            jsonActivite.addProperty("statut", s);
            
            jsonList.add(jsonActivite);
        }
        
        // Objet Json "conteneur"
        JsonObject container = new JsonObject();
        container.add("statuts", jsonList);
        
        // Serialisation & écriture sur le flux de sortie
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(container);
        out.write(json);
    }
    
    public static void printListeDemandes(
        PrintWriter out, List<Demande> demandes) {
        
        JsonArray jsonList = new JsonArray();
        
        for (Demande d : demandes) {
            JsonObject jsonDemandeContainer = new JsonObject();
            JsonObject jsonDemande = new JsonObject();
            
            jsonDemande.addProperty("id", d.getId());
            jsonDemande.addProperty("activite", d.getActivite().getDenomination());
            jsonDemande.addProperty("date",dateToString(d.getDateDemande())); 
            if(d.getEvenement().getLieu() == null) {
                jsonDemande.addProperty("lieu","null");
            } else {
                jsonDemande.addProperty("lieu",d.getEvenement().getLieu().getDenomination());
            }
            jsonDemande.addProperty("dateEvenement",dateToString(d.getEvenement().getDateEvenement()));
            
            if(d.getEvenement().getDateEvenement().before(new Date())) {
                jsonDemande.addProperty("depasse",Boolean.TRUE);
            } else {
                jsonDemande.addProperty("depasse",Boolean.FALSE);
            }
            
            jsonDemande.addProperty("isParEquipe", d.getActivite().isParEquipe());
            
            
            if(d.getActivite().isParEquipe()) {
                JsonArray jsonEquipeA = new JsonArray();
                for(Adherent a :d.getEvenement().getEquipeA()){
                    JsonObject adherent = new JsonObject();
                    adherent.add("adherent", getAdherentInJson(a));
                    jsonEquipeA.add(adherent);
                }
                jsonDemande.add("equipeA", jsonEquipeA);
                
                JsonArray jsonEquipeB = new JsonArray();
                for(Adherent a :d.getEvenement().getEquipeB()){
                    JsonObject adherent = new JsonObject();
                    adherent.add("adherent", getAdherentInJson(a));
                    jsonEquipeA.add(adherent);
                }
                jsonDemande.add("equipeB", jsonEquipeB);
            } else {
                JsonArray jsonParticipants = new JsonArray();
                for(Adherent a :d.getEvenement().getParticipants()){
                    JsonObject adherent = new JsonObject();
                    adherent.add("adherent", getAdherentInJson(a));
                    jsonParticipants.add(adherent);
                }
                jsonDemande.add("participants", jsonParticipants);
            }
            jsonDemandeContainer.add("demande", jsonDemande);
            jsonList.add(jsonDemandeContainer);
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
    
    public static JsonObject getAdherentInJson(Adherent a){
        JsonObject jsonAdherent = new JsonObject();
        jsonAdherent.addProperty("nom",a.getNom());
        jsonAdherent.addProperty("prenom",a.getPrenom());
        return jsonAdherent;
    }
    

    public static void printListeEvenements(
        PrintWriter out, List<Evenement> evenements) {
        
        JsonArray jsonList = new JsonArray();
        
        for (Evenement e : evenements) {
            JsonObject jsonEvenementContainer = new JsonObject();
            JsonObject jsonEvenement = new JsonObject();
            
            jsonEvenement.addProperty("id", e.getId());
            jsonEvenement.addProperty("statut", e.getStatut());
            jsonEvenement.addProperty("activite", e.getActivite().getDenomination());
            jsonEvenement.addProperty("nbParticipants", e.getNombreParticipants());
            jsonEvenement.addProperty("nbParticipantsDemandes", e.getActivite().getNbParticipants());
            jsonEvenement.addProperty("nbParticipants", e.getNombreParticipants());
            jsonEvenement.addProperty("date",dateToString(e.getDateEvenement())); 
            if(e.getLieu() == null) {
                jsonEvenement.addProperty("lieu","null");
            } else {
                jsonEvenement.addProperty("lieu",e.getLieu().getDenomination());
            }
            if(e.getActivite().isParEquipe()) {
                JsonArray jsonEquipeA = new JsonArray();
                for(Adherent a :e.getEquipeA()){
                    JsonObject adherent = new JsonObject();
                    adherent.add("adherent", getAdherentInJson(a));
                    jsonEquipeA.add(adherent);
                }
                jsonEvenement.add("equipeA", jsonEquipeA);
                
                JsonArray jsonEquipeB = new JsonArray();
                for(Adherent a :e.getEquipeB()){
                    JsonObject adherent = new JsonObject();
                    adherent.add("adherent", getAdherentInJson(a));
                    jsonEquipeA.add(adherent);
                }
                jsonEvenement.add("equipeB", jsonEquipeB);
            } else {
                JsonArray jsonParticipants = new JsonArray();
                for(Adherent a :e.getParticipants()){
                    JsonObject adherent = new JsonObject();
                    adherent.add("adherent", getAdherentInJson(a));
                    jsonParticipants.add(adherent);
                }
                jsonEvenement.add("participants", jsonParticipants);
            }
            
            jsonEvenementContainer.add("evenement", jsonEvenement);
            jsonList.add(jsonEvenementContainer);
        }
        
        // Objet Json "conteneur"
        JsonObject container = new JsonObject();
        container.add("evenements", jsonList);
        
        // Serialisation & écriture sur le flux de sortie
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(container);
        out.write(json);
    }
}
