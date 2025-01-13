#include <iostream>
#include "Produit.h"

using namespace std;

//Constructeur
//initialise les attributs nom et prix de l'objet Produit
Produit::Produit(std::string titre, double prix) :id(id_suivant++), nom(titre), prix(prix) {}

// Méthode pour calculer le prix du produit (à implémenter dans les classes dérivées)
double Produit::calculer_prix()
{
	return 0.0;
}

// Méthode pour afficher les détails du produit 
void Produit::afficher()
{
}

// Méthode retournant le type de produit
char Produit::get_type_produit()
{
	return 0;
}



//getters
//pour récupérer les attributs de l'objet Produit
int Produit::get_id() const {
	return this->id;
}
string Produit::get_nom() const {
	return this->nom;
}
double Produit::get_prix() const {
	return this->prix;
}

//setters
//pour définir les attributs de l'objet Produit
void Produit::set_id(int id) { this->id = id; }
void Produit::set_nom(const std::string& nom) { this->nom = nom; }
void Produit::set_prix(double prix) { this->prix = prix; }