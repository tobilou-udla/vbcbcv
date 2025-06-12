#include <stdio.h>
#include "funciones.h"

int main() {
    struct Plato menu[10];
    struct Pedido pedidos[20];
    int totalPlatosMenu = 0;
    int contadorPedidos = 0;
    int opcion;
    char nombreCliente[50];
    struct Pedido *pedidoEncontrado;

    inicializarMenu(menu, &totalPlatosMenu);

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                mostrarMenu(menu, totalPlatosMenu);
                break;
            case 2:
                if (contadorPedidos < 20) {
                    crearPedido(pedidos, &contadorPedidos, menu, totalPlatosMenu);
                } else {
                    printf("No se pueden registrar más pedidos (máximo 20).\n");
                }
                break;
            case 3:
                listarPedidos(pedidos, contadorPedidos);
                break;
            case 4:
                printf("Ingrese el nombre del cliente para buscar el pedido: ");
                leerCadena(nombreCliente, 50);
                pedidoEncontrado = buscarPedido(pedidos, contadorPedidos, nombreCliente);
                if (pedidoEncontrado != NULL) {
                    imprimirPedido(pedidoEncontrado);
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