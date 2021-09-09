#include <iostream>
#include <string>

using namespace std;

#pragma once
class Persona{
    protected:
    string nombre;
    string apellido;
    string ine;
    public:
    Persona(){}
    Persona(string _nombre,string _apellido, string _ine):nombre(_nombre),apellido(_apellido),ine(_ine){}
    string getNombre();
    string getApellido();
    string getIne();
    void setNombre(string);
    void setApellido(string);

    void printPersona();
};