#include "ConexionesComputadora.hpp"
using namespace std;

ConexionesEntrantes* ConexionesComputadora::getConexionesEntrantes(){
    return ConexionEntrante;
}

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
    string IpDestino = ConexionEntrante->getIpOrigen().top();
    return IpDestino;
}
string ConexionesComputadora::saliente(){
    string IpOrigen = ConexionSaliente->getIPOrigen().front();
    return IpOrigen;
}
int ConexionesComputadora::entrantesTotales(){
    return ConexionEntrante->size();         
}
void ConexionesComputadora::salientesTotales(){
    cout << " El numero de conexiones salientes es: " << ConexionSaliente->size() << endl;         
}
vector<string> ConexionesComputadora::ConversionVectorOrigen(){
    /* Guardar todas las direcciones en un vector para hacer su lectura más fácil */
    vector <string> vectorOrigen;
    vector<string> ipOrigenFile = archivoPadre.getIpOrigen();
    int size = archivoPadre.getIpOrigen().size();
    for (int i = 0; i < size; i++){
        if (ipOrigenFile[i] == IP){
            vectorOrigen.push_back(ipOrigenFile[i]);
        }
    }
    return vectorOrigen;
}
vector<string> ConexionesComputadora::ConversionVectorDestino(){
    /* Guardar todas las direcciones en un vector para hacer su lectura más fácil */
    vector <string> vectorDestino; 
    vector<string> ipOrigenFile = archivoPadre.getIpOrigen();
    vector<string> ipDestinoFile = archivoPadre.getIpDestino();
    int size = archivoPadre.getIpDestino().size();
    for (int i = 0; i < size; i++){
        if (ipOrigenFile[i] == IP){
            vectorDestino.push_back(ipDestinoFile[i]);
        }
    }
    return vectorDestino;
}
string ConexionesComputadora::conexionesSeguidas(){
    vector <string> vectorOrigen = ConversionVectorOrigen();
    vector <string> vectorDestino = ConversionVectorDestino();
    bool condicion = false;
    for (int i = 0; i < vectorDestino.size(); i++){
        string comparaExterna1 = vectorDestino[i];
        int n = 1;
        while (n <= 2){
            string comparaExterna2 = vectorDestino[i+n];
            if (comparaExterna1 == comparaExterna2){
                condicion = true;
                n++;
            }
            else{
                condicion = false;
                break;
            }
        }
        if (condicion == true){
                return vectorDestino[i];
            }
    }
    if (condicion == false){
                return "-";
        }
    return "";
}