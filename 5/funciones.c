#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para mostrar el menú principal
int menu() {
    int opcion;
    printf("\nSeleccione una opción:\n");
    printf("1. Mostrar vuelos disponibles\n");
    printf("2. Registrar una reserva\n");
    printf("3. Listar todas las reservas\n");
    printf("4. Buscar una reserva por nombre del pasajero\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el buffer de entrada
    return opcion;
}

// Función para inicializar los vuelos disponibles
void inicializarVuelos(struct Vuelo vuelos[], int *totalVuelos) {
    strcpy(vuelos[0].codigo, "V001");
    strcpy(vuelos[0].origen, "Ciudad A");
    strcpy(vuelos[0].destino, "Ciudad B");
    strcpy(vuelos[0].fechaHora, "15/06/2025 10:00");
    vuelos[0].precio = 150.0;

    strcpy(vuelos[1].codigo, "V002");
    strcpy(vuelos[1].origen, "Ciudad C");
    strcpy(vuelos[1].destino, "Ciudad D");
    strcpy(vuelos[1].fechaHora, "16/06/2025 14:30");
    vuelos[1].precio = 200.0;

    strcpy(vuelos[2].codigo, "V003");
    strcpy(vuelos[2].origen, "Ciudad E");
    strcpy(vuelos[2].destino, "Ciudad F");
    strcpy(vuelos[2].fechaHora, "17/06/2025 09:45");
    vuelos[2].precio = 180.0;

    *totalVuelos = 3; // Número total de vuelos inicializados
}

// Función para mostrar los vuelos disponibles
void mostrarVuelos(struct Vuelo vuelos[], int totalVuelos) {
    printf("\nVuelos disponibles:\n");
    for (int i = 0; i < totalVuelos; i++) {
        printf("%d. [%s] Origen: %s, Destino: %s, Fecha y Hora: %s, Precio: $%.2f\n",
               i + 1, vuelos[i].codigo, vuelos[i].origen, vuelos[i].destino, vuelos[i].fechaHora, vuelos[i].precio);
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

// Función para registrar una nueva reserva
void registrarReserva(struct Reserva reservas[], int *contadorReservas, struct Vuelo vuelos[], int totalVuelos) {
    struct Reserva nuevaReserva;
    int seleccion;

    printf("Ingrese el nombre del pasajero: ");
    leerCadena(nuevaReserva.nombrePasajero, 50);

    printf("Ingrese el documento de identidad del pasajero: ");
    leerCadena(nuevaReserva.documento, 20);

    mostrarVuelos(vuelos, totalVuelos);
    printf("Seleccione el número del vuelo que desea reservar: ");
    scanf("%d", &seleccion);

    if (seleccion > 0 && seleccion <= totalVuelos) {
        nuevaReserva.vuelo = vuelos[seleccion - 1];  // Asignar el vuelo seleccionado

        printf("Ingrese la cantidad de asientos: ");
        scanf("%d", &nuevaReserva.cantidadAsientos);

        // Calcular el total de la reserva
        nuevaReserva.totalReserva = nuevaReserva.vuelo.precio * nuevaReserva.cantidadAsientos;

        reservas[*contadorReservas] = nuevaReserva;
        (*contadorReservas)++;
        printf("Reserva registrada exitosamente.\n");
    } else {
        printf("Selección inválida. Intente de nuevo.\n");
    }
}

// Función para listar todas las reservas
void listarReservas(struct Reserva reservas[], int contadorReservas) {
    printf("\nListado de reservas:\n");
    for (int i = 0; i < contadorReservas; i++) {
        printf("Reserva %d - Pasajero: %s, Documento: %s, Vuelo: [%s] %s -> %s, Asientos: %d, Total: $%.2f\n",
               i + 1, reservas[i].nombrePasajero, reservas[i].documento, reservas[i].vuelo.codigo,
               reservas[i].vuelo.origen, reservas[i].vuelo.destino,
               reservas[i].cantidadAsientos, reservas[i].totalReserva);
    }
}

// Función para buscar una reserva por el nombre del pasajero
struct Reserva* buscarReserva(struct Reserva reservas[], int contadorReservas, char nombrePasajero[]) {
    for (int i = 0; i < contadorReservas; i++) {
        if (strcmp(reservas[i].nombrePasajero, nombrePasajero) == 0) {
            return &reservas[i];
        }
    }
    printf("Reserva no encontrada.\n");
    return NULL;
}

// Función para imprimir los detalles de una reserva
void imprimirReserva(struct Reserva *reserva) {
    printf("\nDetalles de la reserva:\n");
    printf("Nombre del pasajero: %s\n", reserva->nombrePasajero);
    printf("Documento: %s\n", reserva->documento);
    printf("Vuelo: [%s] Origen: %s, Destino: %s, Fecha y Hora: %s\n",
           reserva->vuelo.codigo, reserva->vuelo.origen, reserva->vuelo.destino, reserva->vuelo.fechaHora);
    printf("Cantidad de asientos: %d\n", reserva->cantidadAsientos);
    printf("Total de la reserva: $%.2f\n", reserva->totalReserva);
}