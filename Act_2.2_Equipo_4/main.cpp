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
    ConexionesEntrantes* e1 = new ConexionesEntrantes("equipo4.csv");

    ConexionesSalientes* s1 = new ConexionesSalientes("equipo4.csv");

    ConexionesComputadora c1("1", "Aquiles", e1, s1);
    c1.printEntrante();
    c1.printSaliente();
}