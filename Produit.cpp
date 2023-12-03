#include <iostream>
#include 'Produit.h'

using namespace std;

//Constructeur?

//getters
int Produit::get_id() const {
	return id;
}
string Produit::get_nom() const {
	return nom;
}
double Produit::get_prix() const {
	return prix;
}

//setters
void Produit::set_id(int id){ id(id) }
void Produit::set_nom(const std::string& nom){ nom(nom) }
void Produit::set_prix(double prix) { prix(prix) }