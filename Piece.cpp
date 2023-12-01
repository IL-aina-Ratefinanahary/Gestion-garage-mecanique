#include <iostream>

using namespace std;

Piece::Piece(std::string titre, double prix, int quantite_en_depot):Produit(titre,prix) {
	this->quantite = quantite_en_depot;
}
void Piece::ajouter_piece_depot(int quantite) {
	this->quantite += quantite_en_depot;
}
void Piece::soustraire_piece_depot(int quantite) {
	if (quantite <= quantite_en_depot) {
		quantite -= quantite_en_depot;
	}
	else {
		cout << "Quantité insuffisante en dépôt";
	}
}


//getters
int get_quantite_en_depot() const {
	return quantite_en_depot;
}

//setters
void set_quantite_en_depot(int quantite_en_depot) { quantite_en_depot(quantite_en_depot) }