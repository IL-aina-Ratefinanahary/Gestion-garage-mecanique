#include <iostream>
#include 'ProduitFacture.h'

using namespace std;

//je ne sais pas si j'ai bien fait! A revoir
ProduitFacture::ProduitFacture(Produit* produit, int quantite) {
	produit(produit),
	quantite(quantite),
	prix_total(quantite * (produit->calculer_prix()));	//valeur de prix_total recalculer selon calculer_prix() du Produit produit
}

void ProduitFacture::afficher_produit() const {
	cout << "Qte : " << quantite << " , Produit/Service : (" << produit->get_type_produit() << ") , Unitaire : " << produit->calculer_prix() << " , Total : " << prix_total<<endl;
}

/////////////surcharger l'operateur << pour avoir l'affichage voulue///////////////////////////



//getters
int ProduitFacture::get_id() const {
	return id;
}
int ProduitFacture::get_quantite() const {
	return quantite;
}
double ProduitFacture::get_prix_total() const {
	return prix_total;
}

//setters
void ProduitFacture::set_id(int id){ id(id) }
void ProduitFacture::set_quantite(int quantite){ quantite(quantite) }
void ProduitFacture::set_prix_total(double prix_total){ prix_total(prix_total) }