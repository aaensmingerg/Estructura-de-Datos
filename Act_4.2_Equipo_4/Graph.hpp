//
//  Graph.hpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "Vertex.hpp"

template <class V, class E>
class Graph {
    
    std::vector < Vertex<V, E> * > nodes;
    
public:
    
    Graph() {}
    ~Graph();
    
    void addVertex(V & );
    void addVertex(Vertex<V,E> * );
    void addEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    void addEdge(Vertex<V,E> *, V, E);
    void removeEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    
    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream &, const Graph<Vn,En> &);

    Vertex<V, E> * getVertex(const int);
    std::vector<Vertex<V, E> *> getNodes();
    Edge<V, E> * getEdge(const int, const int);
    int getNumEdges(const int);
};

template <class V, class E>
Graph<V,E>::~Graph()
{
    for (auto v: nodes) {
        delete v;
    }
    
    nodes.clear();
}

template <class V, class E>
void Graph<V,E>::addVertex(V & value )
{
    auto vertex = new Vertex<V, E>(value);
    
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addVertex(Vertex<V,E> * vertex )
{
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value)
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    /* Crear un edge y adicionarlo al vertex */
    Edge<V, E> * edge = new Edge<V,E>(value, target);
    
    (*node)->addEdge(edge);
}

template <class V, class E>
void Graph<V,E>::addEdge(Vertex<V,E> * source, V target, E value)
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);

    /* Definir la variable ne la que almacenar la direccion*/
    Vertex<V,E> * nodeTarget;

    /* Buscar vertice target por valor */
    for (auto verticeTarget : nodes){
        if(verticeTarget->getInfo() == target){
            nodeTarget = verticeTarget;
        }
    }
    addEdge(source, nodeTarget, value);
}


template <class V, class E>
void Graph<V,E>::removeEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value )
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    Vertex<V,E> * vertex = (*node);
    
    auto * edges = vertex->getEdges();
    
    Edge<V,E> * to_remove = nullptr;
    
    for (auto e : *edges) {
        if (e->getInfo() == value && e->getTarget() == target) {
            to_remove = e;
            break;
        }
    }
    
    if (to_remove) {
        vertex->removeEdge(to_remove);
    }
    
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os, const Graph<V,E> & graph)
{
    os << "--- Graph ---" << std::endl;
    
    for (auto v :  graph.nodes) {
        os << *v;
    }
    
    return os;
}


template <class V, class E>
Vertex<V, E> * Graph<V,E>::getVertex(const int n)
{
    return this->nodes[n];
}

template <class V, class E>
std::vector< Vertex<V, E> *> Graph<V,E>::getNodes()
{
    return nodes;
}


template <class V, class E>
Edge<V, E> * Graph<V, E>::getEdge(const int n , const int m)
{
    Vertex <V, E>* vertices = this->nodes[n];
    return vertices->getEdge(m);
}

template <class V, class E>   
int Graph<V, E>::getNumEdges(const int n)
{
    Vertex <V, E>* vertices = this->nodes[n];
    return vertices->size();
}


#endif /* Graph_hpp */
