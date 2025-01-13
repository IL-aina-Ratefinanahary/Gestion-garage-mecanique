#include <iostream>
#include "Vehicule.h"

using namespace std;

int Vehicule::id_suivant = 1;

//constructeur
//initialise les attributs de la classe Vehicule
Vehicule::Vehicule(const std::string& plaque, const std::string& modele,
	const std::string& annee, const std::string& type) {
	this->plaque = plaque;
	this->modele = modele;
	this->annee = annee;
	this->type = type;
	this->id = id_suivant++;

}

//getters
//pour récupérer les attributs de la classe Vehicule
int Vehicule::get_id() const {
	return this->id;
}
string Vehicule::get_plaque() const {
	return this->plaque;
}
string Vehicule::get_modele() const {
	return this->modele;
}
string Vehicule::get_annee() const {
	return this->annee;
}
string Vehicule::get_type() const {
	return this->type;
}

//setters
//pour définir les attributs de la classe Vehicule
void Vehicule::set_id(int id) { this->id = id; }
void Vehicule::set_plaque(const std::string& plaque) { this->plaque = plaque; }
void Vehicule::set_modele(const std::string& modele) { this->modele = modele; }
void Vehicule::set_annee(const std::string& annee) { this->annee = annee; }
void Vehicule::set_type(const std::string& type) { this->type = type; }