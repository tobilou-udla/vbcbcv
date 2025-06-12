#include <stdio.h>
#include "funciones.h"

int main() {
    struct Paciente pacientes[20];
    int contadorPacientes = 0;
    int opcion;
    char nombreAnimal[50];
    struct Paciente *pacienteEncontrado;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                if (contadorPacientes < 20) {
                    registrarPaciente(pacientes, &contadorPacientes);
                } else {
                    printf("No se pueden registrar más pacientes (máximo 20).\n");
                }
                break;
            case 2:
                registrarConsulta(pacientes, contadorPacientes);
                break;
            case 3:
                listarPacientes(pacientes, contadorPacientes);
                break;
            case 4:
                printf("Ingrese el nombre del animal para buscar: ");
                leerCadena(nombreAnimal, 50);
                pacienteEncontrado = buscarPaciente(pacientes, contadorPacientes, nombreAnimal);
                if (pacienteEncontrado != NULL) {
                    imprimirPaciente(pacienteEncontrado);
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