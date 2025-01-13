#include <iostream>

#include "Piece.h"

using namespace std;

// D�finition du constructeur de la classe Piece qui initialise les attributs titre, prix et quantite_en_depot
Piece::Piece(std::string titre, double prix, int quantite_en_depot) :Produit(titre, prix) {
	this->quantite_en_depot = quantite_en_depot;
}

// M�thode pour ajouter des pi�ces au stock en d�p�t
void Piece::ajouter_piece_depot(int quantite) {
	quantite_en_depot += quantite;
}

// M�thode pour soustraire des pi�ces du stock en d�p�t
void Piece::soustraire_piece_depot(int quantite) {
	try{
		if (quantite <= quantite_en_depot) {
			quantite_en_depot -= quantite;
		}
		else {
			//exception � consid�rer quand la quantite est insuffisante
			throw::std::runtime_error("Quantit� insuffisante en d�pot, le reste du d�p�t sera ajout� � la facture.");
		}
	}
	catch (const std::runtime_error& e) {
		// G�rer l'exception ici (affichage du message)
		std::cerr << "Erreur : " << e.what() << endl;
	}
}

//override Produit calculer_prix()
// M�thode pour calculer le prix des pi�ces
double Piece::calculer_prix() {
	return get_prix();
}

//override Produit afficher()
// M�thode pour afficher les d�tails de la pi�ce
void Piece::afficher() {
	cout << "Piece : " << get_nom() << ", $ " << calculer_prix() << ", En depot : " << quantite_en_depot << endl;
}

//override Produit get_type_produit()
// M�thode pour obtenir le type de produit (dans ce cas, 'P' pour Pi�ce)
char Piece::get_type_produit() {
	return 'P'; // P pour piece
}

//getters
// Pour obtenir la quantit� en d�p�t
int Piece::get_quantite_en_depot() const {
	return this->quantite_en_depot;
}

//setters
// Pour d�finir la quantit� en d�p�t
void Piece::set_quantite_en_depot(int quantite_en_depot) { this->quantite_en_depot = quantite_en_depot; }