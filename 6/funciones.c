#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para mostrar el menú principal
int menu() {
    int opcion;
    printf("\nSeleccione una opción:\n");
    printf("1. Mostrar películas disponibles\n");
    printf("2. Registrar una reserva\n");
    printf("3. Listar todas las reservas\n");
    printf("4. Buscar una reserva por nombre del cliente\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el buffer de entrada
    return opcion;
}

// Función para inicializar las películas disponibles en el cine
void inicializarPeliculas(struct Pelicula peliculas[], int *totalPeliculas) {
    strcpy(peliculas[0].codigo, "P001");
    strcpy(peliculas[0].titulo, "La Gran Aventura");
    strcpy(peliculas[0].genero, "Acción");
    peliculas[0].duracion = 120;
    peliculas[0].precioEntrada = 7.5;

    strcpy(peliculas[1].codigo, "P002");
    strcpy(peliculas[1].titulo, "Amor en Tiempos Modernos");
    strcpy(peliculas[1].genero, "Romance");
    peliculas[1].duracion = 105;
    peliculas[1].precioEntrada = 6.0;

    strcpy(peliculas[2].codigo, "P003");
    strcpy(peliculas[2].titulo, "La Magia de los Sueños");
    strcpy(peliculas[2].genero, "Fantasía");
    peliculas[2].duracion = 130;
    peliculas[2].precioEntrada = 8.0;

    *totalPeliculas = 3; // Número total de películas inicializadas
}

// Función para mostrar las películas disponibles
void mostrarPeliculas(struct Pelicula peliculas[], int totalPeliculas) {
    printf("\nPelículas disponibles:\n");
    for (int i = 0; i < totalPeliculas; i++) {
        printf("%d. [%s] Título: %s, Género: %s, Duración: %d min, Precio: $%.2f\n",
               i + 1, peliculas[i].codigo, peliculas[i].titulo, peliculas[i].genero, peliculas[i].duracion, peliculas[i].precioEntrada);
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
void registrarReserva(struct Reserva reservas[], int *contadorReservas, struct Pelicula peliculas[], int totalPeliculas) {
    struct Reserva nuevaReserva;
    int seleccion;

    printf("Ingrese el nombre del cliente: ");
    leerCadena(nuevaReserva.nombreCliente, 50);

    printf("Ingrese el documento de identidad del cliente: ");
    leerCadena(nuevaReserva.documento, 20);

    mostrarPeliculas(peliculas, totalPeliculas);
    printf("Seleccione el número de la película que desea reservar: ");
    scanf("%d", &seleccion);

    if (seleccion > 0 && seleccion <= totalPeliculas) {
        nuevaReserva.pelicula = peliculas[seleccion - 1];  // Asignar la película seleccionada

        printf("Ingrese la cantidad de entradas: ");
        scanf("%d", &nuevaReserva.cantidadEntradas);

        // Calcular el total de la reserva
        nuevaReserva.totalReserva = nuevaReserva.pelicula.precioEntrada * nuevaReserva.cantidadEntradas;

        reservas[*contadorReservas] = nuevaReserva;
        (*contadorReservas)++;
        printf("Reserva registrada exitosamente.\n");
    } else {
        printf("Selección inválida. Intente de nuevo.\n");
    }
}

// Función para listar todas las reservas realizadas
void listarReservas(struct Reserva reservas[], int contadorReservas) {
    printf("\nListado de reservas:\n");
    for (int i = 0; i < contadorReservas; i++) {
        printf("Reserva %d - Cliente: %s, Documento: %s, Película: [%s] %s, Entradas: %d, Total: $%.2f\n",
               i + 1, reservas[i].nombreCliente, reservas[i].documento, reservas[i].pelicula.codigo,
               reservas[i].pelicula.titulo, reservas[i].cantidadEntradas, reservas[i].totalReserva);
    }
}

// Función para buscar una reserva por el nombre del cliente
struct Reserva* buscarReserva(struct Reserva reservas[], int contadorReservas, char nombreCliente[]) {
    for (int i = 0; i < contadorReservas; i++) {
        if (strcmp(reservas[i].nombreCliente, nombreCliente) == 0) {
            return &reservas[i];
        }
    }
    printf("Reserva no encontrada.\n");
    return NULL;
}

// Función para imprimir los detalles de una reserva
void imprimirReserva(struct Reserva *reserva) {
    printf("\nDetalles de la reserva:\n");
    printf("Nombre del cliente: %s\n", reserva->nombreCliente);
    printf("Documento: %s\n", reserva->documento);
    printf("Película: [%s] %s, Género: %s, Duración: %d min\n",
           reserva->pelicula.codigo, reserva->pelicula.titulo, reserva->pelicula.genero, reserva->pelicula.duracion);
    printf("Cantidad de entradas: %d\n", reserva->cantidadEntradas);
    printf("Total de la reserva: $%.2f\n", reserva->totalReserva);
}