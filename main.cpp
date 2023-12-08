#include <iostream>
#include <stdexcept>

// TODO: d'autres includes
#include <fstream>
#include <vector>
#include <sstream>

#include "Facture.h"
#include "Client.h"
#include "Vehicule.h"
#include "FactureFinaliseeException.h"
#include "FacturePasFinaliseeException.h"
#include "ProduitFacture.h"
#include "ProduitFacture.h"
#include "Produit.h"
#include "Piece.h"
#include "Service.h"


using namespace std;

// En supposant que les classes Client, Vehicule, Produit, Piece, Service,ProduitFacture, 
// Facture, FactureFinaliseeException, FacturePasFinaliseeException soient définies…

int main() {
	// Création de pièces et services
	cout << "**** Pieces et service ****" << endl;
	Piece* piece = new Piece("Piece", 10.0, 10);
	Service* service = new Service("Service", 20.0, 3);

	// TODO: ajoutez plus de pièces et de services
	Piece* piece1 = new Piece("Piece", 13.0, 33);
	Service* service1 = new Service("Service", 66.0, 5);

	piece->afficher();
	service->afficher();

	// TODO: ajoutez les appels des méthodes d'autres pièces et services
	piece1->afficher();
	service1->afficher();

	cout << "\n**** ProduitFacture ****" << endl;

	// Création de produit-facture
	ProduitFacture* pfacture = new ProduitFacture(piece, 6);
	pfacture->afficher_produit();
	cout << *pfacture << endl;

	//TODO: créez plus des produit-Facture
	ProduitFacture* pfacture3 = new ProduitFacture(service, 4);
	pfacture3->afficher_produit();
	cout << *pfacture3 << endl;


	ProduitFacture* pfacture1 = new ProduitFacture(piece1, 10);
	pfacture1->afficher_produit();
	cout << *pfacture1 << endl;


	ProduitFacture* pfacture2 = new ProduitFacture(service1, 3);
	pfacture2->afficher_produit();
	cout << *pfacture2 << endl;
	
	// Création de clients et de véhicules
	cout << "\n**** Clients et véhicules ****" << endl;
	Client* client1 = new Client("Eduardo", "Rue X", "666 666-66-66");
	Vehicule* vehicule1 = new Vehicule("JHJ 233", "Honda", "2020", "Voiture");

	//TODO: créez plus des clients et de véhicules
	
	// Création de facture
	cout << "\n**** Factures ****" << endl;
	Facture* facture = new Facture("11-11-2023");

	// Ajout de client et des véhicules à la facture
	facture->set_client(client1);
	facture->set_vehicule(vehicule1);

	//TODO: utilisez les autres versions de constructeur pour la class Facture

	cout << "\n**** Factures: ajouter produits ****" << endl;

	// Ajout de produits à la facture
	facture->ajouter_produit(pfacture);
	facture->ajouter_produit(service, 4);
	cout << "\n**** Factures: afficher factures ****" << endl;
	facture->afficher_facture();

	//TODO: ajoutez les produits aux autres factures
	
	//TODO: affichez toutes les 

	cout << "\n**** Factures: scénarios d'exception ****" << endl;

	//Scénario pour finaliser une facture
	try {
		facture->finaliser_facture();
	}
	catch (const FactureFinaliseeException& e) {
		cout << e.what() << endl;
	}

	//TODO: Scénario pour finaliser une facture que demande plus des pièces qui sont disponibles en dépôt
		
	//Scénario pour enregistrer une facture finalisée
		try {
		facture->enregistrer_facture();
	}
	catch (const FacturePasFinaliseeException& e) {
		cout << e.what() << endl;
	}

	//TODO: Scénario pour essayer d'enregistrer une facture pas finalisée


	delete piece;
	delete service;
	delete pfacture;
	delete client1;
	delete vehicule1;
	delete facture;

	return 0;
}