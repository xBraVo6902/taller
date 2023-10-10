
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"

using namespace std;

class Juegos : public Software {
private:
    vector<string> generos;

public:
    Juegos(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio) {}

    void agregarGenero(const string& genero) {
        generos.push_back(genero);
    }

    const vector<string>& getGeneros() const { return generos; }
};