
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Usuario.hpp" // se incluye para poder usar la clase Usuario

using namespace std;

class Nino : public Usuario { // Nino hereda de Usuario
public:
    Nino(const string& nombreUsuario, const string& contrasena, int edad)
        : Usuario(nombreUsuario, contrasena, edad) {} // constructor

    void mostrarInfo() const override { // muestra la informacion del niño
        cout << "Tipo de usuario: Niño" << endl;
        cout << "Dinero disponible: $" << getDinero() << endl;
    }
};
