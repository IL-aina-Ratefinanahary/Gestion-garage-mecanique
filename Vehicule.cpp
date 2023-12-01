#include <iostream>

using namespace std;

//getters
int Vehicule::get_id() const {
	return id;
}
string Vehicule::get_plaque() const {
	return plaque;
}
string Vehicule::get_modele() const {
	return modele;
}
string Vehicule::get_annee() const {
	return annee;
}
string Vehicule::get_type() const {
	return type;
}

//setters
void Vehicule::set_id(int id) { id(id) }
void Vehicule::set_plaque(const std::string& plaque) { plaque(plaque) }
void Vehicule::set_modele(const std::string& modele) { modele(modele) }
void Vehicule::set_annee(const std::string& annee) { annee(annee) }
void Vehicule::set_typt(const std::string& type) { type(type) }