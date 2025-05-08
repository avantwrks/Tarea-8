#include "Cliente.h"
#include <iostream>

Cliente::Cliente() {}

Cliente::Cliente(int id, const string& nombre, const string& direccion)
    : id(id), nombre(nombre), direccion(direccion) {}

int Cliente::getId() const {
    return id;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getDireccion() const {
    return direccion;
}

void Cliente::mostrarInformacion() const {
    cout << "ID: " << id << ", Nombre: " << nombre << ", Dirección: " << direccion << endl;
}

json Cliente::toJSON() const {
    return json{{"id", id}, {"nombre", nombre}, {"direccion", direccion}};
}

Cliente Cliente::fromJSON(const json& j) {
    return Cliente(j["id"], j["nombre"], j["direccion"]);
}
