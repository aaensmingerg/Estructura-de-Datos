/* Este programa es capaz de leer un archivor csv 
y responder a las preguntas requeridas en la entrega 3.2 
de la situación problema, principalmente la obtención de 
los top 5 de sitios con más conexiones por día de utilizando 
algoritmos de búsqueda y ordenamiento según requeridos,
árboles binarios de búsqueda (BST) así como HashMaps.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Domingo 7 de Octubre de 2021  */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
#include <iterator>
#include <queue>
#include "Graph.hpp"
#include "File.cpp"
#include "Ordenamiento.hpp"


void loadGraph(int v, int e, Graph<int, int> * graph)
{
    int valor;
    int posicionX;
    int posicionY;
    int cuenta = 0;
    for (int i = 0; i < v; ++i){ 
        graph->addVertex(i);
    }

    for (int j = 0; j < e; j++){
        posicionX = rand() % 10;
        posicionY = rand() % 10;
        Vertex<int, int> * valorX = graph->getVertex(posicionX);
        Vertex<int, int> * valorY = graph->getVertex(posicionY);
        if (cuenta < e){
            graph->addEdge(valorX, valorY, cuenta);
        cuenta++;
        }
    }
    /* Vertices extras para imprimir todo el grafo */
    Vertex<int, int> * valor2 = graph->getVertex(0);
    Vertex<int, int> * valor5 = graph->getVertex(5);
    Vertex<int, int> * valor7 = graph->getVertex(7);
    Vertex<int, int> * valor8 = graph->getVertex(8);

    graph->addEdge(valor7,valor2,16);
    graph->addEdge(valor7,valor5,17);
    graph->addEdge(valor2,valor8,18);
    std::cout<< *graph << std::endl;
}





/* En este caso la función main es la encargada de responder a todas las preguntas*/
int main(){
    /* Lectura del archivo csv */
    File f1("equipo4.csv");
    f1.grafoPorDia("10-8-2020");
    /*
    std::cout << "---1. Demostracion mapa primer dia---  " << std::endl;
    std::cout << "R. " << endl;
    map<string,int> mapa = f1.conexionesPorDia("10-8-2021");
    for (auto r: mapa){
        std::cout<< "Nombre conexion: " << r.first << " -> " << "Numero conexiones: " << r.second << std::endl;
    }

    std::cout << "" << std::endl;

    std::cout << "---2. Demostracion top primer dia---  " << std::endl;
    cout << "R. " << std::endl;
    f1.top(5,"10-8-2021");

    std::cout << "" << std::endl;

    std::cout << "--3. Demostracion top 5 dias --" << std::endl;
    std::cout << "R. " << std::endl;
    f1.top5dias();
    */   

    return 0;
}

