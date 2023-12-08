#include <iostream>
#include "Vehicule.h"

using namespace std;

//getters
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
void Vehicule::set_id(int id) { this->id = id; }
void Vehicule::set_plaque(const std::string& plaque) { this->plaque = plaque; }
void Vehicule::set_modele(const std::string& modele) { this->modele=modele; }
void Vehicule::set_annee(const std::string& annee) { this->annee = annee; }
void Vehicule::set_type(const std::string& type) { this->type=type; }