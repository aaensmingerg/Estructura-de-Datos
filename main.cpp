
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
#include <vector>
#include "C:/Users/aaens/Desktop/C++/ObjectOrientedThinking/CodeSamples/tc1031/Tema_5_Ordenamiento/ordenamiento_generico/ordenamiento_generico/Ordenamiento.hpp"
#include "listadoCompras.cpp"

void menu(ListadoCompras &);

int main(int argc, const char * argv[]) {
    
    /* Crear Listado de Compras */
    ListadoCompras listadoCompras;
    Persona persona1("Aquiles","Ensminger","1ER1F");
    Vehiculo vehiculo1(01,"Ferrari",2021,2000);
    Compra c1(5,persona1,vehiculo1);
    listadoCompras.agregarCompra(c1);
    
    /* Invocar la menú de opciones */
    menu(listadoCompras);
    
    return 0;
}


/* La función "crearCompra" genera el menú de entrada 
de los datos de la compra.
*/
Compra crearCompra()
{
    int monto;
    cout << "Valor de la compra:";
    cin >> monto;

    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    
    string apellido;
    cout << "Apellido: ";
    cin >> apellido;
    
    string ine;
    cout << "INE: ";
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
    
    Persona p1(nombre, apellido, ine);
    Vehiculo v1(codigo,marca,modelo,kilometraje);

    return Compra(monto,p1,v1);
}


/* La función "mostrarResultados" recibe como parámetro un vector de tipo compras
, calcula la suma de 1 hasta "n" de manera recursiva
y devuelve el resultado de esta suma*/
void mostrarResultados(vector<Compra> & compras, string msg)
{
    if (compras.size() == 0) {
        cout << "No se encontraron compras con el criterio especificado";
    }
    else {
        /* Imprimir los libros encontrados */
        cout << msg << endl;
        //copy(compras.begin(), compras.end(), ostream_iterator<Compra>(cout));
        compras.clear();
    }
}

/* La función seleccionar Algoritnmo recibe como parámetro el número
deseado "n", calcula la suma de 1 hasta "n" de manera recursiva
y devuelve el resultado de esta suma*/

auto seleccionarAlgoritmo()
{
    int opcion = 1;
    auto algoritmo = Ordenamiento<Compra>::burbuja;
    
    do {
        cout << "Selecciona el algoritmo de ordenamiento: " << endl;
        cout << "1 - Burbuja" << endl;
        cout << "2 - Selección" << endl;
        cout << "3 - Inserción" << endl;
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

auto seleccionarAtributoOrden(int atributo, int orden)
{
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

auto seleccionarComparacion()
{
    int atributo = 1;
    
    do {
        cout << "Selecciona el atributo de ordenamiento: " << endl;
        cout << "1 - Año" << endl;
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

void menu(ListadoCompras & listadoCompras)
{
    int opcion;
    int anio;
    int kilometraje;
    string marca;
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
        cout << "8 - Ordenar" << endl;
        cout << "9 - Mostrar compras en la lista" << endl;
        cout << "10 - Salir" << endl;
        
        cout << "Ingresa la opcion deseada: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
            {
                /* Adicionar libros */
                Compra compra = crearCompra();
                listadoCompras.agregarCompra(compra);
                
                break;
            }
            case 2:
            {
                /* Eliminar libros*/
                cout << "Entre la marca del vehiculo a eliminar: ";
                cin.get();
                getline(cin, marca);
                
                encontrados = listadoCompras.eliminarCompra(marca);
                
                mostrarResultados(encontrados, "Vehiculos eliminados:");
                
                break;
            }
            case 3:
            {
                /* Buscar libros menores a un año */
                cout << "Entre el año: ";
                cin >> anio;
                
                encontrados = listadoCompras.buscarAntesDeAnio(anio);
                
                mostrarResultados(encontrados, "Vehiculos encontrados:");
                
                break;
            }
            case 4:
            {
                /* Buscar mayores a un año */
                cout << "Entre el año: ";
                cin >> anio;
                
                encontrados = listadoCompras.buscarDespuesDeAnio(anio);
                
                mostrarResultados(encontrados, "Vehiculos encontrados:");
                
                break;
            }
            case 5:
            {
                /* Buscar por rango de años */
                cout << "Entre el año inicial: ";
                cin >> anio;
                
                int anio_final;
                cout << "Entre el año final: ";
                cin >> anio_final;
                
                encontrados = listadoCompras.buscarEntreAnios(anio, anio_final);
                
                mostrarResultados(encontrados, "Vehiculos encontrados:");
                
                break;
            }
            case 6:
            {
                /* Buscar menores a un kilometraje */
                cout << "Entre el kilometraje: ";
                cin >> kilometraje;
                
                encontrados = listadoCompras.buscarAntesDeKilometraje(kilometraje);
                
                mostrarResultados(encontrados, "Vehiculos encontrados:");
                
                break;
            }
            case 7:
            {
                /* Buscar mayores a un kilometraje */
                cout << "Entre el kilometraje: ";
                cin >> kilometraje;
                
                encontrados = listadoCompras.buscarDespuesDeKilometraje(kilometraje);
                
                mostrarResultados(encontrados, "Vehiculos encontrados:");
                
                break;
            }
            case 8:
            {
                /* Invocar al método ordenar */
                
                auto algoritmo = seleccionarAlgoritmo();
                auto compara = seleccionarComparacion();
                
                listadoCompras.ordenar(algoritmo, compara);
                
                break;
            }
            case 9:
            {
                /* Visualizar los libros en la biblioteca  */
                if (listadoCompras.size() == 0) {
                    cout << "La lista de compras está vacía" << endl;
                }
                else {
                    cout << "Vehiculos en la lista de compras:" << endl;
                    cout << listadoCompras;
                }
                
                break;
            }
            case 10:
                /* Terminar */
                cout << "Gracias por utilizar la lista de compras. Te esperamos pronto." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        
        cout << endl;
        
    }
    while (opcion != 10);
}
