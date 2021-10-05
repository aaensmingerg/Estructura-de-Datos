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
    public:
    /* Constructor de la Clase */
    ConexionesComputadora(string IP, string nombre, ConexionesEntrantes* ConexionEntrante, ConexionesSalientes* ConexionSaliente):IP(IP),nombre(nombre),ConexionEntrante(ConexionEntrante),ConexionSaliente(ConexionSaliente){}
    void printEntrante(){
        string IpDestino = ConexionEntrante->getIPDestino().front();
        cout << IpDestino << endl;
    }
    void printSaliente(){
        string IpOrigen = ConexionSaliente->getIPOrigen().top();
        cout << IpOrigen << endl;
    }
};