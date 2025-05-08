#include "CuentaCorriente.h"
#include <iostream>

CuentaCorriente::CuentaCorriente() {}

CuentaCorriente::CuentaCorriente(int numero, double saldo, int idCliente, double limiteSobregiro)
    : Cuenta(numero, saldo, idCliente), limiteSobregiro(limiteSobregiro) {}

bool CuentaCorriente::retirar(double cantidad) {
    if (saldo + limiteSobregiro >= cantidad) {
        saldo -= cantidad;
        return true;
    }
    return false;
}

void CuentaCorriente::mostrarInformacion() const {
    cout << "[Corriente] Número: " << numero
         << ", Saldo: " << saldo
         << ", Cliente ID: " << idCliente
         << ", Límite de sobregiro: " << limiteSobregiro << endl;
}

string CuentaCorriente::getTipoCuenta() const {
    return "Corriente";
}

json CuentaCorriente::toJSON() const {
    return json{
            {"tipo", "Corriente"},
            {"numero", numero},
            {"saldo", saldo},
            {"idCliente", idCliente},
            {"limiteSobregiro", limiteSobregiro}
    };
}
