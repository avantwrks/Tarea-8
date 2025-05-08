#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Cuenta {
protected:
    int numero;
    double saldo;
    int idCliente;

public:
    Cuenta();
    Cuenta(int numero, double saldo, int idCliente);

    virtual ~Cuenta() {}

    int getNumero() const;
    double getSaldo() const;
    int getIdCliente() const;

    void consignar(double cantidad);
    virtual bool retirar(double cantidad);

    virtual void mostrarInformacion() const = 0;
    virtual string getTipoCuenta() const = 0;

    virtual json toJSON() const = 0;
    static Cuenta* fromJSON(const json& j); // Fábrica
};

#endif
