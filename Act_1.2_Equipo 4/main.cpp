

#include <iostream>
#include <vector>
#include "../../../tc1031/Tema_5_Ordenamiento/ordenamiento_generico/ordenamiento_generico/Ordenamiento.hpp"
#include "listadoCompras.hpp"

void menu(ListadoCompras &);

int main(int argc, const char * argv[]) {
    
    /* Crear la biblioteca */
    ListadoCompras listadoCompras;
    
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

void mostrarResultados(std::vector<Libro> & libros, std::string msg)
{
    if (libros.size() == 0) {
        std::cout << "No se encontraron libros con el criterio especificado";
    }
    else {
        /* Imprimir los libros encontrados */
        std::cout << msg << std::endl;
        std::copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout));
        libros.clear();
    }
}

auto seleccionarAlgoritmo()
{
    int opcion = 1;
    auto algoritmo = Ordenamiento<Libro>::burbuja;
    
    do {
        std::cout << "Selecciona el algoritmo de ordenamiento: " << std::endl;
        std::cout << "1 - Burbuja" << std::endl;
        std::cout << "2 - Selección" << std::endl;
        std::cout << "3 - Inserción" << std::endl;
        std::cout << "4 - QuickSort" << std::endl;
        std::cout << "5 - MergeSort" << std::endl;
        std::cin >> opcion;
    }
    while (opcion < 1 || opcion > 5);
    
    switch (opcion) {
        case 1:
            algoritmo = Ordenamiento<Libro>::burbuja;
            break;
        case 2:
            algoritmo = Ordenamiento<Libro>::seleccion;
            break;
        case 3:
            algoritmo = Ordenamiento<Libro>::insercion;
            break;
        case 4:
            algoritmo = Ordenamiento<Libro>::quicksort;
            break;
        case 5:
            algoritmo = Ordenamiento<Libro>::mergesort;
            break;
    }
    
    return algoritmo;
}

auto seleccionarAtributoOrden(int atributo, int orden)
{
    auto ordena = Libro::compara_titulo_asc;
    
    switch (atributo) {
        case 1: /* Título */
            if (orden == 1) {
                ordena = Libro::compara_titulo_asc;
            }
            else {
                ordena = Libro::compara_titulo_desc;
            }
            break;
        case 2: /* Autor */
            if (orden == 1) {
                ordena = Libro::compara_autor_asc;
            }
            else {
                ordena = Libro::compara_autor_desc;
            }
            break;
        case 3: /* Año */
            if (orden == 1) {
                ordena = Libro::compara_año_asc;
            }
            else {
                ordena = Libro::compara_año_desc;
            }
            break;
    }
    
    return ordena;
}

auto seleccionarComparacion()
{
    int atributo = 1;
    
    do {
        std::cout << "Selecciona el atributo de ordenamiento: " << std::endl;
        std::cout << "1 - Título" << std::endl;
        std::cout << "2 - Autor" << std::endl;
        std::cout << "3 - Año" << std::endl;
        std::cin >> atributo;
    }
    while (atributo < 1 || atributo > 3);
        
    int orden = 1;
    
    do {
        std::cout << "Selecciona el orden: " << std::endl;
        std::cout << "1 - Ascendente" << std::endl;
        std::cout << "2 - Descendente" << std::endl;
        std::cin >> orden;
    }
    while (orden < 1 || orden > 2);
    
    return seleccionarAtributoOrden(atributo, orden);
}

void menu(ListadoCompras & listadoCompras)
{
    int opcion;
    int año;
    std::string titulo;
    std::vector<Libro> encontrados;
    
    
    do {
        std::cout << "--- Menú de opciones ---" << std::endl;
        std::cout << "1 - Adicionar libro" << std::endl;
        std::cout << "2 - Eliminar libro" << std::endl;
        std::cout << "3 - Buscar menores que un año" << std::endl;
        std::cout << "4 - Buscar mayores a un año" << std::endl;
        std::cout << "5 - Buscar en un rango de años" << std::endl;
        std::cout << "6 - Buscar por autor" << std::endl;
        std::cout << "7 - Buscar por editorial" << std::endl;
        std::cout << "8 - Ordenar" << std::endl;
        std::cout << "9 - Mostrar libros en la biblioteca" << std::endl;
        std::cout << "10 - Salir" << std::endl;
        
        std::cout << "Ingresa la opción deseada: ";
        std::cin >> opcion;
        
        switch (opcion) {
            case 1:
            {
                /* Adicionar libros */
                Libro libro = crearLibro();
                biblioteca.adicionarLibro(libro);
                
                break;
            }
            case 2:
            {
                /* Eliminar libros*/
                std::cout << "Entre el título del libro a eliminar: ";
                std::cin.get();
                getline(std::cin, titulo);
                
                encontrados = biblioteca.eliminarLibro(titulo);
                
                mostrarResultados(encontrados, "Libros eliminados:");
                
                break;
            }
            case 3:
            {
                /* Buscar libros menores a un año */
                std::cout << "Entre el año: ";
                std::cin >> año;
                
                encontrados = biblioteca.buscarAntesDeAño(año);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 4:
            {
                /* Buscar mayores a un año */
                std::cout << "Entre el año: ";
                std::cin >> año;
                
                encontrados = biblioteca.buscarDespuesDeAño(año);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 5:
            {
                /* Buscar por rango de años */
                std::cout << "Entre el año inicial: ";
                std::cin >> año;
                
                int año_final;
                std::cout << "Entre el año final: ";
                std::cin >> año_final;
                
                encontrados = biblioteca.buscarEntreAños(año, año_final);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 6:
            {
                /* Buscar por autor */
                std::cout << "Entre el autor: ";
                std::cin.get();
                std::string autor;
                getline(std::cin, autor);
                    
                encontrados = biblioteca.buscarPorAutor(autor);
                    
                mostrarResultados(encontrados, "Libros encontrados:");
                    
                break;
            }
            case 7:
            {
                /* Buscar por editorial */
                std::cout << "Entre la editorial: ";
                std::cin.get();
                std::string editorial;
                getline(std::cin, editorial);
                
                encontrados = biblioteca.buscarPorEditorial(editorial);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 8:
            {
                /* Invocar al método ordenar */
                
                auto algoritmo = seleccionarAlgoritmo();
                auto compara = seleccionarComparacion();
                
                biblioteca.ordenar(algoritmo, compara);
                
                break;
            }
            case 9:
            {
                /* Visualizar los libros en la biblioteca  */
                if (biblioteca.size() == 0) {
                    std::cout << "La biblioteca está vacía" << std::endl;
                }
                else {
                    std::cout << "Libros en la biblioteca:" << std::endl;
                    std::cout << biblioteca;
                }
                
                break;
            }
            case 10:
                /* Terminar */
                std::cout << "Gracias por utilizar la biblioteca. Te esperamos pronto." << std::endl;
                break;
            default:
                std::cout << "Opción inválida" << std::endl;
                break;
        }
        
        std::cout << std::endl;
        
    }
    while (opcion != 10);
}
