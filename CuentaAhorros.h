#ifndef CUENTA_AHORROS_H
#define CUENTA_AHORROS_H

#include "Cuenta.h"

class CuentaAhorros : public Cuenta {
private:
    double tasaInteres;

public:
    CuentaAhorros();
    CuentaAhorros(int numero, double saldo, int idCliente, double tasaInteres);

    void aplicarInteres();

    void mostrarInformacion() const override;
    string getTipoCuenta() const override;

    json toJSON() const override;
};

#endif
