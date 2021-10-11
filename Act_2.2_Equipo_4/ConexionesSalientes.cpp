#include "ConexionesSalientes.hpp"
using namespace std;

queue<string> ConexionesSalientes::getIPOrigen(){
        return ipOrigen;
    }
int ConexionesSalientes::size(){
    return ipOrigen.size();
}