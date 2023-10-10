
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"

using namespace std;

class Social : public Software {
private:
    vector<string> usuariosSociales;

public:
    Social(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio) {}

    // Método para agregar un usuario social
    void agregarUsuarioSocial(const string& nombreUsuario) {
        usuariosSociales.push_back(nombreUsuario);
    }

    // Método para eliminar un usuario social
    void eliminarUsuarioSocial(const string& nombreUsuario) {
        for (auto it = usuariosSociales.begin(); it != usuariosSociales.end(); ++it) {
            if (*it == nombreUsuario) {
                usuariosSociales.erase(it);
                return;
            }
        }
    }

    const vector<string>& getUsuariosSociales() const { return usuariosSociales; }
};