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

	setlocale(LC_ALL, "fr_FR");					//Pour les charactères français, accents.
	// Création de pièces et services
	cout << "**** Pièces et service ****" << endl;
	Piece* piece = new Piece("Piece", 10.0, 10);
	Service* service = new Service("Service", 20.0, 3);

	// TODO: ajoutez plus de pièces et de services
	Piece* piece1 = new Piece("Plaquettes frein", 15.0, 30);
	Service* service1 = new Service("main d'oeuvre", 10.0, 2);

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
	ProduitFacture* pfacture1 = new ProduitFacture(piece1, 5);
	pfacture1->afficher_produit();
	cout << *pfacture1 << endl;

	ProduitFacture* pfacture2 = new ProduitFacture(service, 3);
	pfacture2->afficher_produit();
	cout << *pfacture2 << endl;

	ProduitFacture* pfacture3 = new ProduitFacture(service1, 7);
	pfacture3->afficher_produit();
	cout << *pfacture3 << endl;

	// Création de clients et de véhicules
	cout << "\n**** Clients et véhicules ****" << endl;
	Client* client1 = new Client("Eduardo", "Rue X", "666 666-66-66");
	Vehicule* vehicule1 = new Vehicule("JHJ 233", "Honda", "2020", "Voiture");

	//TODO: créez plus des clients et de véhicules
	Client* client2 = new Client("Maxime", "Rue Y", "222 222-22-22");
	Vehicule* vehicule2 = new Vehicule("ZXZ 446", "Toyota", "2010", "Voiture");

	Client* client3 = new Client("Lily", "Rue Z", "333 333-33-33");
	Vehicule* vehicule3 = new Vehicule("GHG 332", "Mazda", "2008", "Voiture");

	// Création de facture
	cout << "\n**** Factures ****" << endl;
	Facture* facture = new Facture("11-11-2023");

	// Ajout de client et des véhicules à la facture
	facture->set_client(client1);
	facture->set_vehicule(vehicule1);

	//TODO: utilisez les autres versions de constructeur pour la class Facture

	Facture* facture2 = new Facture(client2, "15-11-2023");
	facture2->set_client(client2);						//ajout du client à la facture.
	facture2->set_vehicule(vehicule2);										//ajout du véhicule à la facture.

	Facture* facture3 = new Facture(client3, vehicule3, "30-11-2023");
	facture3->set_client(client3);				//ajout du client à la facture.
	facture3->set_vehicule(vehicule3);			//ajout du véhicule à la facture.

	cout << "\n**** Factures: ajouter produits ****" << endl;

	// Ajout de produits à la facture
	facture->ajouter_produit(pfacture);
	facture->ajouter_produit(service, 4);
	cout << "\n**** Factures: afficher factures ****" << endl;
	facture->afficher_facture();

	//TODO: ajoutez les produits aux autres factures
	facture2->ajouter_produit(pfacture1);
	facture2->ajouter_produit(service1, 5);
	cout << "\n**** Factures: afficher factures ****" << endl;
	facture2->afficher_facture();										//affiche facture 2

	facture3->ajouter_produit(pfacture2);
	facture3->ajouter_produit(piece, 9);
	cout << "\n**** Factures: afficher factures ****" << endl;
	facture3->afficher_facture();										//affiche facture 3


	//TODO: affichez toutes les factures. Ligne 101, 107 et 112

	cout << "\n**** Factures: scénarios d'exception ****" << endl;

	//Scénario pour finaliser une facture
	try {
		facture->finaliser_facture();
	}
	catch (const FactureFinaliseeException& e) {
		cout << e.what() << endl;
	}


	//TODO: Scénario pour finaliser une facture2
	
	try {
		facture2->finaliser_facture();
	}
	catch (const FactureFinaliseeException& e) {
		cout << e.what() << endl;
	}


	//TODO: Scénario pour finaliser une facture3 avec plus de pieces demandees par rapport a ce qu'on a en depot

	try {
		facture3->finaliser_facture();
	}
	catch (const FactureFinaliseeException& e) {
		cout << e.what() << endl;
	}


	//Scénario pour enregistrer une facture finalisée
	try {
		facture->enregistrer_facture();
	}
	catch (const FacturePasFinaliseeException& e) {
		cout << e.what() << endl;
	}

	//Scénario pour enregistrer une facture pas finalisée
	try {
		facture2->enregistrer_facture();
	}
	catch (const FacturePasFinaliseeException& e) {
		cout << e.what() << endl;
	}

	//TODO: Scénario pour finaliser une facture que demande plus des pièces qui sont
	//disponibles en dépôt
	try {
		facture3->enregistrer_facture();
	}
	catch (const FacturePasFinaliseeException& e) {
		cout << e.what() << endl;
	}

	//liberation de la memoire
	delete piece;
	delete piece1;
	delete service;
	delete service1;
	delete pfacture;
	delete pfacture1;
	delete pfacture2;
	delete pfacture3;
	delete client1;
	delete client2;
	delete client3;
	delete vehicule1;
	delete vehicule2;
	delete vehicule3;
	delete facture;
	delete facture2;
	delete facture3;

	return 0;
}