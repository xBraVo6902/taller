
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp" // se incluye para poder usar la clase Software

using namespace std;

class Ofimatica : public Software { // Ofimatica hereda de Software
private:
    int cantidadArchivos;   // cantidad de archivos creados

public:
    Ofimatica(const string& nombre, const string& desarrollador, int edad, float precio) // constructor
        : Software(nombre, desarrollador, edad, precio), cantidadArchivos(0) {}

    void crearArchivo() { // crea un archivo
        cantidadArchivos++;
    }

    void borrarArchivo() {  // borra un archivo
        if (cantidadArchivos > 0) {
            cantidadArchivos--;
        }
    }

    int getCantidadArchivos() const { return cantidadArchivos; } // retorna la cantidad de archivos
};