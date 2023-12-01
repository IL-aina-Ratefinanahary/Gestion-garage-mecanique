#include<iostream>

using namespace std;

// getters
int Client::get_id() const {
	return id;
}
string Client::get_nom() const{
	return nom;
}
string Client::get_adresse() const {
	return adresse;
}
string Client::get_phone() const {
	return phone;
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