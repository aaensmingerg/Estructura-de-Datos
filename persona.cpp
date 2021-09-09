#include <iostream>
#include <string>
#include "persona.hpp"

using namespace std;

string Persona::getNombre(){
    return nombre;
}

string Persona::getApellido(){
    return apellido;
}

string Persona::getIne(){
    return ine;
}

ostream & operator<<(ostream & os, const Persona & persona)
{
    os << persona.nombre << ", ";
    os << persona.apellido << ". (";
    os << persona.ine << "). ";
    os << endl;
    
    return os;
}