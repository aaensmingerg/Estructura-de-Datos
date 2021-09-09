#include <iostream>
#include <string>
#include "motocicleta.hpp"

using namespace std;

#pragma once
int Motocicleta::getCilindraje(){
    return cilindraje;
}

ostream & operator<<(ostream & os, const Motocicleta & motocicleta){
    os << (Vehiculo)motocicleta;
    os << motocicleta.cilindraje << " cc, ";
    os << endl;
    
    return os;
}