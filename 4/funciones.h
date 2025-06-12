#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para una consulta
struct Consulta {
    char fecha[20];
    char motivo[50];
    char diagnostico[100];
    char tratamiento[100];
};

// Estructura para un paciente
struct Paciente {
    char nombreDuenio[50];
    char nombreAnimal[50];
    char especie[20];
    int edad;
    struct Consulta consultas[10];
    int totalConsultas;
};

// Prototipos de funciones
int menu();
void registrarPaciente(struct Paciente pacientes[], int *contadorPacientes);
void registrarConsulta(struct Paciente pacientes[], int contadorPacientes);
void listarPacientes(struct Paciente pacientes[], int contadorPacientes);
struct Paciente* buscarPaciente(struct Paciente pacientes[], int contadorPacientes, char nombreAnimal[]);
void imprimirPaciente(struct Paciente *paciente);
void leerCadena(char *cadena, int tamano);

#endif