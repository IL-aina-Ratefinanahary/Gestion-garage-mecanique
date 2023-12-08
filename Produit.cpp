#include <iostream>
#include "Produit.h"

using namespace std;

//Constructeur
Produit::Produit(std::string titre, double prix):nom(titre),prix(prix){}

double Produit::calculer_prix()
{
	return 0.0;
}

void Produit::afficher()
{
}

char Produit::get_type_produit()
{
	return 0;
}



//getters
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
void Produit::set_id(int id) { this->id = id; }
void Produit::set_nom(const std::string& nom) { this->nom = nom; }
void Produit::set_prix(double prix) { this->prix = prix; }