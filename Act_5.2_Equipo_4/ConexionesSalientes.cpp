#include "ConexionesSalientes.hpp"
using namespace std;

queue<string> ConexionesSalientes::getIPOrigen(){
        return ipDestino;
    }
int ConexionesSalientes::size(){
    return ipDestino.size();
}