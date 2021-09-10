#include <iostream>
#include <string>

using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
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

    /*Declaración del Set de la variable modelo*/
    virtual void setModelo(int);
    /*Declaración del Set de la variable kilometraje*/
    virtual void setKilometraje(int);

    /*La función "printVeiculo" imprime los valores de vehículo 
    en formato: marca (código). modelo, kilometraje km. */
    virtual void printVehiculo();
};