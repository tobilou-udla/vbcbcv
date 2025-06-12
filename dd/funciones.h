#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definición de estructuras
struct Consulta {
    char motivo[40];
    char resultado[80];
};

struct Paciente {
    char nombre[40];
    int edad;
    struct Consulta consultas[2];
};

// Prototipos de funciones
int menu();
void leerCadena(char *cadena, int tamano);
void registrarPaciente(struct Paciente pacientes[], int *contador);
void listarPacientes(struct Paciente pacientes[], int contador);
struct Paciente* buscarPaciente(struct Paciente pacientes[], int contador, char nombreABuscar[]);
void imprimirPaciente(struct Paciente *paciente);

#endif
