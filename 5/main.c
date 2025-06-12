#include <stdio.h>
#include "funciones.h"

int main() {
    struct Vuelo vuelos[10];
    struct Reserva reservas[20];
    int totalVuelos = 0;
    int contadorReservas = 0;
    int opcion;
    char nombrePasajero[50];
    struct Reserva *reservaEncontrada;

    inicializarVuelos(vuelos, &totalVuelos);

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                mostrarVuelos(vuelos, totalVuelos);
                break;
            case 2:
                if (contadorReservas < 20) {
                    registrarReserva(reservas, &contadorReservas, vuelos, totalVuelos);
                } else {
                    printf("No se pueden registrar más reservas (máximo 20).\n");
                }
                break;
            case 3:
                listarReservas(reservas, contadorReservas);
                break;
            case 4:
                printf("Ingrese el nombre del pasajero para buscar la reserva: ");
                leerCadena(nombrePasajero, 50);
                reservaEncontrada = buscarReserva(reservas, contadorReservas, nombrePasajero);
                if (reservaEncontrada != NULL) {
                    imprimirReserva(reservaEncontrada);
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