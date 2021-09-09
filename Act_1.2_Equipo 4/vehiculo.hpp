#include <iostream>
#include <string>

using namespace std;

#pragma once
class Vehiculo{
    protected:
    int codigo;
    string marca;
    int modelo;
    int kilometraje;
    public:
    Vehiculo(){}
    Vehiculo(int _codigo,string _marca, int _modelo, int _kilometraje):codigo(_codigo),marca(_marca),modelo(_modelo),kilometraje(_kilometraje){}
    virtual int getCodigo();
    virtual string getMarca();
    virtual int getModelo();
    virtual int getKilometraje();

    friend ostream & operator<<(ostream & os, const Vehiculo & vehiculo);
};