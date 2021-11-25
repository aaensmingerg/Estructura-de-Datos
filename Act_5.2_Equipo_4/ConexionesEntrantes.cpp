
#include "ConexionesEntrantes.hpp"
using namespace std;

stack<string> ConexionesEntrantes::getIPDestino(){
    return ipOrigen;
}

int ConexionesEntrantes::size(){
    return ipOrigen.size();
}