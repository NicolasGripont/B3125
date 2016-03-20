


public Class ChoisirLivreur { 

	public Livreur ChoisirLivreur( Commande commande ) {
		
		//coordonées destination commande : 
		Latlng latDest.lng = commande.client.getLongitude();
		latDest.lat = commande.client.getLatitude();
		// livreurs disponibles : 
		List<LivreurDrone> drones = LivreurDroneDao.findLivreursDisponibles();
		List<LivreurVelo> velos = LivreursVeloDao.findLivreursDisponibles();
		//tempo pour remplir les 2 listes à faire ici.

		//épurer la liste selon charges max :
		LivreursPossibleSelonChargeMax(drones, c);
		LivreursPossibleSelonChargeMax(velos, c);
		//Calcul du temps minimal :
		double tempsDrone = tempsMinDrone( drones, droneChoisi, latDest);
		double tempsVelo = tempsMinVelo( velos, veloChoisi, latDest); 
		if (tempsDrone < tempsvelo) 
		{
			return droneChoisi;
		else
		{
			return veloChoisi;
		}
		//faire la synchro
	}

	public double tempsMinDrone(List<LivreurDrone> drones, LivreurDrone droneChoisi, Latlng latDest ) {
		double tempsFinal = 1000; //unité à definir et à homogeneiser avec celle des velos (minutes).
		for ( int i = 0; i < drones.size(); i++ ) {
			Latlng latOrigin.lng = drones[i].getLongitude();
			latOrigin.lat = drones[i].getLatitude();
			double distance = GeoTest.getFlightDistanceInKm(latOrigin, latDest);
			float temps = distance / drones[i].vitesseMoyenneDeVol; //il faut connaitre l'unité de la vitesse (pas specifiee dans le sujet)
			if( temps < tempsFinal ) 
			{
				tempsFinal = temps;
				droneChoisi = new LivreurDrone(drones[i].getVitesseMoyenneDeVol(), drones[i].getMail(), drones[i].getMotDePasse(), drones[i].getAdresse(), drones[i].getChargeMax());
			}
		}
		return tempsFinal;		
	}

	public double tempsMinVelo ( List<LivreurVelo> velos, LivreurVelo veloChoisi, Latlng latDest) {
		double tempsFinal = 1000; 
		for ( int j = 0; j < velos.size(); j++ ) {
			Latlng latOrigin.lng = velos[i].getLongitude();
			latlng.lat = velos[i].getLatitude();
			double temps = GeoTest.getTripDurationByBicycleInMinute(latOrigin, latDest, /*steps : à voir*/ 0 ) ;
			if( temps < tempsFinal ) 
			{
				tempsFinal = temps;
				veloChoisi = new LivreurVelo(velos[i].getNom(), velos[i].getPrenom(), velos[i].getMail(), velos[i].getMotDePasse(), velos[i].getAdresse(), velos[i].getChargeMax());
			}		
		}
		return tempsFinal;
	}

	public void LivreursPossibleSelonChargeMax( List<Livreur> livreurs, Commande commande) {
		Float poidsTotal = 0;
		for ( int i =0; i < commande.lignesDeCommande.size(); i++) {
			poidsTotal = poidsTotal + commande.lignesDeCommande[i].getPoids();		
		}
		for ( int j = 0; j < livreurs.size(); j++ ) {
			if( livreurs[i].getChargeMax() < poidsTotal )
			{
				livreurs.remove(i);
			}
		} 	
	}
}
    
