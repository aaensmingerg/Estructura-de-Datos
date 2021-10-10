#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ConexionesEntrantes.hpp"
#include "ConexionesSalientes.hpp"
using namespace std;
class ConexionesComputadora{
    private:
    /*

    El nombre se asigna como parametro o se determina 
    a partir de una busqueda del documento donde sea igual 
    la ip dada?

    */

    string IP = "172.17.230", nombre;
    ConexionesEntrantes* ConexionEntrante;
    ConexionesSalientes* ConexionSaliente;

    public:
    /* Constructor de la Clase */
    ConexionesComputadora(string IP_, string nombre_, File f1){
        for(int i=0; i < IP_.size(); i++){
            IP.push_back(IP_[i]);
        }
        nombre = nombre_;
        ConexionesEntrantes* e1 = new ConexionesEntrantes(IP,f1);
        ConexionesSalientes* s1 = new ConexionesSalientes(IP,f1);
        ConexionEntrante = e1;
        ConexionSaliente = s1;
    }

    void printIp(){
        cout << "IP: " << IP << endl;;
    }
    void printEntrante(){
        string IpDestino = ConexionEntrante->getIPDestino().top();
        cout << IpDestino << endl;
    }
    void printSaliente(){
        string IpOrigen = ConexionSaliente->getIPOrigen().front();
        cout << IpOrigen << endl;
    }
    void entrantesTotales(){
        cout << " El numero de conexiones entrantes es: " << ConexionEntrante->size() << endl;         
    }
    void salientesTotales(){
        cout << " El numero de conexiones salientes es: " << ConexionSaliente->size() << endl;         
    }
};