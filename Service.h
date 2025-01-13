#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include "Produit.h"

class Service : public Produit {
private:
	std::string description;
	double temps_d_execution;

public:
	// Constructeur pour initialiser un service avec un titre, un prix et une durée d'exécution
	Service(std::string titre, double prix, double temps_d_execution);

	// Méthodes héritées de la classe Produit
	double calculer_prix() override;
	void afficher() override;
	char get_type_produit() override;

	//getters
	std::string get_description() const;
	double get_temps_d_execution() const;

	//setters
	void set_description(const std::string& description);
	void set_temps_d_execution(double temps_d_execution);
};

#endif // !SERVICE_H

