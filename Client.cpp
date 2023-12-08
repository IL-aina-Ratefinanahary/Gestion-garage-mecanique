#include<iostream>
#include "Client.h"

using namespace std;

// getters
int Client::get_id() const {
	return this->id;
}
string Client::get_nom() const{
	return this->nom;
}
string Client::get_adresse() const {
	return this->adresse;
}
string Client::get_phone() const {
	return this->phone;
}

//setters
void Client::set_id(int id) {
	this->id = id;
}
void Client::set_nom(const std::string& nom) {
	this->nom = nom;
}
void Client::set_adresse(const std::string& adresse) {
	this->adresse = adresse;
}
void Client::set_phone(const std::string& phone) {
	this->phone = phone;
}