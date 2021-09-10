#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class Auto:public Vehiculo{
    public:
    /*Declaración de constructor vacío*/
    Auto(){}
    /*Se declara el constructor de la clase*/
    Auto(int _codigo,string _marca, int _modelo, int _kilometraje):Vehiculo(_codigo,_marca,_modelo,_kilometraje){}
};