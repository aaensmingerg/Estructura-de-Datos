#include <iostream>
#include <string>

using namespace std;
class Persona{
    protected:
    string nombre;
    string apellido;
    string ine;
    public:
    /* Declaración del constructor vacío*/
    Persona(){}
    /*Declaración del constructor*/
    Persona(string _nombre,string _apellido, string _ine):nombre(_nombre),apellido(_apellido),ine(_ine){}
    
    /*La función "getNombre" regresa el valor de la variable nombre*/
    string getNombre();
    
    /*La función "getApellido" regresa el valor de la variable apellido*/
    string getApellido();
    
    /*La función "getNombre" regresa el valor de la variable ine*/
    string getIne();

    /*Se sobre carga el operador "<<" para imprimir los datos en formato: nombre,apellido(ine)*/
    friend ostream & operator<<(ostream & os, const Persona & persona);
};