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
    /*

    El nombre se asigna como parametro o se determina 
    a partir de una busqueda del documento donde sea igual 
    la ip dada?


    No contamos los valores "-"?
    */

    string IP = "172.17.230", nombre;
    ConexionesEntrantes* ConexionEntrante;
    ConexionesSalientes* ConexionSaliente;
    File archivoPadre;
    public:
    
    /* Constructor de la Clase */
    ConexionesComputadora(string IP_, string nombre_, File f1){
        for(int i=0; i < IP_.size(); i++){
            IP.push_back(IP_[i]);
        }
        archivoPadre = f1;
        nombre = nombre_;
        ConexionesEntrantes* e1 = new ConexionesEntrantes(IP,f1);
        ConexionesSalientes* s1 = new ConexionesSalientes(IP,f1);
        ConexionEntrante = e1;
        ConexionSaliente = s1;
    }

    /* Determina si el valor parámetro de tipo string "ip" pertenece a las ip internas */
    void isInterna(string IP_);

    /* Imprime el valor de IP */
    void printIp();

    /* Regresa el valor de la última conexión entrante*/
    string entrante();

    /* Regresa el valor de la primera conexión saliente */
    string saliente();

    /* imprime el número de conexiones entrantes totales */
    void entrantesTotales();

    /* imprime el número de conexiones entrantes salientes */
    void salientesTotales();
};