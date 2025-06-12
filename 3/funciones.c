#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para mostrar el menú principal
int menu() {
    int opcion;
    printf("\nSeleccione una opción:\n");
    printf("1. Mostrar menú de platos\n");
    printf("2. Crear un pedido\n");
    printf("3. Listar todos los pedidos\n");
    printf("4. Buscar un pedido por nombre del cliente\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el buffer de entrada
    return opcion;
}

// Función para inicializar el menú del restaurante con platos predefinidos
void inicializarMenu(struct Plato menu[], int *totalPlatosMenu) {
    strcpy(menu[0].nombre, "Hamburguesa");
    menu[0].precio = 5.5;

    strcpy(menu[1].nombre, "Pizza");
    menu[1].precio = 8.0;

    strcpy(menu[2].nombre, "Ensalada");
    menu[2].precio = 4.0;

    strcpy(menu[3].nombre, "Pasta");
    menu[3].precio = 7.5;

    *totalPlatosMenu = 4; // Número de platos disponibles en el menú
}

// Función para mostrar los platos del menú
void mostrarMenu(struct Plato menu[], int totalPlatosMenu) {
    printf("\nMenú de platos:\n");
    for (int i = 0; i < totalPlatosMenu; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].nombre, menu[i].precio);
    }
}

// Función para leer cadenas de texto
void leerCadena(char *cadena, int tamano) {
    fflush(stdin);
    fgets(cadena, tamano, stdin);
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}

// Función para crear un nuevo pedido
void crearPedido(struct Pedido pedidos[], int *contadorPedidos, struct Plato menu[], int totalPlatosMenu) {
    struct Pedido nuevoPedido;
    int cantidadPlatos;
    int seleccion;

    printf("Ingrese el nombre del cliente: ");
    leerCadena(nuevoPedido.nombreCliente, 50);

    nuevoPedido.totalPlatos = 0;
    nuevoPedido.totalPedido = 0.0;

    printf("¿Cuántos platos desea pedir? ");
    scanf("%d", &cantidadPlatos);

    for (int i = 0; i < cantidadPlatos; i++) {
        mostrarMenu(menu, totalPlatosMenu);
        printf("Seleccione el número del plato %d: ", i + 1);
        scanf("%d", &seleccion);

        if (seleccion > 0 && seleccion <= totalPlatosMenu) {
            nuevoPedido.platos[nuevoPedido.totalPlatos] = menu[seleccion - 1];
            printf("Ingrese la cantidad de %s: ", menu[seleccion - 1].nombre);
            scanf("%d", &nuevoPedido.cantidades[nuevoPedido.totalPlatos]);

            // Calcular el costo total para este plato
            nuevoPedido.totalPedido += menu[seleccion - 1].precio * nuevoPedido.cantidades[nuevoPedido.totalPlatos];
            nuevoPedido.totalPlatos++;
        } else {
            printf("Selección inválida. Intente de nuevo.\n");
            i--; // Reintentar el mismo plato
        }
    }

    pedidos[*contadorPedidos] = nuevoPedido;
    (*contadorPedidos)++;
    printf("Pedido creado exitosamente.\n");
}

// Función para listar todos los pedidos
void listarPedidos(struct Pedido pedidos[], int contadorPedidos) {
    printf("\nListado de pedidos:\n");
    for (int i = 0; i < contadorPedidos; i++) {
        printf("Pedido %d - Cliente: %s, Total: $%.2f\n",
               i + 1, pedidos[i].nombreCliente, pedidos[i].totalPedido);
    }
}

// Función para buscar un pedido por el nombre del cliente
struct Pedido* buscarPedido(struct Pedido pedidos[], int contadorPedidos, char nombreCliente[]) {
    for (int i = 0; i < contadorPedidos; i++) {
        if (strcmp(pedidos[i].nombreCliente, nombreCliente) == 0) {
            return &pedidos[i];
        }
    }
    printf("Pedido no encontrado.\n");
    return NULL;
}

// Función para imprimir los detalles de un pedido
void imprimirPedido(struct Pedido *pedido) {
    printf("\nDetalles del pedido:\n");
    printf("Cliente: %s\n", pedido->nombreCliente);
    printf("Total: $%.2f\n", pedido->totalPedido);
    printf("Platos pedidos:\n");
    for (int i = 0; i < pedido->totalPlatos; i++) {
        printf("%d. %s - $%.2f x %d\n", i + 1,
               pedido->platos[i].nombre,
               pedido->platos[i].precio,
               pedido->cantidades[i]);
    }
}