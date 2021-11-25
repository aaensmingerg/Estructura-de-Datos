#include "HashMap_Enlazado.hpp"
#include <vector>

template <class K, class V>
class HashMapEnlazado {
    int _capacity = 0;
    
    std::vector<std::vector<K>> _keys;
    std::vector<std::vector<V>>  _values;
    std::vector<std::string> _status;
    
    int _size = 0;
    
    int hash_function(K) const;
    
public:
    HashMapEnlazado(int);
    ~HashMapEnlazado();
    
    bool empty() const;
    int size() const;
    int capacity() const;
    
    bool put(K,V);
    int rehash(int, int);
    V get(K);
};

template <class K, class V>
HashMapEnlazado<K,V>::HashMapEnlazado(int capacity)
{
    this->_capacity = capacity;
    this->_status = std::vector<std::string>(capacity);
    this->_keys = std::vector<std::vector<K>>(capacity);
    this->_values = std::vector<std::vector<V>>(capacity);
    
    fill(_status.begin(), _status.end(), "vacio");
}

template <class K, class V>
HashMapEnlazado<K,V>::~HashMapEnlazado()
{
    /*
    delete this->_status;
    delete this->_values;
    delete this->_keys;
     */
}

template <class K, class V>
bool HashMapEnlazado<K,V>::empty() const
{
    return this->_size == 0;
}

template <class K, class V>
int HashMapEnlazado<K,V>::size() const
{
    return this->_size;
}

template <class K, class V>
int HashMapEnlazado<K,V>::capacity() const
{
    return this->_capacity;
}

template <class K, class V>
int HashMapEnlazado<K,V>::hash_function(K key) const
{
    return key % this->_capacity;
}

template <class K, class V>
bool HashMapEnlazado<K,V>::put(K key,V value)
{
    int indice = hash_function(key);

    this->_keys[indice].push_back(key);
    this->_values[indice].push_back(value);
    
    
    return true;
}

template <class K, class V>
int HashMapEnlazado<K,V>::rehash(int indice, int steps)
{
    if (indice < this->_capacity && steps < this->_capacity) {
        
        ++indice;
        
        if (indice == this->_capacity) indice = 0;
        
        if (this->_status[indice] == "ocupado")
        {
            indice = rehash(indice, ++steps);
        }
        
        return indice;
    }
    else {
        return -1;
    }
}

template <class K, class V>
V HashMapEnlazado<K,V>::get(K key)
{
    int steps = 0;
    
    int indice = hash_function(key);
    for (int i = 0; i < this->_keys[indice].size(); i++){
        if (this->_keys[indice][i] == key){
            std::cout << "Posicion en el Hash Map" << std::endl;
            std::cout << indice << " --> " << i << std::endl; //Comprobar que funciona lista enlazada
            std::cout << "Valor" << std::endl;
            return this->_values[indice][i];
        }
    }
    return -1;
}
