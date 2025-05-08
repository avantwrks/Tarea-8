#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "Cliente.h"
#include "Cuenta.h"

class Banco {
private:
    string nombre;
    vector<Cliente> clientes;
    vector<Cuenta*> cuentas;

    int ultimoIdCliente;
    int ultimoNumeroCuenta;

public:
    Banco(const string& nombre);
    ~Banco();

    void agregarCliente(const string& nombre, const string& direccion);
    void listarClientes() const;

    void agregarCuentaAhorros(int idCliente, double saldo, double tasa);
    void agregarCuentaCorriente(int idCliente, double saldo, double sobregiro);
    void listarCuentas() const;

    void guardarJSON(const string& filename) const;
    void cargarJSON(const string& filename);

    void aplicarInteres();
    bool consignar(int numeroCuenta, double cantidad);
    bool retirar(int numeroCuenta, double cantidad);

    int totalClientes() const;
    int totalCuentas() const;
    double promedioSaldo() const;
    int cuentasAhorro() const;
    int cuentasCorriente() const;
};

#endif
