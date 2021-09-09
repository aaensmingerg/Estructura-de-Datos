#include <iostream>
#include <string>
#include "motocicleta.hpp"

using namespace std;

#pragma once
int Motocicleta::getCilindraje(){
    return cilindraje;
}

void Motocicleta::printVehiculo(){
    cout << getMarca() << " (";
    cout << getCodigo() << "). ";
    cout << getModelo() << ", ";
    cout << getKilometraje() << " km, ";
    cout << getCilindraje() << " cc. " << endl;
}