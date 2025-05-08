#include "CuentaAhorros.h"
#include <iostream>

CuentaAhorros::CuentaAhorros() {}

CuentaAhorros::CuentaAhorros(int numero, double saldo, int idCliente, double tasaInteres)
    : Cuenta(numero, saldo, idCliente), tasaInteres(tasaInteres) {}

void CuentaAhorros::aplicarInteres() {
    saldo += saldo * tasaInteres;
}

void CuentaAhorros::mostrarInformacion() const {
    cout << "[Ahorros] Número: " << numero
         << ", Saldo: " << saldo
         << ", Cliente ID: " << idCliente
         << ", Tasa de interés: " << tasaInteres << endl;
}

string CuentaAhorros::getTipoCuenta() const {
    return "Ahorros";
}

json CuentaAhorros::toJSON() const {
    return json{
            {"tipo", "Ahorros"},
            {"numero", numero},
            {"saldo", saldo},
            {"idCliente", idCliente},
            {"tasaInteres", tasaInteres}
    };
}
