
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"

using namespace std;

class Ofimatica : public Software {
private:
    int cantidadArchivos;

public:
    Ofimatica(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio), cantidadArchivos(0) {}

    void crearArchivo() {
        cantidadArchivos++;
    }

    void borrarArchivo() {
        if (cantidadArchivos > 0) {
            cantidadArchivos--;
        }
    }

    int getCantidadArchivos() const { return cantidadArchivos; }
};