#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
    Banco banco("Banco Central");


    banco.cargarJSON("banco.json");


    banco.agregarCliente("Juan Pérez", "Calle 123");
    banco.agregarCliente("Ana Gómez", "Carrera 45");


    banco.agregarCuentaAhorros(1, 5000, 0.03); // Cliente ID 1
    banco.agregarCuentaCorriente(2, 10000, 2000); // Cliente ID 2


    cout << "Clientes registrados:\n";
    banco.listarClientes();

    cout << "\nCuentas registradas:\n";
    banco.listarCuentas();


    banco.consignar(100, 1500); // Cuenta número 100
    banco.retirar(101, 12000);  // Cuenta número 101 (sobregiro)


    banco.aplicarInteres();


    cout << "\nCuentas después de operaciones:\n";
    banco.listarCuentas();


    banco.guardarJSON("banco.json");


    cout << "\nEstadísticas del banco:\n";
    cout << "Total clientes: " << banco.totalClientes() << endl;
    cout << "Total cuentas: " << banco.totalCuentas() << endl;
    cout << "Saldo promedio: $" << banco.promedioSaldo() << endl;
    cout << "Cuentas de ahorro: " << banco.cuentasAhorro() << endl;
    cout << "Cuentas corriente: " << banco.cuentasCorriente() << endl;

    return 0;
}
