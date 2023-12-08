#include <iostream>
#include "ProduitFacture.h"

using namespace std;


ProduitFacture::ProduitFacture(Produit* produit, int quantite){
	this->id=id_suivant++;
	this->produit=produit;
	this->quantite=quantite;
	this->prix_total=quantite * (produit->calculer_prix());	//valeur du prix_total recalculee selon calculer_prix() du Produit produit
}

void ProduitFacture::afficher_produit() const {
	cout << "Qte : " << quantite << " , Produit/Service : (" << produit->get_type_produit() << ") , Unitaire : " << produit->calculer_prix() << " , Total : " << prix_total <<endl;
}

// surcharge de l'operateur << pour avoir l'affichage voulue
ostream& operator<<(std::ostream& os, const ProduitFacture& pf) {
	os << pf.get_quantite() << " | " << pf.produit->get_type_produit() << " ("
		<< (pf.produit->get_type_produit() == 'P' ? 'P' : 'S') << ") | "
		<< pf.produit->calculer_prix() << " | " << pf.get_prix_total();
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
void ProduitFacture::set_prix_total(double prix_total) { this->prix_total=prix_total; }