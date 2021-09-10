
/* Este programa lleva un registro de ventas 
de una concesionaria que comercializa vehículos usados. 
Los vehículos se clasifican en: autos, camionetas y motocicletas. 
Todos los vehículos tienen un código, una marca, un modelo (año), y el kilometraje.
De las camionetas se conoce además el tipo de tracción que tienen (4x2, 4x4, AWD o 4WD). 
De las motocicletas se conoce además el cilindraje (150cc, 250cc, etc.). 
cada registro consiste de la siguiente información: monto de la venta, vehículo vendido y comprador (apellido, nombre e INE).
Además se ecnuentra un menú de búsqueda para hacer busqueda sobre el inventario
con algoritmos de búsqueda de: Burbuja, Selección, Inserción, QuickSort y MergeSort
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Jueves 26 de Agosto de 2021  */


#include <iostream>
#include <iterator>
#include <vector>
#include "Ordenamiento.hpp"
#include "listadoCompras.cpp"
#include "camioneta.cpp"
#include "motocicleta.cpp"





/* La función "crearCompra" Genra un menú de entrada 
en el que se ingresan los valores necesarios para construir un objeto de tipo Compra*/
Compra crearCompra(){
    cout << "Introduzca los datos de la compra: " << endl;
    cin.get();
    
    int monto;
    cout << "Valor de la compra: ";
    cin >> monto;

    string nombre;
    cout << "Nombre del comprador: ";
    cin >> nombre;
    
    string apellido;
    cout << "Apellido del comprador: ";
    cin >> apellido;
    
    string ine;
    cout << "INE del comprador: ";
    cin >> ine;
    
    int codigo;
    cout << "Codigo del vehiculo: ";
    cin >> codigo;
    
    string marca;
    cout << "Marca del vehiculo: ";
    cin >> marca;
    
    int modelo;
    cout << "Modelo del vehiculo: ";
    cin >> modelo;

    int kilometraje;
    cout << "Kilometraje del vehiculo: ";
    cin >> kilometraje;

    string tipoDeVehiculo;
    cout << "Tipo de vehiculo (A)->Auto (C)->Camioneta (M)->Moto: ";
    cin >> tipoDeVehiculo;

    if (tipoDeVehiculo=="A"){
        Persona* p1=new Persona(nombre, apellido, ine);
        Vehiculo* v1=new Vehiculo(codigo,marca,modelo,kilometraje);
        return Compra(monto,p1,v1);
    }
    else if (tipoDeVehiculo=="C"){
        string traccion;
        cout << "Tipo de traccion: ";
        cin >> traccion;
        Persona* p1= new Persona(nombre, apellido, ine);
        Camioneta* c1=new Camioneta(codigo,marca,modelo,kilometraje,traccion);
        return Compra(monto,p1,c1);
    }
    else if (tipoDeVehiculo=="M"){
        int cilindraje;
        cout << "Tipo de cilindraje: ";
        cin >> cilindraje;
        Persona* p1=new Persona(nombre, apellido, ine);
        Motocicleta* m1=new Motocicleta(codigo,marca,modelo,kilometraje,cilindraje);
        return Compra(monto,p1,m1);
    }
}

/* La función "mostrarResultados" como parámetro el vector con los registros de compras e imprime los resultados de la busqueda */
void mostrarResultados(vector<Compra> & compras){
    if (compras.size() == 0) {
        cout << "No se encontraron compras con el criterio especificado";
    }
    else {
        /* Imprimir las compras encontrados */
        cout << "Vehiculos encontrados: " << endl;
        for (int i=0; i<compras.size(); i++){
        Compra compra=compras[i];
        compra.printCompra();
    }
        compras.clear();
    }
}

