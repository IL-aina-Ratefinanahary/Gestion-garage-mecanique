#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "Vehicule.h"

class Client {
private:
	int id;
	std::string nom;
	std::string adresse;
	std::string phone;
	static int id_suivant;

public:
	// Constructeur a utiliser dans TODO
	Client(const std::string& nom, const std::string& adresse, const std::string& phone);


	// getters
	int get_id() const;
	std::string get_nom() const;
	std::string get_adresse() const;
	std::string get_phone() const;

	//setters
	void set_id(int id);
	void set_nom(const std::string& nom);
	void set_adresse(const std::string& adresse);
	void set_phone(const std::string& phone);
};

#endif // !CLIENT_H
