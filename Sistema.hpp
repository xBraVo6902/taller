
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Usuario.hpp"
#include "Software.hpp"
#include "Administrador.hpp"



using namespace std;


class Sistema {
private:
    unordered_map<string, Usuario*> usuarios;
    unordered_map<string, Software*> software;
    unordered_map<string, vector<string>> registroActividad;

public:
    ~Sistema() {
        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
            delete it->second;
        }

        for (auto it = software.begin(); it != software.end(); ++it) {
            delete it->second;
        }
    }

    bool iniciarSesion(const string& nombreUsuario, const string& contrasena) {
        auto it = usuarios.find(nombreUsuario);
        if (it != usuarios.end() && it->second->getContrasena() == contrasena) {
            return true;
        }
        return false;
    }

    bool agregarSoftware(const string& nombreUsuario, const string& nombreSoftware) {
        auto usuarioIt = usuarios.find(nombreUsuario);
        auto softwareIt = software.find(nombreSoftware);

        if (usuarioIt != usuarios.end() && softwareIt != software.end()) {
            Usuario* u = usuarioIt->second;
            Software* s = softwareIt->second;

            if ((u->getEdad() >= 18 || s->getEdad() < 18) && !(s->getNombre() == "Produccion" && u->getEdad() < 18) &&
                !(s->getNombre() == "Seguridad" && dynamic_cast<Administrador*>(u) == nullptr)) {
                u->agregarSoftware(s->getNombre());
                s->agregarUsuario(u->getNombreUsuario());
                return true;
            }
        }

        return false;
    }

    bool eliminarSoftware(const string& nombreUsuario, const string& nombreSoftware) {
        auto usuarioIt = usuarios.find(nombreUsuario);
        auto softwareIt = software.find(nombreSoftware);

        if (usuarioIt != usuarios.end() && softwareIt != software.end()) {
            Usuario* u = usuarioIt->second;
            Software* s = softwareIt->second;

            if (u->eliminarSoftware(s->getNombre())) {
                s->eliminarUsuario(u->getNombreUsuario());
                return true;
            }
        }

        return false;
    }

    void agregarActividadUsuario(const string& nombreUsuario, const string& actividad) {
        registroActividad[nombreUsuario].push_back(actividad);
    }

    const unordered_map<string, vector<string>>& getRegistroActividad() const {
        return registroActividad;
    }

    void agregarUsuario(Usuario* u) {
        usuarios[u->getNombreUsuario()] = u;
    }

    void agregarSoftware(Software* s) {
        software[s->getNombre()] = s;
    }

    Usuario* getUsuario(const string& nombreUsuario) const {
        auto it = usuarios.find(nombreUsuario);
        if (it != usuarios.end()) {
            return it->second;
        }
        return nullptr; 
    }

    Software* getSoftware(const string& nombreSoftware) const {
        auto it = software.find(nombreSoftware);
        if (it != software.end()) {
            return it->second;
        }
        return nullptr; 
    }
};