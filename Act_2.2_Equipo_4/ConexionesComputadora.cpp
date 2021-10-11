#include "ConexionesComputadora.hpp"
using namespace std;

void ConexionesComputadora::isInterna(string IP_){
    string dummyIp;
    string dummyIp2;
    int n = 0;
    int i = 0;
    while(n < 3){
        dummyIp.push_back(IP_[i]);
        if (IP_[i] == '.'){
            n++;
        }
        i++;
    }
    
    n = 0;
    i = 0;
    while(n < 3){
        dummyIp2.push_back(IP[i]);
        if (IP[i] == '.'){
            n++;
        }
        i++;
    }

    if( dummyIp == dummyIp2){
        cout << "La IP: " << IP_ << ", es interna" << endl;
    }
    else 
        cout << "La IP: " << IP_ << ", es externa" << endl;
}

void ConexionesComputadora::printIp(){
    cout << "IP: " << IP << endl;;
}
string ConexionesComputadora::entrante(){
    string IpDestino = ConexionEntrante->getIPDestino().top();
    return IpDestino;
}
string ConexionesComputadora::saliente(){
    string IpOrigen = ConexionSaliente->getIPOrigen().front();
    return IpOrigen;
}
void ConexionesComputadora::entrantesTotales(){
    cout << " El numero de conexiones entrantes es: " << ConexionEntrante->size() << endl;         
}
void ConexionesComputadora::salientesTotales(){
    cout << " El numero de conexiones salientes es: " << ConexionSaliente->size() << endl;         
}