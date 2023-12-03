#pragma once
#include <iostream>
#include 'ProduitFacture.h'

class Produit {
protected:
	int id_suivant;

private:
	int id;
	std::string nom;
	double prix;

public:
	Produit(std::string titre, double prix); //Voir note de cours pour savoir comment faire avec ca?
	virtual double calculer_prix() const = 0;
	virtual void afficher() const =0;
	virtual char get_type_produit() const =0;

	//getters
	int get_id() const;
	std::string get_nom() const;
	double get_prix() const;

	//setters
	void set_id(int id);
	void set_nom(const std::string& nom);
	void set_prix(double prix);
};