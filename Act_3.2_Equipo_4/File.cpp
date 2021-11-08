
#include "File.hpp"
using namespace std;
        

Fecha File::buscarSegundaFecha(){
        int encontrados;
        int inicial;
        Fecha fechaInicial = fecha[0];
        Fecha fechaBuscar;
        for (int i = 0; i < fecha.size(); i++){
            if (fecha[i] != fechaInicial){
                inicial = i;
                fechaBuscar = fecha[i];
                break;
            }
        }
        while (fecha[inicial] == fechaBuscar){
            encontrados++;
            inicial++;
        }
        cout << encontrados << endl;
        return fechaBuscar;
    }

vector<Fecha> File::getFecha(){
    return fecha;
}

vector<string> File::getNombreDestino(){
    return nombreDestino;
}

template<class T>
vector<T> File::valoresUnicos(vector<T> vectorBusqueda){
    vector<T> unicos = {vectorBusqueda[0]};
    T valorComparar = vectorBusqueda[0];
    for(int i=0; i < vectorBusqueda.size(); i++){
        if(vectorBusqueda[i] != valorComparar){
            if(i > 0 && vectorBusqueda[i-1] != valorComparar){
                unicos.push_back(vectorBusqueda[i]);
                valorComparar = vectorBusqueda[i];
            }
        }
    }
    return unicos;
}

template<class T>
vector<T> File::valoresUnicosDia(vector<T> vectorBusqueda,Fecha dia){
    vector<T> unicos = {vectorBusqueda[0]};
    T valorComparar = vectorBusqueda[0];
    for(int i=0; i < vectorBusqueda.size(); i++){
        if(vectorBusqueda[i] != valorComparar && fecha[i] == dia){
            if(i > 0 && vectorBusqueda[i-1] != valorComparar){
                unicos.push_back(vectorBusqueda[i]);
                valorComparar = vectorBusqueda[i];
            }
        }
    }
    return unicos;
}

void File::busquedaNombre(){
    vector<string> nombres = {"jeffrey.reto.com","betty.reto.com","katherine.reto.com",
    "scott.reto.com","benjamin.reto.com","samuel.reto.com","raymond.reto.com","server.reto.com"};
    for(int i=0; i < nombres.size(); i++){
        int indice = Busqueda<string>::busquedaSecuencial(nombreOrigen, nombres[i]);
        if(indice == -1){
            cout << "El nombre: " << nombres[i] << " |no se encuentra|" << endl;
        }
        else{
            cout << "El nombre: " << nombres[i] << " |si se encuentra| " << endl;
        }

    }
}

void File::printNombresUnicos(){
    vector<string> dummy = nombreOrigen;
    sort(dummy.begin(), dummy.end(), Ordenamiento<string>::asc);
    vector<string> unico;
    unico = valoresUnicos(dummy);
    for(int i=0; i < unico.size(); i++){
        cout << "Nombre Registrado: " << unico[i] << endl;
    }
}
vector<string> File::direcccionIterna(){
    vector<string> almacena;
    string s1;
    for(int i=0; i < ipOrigen.size(); i++){
        if (ipOrigen[i].size() > 1){
            for(int b=0; b < 10; b++){
                s1.push_back(ipOrigen[i][b]);
            }
            almacena.push_back(s1);
            s1.clear();
        }
        
    }   
    
    return valoresUnicos(almacena);
}

void File::correosElectronicos(){
    vector<string> dummy = nombreDestino;
    sort(dummy.begin(), dummy.end(), Ordenamiento<string>::asc);
    vector<string> unico;
    unico = valoresUnicos(dummy);
    for(int i=0; i < unico.size(); i++){
        cout << "Direccion registrada: " << unico[i] << endl; 
    }
}

void File::puertosUsados(){
    vector<int> puertos = {};
    int puerto;
    for(int i=0; i < puertoDestino.size(); i++){
        if (puertoDestino[i] != "-"){
            puerto =  stoi(puertoDestino[i]);  
            if(puerto<=1000 && find(puertos.begin(), puertos.end(), puerto) == puertos.end()){
                puertos.push_back(puerto);
            }
        }
    }
    printPuertos(puertos);
}

void File::printPuertos(vector<int> puertos){
    puertos = Ordenamiento<int>::mergesort(puertos,Ordenamiento<int>::asc);
    cout << "Los puertos encontrados debajo del mil son: " << endl;
    for (int i=0; i < puertos.size(); i++){
        if (i == puertos.size()-1){
            cout << puertos[i] << "." << endl;
        }
        else{
            cout << puertos[i] << ", ";
        }  
    }
}

map<string,int> File::conexionesPorDia(string dia_){
    
    map<string,int> conexiones;
    Fecha dia = Fecha(dia_);
    vector<string> ipDestinoUnicos = valoresUnicosDia(ipDestino,dia);
    int f = 0;
    
    /* Recorrer la lista de direcciones por cada direccion en la lista*/
    for(int i=0; i < ipDestinoUnicos.size(); i++){
        int contador = 0;
        /* recorrer la lista de direcciones buscando el dia y la conexion dada*/
        for (int i=0; i <fecha.size(); i ++){

            /* Comprobar que sea el mismo dia y misma conexion*/
            if (fecha[i] == dia && ipDestino[i] == ipDestinoUnicos[f] && ipDestino[i] != "-"){
                contador ++;
            }
        }
        /* Insertar en el mapa */
        conexiones.insert(pair<string,int>(ipDestinoUnicos[f],contador));
        f ++;
    }

    return conexiones;

}

