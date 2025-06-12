#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para el producto
struct Producto {
    char nombre[30];
    float precio;
};

// Estructura para la venta
struct Venta {
    char nombreCliente[50];
    char cedula[20];
    float totalVenta;
    struct Producto productosVendidos[10];
    int totalProductos;
};

// Prototipos de funciones
int menu();
void inicializarProductos(struct Producto productos[], int *totalProductos);
void visualizarProductos(struct Producto productos[], int totalProductos);
void crearVenta(struct Venta ventas[], int *contadorVentas, struct Producto productos[], int totalProductos);
void listarVentas(struct Venta ventas[], int contadorVentas);
struct Venta* buscarVenta(struct Venta ventas[], int contadorVentas, char cedula[]);
void imprimirVenta(struct Venta *venta);
void leerCadena(char *cadena, int tamano);

#endif