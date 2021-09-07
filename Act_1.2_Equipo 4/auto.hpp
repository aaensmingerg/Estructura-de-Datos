#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

class Auto:public Vehiculo{
    public:
    Auto(){}
    Auto(int _codigo,string _marca, int _modelo, int _kilometraje):Vehiculo(_codigo,_marca,_modelo,_kilometraje){}
};