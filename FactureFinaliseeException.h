#pragma once
#include <iostream>
#include <stdexcept>

class FactureFinaliseeException : public std::runtime_error {
public:
    FactureFinaliseeException() : std::runtime_error("La facture a d�j� �t� finalis�e") {}
};