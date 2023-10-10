
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Software { // clase base
private:
    string nombre; // nombre del software
    string desarrollador;  // desarrollador del software
    int edad;  // edad minima para usar el software 
    float precio;  // precio del software
    vector<string> usuarios;   // usuarios que usan el software

public:
    Software(const string& nombre, const string& desarrollador, int edad, float precio)
        : nombre(nombre), desarrollador(desarrollador), edad(edad), precio(precio) {} // constructor

    const string& getNombre() const { return nombre; } // retorna el nombre
    int getEdad() const { return edad; }   // retorna la edad minima
    float getPrecio() const { return precio; } // retorna el precio

    void agregarUsuario(const string& nombreUsuario) { // agrega un usuario al vector de usuarios
        usuarios.push_back(nombreUsuario);
    }

    void eliminarUsuario(const string& nombreUsuario) { // elimina un usuario del vector de usuarios
        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) { // recorre el vector de usuarios
            if (*it == nombreUsuario) { // si el usuario esta en el vector de usuarios
                usuarios.erase(it); // lo elimina
                return; 
            }
        }
    }

    const vector<string>& getUsuarios() const { return usuarios; } // retorna el vector de usuarios

    virtual ~Software() {}  // destructor virtual
};