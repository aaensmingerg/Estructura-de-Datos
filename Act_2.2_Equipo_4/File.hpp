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
    
    /* Getter de fecha */
    vector<Fecha> getFecha();
    
    /* Getter de nombreDestino */
    vector<string> getNombreDestino();

    /* Getter de ipOrigen */
    vector<string> getIpOrigen();

    /* Getter de ipDestino */
    vector<string> getIpDestino();

    /* Getter de puertoOrigen */
    vector<string> getPuertoOrigen();
    
    /* La función "buscarSegundaFecha" busca todas las fechas correspondientes a
    la segunda fecha */
    Fecha buscarSegundaFecha();

    /* La función "busquedaNombre" busca todas instancias
    que tiene alguno de los nombres requeridos */
    void busquedaNombre();
    
    /* La función "ValoresUnicos" regresa los valores unicos de un vector, 
    solo si el vector se encuentra ordenado  */
    template<class T>
    vector<T> valoresUnicos(vector<T>);

    /* La funcion "printNombresUnicos" imprime 
    los valores unicos de la columna nombre */
    void printNombresUnicos();
    
    /* La función "direcccionIterna" obtiene la
    dirección interna del IP de Origen */
    vector<string> direcccionIterna();

    /* La función "correosElectronicos" busca todas instancias
    que tiene alguno de los servicios de correo electrónico
    requeridos */
    void correosElectronicos();

    /* La función "puertosUsados" calcula los puertos destino debajo del 1000  */
    void puertosUsados();

    /* La función "printPuertos" imprime los puertos destino debajo del 1000 */
    void printPuertos(vector<int>);
};
