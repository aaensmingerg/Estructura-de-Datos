//
//  main.cpp
//  HashMap
//
//  Created by Vicente Cubells on 20/11/20.
//

#include <iostream>
#include "HashMap.cpp"
#include "HashMap_Enlazado.cpp"

int main(int argc, const char * argv[]) {
    
    int capacity = 5;
    
    /* Crear un HashMap */
    HashMap<int, int> * tabla = new HashMap<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << "--1. Hash Map con desbordamiento Lineal--" << std::endl;
    
    tabla->put(1, 1);
    tabla->put(5, 5);
    tabla->put(11, 11);
    tabla->put(15, 15);
    tabla->put(2, 2);
    tabla->put(8, 8);

    std::cout << "Impresion de Resultados:" << std::endl;
    std::cout << tabla->get(5) << std::endl;
    std::cout << tabla->get(15) << std::endl;
    std::cout << tabla->get(8) << std::endl;
    
    /* Eliminar la tabla */
    delete tabla;

    
    /* Crear un HashMap */
    HashMapEnlazado<int, int> * tabla2 = new HashMapEnlazado<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << "--2. Hash Map con desbordamiento en Cadena--" << std::endl;
    tabla2->put(1, 1);
    tabla2->put(5, 5);
    tabla2->put(11, 11);
    tabla2->put(15, 15);
    tabla2->put(2, 2);
    tabla2->put(12, 12);
    
    std::cout << "Impresion de Resultados:" << std::endl;
    std::cout << tabla2->get(5) << std::endl;
    std::cout << tabla2->get(15) << std::endl;
    std::cout << tabla2->get(2) << std::endl;
    std::cout << tabla2->get(12) << std::endl;
    
    /* Eliminar la tabla */
    delete tabla2;
    
    return 0;
}
