#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;
/*Se declara la clase Motocicleta que hereda elementos de la clase Vehiculo*/
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
};