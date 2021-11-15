/* Este programa implementa las funciones definidas
por el profesor, que permiten la lectura e impresión
de un grafo como matriz de adyacencia y por niveles.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Domingo 14 de Noviembre de 2021  */

/* Comentario extra para el profesor:
Este main y las conexiones extras para loadGraph2 estaban pensadas para el primer
grafo generado con random. Es decir que cuando se genera un nuevo grafo con random,
quizás haya que generar otras conexiones para imprimir todo el árbol.
Por esta misma razón hace unos días se imprimía el grafo completo, pero ahora solo
imprime una parte debido a que los valores random han cambiado. */

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <queue>
#include "Graph.hpp"

void visualizar(std::vector < std::vector<int> > grafo, std::vector<int> vectorVertices)
{
    /* Imprimir los nodos */
    std::cout << "\t";
    for (auto vertice : vectorVertices) {
        std::cout << vertice << "\t";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    /* Imprimir las filas de la matriz */
    int i = 0;
    for (auto fila : grafo) {
        std::cout << vectorVertices[i++] << "\t";
        std::copy(fila.begin(), fila.end(), std::ostream_iterator<int>(std::cout, "\t") );
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

std::vector <std::vector<int>> loadGraph(int v, int e, std::vector < std::vector<int> > graph, std::vector <int> vectorVertices)
{
    int cuenta = 0;
    for(int i = 0; i < v; ++i){
        graph[i] = std::vector<int>(v);
        for (int j = 1; j < v; j++){
            int valor = rand() % 2;
            if (cuenta < e && valor == 1){
                graph[i][j] = valor;
                cuenta++;
                //std::cout << i << " -> " << j << std::endl;
            }
        }
    }
    return graph;
    //visualizar(graph, vectorVertices);
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
    /* Vertices extras para imprimir todo el grafo */
    Vertex<int, int> * valor0 = graph->getVertex(0);
    Vertex<int, int> * valor5 = graph->getVertex(5);
    Vertex<int, int> * valor7 = graph->getVertex(7);
    Vertex<int, int> * valor8 = graph->getVertex(8);

    graph->addEdge(valor7,valor0,16);
    graph->addEdge(valor7,valor5,17);
    graph->addEdge(valor0,valor8,18);

    //std::cout << *graph << std::endl;
}

void DFS(std::vector < std::vector<int> > graph, int u, std::vector<int> vectorVertices, std::vector<int>* visitados)
{
    int valor;
    int cuenta = 0;
    std::vector<int> aristasVerticeActual;
    for (int i = 0; i < vectorVertices.size(); i++){
        if (graph[u][i] == 1){
            aristasVerticeActual.push_back(i);
        }
    }

    for (int arista : aristasVerticeActual){
        if (find(visitados->begin(), visitados->end(), arista) == visitados->end()){
            visitados->push_back(arista);
            std::cout << arista << std::endl;
            DFS(graph, arista, vectorVertices, visitados);
        }   
    }
}

void BFS(Graph<int, int> * graph, int u)
{
    int target = 0;
    int valor;
    /* Defición de queue para alamcenar los nodos */
    std::queue< Vertex <int, int>* > q;
    std::vector<int> valores;
    /* Nodo auxiliar para comparar */
    Vertex <int, int> * aux;
    q.push(graph->getVertex(target));
    valores.push_back(target);
    

    /* Recorrer los nodos por nivel hasta llegar al final */
    while (!q.empty()){
        /* Almacenar el primer valor de la queue en auxiliar*/
        aux = q.front();
        target = aux->getInfo();
        std::cout << aux->getInfo() << std::endl;
        q.pop();
        for (int i = 0; i<graph->getNumEdges(target); i++){
            Edge<int, int> * arista = graph->getEdge(target, i);
            valor = arista->getTarget()->getInfo();
            if (find(valores.begin(), valores.end(), valor) == valores.end()){
                valores.push_back(valor);
                q.push(arista->getTarget()); 
                
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    /* Definir número de vértices y aristas */
    const int vertices = 10;
    const int aristas = 15;
    
    /* Declaración del grafo como matriz de adyacencia */
    std::vector < std::vector<int> > matriz_adyacencia(vertices);

    std::vector<int> vectorVertices(vertices);
    
    /* Generar los vértices */
    for (int i = 0; i < vertices; ++i) {
        vectorVertices[i] = i;
    }

    /* Generar el grafo como matriz de adyacencia */
    matriz_adyacencia = loadGraph(vertices, aristas, matriz_adyacencia, vectorVertices);
    
    /* Recorrido con DFS */
    std::cout << "------ Matriz de adyacencia con DFS ------" << std::endl;
    int nodo_u = 0;
    std::vector<int> * visitados = new std::vector<int>();
    visitados->push_back(nodo_u);

    //visualizar(matriz_adyacencia, vectorVertices);
    
    /* Imprimir el primer nodo */
    std::cout << nodo_u << std::endl;
    DFS(matriz_adyacencia, nodo_u, vectorVertices, visitados);
    
    /* Declaración del grafo como multilista */
    Graph<int, int> * multilista = new Graph<int, int>();

    /* Generar el grafo como multilista */
    loadGraph2(vertices, aristas, multilista);
    
    /* Recorrido con BFS */
    std::cout << "------ Multilista con BFS ------" << std::endl;
    int nodo_v = 0;
    BFS(multilista, nodo_v);
    
    delete multilista;
    
    return 0;
}
