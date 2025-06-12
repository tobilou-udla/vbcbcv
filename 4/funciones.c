#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para mostrar el menú principal
int menu() {
    int opcion;
    printf("\nSeleccione una opción:\n");
    printf("1. Registrar un nuevo paciente\n");
    printf("2. Registrar una consulta\n");
    printf("3. Listar todos los pacientes\n");
    printf("4. Buscar un paciente por el nombre del animal\n");
    printf("5. Salir\n");
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
void registrarPaciente(struct Paciente pacientes[], int *contadorPacientes) {
    struct Paciente nuevoPaciente;

    printf("Ingrese el nombre del dueño: ");
    leerCadena(nuevoPaciente.nombreDuenio, 50);

    printf("Ingrese el nombre del animal: ");
    leerCadena(nuevoPaciente.nombreAnimal, 50);

    printf("Ingrese la especie del animal: ");
    leerCadena(nuevoPaciente.especie, 20);

    printf("Ingrese la edad del animal: ");
    scanf("%d", &nuevoPaciente.edad);
    getchar(); // Limpiar el buffer de entrada

    nuevoPaciente.totalConsultas = 0;

    pacientes[*contadorPacientes] = nuevoPaciente;
    (*contadorPacientes)++;
    printf("Paciente registrado exitosamente.\n");
}

// Función para registrar una consulta para un paciente
void registrarConsulta(struct Paciente pacientes[], int contadorPacientes) {
    char nombreAnimal[50];
    struct Paciente *pacienteEncontrado;

    printf("Ingrese el nombre del animal que necesita una consulta: ");
    leerCadena(nombreAnimal, 50);

    pacienteEncontrado = buscarPaciente(pacientes, contadorPacientes, nombreAnimal);
    if (pacienteEncontrado != NULL) {
        if (pacienteEncontrado->totalConsultas < 10) {
            struct Consulta nuevaConsulta;

            printf("Ingrese la fecha de la consulta (DD/MM/AAAA): ");
            leerCadena(nuevaConsulta.fecha, 20);

            printf("Ingrese el motivo de la consulta: ");
            leerCadena(nuevaConsulta.motivo, 50);

            printf("Ingrese el diagnóstico: ");
            leerCadena(nuevaConsulta.diagnostico, 100);

            printf("Ingrese el tratamiento: ");
            leerCadena(nuevaConsulta.tratamiento, 100);

            pacienteEncontrado->consultas[pacienteEncontrado->totalConsultas] = nuevaConsulta;
            pacienteEncontrado->totalConsultas++;
            printf("Consulta registrada exitosamente.\n");
        } else {
            printf("El paciente ya tiene el máximo de consultas registradas (10).\n");
        }
    }
}

// Función para listar todos los pacientes
void listarPacientes(struct Paciente pacientes[], int contadorPacientes) {
    printf("\nListado de pacientes:\n");
    for (int i = 0; i < contadorPacientes; i++) {
        printf("%d. Nombre del dueño: %s, Nombre del animal: %s, Especie: %s, Edad: %d\n",
               i + 1, pacientes[i].nombreDuenio, pacientes[i].nombreAnimal, pacientes[i].especie, pacientes[i].edad);
    }
}

// Función para buscar un paciente por el nombre del animal
struct Paciente* buscarPaciente(struct Paciente pacientes[], int contadorPacientes, char nombreAnimal[]) {
    for (int i = 0; i < contadorPacientes; i++) {
        if (strcmp(pacientes[i].nombreAnimal, nombreAnimal) == 0) {
            return &pacientes[i];
        }
    }
    printf("Paciente no encontrado.\n");
    return NULL;
}

// Función para imprimir los detalles de un paciente
void imprimirPaciente(struct Paciente *paciente) {
    printf("\nDetalles del paciente:\n");
    printf("Nombre del dueño: %s\n", paciente->nombreDuenio);
    printf("Nombre del animal: %s\n", paciente->nombreAnimal);
    printf("Especie: %s\n", paciente->especie);
    printf("Edad: %d\n", paciente->edad);
    printf("Consultas:\n");
    for (int i = 0; i < paciente->totalConsultas; i++) {
        printf("Consulta %d:\n", i + 1);
        printf("  Fecha: %s\n", paciente->consultas[i].fecha);
        printf("  Motivo: %s\n", paciente->consultas[i].motivo);
        printf("  Diagnóstico: %s\n", paciente->consultas[i].diagnostico);
        printf("  Tratamiento: %s\n", paciente->consultas[i].tratamiento);
    }
}