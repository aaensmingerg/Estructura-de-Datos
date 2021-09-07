#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

class Camioneta:public Vehiculo{
    protected:
    string traccion;
    public:
    Camioneta(){}
    Camioneta(int _codigo,string _marca, int _modelo, int _kilometraje,string _traccion):Vehiculo(_codigo,_marca,_modelo,_kilometraje),traccion(_traccion){}
    string getTraccion();    
};