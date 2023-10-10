
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Usuario.hpp"

using namespace std;

class Nino : public Usuario {
public:
    Nino(const string& nombreUsuario, const string& contrasena, int edad)
        : Usuario(nombreUsuario, contrasena, edad) {}

    void mostrarInfo() const override {
        cout << "Tipo de usuario: Niño" << endl;
        cout << "Dinero disponible: $" << getDinero() << endl;
    }
};
