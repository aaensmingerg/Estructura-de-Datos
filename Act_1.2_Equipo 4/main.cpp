

#include <iostream>
#include <vector>
#include "C:/Users/aaens/Desktop/C++/ObjectOrientedThinking/CodeSamples/tc1031/Tema_5_Ordenamiento/ordenamiento_generico/ordenamiento_generico/Ordenamiento.hpp"
#include "listadoCompras.hpp"

void menu(ListadoCompras &);

int main(int argc, const char * argv[]) {
    
    /* Crear la biblioteca */
    ListadoCompras listadoCompras;
    Persona persona1("Aquiles","Ensminger","1ER1F");
    Vehiculo vehiculo1(01,"Ferrari",2021,2000);
    Compra c1(5,&persona1,&vehiculo1);
    listadoCompras.agregarCompra(c1);
    
    /* Invocar la menú de opciones */
    menu(listadoCompras);
    
    return 0;
}

Compra crearCompra()
{
    cout << "Introduzca los datos del libro: " << endl;
    cin.get();
    
    int monto;
    cout << "Valor de la compra:";
    cin >> monto;

    string nombre;
    cout << "Nombre: ";
    getline(cin, nombre);
    
    string apellido;
    cout << "Apellido: ";
    getline(cin, apellido);
    
    string ine;
    cout << "Editorial: ";
    getline(cin, ine);
    
    int codigo;
    cout << "Código del vehiculo: ";
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

    return Compra(monto,&p1,&v1);
}

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
        cout << "--- Menú de opciones ---" << endl;
        cout << "1 - Adicionar compra" << endl;
        cout << "2 - Eliminar compra" << endl;
        cout << "3 - Buscar menores que un año" << endl;
        cout << "4 - Buscar mayores a un año" << endl;
        cout << "5 - Buscar en un rango de años" << endl;
        cout << "6 - Buscar menores que un kilometraje" << endl;
        cout << "7 - Buscar mayores que un kilometraje" << endl;
        cout << "8 - Ordenar" << endl;
        cout << "9 - Mostrar compras en la lista" << endl;
        cout << "10 - Salir" << endl;
        
        cout << "Ingresa la opción deseada: ";
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
                cout << "Opción inválida" << endl;
                break;
        }
        
        cout << endl;
        
    }
    while (opcion != 10);
}
