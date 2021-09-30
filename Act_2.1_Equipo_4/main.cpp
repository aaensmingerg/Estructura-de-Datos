/* Este programa es una continuación de la implementación de una lista ligada
y sus funciones, la mayoría de los métodos son tomados del archivo "LinkedList",
proporcionado por el profesor. Lo nuevo que se incluye son las funciones que permiten buscar
y eliminar en un rango, unir dos lista, realizar la función matemática intersección entre dos
listas y comparar dos lista y devolver las elementos únicos de la primera, a través de otra función que revisa
si pertenece o no.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Viernes 1 de Octubre de 2021  */

#include <iostream>
#include "Node.hpp"
#include "LinkedList.cpp"

int main(int argc, const char * argv[]) {
    
    /* Creación de nodos */
    std::cout << "--- Creación y eliminación de nodos ---" << std::endl;
    std::cout << std::endl;
    
    /* Uso de constructor predeterminado Node<T>() */
    Node<int> n1;
    std::cout << "-> Nodo creado con constructor predeterminado: " << n1 << std::endl;
    
    /* Uso de constructor con parámetros Node<T>(T) */
    Node<float> n2(3.14);
    std::cout << "-> Nodo creado con constructor con parámetros: " << n2 << std::endl;
    
    /* Uso de constructor copia Node<T>(Node<T> &) */
    Node<int> n3 = n1;
    std::cout << "-> Nodo creado con constructor copia: " << n3 << std::endl;
    
    /* Crear un nodo con memoria dinámica */
    Node<int> * nodeptr = new Node<int>(10);
    std::cout << "-> Nodo creado con memoria dinámica: " << *nodeptr << std::endl;
    
    /* Liberar la memoria ocupada por el nodo */
    std::cout << "<- Nodo eliminado con delete: " << *nodeptr << std::endl;
    delete nodeptr;
    
    /* Trabajo con una LinkedList */
    std::cout << std::endl;
    std::cout << "--- Demostración de uso de la LinkedList ---" << std::endl;
    std::cout << std::endl;
    
    /* Crear una lista */
    std::cout << "(C) Se crea una lista vacía" << std::endl;
    LinkedList<int> * list = new LinkedList<int>();
    
    /* Determinar si la lista está vacía */
    std::cout << (list->empty() ? "(E) La lista está vacía" : "(E) La lista tiene elementos") << std::endl;
    
    /* Insertar un elemento al inicio de la lista */
    std::cout << "(I) Se inserta el 1 al inicio" << std::endl;
    list->insert_front(1);

    /* Insertar un elemento al final de la lista */
    std::cout << "(I) Se inserta el 2 al final" << std::endl;
    list->insert_back(2);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 5 en la posición 1" << std::endl;
    list->insert(5,1);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 8 en la posición 1" << std::endl;
    list->insert(8,1);
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *list << std::endl;
    
    std::cout << "--- Demostracion de SubList lista ---" << std::endl;
    LinkedList<int> * subList = list->SubList(0, 2);
    std::cout << *subList << std::endl;

    std::cout << "--- Demostracion de DeleteRange lista ---" << std::endl;
    list->DeleteRange(0, 2);
    std::cout << *list << std::endl;

    /* Crear nueva lista */
    LinkedList<int> * listB = new LinkedList<int>();
    listB->insert_front(9);
    listB->insert_front(7);
    listB->insert_front(0);
    std::cout << "(LB) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *listB << std::endl;


    std::cout << "--- Demostracion de union lista ---" << std::endl;
    LinkedList<int> * listc = list->Union(listB);
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *listc << std::endl;

    std::cout << "--- Demostracion de Interseccion lista ---" << std::endl;
    LinkedList<int> * listd = list->Intersection(listB);
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *listd << std::endl;

    std::cout << "--- Demostracion de Except lista ---" << std::endl;
    LinkedList<int> * liste = list->Except(listB);
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *liste << std::endl;
    
    std::cout << "--- Demostracion de isIn lista ---" << std::endl;
    std::cout << list->isIn(4) << std::endl;

    return 0;
}