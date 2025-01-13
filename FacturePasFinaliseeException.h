#ifndef FACTUREPASFINALISEEEXCEPTION_H
#define FACTUREPASFINALISEEEXCEPTION_H

#include <iostream>
#include <stdexcept>

class FacturePasFinaliseeException : public std::runtime_error {
public:
    FacturePasFinaliseeException() : std::runtime_error("La facture doit être finalisée avant le registre. Sauvegarde  de la facture non-finalisée dans un fichier .txt") {}
};


#endif // !FACTUREPASFINALISEEEXCEPTION_H