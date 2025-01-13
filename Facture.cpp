#include <iostream>
#include <fstream> // Pour la gestion des fichiers
#include <vector>
#include "Facture.h"
#include "Piece.h"
#include "Service.h"

using namespace std;

int Facture::id_suivant = 1;    // Initialisation de la variable statique id_suivant

// Constructeur de Facture prenant la date de la facture comme argument
Facture::Facture(std::string date_facture)
    : id(id_suivant++), date_facture(date_facture), status(0), balance(0.0), client(nullptr), vehicule(nullptr) {}

// Constructeur de Facture prenant un client et une date comme arguments
Facture::Facture(Client* client, std::string date)
    : id(id_suivant++), date_facture(date), status(0), balance(0.0), client(client), vehicule(nullptr) {}

// Constructeur de Facture prenant un client, un véhicule et une date comme arguments
Facture::Facture(Client* client, Vehicule* vehicule, std::string date)
    : id(id_suivant++), date_facture(date), status(0), balance(0.0), client(client), vehicule(vehicule) {}

// Méthode pour ajouter un produit à la facture en prenant un ProduitFacture comme argument
void Facture::ajouter_produit(ProduitFacture* produit) {
    //Lancement de l'exception si la facture est finalisee
    if (status == 1) {
        throw FactureFinaliseeException();
    }
    produits.push_back(produit);
}

// Méthode pour ajouter un produit avec une quantité spécifique à la facture
void Facture::ajouter_produit(Produit* produit, int quantite) {
    ProduitFacture* produitFacture = new ProduitFacture(produit, quantite);
    produits.push_back(produitFacture);
}

// Méthode pour calculer le total de la facture en parcourant tous les produits
double Facture::calculer_balance() const {
    double total = 0.0;
    for (const auto& produit : produits) {
        total += produit->get_prix_total();
    }
    return total;
}

// Méthode pour afficher les détails de la facture dans la console
void Facture::afficher_facture() const {
    cout << "------------------------------------------------------------" << endl;
    cout << "                        FACTURE" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Afficher les informations du client et du véhicule
    cout << "Client: " << client->get_nom() << endl;
    cout << "Adresse: " << client->get_adresse() << endl;
    cout << "Phone: " << client->get_phone() << endl;
    cout << "Vehicule: " << vehicule->get_modele() << "| Plaque: " << vehicule->get_plaque() << endl;

    cout << "------------------------------------------------------------" << endl;
    cout << setw(3)<< "Qte"<<" | "<< setw(23) <<" Produit / Service" <<" | "<< setw(9)<< "Unitaire" <<" | "<< setw(9) <<"Total" << endl;
    for (const auto& produit : produits) {
        cout << *produit << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    cout <<setw(44)<< "Balance| " << setw(9) << calculer_balance() << endl;
    cout << endl;
}

// Méthode pour finaliser la facture en mettant à jour les quantités en stock pour les pièces et le statut de la facture
void Facture::finaliser_facture() {
    if (status == 1) {
        throw FactureFinaliseeException();
    }

    // Mettre à jour la quantité en soustrayant la quantité vendue pour chaque Pièce
    for (auto& pf : produits) {
        // Vérifiez si c'est une pièce pour mettre à jour la quantité en soustrayant la quantité vendue
        if (auto piece = dynamic_cast<Piece*>(pf->get_produit())) {
            int temp = piece->get_quantite_en_depot();
            piece->soustraire_piece_depot(pf->get_quantite());
            if (piece->get_quantite_en_depot() == 0) { 
                pf->set_quantite(temp);
            }
        }
    }

    status = 1;
    balance = calculer_balance(); // Mettre à jour la balance lors de la finalisation
}

// Méthode pour enregistrer les détails de la facture dans un fichier texte
void Facture::enregistrer_facture() const {
    //lancement de l'exception si facture non finalisee (status = 0)
    if (status == 0) {
        ofstream file("facture-" + to_string(id) + ".txt");
        if (file.is_open()) {
            file << "------------------------------------------------------------" << endl;

            file << "FACTURE" << endl;

            file << "------------------------------------------------------------" << endl;

            file << "Client: " << client->get_nom() << endl;

            file << "Adresse: " << client->get_adresse() << endl;

            file << "Phone: " << client->get_phone() << endl;

            file << "Vehicule: " << vehicule->get_modele() << "| Plaque: " << vehicule->get_plaque() << endl;

            file << "------------------------------------------------------------" << endl;

            file << "Qte | Produit / Service | Unitaire | Total" << endl;

            for (const auto& pf : produits) {
                file << pf->get_quantite() << " | " << pf->get_produit()->get_type_produit() << " | "
                    << pf->get_produit()->calculer_prix() << " | " << pf->get_prix_total() << "\n";
            }

            file << "------------------------------------------------------------" << endl;
            file << "Balance| " << calculer_balance() << endl;
        }
        else {
            // Gestion des erreurs durant l'ouverture du fichier
            throw std::runtime_error("Impossible d'ouvrir le fichier pour enregistrer la facture.");
        }
        throw FacturePasFinaliseeException();
    }

    //sauvegarde des donnees de la Facture dans un fichier txt
    ofstream file("facture-" + to_string(id) + ".txt");
    if (file.is_open()) {
        file << "------------------------------------------------------------" << endl;

        file << "FACTURE" << endl;

        file << "------------------------------------------------------------" << endl;

        file << "Client: " << client->get_nom() << endl;

        file << "Adresse: " << client->get_adresse() << endl;

        file << "Phone: " << client->get_phone() << endl;

        file << "Vehicule: " << vehicule->get_modele() << "| Plaque: " << vehicule->get_plaque() << endl;

        file << "------------------------------------------------------------" << endl;

        file << "Qte | Produit / Service | Unitaire | Total" << endl;

        for (const auto& pf : produits) {
            file << pf->get_quantite() << " | " << pf->get_produit()->get_type_produit() << " | "
                << pf->get_produit()->calculer_prix() << " | " << pf->get_prix_total() << "\n";
        }

        file << "------------------------------------------------------------" << endl;
        file << "Balance| " << calculer_balance() << endl;
    }
    else {
        // Gestion des erreurs durant l'ouverture du fichier
        throw std::runtime_error("Impossible d'ouvrir le fichier pour enregistrer la facture.");
    }
}


//getters
//pour récupérer les attributs de la facture
int Facture::get_id() const
{
    return this->id;
}

string Facture::get_date_facture() const
{
    return this->date_facture;
}

int Facture::get_status() const
{
    return this->status;
}

double Facture::get_balance() const
{
    return this->balance;
}



//setters
// pour définir les attributs de la facture
void Facture::set_id(int id)
{
    this->id = id;
}

void Facture::set_date_facture(const string& date_facture)
{
    this->date_facture = date_facture;
}

void Facture::set_status(int status)
{
    this->status = status;
}

void Facture::set_balance(double balance)
{
    this->balance = balance;
}

//Setters client et vehicule pour TODO
void Facture::set_client(Client* client)
{
    this->client = client;
}

void Facture::set_vehicule(Vehicule* vehicule)
{
    this->vehicule = vehicule;
}

