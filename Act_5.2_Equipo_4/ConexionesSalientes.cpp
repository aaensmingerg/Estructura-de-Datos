#include "ConexionesSalientes.hpp"
using namespace std;

vector<pair<string,string>> ConexionesSalientes::getVecIpDestino(){
    return vecIpDestino;
}

vector<string> ConexionesSalientes::getIPOrigen(){
        return ipOrigen;
    }
int ConexionesSalientes::size(){
    return ipOrigen.size();
}