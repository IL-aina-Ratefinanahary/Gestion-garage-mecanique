#include <iostream>

using namespace std;

#include "Piece.h"

Piece::Piece(std::string titre, double prix, int quantite_en_depot) :Produit(titre, prix) {
	this->quantite_en_depot = quantite_en_depot;
}

void Piece::ajouter_piece_depot(int quantite) {
	quantite_en_depot+=quantite;
}
void Piece::soustraire_piece_depot(int quantite) {
	if (quantite <= quantite_en_depot) {
		quantite_en_depot-=quantite;
	}
	else { //exception a considerer
		cout << "Quantit� insuffisante en depot";
	}
}

//override Produit calculer_prix()
double Piece::calculer_prix() {
	return get_prix();
}

//override Produit afficher()
void Piece::afficher() {
	cout << "Piece : " << get_nom() << ", $ " << calculer_prix() << ", En depot : " << quantite_en_depot << endl;
}

//override Produit get_type_produit() 
char Piece::get_type_produit() {
	return 'P'; // P pour piece
}

//getters
int Piece::get_quantite_en_depot() const {
	return this->quantite_en_depot;
}

//setters
void Piece::set_quantite_en_depot(int quantite_en_depot) { this->quantite_en_depot = quantite_en_depot; }