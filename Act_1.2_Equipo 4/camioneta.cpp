#include <iostream>
#include <string>
#include "camioneta.hpp"

using namespace std;

#pragma once
string Camioneta::getTraccion(){
    return traccion;
}

void Camioneta::printVehiculo(){
    cout << getMarca() << " (";
    cout << getCodigo() << "). ";
    cout << getModelo() << ", ";
    cout << getKilometraje() << " km, ";
    cout << getTraccion() << ". " << endl;
}