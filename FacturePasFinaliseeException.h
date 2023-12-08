#pragma once
#include <iostream>
#include <stdexcept>

class FacturePasFinaliseeException : public std::runtime_error {
public:
    FacturePasFinaliseeException() : std::runtime_error("La facture doit �tre finalis�e avant le registre") {}
};
