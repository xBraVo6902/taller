
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"

using namespace std;

class Navegador : public Software {
private:
    vector<string> historial;

public:
    Navegador(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio) {}

    void agregarPaginaAlHistorial(const string& pagina) {
        historial.push_back(pagina);
        if (historial.size() > 10) {
            historial.erase(historial.begin());
        }
    }

    const vector<string>& getHistorialNavegacion() const { return historial; }
};