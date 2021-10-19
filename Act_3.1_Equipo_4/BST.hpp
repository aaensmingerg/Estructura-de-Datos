//
//  BST.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 20/10/20.
//

#ifndef BST_hpp
#define BST_hpp

#include "BinaryTree.hpp"

template <class T>
class BST : public BinaryTree<T>
{
    
public:
    BST() {};
    virtual ~BST() { };
    
    TreeNode<T> * search(const T &) const;
    bool insert(T &);
    bool insert(TreeNode<T> * );

    void getAltura(std::vector<T>);
    void getAncestors(TreeNode<T> * );
    int getNivel(TreeNode<T> * );
    
    
private:
    /* Ocultar algunos métodos heredados */
    //using BinaryTree<T>::insert;
};
template <class T>
TreeNode<T> * BST<T>::search(const T & value) const
{
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            return aux;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    return nullptr;
}

template <class T>
bool BST<T>::insert(T & value)
{
    return this->insert(new TreeNode<T>(value));
}

template <class T>
bool BST<T>::insert(TreeNode<T> * node )
{
    /* No se puede insertar un nodo NULL */
    if (node == nullptr) return false;
    
    /* Obtener la info del nodo a insertar */
    T value = node->getInfo();
    
    /* Establecer un apuntador auxiliar */
    TreeNode<T> * aux = this->root;
    
    /* Estalecer una variable para el padre */
    TreeNode<T> * parent = nullptr;
    
    /* Buscar la posición que le corresponde */
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            /* Liberar la memoria del nodo porque ya existe */
            delete node;
            
            return false;
        }
        else {
            parent = aux;
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    /* Establecer el parent del nodo a insertar */
    node->setParent(parent);
    
    /* Si el árbol está vacío, se inserta la raiz */
    if (parent == nullptr) {
        this->root = node;
    }
    else {
        /* Si el value a insertar es menor, se inserta a la izquierda */
        if ( parent->getInfo() > value ) {
            parent->setLeft(node);
        }
        /* Si el value a insertar es mayor, se inserta a la derecha */
        else {
            parent->setRight(node);
        }
    }
    
    return true;
}

template <class T>
void BST<T>::getAltura(std::vector<T> hojas){
    int mayor = 0;
    for (int n =0; n < hojas.size(); n++){
        TreeNode <int> * hoja = search(hojas[n]);
        int nivel = getNivel(hoja);
        if (nivel > mayor){
            mayor = nivel;
        }
    }
    std::cout << mayor << std::endl;
}

template <class T>
void BST<T>::getAncestors(TreeNode<T> * node){
    TreeNode<T> * aux = this->root;
    while (node != aux){
        std::cout << *node->getParent() << std::endl;
        node = node->getParent();
    }
}

template <class T>
int BST<T>::getNivel(TreeNode<T> * node){
    TreeNode<T> * aux = this->root;
    int cuenta = 1;
    while (node != aux){
        node = node->getParent();
        cuenta++;
    }
    return cuenta;
}

#endif /* BST_hpp */
