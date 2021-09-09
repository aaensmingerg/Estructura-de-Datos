#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

/* En este programa se declara la clase "auto", 
que hereda elementos de la clase Vehículo */

class Auto:public Vehiculo{
    public:
    /*Declaración de constructor vacío*/
    Auto(){}
    /*Se declara el constructor de la clase*/
    Auto(int _codigo,string _marca, int _modelo, int _kilometraje):Vehiculo(_codigo,_marca,_modelo,_kilometraje){}
};