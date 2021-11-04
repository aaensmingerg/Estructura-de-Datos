//
//  main.cpp
//  BinaryTree
//
//  Created by Vicente Cubells on 13/10/20.
//  Updated by Aquiles Ensminger and Javier Lozano

/* Este programa utiliza la estructura de un árbol binario de búsqueda 
sobre la que se implementan los métodos "Visit", "Height", "whatlevelami" y 
"ancestors". Estos se encuentran definidos en el archivo BST.hpp.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Viernes 22 de Octubre de 2021  */

#include <iostream>
#include <vector>
#include "TreeNode.hpp"
#include "BinaryTree.hpp"
#include "BST.hpp"

int main(int argc, const char * argv[]) {
    
    /* Crear un árbol */
    BST<int> * bst = new BST<int>();
    
    /* Insertar nodos en el árbol */
    TreeNode<int> * na = new TreeNode<int>(10);
    TreeNode<int> * nb = new TreeNode<int>(8);
    TreeNode<int> * nc = new TreeNode<int>(4);
    TreeNode<int> * nd = new TreeNode<int>(12);
    TreeNode<int> * ne = new TreeNode<int>(6);
    TreeNode<int> * nf = new TreeNode<int>(9);
    TreeNode<int> * ng = new TreeNode<int>(7);
    TreeNode<int> * nh = new TreeNode<int>(3);
    
    bst->insert(na);
    bst->insert(nb);
    bst->insert(nc);
    bst->insert(nd);
    bst->insert(ne);
    bst->insert(nf);
    bst->insert(ng);
    bst->insert(nh);
    
    /* Una vez añadidos los nodos se usa el método "setLevels" 
    para asignar el nivel que tiene cada nodo */

    bst->setLevels();

    /* Variable input*/
    int opt;

    /* Demostración método "visit" */
    std::cout << "--- 1) Indique metodo de visita---" << std::endl;
    std::cout << "1. Preorden" << std::endl << "2. Inorden" << std::endl;
    std::cout << "3. Postorden" << std::endl << "4. Level by level" << std::endl;
    std::cout << ": ";
    std::cin>>opt;
    bst->visit(opt);

    /* Demostración método "height" */
    std::cout << "2) La altura del árbol es: ";
    int altura = bst->height();
    std::cout << altura << std::endl;
    
    /* Demostración método "ancestors" */

    /* Búsqueda de nodo a encontrar ancestros */
    int nodoBuscar;
    std::cout << "Ingrese nodo para buscar sus ancestros: ";
    std::cin >> nodoBuscar;
    TreeNode<int> * node = bst->search(nodoBuscar);
    if (node != nullptr){
        std::cout << "3) Los ancestros del nodo con valor (" << nodoBuscar << ") son: " << std::endl;
        bst->ancestors(node);
    }    
    else std::cout << "El nodo: " << nodoBuscar << " no se encuentra en el arbol" << std::endl;

    /* Demostración método "whatlevelami" */
    std::cout << "Ingrese nodo para encontrar su nivel: ";
    std::cin >> nodoBuscar;
    TreeNode<int> * node2 = bst->search(nodoBuscar);
    if (node2 != nullptr){
        int altura = bst->whatlevelami(node2);
        std::cout << "4) El nivel al que se encuentra el nodo (" << *node2 << ") es: " << altura << std::endl;  
    }
    else std::cout << "El nodo: " << nodoBuscar << " no se encuentra en el arbol" << std::endl;

    /* Eliminar la memoria ocupada por el BST */
    delete bst;
    std::cout << "Se liberó la memoria del BST" << std::endl;
    
    
    return 0;
}
