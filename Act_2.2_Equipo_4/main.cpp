/* Este programa utiliza las estructuras lineales de datos "queue"
y "stack" para registrar las conexiones escritas en un csv en objetos 
de tipo "ConexionesSalientes y ConexionesEntrantes". 
A partir de estos registros se resolverán las preguntas de la
segunda entrega de la situación problema.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Lunes 11 de Octubre de 2021  */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "File.cpp"
#include "Ordenamiento.hpp"
#include "ConexionesComputadora.cpp"


int main(){
    /* Lectura del archivo csv */
    File f1("equipo4.csv");

    /* Crear objeto de conexiones computadora */
    ConexionesComputadora c1(".146","Aquiles",f1);
    
    cout << "Que direccion ip estas usando?" << endl; 
    c1.printIp();
    cout << "Cual fue la direccion IP de la ultima conexion que recibio esta computadora? " << endl;
    string entrante = c1.entrante();
    cout << entrante << endl;
    cout << "Es interna o externa? " << endl;
    c1.isInterna(entrante);
    cout << "Cuantas conexiones entrantes tiene esta computadora?" << endl;
    c1.entrantesTotales();
    cout << "Cuantas conexiones salientes tiene esta computadora?" << endl;
    c1.salientesTotales();
    
}