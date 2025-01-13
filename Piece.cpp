#include <iostream>

#include "Piece.h"

using namespace std;

// Définition du constructeur de la classe Piece qui initialise les attributs titre, prix et quantite_en_depot
Piece::Piece(std::string titre, double prix, int quantite_en_depot) :Produit(titre, prix) {
	this->quantite_en_depot = quantite_en_depot;
}

// Méthode pour ajouter des pièces au stock en dépôt
void Piece::ajouter_piece_depot(int quantite) {
	quantite_en_depot += quantite;
}

// Méthode pour soustraire des pièces du stock en dépôt
void Piece::soustraire_piece_depot(int quantite) {
	try{
		if (quantite <= quantite_en_depot) {
			quantite_en_depot -= quantite;
		}
		else {
			//exception à considérer quand la quantite est insuffisante
			throw::std::runtime_error("Quantité insuffisante en dépot, le reste du dépôt sera ajouté à la facture.");
		}
	}
	catch (const std::runtime_error& e) {
		// Gérer l'exception ici (affichage du message)
		std::cerr << "Erreur : " << e.what() << endl;
	}
}

//override Produit calculer_prix()
// Méthode pour calculer le prix des pièces
double Piece::calculer_prix() {
	return get_prix();
}

//override Produit afficher()
// Méthode pour afficher les détails de la pièce
void Piece::afficher() {
	cout << "Piece : " << get_nom() << ", $ " << calculer_prix() << ", En depot : " << quantite_en_depot << endl;
}

//override Produit get_type_produit()
// Méthode pour obtenir le type de produit (dans ce cas, 'P' pour Pièce)
char Piece::get_type_produit() {
	return 'P'; // P pour piece
}

//getters
// Pour obtenir la quantité en dépôt
int Piece::get_quantite_en_depot() const {
	return this->quantite_en_depot;
}

//setters
// Pour définir la quantité en dépôt
void Piece::set_quantite_en_depot(int quantite_en_depot) { this->quantite_en_depot = quantite_en_depot; }