#include <stdio.h>
#include "funciones.h"

int main() {
    struct Pelicula peliculas[10];
    struct Reserva reservas[20];
    int totalPeliculas = 0;
    int contadorReservas = 0;
    int opcion;
    char nombreCliente[50];
    struct Reserva *reservaEncontrada;

    inicializarPeliculas(peliculas, &totalPeliculas);

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                mostrarPeliculas(peliculas, totalPeliculas);
                break;
            case 2:
                if (contadorReservas < 20) {
                    registrarReserva(reservas, &contadorReservas, peliculas, totalPeliculas);
                } else {
                    printf("No se pueden registrar más reservas (máximo 20).\n");
                }
                break;
            case 3:
                listarReservas(reservas, contadorReservas);
                break;
            case 4:
                printf("Ingrese el nombre del cliente para buscar la reserva: ");
                leerCadena(nombreCliente, 50);
                reservaEncontrada = buscarReserva(reservas, contadorReservas, nombreCliente);
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