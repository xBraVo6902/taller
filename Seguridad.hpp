
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"

using namespace std;

class Seguridad : public Software {
private:
    string tipoMalware;

public:
    Seguridad(const string& nombre, const string& desarrollador, int edad, float precio, const string& tipoMalware)
        : Software(nombre, desarrollador, edad, precio), tipoMalware(tipoMalware) {}

    const string& getTipoMalware() const { return tipoMalware; }
};