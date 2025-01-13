#include <iostream>
#include "ProduitFacture.h"

using namespace std;

int ProduitFacture::id_suivant = 1;

// Constructeur de ProduitFacture initialisant les attributs avec un Produit et une quantité
ProduitFacture::ProduitFacture(Produit* produit, int quantite) {
	this->id = id_suivant++;
	this->produit = produit;
	this->quantite = quantite;
	this->prix_total = quantite * (produit->calculer_prix());
	/*
	valeur du prix_total recalculee selon get_prix() du Produit produit non pas calculer_prix() 
	car si on utilise calculer_prix, pour les produits Service
	cela ne va s'afficher logiquement comme il faut
	*/
}

// Méthode affichant les détails du ProduitFacture
void ProduitFacture::afficher_produit() const {
	cout << setw(3) << "Qte : " << quantite << setw(19) <<" , Produit/Service : (" << produit->get_type_produit() << ")" << setw(5) <<", Unitaire: " << produit->get_prix() << setw(9) << ", Total : " << prix_total << endl;
}

// surcharge de l'operateur << pour avoir l'affichage voulue
ostream& operator<<(std::ostream& os, const ProduitFacture& pf) {
	os << setw(3) << pf.get_quantite()  << " | " << setw(19) << pf.produit->get_nom() << " ("
		<< (pf.produit->get_type_produit() == 'P' ? 'P' : 'S') << ") | "
		<< setw(9) << pf.produit->get_prix() << " | " << setw(9) << pf.get_prix_total();
	return os;
}


//getters
int ProduitFacture::get_id() const {
	return this->id;
}
int ProduitFacture::get_quantite() const {
	return this->quantite;
}
double ProduitFacture::get_prix_total() const {
	return this->prix_total;
}

//setters
void ProduitFacture::set_id(int id) { this->id = id; }
void ProduitFacture::set_quantite(int quantite) { this->quantite = quantite; }
void ProduitFacture::set_prix_total(double prix_total) { this->prix_total = prix_total; }