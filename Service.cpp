#include <iostream>
#include "Service.h"

using namespace std;

// Constructeur de la classe Service, initialisant les attributs de Produit et ceux sp�cifiques � Service
Service::Service(std::string titre, double prix, double temps_d_execution)
	: Produit(titre, prix), temps_d_execution(temps_d_execution) {
	description = titre;
	this->temps_d_execution = temps_d_execution;
}

//override Produit calculer_prix()
// Red�finition de la m�thode calculer_prix de la classe Produit pour Service
double Service::calculer_prix() {
	return temps_d_execution * get_prix();
}

//override Produit afficher()
// Red�finition de la m�thode afficher de la classe Produit pour Service
void Service::afficher() {
	cout << "Service : " << get_description() << ", $ " << get_prix() << " , Execution : " << get_temps_d_execution() <<"h"<< endl;
}

//override Produit get_type_produit()
// Red�finition de la m�thode get_type_produit de la classe Produit pour Service
char Service::get_type_produit() {
	return 'S';
}

//getters
//pour r�cup�rer les attributs sp�cifiques de Service
string Service::get_description() const {
	return this->description;
}

double Service::get_temps_d_execution() const {
	return this->temps_d_execution;
}

//setters
//pour d�finir les attributs sp�cifiques de Service
void Service::set_description(const std::string& description) { this->description = description; }
void Service::set_temps_d_execution(double temps_d_execution) { this->temps_d_execution = temps_d_execution; }

