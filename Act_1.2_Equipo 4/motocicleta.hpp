#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class Motocicleta:public Vehiculo{
    protected:
    int cilindraje;
    public:
    /*Declaración del constructor vacío*/
    Motocicleta(){}
    /*Declaración del contructor*/
    Motocicleta(int _codigo,string _marca, int _modelo, int _kilometraje,int _cilindraje):Vehiculo(_codigo,_marca,_modelo,_kilometraje),cilindraje(_cilindraje){}
    
    /*La función "getCilindraje recupera el valor de cilindraje*/
    int getCilindraje(); 

    /*La función "printVehículo" imprime los valores de la clase
    en formato: marca(codigo). modelo, kilometraje km, cilindraje cc.*/    
    void printVehiculo();   
};