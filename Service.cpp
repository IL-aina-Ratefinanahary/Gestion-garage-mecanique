#include <iostream>
#include "Service.h"

using namespace std;

Service::Service(std::string titre, /*double prix_heure */, double temps_d_execution) { titre(titre), /* prix_heure(prix_heure) */, temps_d_execution(temps_d_execution) }

//override Produit calculer_prix()
void Service::calculer_prix() const override {
	return /* temps_d_execution*prix_heure; */
}

//override Produit afficher()
void Service::afficher() const override {
	cout << "Service : " << titre << ", $ " << /* prix_heure << */" , Execution : " << temps_d_execution << endl;
}

//override Produit get_type_produit()
char Service::get_type_produit() const override {
	return 'S';
}