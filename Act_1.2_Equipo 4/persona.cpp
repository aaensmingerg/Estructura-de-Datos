#include <iostream>
#include <string>
#include "persona.hpp"

using namespace std;

#pragma once
string Persona::getNombre(){
    return nombre;
}

string Persona::getApellido(){
    return apellido;
}

string Persona::getIne(){
    return ine;
}

void Persona::setNombre(string _nombre){
    nombre=_nombre;
}

void Persona::setApellido(string _apellido){
    apellido=_apellido;
}

void Persona::printPersona(){
    cout << getNombre() << ",  ";
    cout << getApellido() << ". (";
    cout << getIne() << "). ";
}