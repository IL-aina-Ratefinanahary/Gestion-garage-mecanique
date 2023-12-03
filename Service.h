#pragma once
#include <iostream>
#include "Produit.h"

class Service : public Produit {
private:
	std::string description;
	double temps_d_execution;<
	//double prix_heure;

public:
	Service(std::string titre, /*double prix_heure */, double temps_d_execution);

	//getters
	std::string get_description() const;
	double get_temps_d_execution() const;

	//setters
	void set_description(const std::string& description);
	void set_temps_d_execution(const std::string& temps_d_execution);
};