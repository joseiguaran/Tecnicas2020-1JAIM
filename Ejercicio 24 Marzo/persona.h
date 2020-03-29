#include <stdio.h>
#include <string.h>


typedef enum Nacionalidad{
    COLOMBIANA, EXTRANJERO
}Nacionalidad;

typedef struct Persona{
    char nombre[25];
    int dia;
    int anio;
    Nacionalidad nacionalidad;
}Persona;

int menu();

void anadirUsuario(Persona matriz[][5], int tamano[]);

void buscarMes(Persona matriz[][5], int tamano[]);

int sumarEdad (Persona matriz[][5], int tamano[]);

void buscarNacionalidad(Persona matriz[][5], int tamano[]);
