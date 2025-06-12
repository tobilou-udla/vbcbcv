#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para una película
struct Pelicula {
    char codigo[10];
    char titulo[50];
    char genero[30];
    int duracion; // en minutos
    float precioEntrada;
};

// Estructura para una reserva (anida la estructura Pelicula)
struct Reserva {
    char nombreCliente[50];
    char documento[20];
    struct Pelicula pelicula;  // Película asociada a la reserva
    int cantidadEntradas;
    float totalReserva;
};

// Prototipos de funciones
int menu();
void inicializarPeliculas(struct Pelicula peliculas[], int *totalPeliculas);
void mostrarPeliculas(struct Pelicula peliculas[], int totalPeliculas);
void registrarReserva(struct Reserva reservas[], int *contadorReservas, struct Pelicula peliculas[], int totalPeliculas);
void listarReservas(struct Reserva reservas[], int contadorReservas);
struct Reserva* buscarReserva(struct Reserva reservas[], int contadorReservas, char nombreCliente[]);
void imprimirReserva(struct Reserva *reserva);
void leerCadena(char *cadena, int tamano);

#endif