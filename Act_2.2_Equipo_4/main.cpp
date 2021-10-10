#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "File.cpp"
#include "Ordenamiento.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "ConexionesComputadora.hpp"


int main(){
    /* Lectura del archivo csv */
    File f1("equipo4.csv");
    ConexionesComputadora c1(".55","Aquiles",f1);
    
    cout << "Que direccion ip estas usando?" << endl; 
    c1.printIp();
    cout << "Cual fue la direccion IP de la ultima conexion que recibio esta computadora? " << endl;
    c1.printEntrante();
    cout << "Cuantas conexiones entrantes tiene esta computadora?" << endl;
    c1.entrantesTotales();
    cout << "Cuantas conexiones salientes tiene esta computadora?" << endl;
    c1.salientesTotales();
    
}