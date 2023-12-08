#pragma once
#include <iostream>
#include "Produit.h"

class Piece : public Produit {
private:
	int quantite_en_depot;

public:
	Piece(std::string titre, double prix, int quatite_en_depot);
	void ajouter_piece_depot(int quantite);
	void soustraire_piece_depot(int quantite);

	virtual double calculer_prix() override;
	virtual void afficher() override;
	virtual char get_type_produit() override;

	//getters
	int get_quantite_en_depot() const;

	//setters
	void set_quantite_en_depot(int quantite_en_depot);
};