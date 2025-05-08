#include "Cuenta.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include <iostream>

Cuenta::Cuenta() {}

Cuenta::Cuenta(int numero, double saldo, int idCliente)
    : numero(numero), saldo(saldo), idCliente(idCliente) {}

int Cuenta::getNumero() const {
    return numero;
}

double Cuenta::getSaldo() const {
    return saldo;
}

int Cuenta::getIdCliente() const {
    return idCliente;
}

void Cuenta::consignar(double cantidad) {
    saldo += cantidad;
}

bool Cuenta::retirar(double cantidad) {
    if (saldo >= cantidad) {
        saldo -= cantidad;
        return true;
    }
    return false;
}

// Fábrica estática para reconstruir desde JSON
Cuenta* Cuenta::fromJSON(const json& j) {
    string tipo = j["tipo"];
    if (tipo == "Ahorros") {
        return new CuentaAhorros(j["numero"], j["saldo"], j["idCliente"], j["tasaInteres"]);
    } else if (tipo == "Corriente") {
        return new CuentaCorriente(j["numero"], j["saldo"], j["idCliente"], j["limiteSobregiro"]);
    }
    return nullptr;
}
