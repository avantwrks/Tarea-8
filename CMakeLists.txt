cmake_minimum_required(VERSION 3.30)
project(Tarea8)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tarea8 main.cpp
        Cliente.cpp
        Cliente.h
        Cuenta.cpp
        Cuenta.h
        CuentaAhorros.cpp
        CuentaAhorros.h
        CuentaCorriente.cpp
        CuentaCorriente.h
        Banco.cpp
        Banco.h)
