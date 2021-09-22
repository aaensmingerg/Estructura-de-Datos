#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Fecha.cpp"
#include "Ordenamiento.hpp"
using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class File{
    protected:
        string fileName;
        vector<Fecha> fecha;
        vector<string> hora,ipOrigen,puertoOrigen,nombreOrigen,ipDestino,puertoDestino,nombreDestino;
    public:
    /* Constructor de la clase*/
    File(string fileName_){
        fileName = fileName_;
        string line,word;
        string row[8];
        ifstream file;
        int j = 0;
        file.open(fileName);
        while(getline(file, line)){
            stringstream sS(line);
            int i = 0;
            while(getline(sS,word,',')){
                row[i] = word;
                i++;
            }
            Fecha f(row[0]);
            fecha.push_back(f);
            hora.push_back(row[1]);
            ipOrigen.push_back(row[2]);
            puertoOrigen.push_back(row[3]);
            nombreOrigen.push_back(row[4]);
            ipDestino.push_back(row[5]);
            puertoDestino.push_back(row[6]);
            nombreDestino.push_back(row[7]);
            j++;
        }
        file.close();
    }
    
    /* get fecha */
    vector<Fecha> getFecha();
    
    /* get fecha */
    vector<string> getNombreDestino();

    /* get Puertos */
    vector<string> getPuertoOrigen();
    
    /* Hace falta ordenar primero */
    Fecha buscarSegundaFecha(File);

    /* Busqueda por nombre */
    void busquedaNombre();
    
    /* Valores unicos */
    template<class T>
    vector<T> valoresUnicos(vector<T>);

    /* Direccion interna */
    vector<string> direcccionIterna();

    /* Servicio de correo electronico */
    void correosElectronicos();

    /* Puertos destino debajo del 1000 */
    void puertosUsados();

    /* Imprimir puertos destino debajo del 1000 */
    void printPuertos(vector<int>);
};