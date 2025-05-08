#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H

#include "Cuenta.h"

class CuentaCorriente : public Cuenta {
private:
    double limiteSobregiro;

public:
    CuentaCorriente();
    CuentaCorriente(int numero, double saldo, int idCliente, double limiteSobregiro);

    bool retirar(double cantidad) override;

    void mostrarInformacion() const override;
    string getTipoCuenta() const override;

    json toJSON() const override;
};

#endif
