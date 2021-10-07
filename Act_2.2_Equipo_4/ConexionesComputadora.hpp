#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ConexionesEntrantes.hpp"
#include "ConexionesSalientes.hpp"

class ConexionesComputadora{
    private:
    std::string IP, nombre;
    ConexionesEntrantes* ConexionEntrante;
    ConexionesSalientes* ConexionSaliente;
    void setIP(string _IP){
        IP = _IP;
    }
    public:
    /* Constructor de la Clase */
    ConexionesComputadora(string IP, string nombre, ConexionesEntrantes* ConexionEntrante, ConexionesSalientes* ConexionSaliente):IP(IP),nombre(nombre),ConexionEntrante(ConexionEntrante),ConexionSaliente(ConexionSaliente){}
    void printEntrante(){
        string IpDestino = ConexionEntrante->getIPDestino().top();
        cout << IpDestino << endl;
    }
    void printSaliente(){
        string IpOrigen = ConexionSaliente->getIPOrigen().front();
        cout << IpOrigen << endl;
    }
    void direcccionIterna(string _IP){
        string IP;
        string IpOrigen = ConexionSaliente->getIPOrigen().front();
        queue<string> IpOrigenes = ConexionSaliente->getIPOrigen();
        while(IpOrigenes.front() == "-"){
            IpOrigenes.pop();
        }
        IpOrigen = IpOrigenes.front(); 
        for(int i=0; i < 10; i++){
            IP.push_back(IpOrigen[i]);
        }
        IP.append(".");
        IP.append(_IP);
        setIP(IP);   
    }
    void printIP(){
        cout << IP << endl;
    }
};