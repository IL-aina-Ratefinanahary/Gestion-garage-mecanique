#ifndef FACTURE_H
#define FACTURE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>

#include "Vehicule.h"
#include "Client.h"
#include "ProduitFacture.h"
#include "FactureFinaliseeException.h"
#include "FacturePasFinaliseeException.h"


class Facture {
private:
	int id;
	std::string date_facture;
	int status;		//0 sinon finalisee et 1 si finalisee 
	double balance;
	static int id_suivant;

	Client* client;
	Vehicule* vehicule;
	std::vector<ProduitFacture*> produits;

public:
	// Constructeurs
	Facture(std::string date_facture);	
	Facture(Client* client, std::string date);	
	Facture(Client* client, Vehicule* vehicule, std::string date);

	// M�thodes pour ajouter des produits � la facture
	void ajouter_produit(ProduitFacture* produit);
	void ajouter_produit(Produit* produit, int quantite);

	// M�thodes pour afficher et g�rer la facture
	void afficher_facture() const;
	double calculer_balance() const;
	void finaliser_facture();
	void enregistrer_facture() const;

	//getters
	int get_id() const;
	std::string get_date_facture() const;
	int get_status() const;
	double get_balance() const;

	//setters
	void set_id(int id);
	void set_date_facture(const std::string& date_facture);
	void set_status(int status);
	void set_balance(double balance);

	// M�thodes setter pour attribuer un client et un v�hicule "TODO"
	void set_client(Client* client);
	void set_vehicule(Vehicule* vehicule);
};

#endif // !FACTURE_H

