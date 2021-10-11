#include "ConexionesComputadora.hpp"
using namespace std;

void ConexionesComputadora::isInterna(string IP_){
    vector<string> ipInternos = archivoPadre.valoresUnicos(archivoPadre.getIpOrigen());
    int indice = Busqueda<string>::busquedaSecuencial(ipInternos, IP_);
    if(indice != -1){
        cout << "La IP: " << IP_ << ", Es interna" << endl;
    }
    else
        cout << "La IP: " << IP_ << ", Es externa" << endl;
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