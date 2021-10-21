//
//  BST.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 20/10/20.
//

#include <queue>
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

    int height();

    void ancestors(TreeNode<T> * );
    
    int whatlevelami(TreeNode<T> * );
    
    void levelByLevel();
    void levelByLevel(TreeNode<T> *);

    void visit(int);

    void setLevels(); 
    void setLevels(TreeNode<T> *);    
    
private:
    /* Ocultar algunos métodos heredados */
    //using BinaryTree<T>::insert;
    int altura = 0;
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
int BST<T>::height(){
   return this->altura;
}

template <class T>
void BST<T>::ancestors(TreeNode<T> * node){
    TreeNode<T> * aux = node;
    while (this->root != aux){
        std::cout << *aux->getParent() << std::endl;
        aux = aux->getParent();
    }
}

template <class T>
int BST<T>::whatlevelami(TreeNode<T> * node){
    return node->getAltura();
}

template <class T>
void BST<T>::levelByLevel(){
    if (!this->empty()){
    this->root->setAltura(1);
    this->levelByLevel( this->root);
    }
}

template <class T>
void BST<T>::levelByLevel(TreeNode<T> * node) {
    std::queue< TreeNode <T>* > q;
    TreeNode<T>* aux;

    q.push(node);
    
    int alturaActual = 0;

    while (!q.empty()){
        aux = q.front();
        int auxLevel = aux->getAltura();
        q.pop();
        
        TreeNode<T>* Izq = aux->getLeft();
        if (Izq != nullptr){
            q.push(Izq);
        }

        TreeNode<T>* Der = aux->getRight();
        if (Der != nullptr){
            q.push(Der);
        }

        if (alturaActual != auxLevel){
            alturaActual += 1 ;
            std::cout << std::endl <<"Nivel " << alturaActual << ": ";
            
        }
        std::cout << *aux << " - "; 

    }
}

template <class T>
void BST<T>::setLevels(){
    if (!this->empty()){
    this->root->setAltura(1);
    this->setLevels( this->root);
    }
}

template <class T>
void BST<T>::setLevels(TreeNode<T> * node) {
    std::queue< TreeNode <T>* > q;
    TreeNode<T>* aux;
    q.push(node);
    
    int alturaActual = 0;

    while (!q.empty()){
        aux = q.front();
        int auxLevel = aux->getAltura();
        q.pop();
        
        TreeNode<T>* Izq = aux->getLeft();
        if (Izq != nullptr){
            Izq->setAltura(auxLevel + 1);
            q.push(Izq);
        }

        TreeNode<T>* Der = aux->getRight();
        if (Der != nullptr){
            Der->setAltura(auxLevel + 1);
            q.push(Der);
        }

        if (alturaActual != auxLevel){
            alturaActual += 1 ;
            this->altura = alturaActual;
        }
    }
}

template <class T>
void BST<T>::visit(int opt){
    switch (opt)
    {
    case 1:
        std::cout << std::endl <<"Se imprime el BST en PreOrden" << std::endl;
        this->preOrden();
        std::cout << std::endl;
        break;
    
    case 2:
        std::cout << std::endl << "Se imprime el BST en InOrden" << std::endl;
        this->inOrden();
        std::cout << std::endl;
        break;
    case 3:
        std::cout << std::endl << "Se imprime el BST en PostOrden" << std::endl;
        this->postOrden();
        std::cout << std::endl;
        break;
    case 4:
        std::cout << std::endl << "Se imprime el BST por nivel " << std::endl;
        this->levelByLevel();
        std::cout << std::endl;
        break;
    default:
        break;
    }

}
#endif /* BST_hpp */
