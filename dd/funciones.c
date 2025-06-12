#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para mostrar el menú
int menu() {
    int opcion;
    printf("\nSeleccione una opción:\n");
    printf("1. Registrar nuevo paciente\n");
    printf("2. Listar pacientes\n");
    printf("3. Buscar paciente\n");
    printf("4. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el buffer de entrada
    return opcion;
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

// Función para registrar un nuevo paciente
void registrarPaciente(struct Paciente pacientes[], int *contador) {
    printf("Ingrese el nombre del paciente: ");
    leerCadena(pacientes[*contador].nombre, 40);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &pacientes[*contador].edad);
    getchar(); // Limpiar el buffer de entrada

    for (int i = 0; i < 2; i++) {
        printf("Ingrese el motivo de la consulta %d: ", i + 1);
        leerCadena(pacientes[*contador].consultas[i].motivo, 40);
        printf("Ingrese el resultado de la consulta %d: ", i + 1);
        leerCadena(pacientes[*contador].consultas[i].resultado, 80);
    }

    (*contador)++;
}

// Función para listar todos los pacientes
void listarPacientes(struct Paciente pacientes[], int contador) {
    printf("\nListado de pacientes:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. Nombre: %s, Edad: %d\n", i + 1, pacientes[i].nombre, pacientes[i].edad);
    }
}

// Función para buscar un paciente por nombre
struct Paciente* buscarPaciente(struct Paciente pacientes[], int contador, char nombreABuscar[]) {
    for (int i = 0; i < contador; i++) {
        if (strcmp(pacientes[i].nombre, nombreABuscar) == 0) {
            return &pacientes[i];
        }
    }
    printf("Paciente no encontrado.\n");
    return NULL;
}

// Función para imprimir los datos de un paciente
void imprimirPaciente(struct Paciente *paciente) {
    printf("\nDatos del paciente:\n");
    printf("Nombre: %s\n", paciente->nombre);
    printf("Edad: %d\n", paciente->edad);
    printf("Consultas:\n");
    for (int i = 0; i < 2; i++) {
        printf("Consulta %d:\n", i + 1);
        printf("  Motivo: %s\n", paciente->consultas[i].motivo);
        printf("  Resultado: %s\n", paciente->consultas[i].resultado);
    }
}