/* La función "seleccionarAlgoritmo" muestra un menú sobre el cual se selecciona el algoritmo con el cual hacer la búsqueda*/
auto seleccionarAlgoritmo(){
    int opcion = 1;
    auto algoritmo = Ordenamiento<Compra>::burbuja;
    
    do {
        cout << "Selecciona el algoritmo de ordenamiento: " << endl;
        cout << "1 - Burbuja" << endl;
        cout << "2 - Seleccion" << endl;
        cout << "3 - Insercion" << endl;
        cout << "4 - QuickSort" << endl;
        cout << "5 - MergeSort" << endl;
        cin >> opcion;
    }
    while (opcion < 1 || opcion > 5);
    
    switch (opcion) {
        case 1:
            algoritmo = Ordenamiento<Compra>::burbuja;
            break;
        case 2:
            algoritmo = Ordenamiento<Compra>::seleccion;
            break;
        case 3:
            algoritmo = Ordenamiento<Compra>::insercion;
            break;
        case 4:
            algoritmo = Ordenamiento<Compra>::quicksort;
            break;
        case 5:
            algoritmo = Ordenamiento<Compra>::mergesort;
            break;
    }
    
    return algoritmo;
}

/* La función "selccionarAtributoOrden" tiene dos parámtetros: un valor de tipo int "atributo" que indica si se 
ordena con respectoa los kilómetros o años y como segundo parámetro un valor de tipo int "orden" 
con el que e indica si el ordenamiento se hace de manera ascendente o descendente sea 1 ascendente*/
auto seleccionarAtributoOrden(int atributo, int orden){
    auto ordena = Compra::compara_anio_asc;
    
    switch (atributo) {
        case 1: /* Año */
            if (orden == 1) {
                ordena = Compra::compara_anio_asc;
            }
            else {
                ordena = Compra::compara_anio_desc;
            }
            break;
        case 2: /* Kilometraje */
            if (orden == 1) {
                ordena = Compra::compara_kilometraje_asc;
            }
            else {
                ordena = Compra::compara_kilometraje_desc;
            }
            break;
    }
    
    return ordena;
}

/* La función "seleccionarComparacion" muestra un menu para escoger el atributo sobre el cuál se desea ordenar*/
auto seleccionarComparacion(){
    int atributo = 1;
    
    do {
        cout << "Selecciona el atributo de ordenamiento: " << endl;
        cout << "1 - Anio" << endl;
        cout << "2 - Kilometraje" << endl;
        cin >> atributo;
    }
    while (atributo < 1 || atributo > 3);
        
    int orden = 1;
    
    do {
        cout << "Selecciona el orden: " << endl;
        cout << "1 - Ascendente" << endl;
        cout << "2 - Descendente" << endl;
        cin >> orden;
    }
    while (orden < 1 || orden > 2);
    
    return seleccionarAtributoOrden(atributo, orden);
}

