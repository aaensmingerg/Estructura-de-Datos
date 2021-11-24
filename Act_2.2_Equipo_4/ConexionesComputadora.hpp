#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ConexionesEntrantes.cpp"
#include "ConexionesSalientes.cpp"
#include "Busqueda.hpp"
using namespace std;
class ConexionesComputadora{
    private:
    string IP = "1.1.1.";
    ConexionesEntrantes* ConexionEntrante;
    ConexionesSalientes* ConexionSaliente;
    File archivoPadre;
    public:
    
    /* Constructor de la Clase */
    ConexionesComputadora(string IP_, File f1){
        for(int i=0; i < IP_.size(); i++){
            IP.push_back(IP_[i]);
        }
        archivoPadre = f1;
        ConexionesEntrantes* e1 = new ConexionesEntrantes(IP,f1);
        ConexionesSalientes* s1 = new ConexionesSalientes(IP,f1);
        ConexionEntrante = e1;
        ConexionSaliente = s1;
    }

    /* Determina si el valor parámetro de tipo string "ip" pertenece a las ip internas segmento de red.... */
    void isInterna(string IP_);

    /* Imprime el valor de IP */
    void printIp();

    /* Regresa el valor de la última conexión entrante*/
    string entrante();

    /* Regresa el valor de la primera conexión saliente */
    string saliente();

    /* Imprime el número de conexiones entrantes totales */
    void entrantesTotales();

    /* Imprime el número de conexiones entrantes salientes */
    void salientesTotales();

    vector<string> ConversionVectorDestino();

    vector<string> ConversionVectorOrigen();

    string conexionesSeguidas();
};