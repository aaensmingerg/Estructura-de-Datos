//
//  main.cpp
//  actividad_4-1
//
//  Created by Vicente Cubells on 13/11/20.
//

#include <iostream>
#include <random>
#include <queue>
#include "Graph.hpp"



void loadGraph(int v, int e, std::vector < std::vector<int> > graph)
{
    int cuenta = 0;
    for(int i = 1; i < v; ++i){
        graph[i] = std::vector<int>(v);
        for (int j = 1; j < v; j++){
            int valor = rand() % 2;
            if (cuenta < e && valor == 1){
                graph[i][j] = valor;
                cuenta++;
            }
            else{
                graph[i][j] = valor;
            }
        }
    }
}

void loadGraph2(int v, int e, Graph<int, int> * graph)
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
    std::cout << *graph << std::endl;
}

void DFS(std::vector < std::vector<int> > & graph, int u)
{
    /* Implementar */
}

void BFS(Graph<int, int> * graph, int u)
{
    int cuenta = 0;
    /* Defición de queue para alamcenar los nodos */
    std::queue< Vertex <int, int>* > q;

    /* Nodo auxiliar para comparar */
    Vertex <int, int> * aux;
    q.push(graph->getVertex(cuenta));
    

    /* Recorrer los nodos por nivel hasta llegar al final */
    while (!q.empty()){
        /* Almacenar el primer valor de la queue en auxiliar*/
        aux = q.front();
        std::cout << q.front()->getInfo() << std::endl;
        q.pop();
        if (aux->getIsVisited() == false){
            for (int i = 0; i<graph->getNumEdges(cuenta); i++){
                Edge<int, int> * arista = graph->getEdge(cuenta, i);
                q.push(arista->getTarget());
            }
            aux->setIsVisited();
            cuenta = q.front()->getInfo();
        }
    }
}

int main(int argc, const char * argv[]) {
    
    /* Definir número de vértices y aristas */
    const int vertices = 10;
    const int aristas = 15;
    
    /* Declaración del grafo como matriz de adyacencia */
    std::vector < std::vector<int> > matriz_adyacencia(vertices);

    /* Generar el grafo como matriz de adyacencia */
    loadGraph(vertices, aristas, matriz_adyacencia);
    
    /* Recorrido con DFS */
    std::cout << "------ Matriz de adyacencia con DFS ------" << std::endl;
    int nodo_u = 1;
    DFS(matriz_adyacencia, nodo_u);
    
    /* Declaración del grafo como multilista */
    Graph<int, int> * multilista = new Graph<int, int>();

    /* Generar el grafo como multilista */
    loadGraph2(vertices, aristas, multilista);
    
    /* Recorrido con BFS */
    std::cout << "------ Multilista con BFS ------" << std::endl;
    int nodo_v = 1;
    BFS(multilista, nodo_v);
    
    delete multilista;
    
    return 0;
}
