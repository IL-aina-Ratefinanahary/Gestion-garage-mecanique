#pragma once
#include <iostream>
#include "Vehicule.h"
#include "Client.h"
#include "ProduitFacture.h"


class Facture {
private:
	int id;
	std::string date_facture;
	int status;		//0 sinon finalisee et 1 si finalisee 
	double balance;
	static int id_suivant;

	Vehicule vehicule;
	std::vector<ProduitFacture> produits;

public:
	Facture(std::string date_facture);
	Facture(Client client, std::string date);
	Facture(Client client, Vehicule vehicule, std::string date);
	void ajouter_produit(const ProduitFacture& produit);
	void ajouter_produit(Produit* produit, int quantite);
	void afficher_facture();
	double calculer_balance();
	void finaliser_facture();
	void enregistrer_facture();

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
};