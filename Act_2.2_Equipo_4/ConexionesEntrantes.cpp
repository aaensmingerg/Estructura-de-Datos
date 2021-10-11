
#include "ConexionesEntrantes.hpp"
using namespace std;

stack<string> ConexionesEntrantes::getIPDestino(){
    return ipDestino;
}

int ConexionesEntrantes::size(){
    return ipDestino.size();
}