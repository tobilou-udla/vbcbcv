#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para un vuelo
struct Vuelo {
    char codigo[10];
    char origen[30];
    char destino[30];
    char fechaHora[20];
    float precio;
};

// Estructura para una reserva (anida la estructura Vuelo)
struct Reserva {
    char nombrePasajero[50];
    char documento[20];
    struct Vuelo vuelo;  // Vuelo asociado a la reserva
    int cantidadAsientos;
    float totalReserva;
};

// Prototipos de funciones
int menu();
void inicializarVuelos(struct Vuelo vuelos[], int *totalVuelos);
void mostrarVuelos(struct Vuelo vuelos[], int totalVuelos);
void registrarReserva(struct Reserva reservas[], int *contadorReservas, struct Vuelo vuelos[], int totalVuelos);
void listarReservas(struct Reserva reservas[], int contadorReservas);
struct Reserva* buscarReserva(struct Reserva reservas[], int contadorReservas, char nombrePasajero[]);
void imprimirReserva(struct Reserva *reserva);
void leerCadena(char *cadena, int tamano);

#endif