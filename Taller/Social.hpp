
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp" // se incluye para poder usar la clase Software

using namespace std;

class Social : public Software { // Social hereda de Software
private:
    vector<string> usuariosSociales; // usuarios sociales

public:
    Social(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio) {} // constructor

    // Método para agregar un usuario social
    void agregarUsuarioSocial(const string& nombreUsuario) { // agrega un usuario social al vector de usuarios sociales
        usuariosSociales.push_back(nombreUsuario); 
    }

    // Método para eliminar un usuario social
    void eliminarUsuarioSocial(const string& nombreUsuario) { // elimina un usuario social del vector de usuarios sociales
        for (auto it = usuariosSociales.begin(); it != usuariosSociales.end(); ++it) {
            if (*it == nombreUsuario) {
                usuariosSociales.erase(it);
                return;
            }
        }
    }

    const vector<string>& getUsuariosSociales() const { return usuariosSociales; } // retorna el vector de usuarios sociales
}; 