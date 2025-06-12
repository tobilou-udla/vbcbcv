#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para un plato
struct Plato {
    char nombre[30];
    float precio;
};

// Estructura para un pedido
struct Pedido {
    char nombreCliente[50];
    struct Plato platos[10];
    int cantidades[10];
    int totalPlatos;
    float totalPedido;
};

// Prototipos de funciones
int menu();
void inicializarMenu(struct Plato menu[], int *totalPlatosMenu);
void mostrarMenu(struct Plato menu[], int totalPlatosMenu);
void crearPedido(struct Pedido pedidos[], int *contadorPedidos, struct Plato menu[], int totalPlatosMenu);
void listarPedidos(struct Pedido pedidos[], int contadorPedidos);
struct Pedido* buscarPedido(struct Pedido pedidos[], int contadorPedidos, char nombreCliente[]);
void imprimirPedido(struct Pedido *pedido);
void leerCadena(char *cadena, int tamano);

#endif