map<string,int> File::conexionesPorDia(Fecha dia){
    
    map<string,int> conexiones;
    vector<string> ipDestinoUnicos = valoresUnicosDia(ipDestino,dia);
    int f = 0;
    
    /* Recorrer la lista de direcciones por cada direccion en la lista*/
    for(int i=0; i < ipDestinoUnicos.size(); i++){
        int contador = 0;
        /* recorrer la lista de direcciones buscando el dia y la conexion dada*/
        for (int i=0; i <fecha.size(); i ++){

            /* Comprobar que sea el mismo dia y misma conexion*/
            if (fecha[i] == dia && ipDestino[i] == ipDestinoUnicos[f] && ipDestino[i] != "-"){
                contador ++;
            }
        }
        /* Insertar en el mapa */
        conexiones.insert(pair<string,int>(ipDestinoUnicos[f],contador));
        f ++;
    }

    return conexiones;

}

void File::top(int n, string dia){
    vector<Conexiones> vect;
    /* Crear un árbol */
    BST<Conexiones> * bst = new BST<Conexiones>();

    map<string,int> mapConexiones = conexionesPorDia(dia);
    for(auto r : mapConexiones){
        Conexiones con = Conexiones(r.first,r.second);
        bst->insert(new TreeNode<Conexiones>(con));
    }
    bst->topN(n);
}

void File::top(int n, Fecha dia){
    BST<Conexiones> * bst = hacerArbol(dia);
    bst->topN(n);
       
}

BST<Conexiones>* File::hacerArbol(Fecha dia){
    BST<Conexiones> * bst = new BST<Conexiones>();

    map<string,int> mapConexiones = conexionesPorDia(dia);
    for(auto r : mapConexiones){
        Conexiones con = Conexiones(r.first,r.second);
        bst->insert(new TreeNode<Conexiones>(con));
    }
    return bst;
}

vector<BST<Conexiones>> File::top5dias(){
    vector<Conexiones> conexionesDia1;
    vector<Conexiones> conexionesDiaX;
    vector<string> conexionesSiguiente;
    vector<BST<Conexiones>*> Conec;
    vector<Fecha> fechasUnicas = valoresUnicos(fecha);
    string ipSearch;
    
    for (int i=0; i < fechasUnicas.size(); i++){
        Conec.push_back(hacerArbol(fechasUnicas[i]));
        Conec[i]->setId(fechasUnicas[i]);
    }
    
    /*Es necesario correr topN para asignar los tops */
    for(auto v:Conec){
        cout << "Top 5 en el dia -> " << v->getId() << endl;
        v->topN(5);
        cout << endl;
    }
    
    for (int i=0; i<5; i++){
        conexionesDia1.push_back(Conec[0]->getTop(i));
    }

    for (auto a:conexionesDia1){
        int cont = 0;
        for (auto b:Conec){
            for (int i=0; i<5; i++){
                ipSearch = a.getIp();
                if (b->getTop(i).getIp() == ipSearch){
                    cont ++;
                }
            }
        }
        a.setDiasSeguidos(cont);
        if (a.getDiasSeguidos() == fechasUnicas.size()){
            cout << "La IP -> " << a.getIp() << ". Aparece en el top 5 todos los dias.";
            cout << " Con una frecuencia de: " << a.getFrecuencia() << " el primer dia " << endl;
        }
    }

    int b = 1;
    int cuenta = 0;
    Fecha fechaAparece;
    for (int f = 0; f < fechasUnicas.size(); f++){
        int cont = 0;
        bool diaSiguiente = false;
        for (int i = 0; i < 5; i++){
            conexionesDiaX.push_back(Conec[f]->getTop(i));
        }
        for (auto a:conexionesDiaX){
            for (int i = 0; i < 5; i++){
                ipSearch = a.getIp();
                if (Conec[b]->getTop(i).getIp() == ipSearch){
                    diaSiguiente = true;
                    if (find(conexionesSiguiente.begin(), conexionesSiguiente.end(), Conec[b]->getTop(i).getIp()) == conexionesSiguiente.end() && find(conexionesDia1.begin(), conexionesDia1.end(), Conec[b]->getTop(i)) == conexionesDia1.end()){
                        conexionesSiguiente.push_back(Conec[b]->getTop(i).getIp());
                        fechaAparece = fechasUnicas[f];
                        break;
                    }
                }
            }  
        }
        b++;
        if (conexionesSiguiente.size() !=0 && cuenta == 0){
            for (int i = 0; i < conexionesSiguiente.size(); i++){
                cuenta++;
                cout << "La IP -> " << conexionesSiguiente[i] << ". Aparece en el top 5 desde la fecha -> " << fechaAparece << endl;
            }

        }
    }
    //cout << conexionesSiguiente.size() << endl;
    //conexionesDiaX.clear();
}

    


    



