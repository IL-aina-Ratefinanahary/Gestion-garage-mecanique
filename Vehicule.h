#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>

class Vehicule {
private:
	int id;
	std::string plaque;
	std::string modele;
	std::string annee;
	std::string type;
	static int id_suivant;

public:
	//Constructeur pour TODO
	Vehicule(const std::string& plaque, const std::string& modele,
		const std::string& annee, const std::string& type);


	//getters
	int get_id() const;
	std::string get_plaque() const;
	std::string get_modele() const;
	std::string get_annee() const;
	std::string get_type() const;

	//setters
	void set_id(int id);
	void set_plaque(const std::string& plaque);
	void set_modele(const std::string& modele);
	void set_annee(const std::string& annee);
	void set_type(const std::string& type);
};

#endif // !VEHICULE_H

