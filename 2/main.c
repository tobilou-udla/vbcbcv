#include <stdio.h>
#include "funciones.h"

int main() {
    struct Producto productos[5];
    struct Venta ventas[10];
    int totalProductos = 0;
    int contadorVentas = 0;
    int opcion;
    char cedula[20];
    struct Venta *ventaEncontrada;

    inicializarProductos(productos, &totalProductos);

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                visualizarProductos(productos, totalProductos);
                break;
            case 2:
                if (contadorVentas < 10) {
                    crearVenta(ventas, &contadorVentas, productos, totalProductos);
                } else {
                    printf("No se pueden registrar más ventas (máximo 10).\n");
                }
                break;
            case 3:
                listarVentas(ventas, contadorVentas);
                break;
            case 4:
                printf("Ingrese la cédula del cliente para buscar la venta: ");
                leerCadena(cedula, 20);
                ventaEncontrada = buscarVenta(ventas, contadorVentas, cedula);
                if (ventaEncontrada != NULL) {
                    imprimirVenta(ventaEncontrada);
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}