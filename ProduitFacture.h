#ifndef PRODUITFACTURE_H
#define PRODUITFACTURE_H

#include <iostream>
#include <iomanip>
#include "Produit.h"

class ProduitFacture {
private:
	int id;
	int quantite;
	double prix_total;
	static int id_suivant;
	Produit* produit;	//relation d'association avec la classe Produit

public:
	// Constructeur de ProduitFacture initialisant les attributs avec un Produit et une quantit�
	ProduitFacture(Produit* produit, int quantite);

	// M�thode pour afficher les d�tails du ProduitFacture
	void afficher_produit() const;

	//Pour surcharger l'operateur <<
	friend std::ostream& operator<<(std::ostream& os, const ProduitFacture& pf);

	//getters
	int get_id() const;
	int get_quantite() const;
	double get_prix_total() const;

	//setters
	void set_id(int id);
	void set_quantite(int quantite);
	void set_prix_total(double prix_total);

	// Fonction membre pour obtenir l'objet produit associ�
	Produit* get_produit() const {
		return produit;
	}
};

#endif // !PRODUITFACTURE_H

