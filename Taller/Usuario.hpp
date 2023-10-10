#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Usuario { // clase abstracta
protected:
    string nombreUsuario; // nombre de usuario
    string contrasena; // contrasena del usuario
    int edad; // edad del usuario
    vector<string> biblioteca; // biblioteca del usuario
    float dinero; // dinero del usuario

public:
    Usuario(const string& nombreUsuario, const string& contrasena, int edad)
        : nombreUsuario(nombreUsuario), contrasena(contrasena), edad(edad), dinero(0) {}    // constructor

    const string& getNombreUsuario() const { return nombreUsuario; } // retorna el nombre de usuario
    const string& getContrasena() const { return contrasena; } // retorna la contrasena
    int getEdad() const { return edad; } // retorna la edad
    float getDinero() const { return dinero; } // retorna el dinero

    void verBiblioteca() const { // muestra la biblioteca del usuario
        if (biblioteca.empty()) {
            cout << "Biblioteca vacía." << endl; // si la biblioteca esta vacia
            return;
        }
        cout << "Biblioteca de " << nombreUsuario << ":" << endl; // si la biblioteca no esta vacia
        for (const string& software : biblioteca) {
            cout << software << endl;
        }
    }

    void agregarSoftware(const string& nombreSoftware) { // agrega un software a la biblioteca
    
    for (const string& software : biblioteca) { // recorre la biblioteca
        if (software == nombreSoftware) { // si el software ya esta en la biblioteca
            cout << "El software ya está en tu biblioteca." << endl; 
            return;
        }
    }

    biblioteca.push_back(nombreSoftware); // si el software no esta en la biblioteca
    cout << "El software se agregó con éxito." << endl;
}


    bool eliminarSoftware(const string& nombreSoftware) { // elimina un software de la biblioteca
        for (auto it = biblioteca.begin(); it != biblioteca.end(); ++it) { // recorre la biblioteca
            if (*it == nombreSoftware) { // si el software esta en la biblioteca
                biblioteca.erase(it); // lo elimina
                return true;
            }
        }
        return false;
    }

    const vector<string>& getBiblioteca() const { return biblioteca; } // retorna la biblioteca

    void agregarDinero(float cantidad) { // agrega dinero al usuario
        dinero += cantidad;
    }

    void mostrarRegistroActividad(const unordered_map<string, vector<string>>& registro) const { // muestra el registro de actividad
        cout << "Registro de actividad:" << endl; 
        for (const auto& entry : registro) { // recorre el registro
            cout << "Usuario: " << entry.first << endl; // muestra el nombre de usuario
            cout << "Actividades:" << endl; // muestra las actividades
            for (const string& actividad : entry.second) { // recorre las actividades
                cout << " - " << actividad << endl;
            }
            cout << endl;
        }
    }

    

    virtual void mostrarInfo() const = 0; // metodo virtual puro
};