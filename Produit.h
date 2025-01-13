#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>


class Produit {
protected:
	int id_suivant;

private:
	int id;
	std::string nom;
	double prix;

public:
	virtual ~Produit() = default;	// Destructeur
	Produit(std::string titre, double prix);
	virtual double calculer_prix();
	virtual void afficher();
	virtual char get_type_produit();

	//getters
	int get_id() const;
	std::string get_nom() const;
	double get_prix() const;

	//setters
	void set_id(int id);
	void set_nom(const std::string& nom);
	void set_prix(double prix);
};

#endif // !PRODUIT_H
