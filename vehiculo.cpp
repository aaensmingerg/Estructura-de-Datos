#include <iostream>
#include <string>
#include "vehiculo.hpp"

using namespace std;

int Vehiculo::getCodigo(){
    return codigo;
}

string Vehiculo::getMarca(){
    return marca;
}

int Vehiculo::getModelo(){
    return modelo;
}

int Vehiculo::getKilometraje(){
    return kilometraje;
}

ostream & operator<<(ostream & os, const Vehiculo & vehiculo)
{
    os << vehiculo.marca << " (";
    os << vehiculo.codigo << "). ";
    os << vehiculo.modelo << ", ";
    os << vehiculo.kilometraje << " km, ";
    os << endl;
    
    return os;
}