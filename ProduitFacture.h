#pragma once
#include <iostream>


class ProduitFacture {
private:
	int id;
	int quantite;
	double prix_total;
	static int id_suivant;
	Produit* produit;	//relation d'association

public:
	ProduitFacture(Produit* produit, int quantite);
	void afficher_produit() const;

	//getters
	int get_id() const;
	int get_quantite() const;
	double get_prix_total() const;

	//setters
	void set_id(int id);
	void set_quantite(int quantite);
	void set_prix_total(double prix_total);
};