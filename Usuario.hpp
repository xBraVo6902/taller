#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Usuario {
protected:
    string nombreUsuario;
    string contrasena;
    int edad;
    vector<string> biblioteca;
    float dinero;

public:
    Usuario(const string& nombreUsuario, const string& contrasena, int edad)
        : nombreUsuario(nombreUsuario), contrasena(contrasena), edad(edad), dinero(0) {}

    const string& getNombreUsuario() const { return nombreUsuario; }
    const string& getContrasena() const { return contrasena; }
    int getEdad() const { return edad; }
    float getDinero() const { return dinero; }

    void verBiblioteca() const {
        if (biblioteca.empty()) {
            cout << "Biblioteca vacía." << endl;
            return;
        }
        cout << "Biblioteca de " << nombreUsuario << ":" << endl;
        for (const string& software : biblioteca) {
            cout << software << endl;
        }
    }

    void agregarSoftware(const string& nombreSoftware) {
    
    for (const string& software : biblioteca) {
        if (software == nombreSoftware) {
            cout << "El software ya está en tu biblioteca." << endl;
            return;
        }
    }

    biblioteca.push_back(nombreSoftware);
    cout << "El software se agregó con éxito." << endl;
}


    bool eliminarSoftware(const string& nombreSoftware) {
        for (auto it = biblioteca.begin(); it != biblioteca.end(); ++it) {
            if (*it == nombreSoftware) {
                biblioteca.erase(it);
                return true;
            }
        }
        return false;
    }

    const vector<string>& getBiblioteca() const { return biblioteca; }

    void agregarDinero(float cantidad) {
        dinero += cantidad;
    }

    void mostrarRegistroActividad(const unordered_map<string, vector<string>>& registro) const {
        cout << "Registro de actividad:" << endl;
        for (const auto& entry : registro) {
            cout << "Usuario: " << entry.first << endl;
            cout << "Actividades:" << endl;
            for (const string& actividad : entry.second) {
                cout << " - " << actividad << endl;
            }
            cout << endl;
        }
    }

    

    virtual void mostrarInfo() const = 0;
};