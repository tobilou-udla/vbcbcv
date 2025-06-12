#include <stdio.h>
#include "funciones.h"

int main() {
    struct Paciente pacientes[3];
    struct Paciente *pacienteEncontrado;
    int contador = 0;
    int opcion = 0;
    char nombreABuscar[40];

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                if (contador < 3) {
                    registrarPaciente(pacientes, &contador);
                } else {
                    printf("No se pueden registrar más pacientes (máximo 3).\n");
                }
                break;
            case 2:
                listarPacientes(pacientes, contador);
                break;
            case 3:
                printf("Ingrese el nombre del paciente a buscar: ");
                leerCadena(nombreABuscar, 40);
                pacienteEncontrado = buscarPaciente(pacientes, contador, nombreABuscar);
                if (pacienteEncontrado != NULL) {
                    imprimirPaciente(pacienteEncontrado);
                }
                break;
            default:
                if (opcion != 4) {
                    printf("Opción no válida.\n");
                }
                break;
        }
    } while (opcion != 4);

    printf("Saliendo del programa...\n");
    return 0;
}
