
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"     // se incluye para poder usar la clase Software

using namespace std;

class Produccion : public Software {    // Produccion hereda de Software
private:
    string tipoSolucion;    // tipo de solucion que ofrece

public:
    Produccion(const string& nombre, const string& desarrollador, int edad, float precio, const string& tipoSolucion) // constructor
        : Software(nombre, desarrollador, edad, precio), tipoSolucion(tipoSolucion) {}

    const string& getTipoSolucion() const { return tipoSolucion; } // retorna el tipo de solucion
};