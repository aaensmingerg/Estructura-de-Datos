#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

#pragma once
class Motocicleta:public Vehiculo{
    protected:
    int cilindraje;
    public:
    Motocicleta(){}
    Motocicleta(int _codigo,string _marca, int _modelo, int _kilometraje,int _cilindraje):Vehiculo(_codigo,_marca,_modelo,_kilometraje),cilindraje(_cilindraje){}
    int getCilindraje(); 

    void printVehiculo();   
};