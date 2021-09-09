#include <iostream>
#include <string>

using namespace std;


class Vehiculo{
    protected:
    int codigo;
    string marca;
    int modelo;
    int kilometraje;
    public:
    /*Declaración del constructor vacío*/
    Vehiculo(){}
    /*Declaración del constructor*/
    Vehiculo(int _codigo,string _marca, int _modelo, int _kilometraje):codigo(_codigo),marca(_marca),modelo(_modelo),kilometraje(_kilometraje){}
    
    /*La función "getCódigo" regresa el valor de la variable codigo*/
    int getCodigo();
    
    /*La función "getMarca" regresa el valor de la variable Marca*/
    string getMarca();
    
    /*La función "getModelo" regresa el valor de la variable Modelo*/
    int getModelo();
    
    /*La función "getKilometraje" regresa el valor de la variable kilometraje*/
    int getKilometraje();

    /*Sobrecrga del operador "<<" para imprimir en formato: marca(codigo).modelo,kilometraje km*/
    friend ostream & operator<<(ostream & os, const Vehiculo & vehiculo);
};