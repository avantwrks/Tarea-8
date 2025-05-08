#include "Banco.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include <iostream>
#include <fstream>

Banco::Banco(const string& nombre) : nombre(nombre), ultimoIdCliente(1), ultimoNumeroCuenta(100) {}

Banco::~Banco() {
    for (Cuenta* c : cuentas)
        delete c;
}

void Banco::agregarCliente(const string& nombre, const string& direccion) {
    clientes.emplace_back(ultimoIdCliente++, nombre, direccion);
}

void Banco::listarClientes() const {
    for (const Cliente& c : clientes)
        c.mostrarInformacion();
}

void Banco::agregarCuentaAhorros(int idCliente, double saldo, double tasa) {
    cuentas.push_back(new CuentaAhorros(ultimoNumeroCuenta++, saldo, idCliente, tasa));
}

void Banco::agregarCuentaCorriente(int idCliente, double saldo, double sobregiro) {
    cuentas.push_back(new CuentaCorriente(ultimoNumeroCuenta++, saldo, idCliente, sobregiro));
}

void Banco::listarCuentas() const {
    for (const Cuenta* c : cuentas)
        c->mostrarInformacion();
}

void Banco::guardarJSON(const string& filename) const {
    json j;
    j["clientes"] = json::array();
    j["cuentas"] = json::array();

    for (const Cliente& c : clientes)
        j["clientes"].push_back(c.toJSON());

    for (const Cuenta* c : cuentas)
        j["cuentas"].push_back(c->toJSON());

    ofstream file(filename);
    file << j.dump(4);
}

void Banco::cargarJSON(const string& filename) {
    ifstream file(filename);
    if (!file) return;

    json j;
    file >> j;

    for (const json& jc : j["clientes"]) {
        clientes.push_back(Cliente::fromJSON(jc));
        ultimoIdCliente = max(ultimoIdCliente, jc["id"].get<int>() + 1);
    }

    for (const json& jcu : j["cuentas"]) {
        Cuenta* c = Cuenta::fromJSON(jcu);
        if (c) {
            cuentas.push_back(c);
            ultimoNumeroCuenta = max(ultimoNumeroCuenta, jcu["numero"].get<int>() + 1);
        }
    }
}

void Banco::aplicarInteres() {
    for (Cuenta* c : cuentas) {
        if (c->getTipoCuenta() == "Ahorros") {
            dynamic_cast<CuentaAhorros*>(c)->aplicarInteres();
        }
    }
}

bool Banco::consignar(int numeroCuenta, double cantidad) {
    for (Cuenta* c : cuentas) {
        if (c->getNumero() == numeroCuenta) {
            c->consignar(cantidad);
            return true;
        }
    }
    return false;
}

bool Banco::retirar(int numeroCuenta, double cantidad) {
    for (Cuenta* c : cuentas) {
        if (c->getNumero() == numeroCuenta) {
            return c->retirar(cantidad);
        }
    }
    return false;
}

int Banco::totalClientes() const {
    return clientes.size();
}

int Banco::totalCuentas() const {
    return cuentas.size();
}

double Banco::promedioSaldo() const {
    if (cuentas.empty()) return 0;
    double suma = 0;
    for (const Cuenta* c : cuentas)
        suma += c->getSaldo();
    return suma / cuentas.size();
}

int Banco::cuentasAhorro() const {
    int cont = 0;
    for (const Cuenta* c : cuentas)
        if (c->getTipoCuenta() == "Ahorros") cont++;
    return cont;
}

int Banco::cuentasCorriente() const {
    int cont = 0;
    for (const Cuenta* c : cuentas)
        if (c->getTipoCuenta() == "Corriente") cont++;
    return cont;
}