/*La función "menu" muestra el menú principal, sobre el cual se escogen las acciones que se desean llevar a cabo
tiene como parámetro la dirección del vector de listado de compras para realizar sobre este las acciones indicadas*/
void menu(ListadoCompras & listadoCompras){
    int opcion;
    int anio;
    int kilometraje;
    string marca;
    string nombreComprador;
    string apellidoComprador;
    vector<Compra> encontrados;
    
    
    do {
        cout << "--- Menu de opciones ---" << endl;
        cout << "1 - Adicionar compra" << endl;
        cout << "2 - Eliminar compra" << endl;
        cout << "3 - Buscar menores que un anio" << endl;
        cout << "4 - Buscar mayores a un anio" << endl;
        cout << "5 - Buscar en un rango de anios" << endl;
        cout << "6 - Buscar menores que un kilometraje" << endl;
        cout << "7 - Buscar mayores que un kilometraje" << endl;
        cout << "8 - Buscar por comprador" << endl;
        cout << "9 - Ordenar" << endl;
        cout << "10 - Mostrar compras en la lista" << endl;
        cout << "11 - Salir" << endl;
        
        cout << "Ingresa la opcion deseada: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:{
                /* Adicionar compras */
                Compra compra = crearCompra();
                listadoCompras.agregarCompra(compra);
                
                break;
            }
            case 2:{
                /* Eliminar compras*/
                cout << "Entre la marca del vehiculo a eliminar: ";
                cin.get();
                getline(cin, marca);
                
                encontrados = listadoCompras.eliminarCompra(marca);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 3:{
                /* Buscar vehiculos menores a un año */
                cout << "Entre el anio: ";
                cin >> anio;
    
                encontrados = listadoCompras.buscarAntesDeAnio(anio);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 4:{
                /* Buscar vehiculos mayores a un año */
                cout << "Entre el anio: ";
                cin >> anio;
                
                encontrados = listadoCompras.buscarDespuesDeAnio(anio);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 5:{
                /* Buscar por rango de años */
                cout << "Entre el anio inicial: ";
                cin >> anio;
                
                int anio_final;
                cout << "Entre el anio final: ";
                cin >> anio_final;
                
                encontrados = listadoCompras.buscarEntreAnios(anio, anio_final);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 6:{
                /* Buscar menores a un kilometraje */
                cout << "Entre el kilometraje: ";
                cin >> kilometraje;
                
                encontrados = listadoCompras.buscarAntesDeKilometraje(kilometraje);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 7:{
                /* Buscar mayores a un kilometraje */
                cout << "Entre el kilometraje: ";
                cin >> kilometraje;
                
                encontrados = listadoCompras.buscarDespuesDeKilometraje(kilometraje);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 8:{
                /* Buscar por comprador */
                cout << "Entre el nombre del comprador: ";
                cin >> nombreComprador;

                cout << "Entre el apellido del comprador: ";
                cin >> apellidoComprador;
                
                encontrados = listadoCompras.buscarPorComprador(nombreComprador,apellidoComprador);
                
                mostrarResultados(encontrados);
                
                break;
            }
            case 9:{
                /* Invocar al método ordenar */
                
                auto algoritmo = seleccionarAlgoritmo();
                auto compara = seleccionarComparacion();
                
                listadoCompras.ordenar(algoritmo, compara);
                
                break;
            }
            case 10:{
                /* Visualizar las compras en la lista  */
                if (listadoCompras.size() == 0) {
                    cout << "La lista de compras está vacía" << endl;
                }
                else {
                    cout << "Vehiculos en la lista de compras:" << endl;
                    listadoCompras.printLista();
                }
                
                break;
            }
            case 11:
                /* Terminar */
                cout << "Gracias por utilizar la lista de compras. Te esperamos pronto." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        
        cout << endl;
        
    }
    while (opcion != 11);
}

int main(int argc, const char * argv[]){
    
    /* Crear la Lista de Compra */
    ListadoCompras listadoCompras;
    Persona persona1("Aquiles","Ensminger","1ER1F");
    Motocicleta motocicleta1(01,"Ferrari",2021,0,200);
    Compra c1(5000000,&persona1,&motocicleta1);
    listadoCompras.agregarCompra(c1);

    Persona persona2("Javier","Lozano","1JOP23");
    Vehiculo vehiculo2(02,"Fiat",2002,2500);
    Compra c2(24000,&persona1,&vehiculo2);
    listadoCompras.agregarCompra(c2);

    Persona persona3("German","Garmendia","DRO89E");
    Vehiculo vehiculo3(03,"Nissan",2016,15000);
    Compra c3(554000,&persona3,&vehiculo3);
    listadoCompras.agregarCompra(c3);

    Persona persona4("Juan","Gabriel","KS485KL");
    Vehiculo vehiculo4(04,"Chevrolet",2013,11500);
    Compra c4(10000,&persona4,&vehiculo4);
    listadoCompras.agregarCompra(c4);
    
    /* Invocar la menú de opciones */
    menu(listadoCompras);
    
    return 0;
}


