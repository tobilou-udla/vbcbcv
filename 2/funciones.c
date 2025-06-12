#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para mostrar el menú
int menu() {
    int opcion;
    printf("\nSeleccione una opción:\n");
    printf("1. Visualizar productos\n");
    printf("2. Crear nueva venta\n");
    printf("3. Listar ventas\n");
    printf("4. Buscar venta por cédula\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el buffer de entrada
    return opcion;
}

// Función para inicializar los productos
void inicializarProductos(struct Producto productos[], int *totalProductos) {
    strcpy(productos[0].nombre, "Producto A");
    productos[0].precio = 10.0;

    strcpy(productos[1].nombre, "Producto B");
    productos[1].precio = 15.5;

    strcpy(productos[2].nombre, "Producto C");
    productos[2].precio = 20.0;

    *totalProductos = 3; // Total de productos inicializados
}

// Función para visualizar los productos
void visualizarProductos(struct Producto productos[], int totalProductos) {
    printf("\nProductos disponibles:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("%d. %s - $%.2f\n", i + 1, productos[i].nombre, productos[i].precio);
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

// Función para crear una nueva venta
void crearVenta(struct Venta ventas[], int *contadorVentas, struct Producto productos[], int totalProductos) {
    struct Venta nuevaVenta;
    int cantidadProductos;
    int seleccion;

    printf("Ingrese el nombre del cliente: ");
    leerCadena(nuevaVenta.nombreCliente, 50);

    printf("Ingrese la cédula del cliente: ");
    leerCadena(nuevaVenta.cedula, 20);

    nuevaVenta.totalProductos = 0;
    nuevaVenta.totalVenta = 0.0;

    printf("¿Cuántos productos desea comprar? ");
    scanf("%d", &cantidadProductos);

    for (int i = 0; i < cantidadProductos; i++) {
        visualizarProductos(productos, totalProductos);
        printf("Seleccione el número del producto %d: ", i + 1);
        scanf("%d", &seleccion);

        if (seleccion > 0 && seleccion <= totalProductos) {
            nuevaVenta.productosVendidos[nuevaVenta.totalProductos] = productos[seleccion - 1];
            nuevaVenta.totalVenta += productos[seleccion - 1].precio;
            nuevaVenta.totalProductos++;
        } else {
            printf("Selección inválida. Intente de nuevo.\n");
            i--; // Reintentar el mismo producto
        }
    }

    ventas[*contadorVentas] = nuevaVenta;
    (*contadorVentas)++;
    printf("Venta creada exitosamente.\n");
}

// Función para listar las ventas
void listarVentas(struct Venta ventas[], int contadorVentas) {
    printf("\nListado de ventas:\n");
    for (int i = 0; i < contadorVentas; i++) {
        printf("Venta %d - Cliente: %s, Cédula: %s, Total: $%.2f\n",
               i + 1, ventas[i].nombreCliente, ventas[i].cedula, ventas[i].totalVenta);
    }
}

// Función para buscar una venta por cédula
struct Venta* buscarVenta(struct Venta ventas[], int contadorVentas, char cedula[]) {
    for (int i = 0; i < contadorVentas; i++) {
        if (strcmp(ventas[i].cedula, cedula) == 0) {
            return &ventas[i];
        }
    }
    printf("Venta no encontrada.\n");
    return NULL;
}

// Función para imprimir los detalles de una venta
void imprimirVenta(struct Venta *venta) {
    printf("\nDetalles de la venta:\n");
    printf("Cliente: %s\n", venta->nombreCliente);
    printf("Cédula: %s\n", venta->cedula);
    printf("Total: $%.2f\n", venta->totalVenta);
    printf("Productos vendidos:\n");
    for (int i = 0; i < venta->totalProductos; i++) {
        printf("%d. %s - $%.2f\n", i + 1, venta->productosVendidos[i].nombre, venta->productosVendidos[i].precio);
    }
}