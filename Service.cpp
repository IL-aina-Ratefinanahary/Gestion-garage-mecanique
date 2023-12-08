#include <iostream>
#include "Service.h"

using namespace std;
Service::Service(std::string titre,double prix, double temps_d_execution)
	: Produit(titre, prix), temps_d_execution(temps_d_execution) {
	description = titre;
	this->temps_d_execution = temps_d_execution;
}

//override Produit calculer_prix()
double Service::calculer_prix() {
	return temps_d_execution * get_prix();
}

//override Produit afficher()
void Service::afficher() {
	cout << "Service : " << get_description() << ", $ " << calculer_prix() << " , Execution : " << get_temps_d_execution() << endl;
}

//override Produit get_type_produit()
char Service::get_type_produit() {
	return 'S';
}

//getters
string Service::get_description() const {
	return this->description;
}

double Service::get_temps_d_execution() const {
	return this->temps_d_execution;
}

//setters
void Service::set_description(const std::string& description) { this->description=description; }
void Service::set_temps_d_execution(double temps_d_execution) { this->temps_d_execution = temps_d_execution; }

