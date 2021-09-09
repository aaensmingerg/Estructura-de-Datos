#include <iostream>
#include <string>
#include "persona.cpp"
#include "vehiculo.cpp"

using namespace std;

#pragma once
class Compra{
    protected:
    int monto;
    Persona* persona;
    Vehiculo* vehiculo;
    public:
    Compra(){}
    Compra(int _monto, Persona* _persona, Vehiculo* _vehiculo):monto(_monto),persona(_persona),vehiculo(_vehiculo){}
    int getMonto();
    string getComprador();
    Persona* getDireccionComprador();
    string getVehiculoComprado();
    Vehiculo* getDireccionVehiculoComprado();
    int getAnio();
    int getKilometraje();
    void setAnio(int);
    void setKilometraje(int);
    void setNombre(string);
    void setApellido(string);

    static bool compara_anio_asc(Compra, Compra);
    static bool compara_anio_desc(Compra, Compra);

    static bool compara_kilometraje_asc(Compra, Compra);
    static bool compara_kilometraje_desc(Compra, Compra);

    static bool compara_comprador_eq(Compra, Compra);

    void printCompra();
};