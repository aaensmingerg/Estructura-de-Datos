#include <iostream>
#include <string>
#include "vehiculo.hpp"

using namespace std;

#pragma once
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

void Vehiculo::printVehiculo(){
    cout << getMarca() << " (";
    cout << getCodigo() << "). ";
    cout << getModelo() << ", ";
    cout << getKilometraje() << " km. ";

    cout << endl;
}