#include <iostream>
#include <string>
#include "vehiculo.cpp"

using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class Camioneta:public Vehiculo{
    protected:
    string traccion;
    public:
    /*Declaración de constructor vacío*/
    Camioneta(){}
    /*Se declara el constructor de la clase*/
    Camioneta(int _codigo,string _marca, int _modelo, int _kilometraje,string _traccion):Vehiculo(_codigo,_marca,_modelo,_kilometraje),traccion(_traccion){}
    
    /* Se plantea la funcíon "getTraccion" que se definirá en "camioneta.hpp"*/
    string getTraccion();  

    /* La función "printVehiculo" 
    imprime la información de vehículo en formato: marca(codigo).modelo,kilometraje km, tracción. */  
    void printVehiculo();    
};