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
using namespace std;

int main(){
    /* Lectura del archivo csv */
    File file("equipo4.csv");
    ConexionesEntrantes* e1 = new ConexionesEntrantes(".55",file);

    ConexionesSalientes* s1 = new ConexionesSalientes(".55",file);

    queue q1 = s1->getIPOrigen(); 
    cout << q1 << endl;
    /*
    ConexionesComputadora c1("1", "Aquiles", e1, s1);
    c1.printEntrante();
    c1.printSaliente();
    c1.direcccionIterna("28");
    c1.printIP();
    c1.direcccionIterna("150");
    c1.printIP();*/
}