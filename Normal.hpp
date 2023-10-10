
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Usuario.hpp"

using namespace std;

class Normal : public Usuario {
private:
    string correo;

public:
    Normal(const string& nombreUsuario, const string& contrasena, int edad, const string& correo)
        : Usuario(nombreUsuario, contrasena, edad), correo(correo) {}

    void mostrarInfo() const override {
        cout << "Tipo de usuario: Normal" << endl;
        cout << "Correo: " << correo << endl;
        cout << "Dinero disponible: $" << getDinero() << endl;
    }
};