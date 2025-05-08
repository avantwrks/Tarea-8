#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    string direccion;

public:
    Cliente();
    Cliente(int id, const string& nombre, const string& direccion);

    int getId() const;
    string getNombre() const;
    string getDireccion() const;

    void mostrarInformacion() const;
    json toJSON() const;
    static Cliente fromJSON(const json& j);
};

#endif
