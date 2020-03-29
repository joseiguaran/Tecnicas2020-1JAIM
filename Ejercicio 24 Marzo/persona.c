#include "persona.h"

int menu()
{
    int opcion;
    printf("Seleccione la opcion \n");
    printf("1: Anadir usuario\n");
    printf("2: Personas por Mes\n");
    printf("3: Suma de Edades por Mes\n");
    printf("4: Personas por nacionalidad\n");
    printf("0: Salir\n");
    scanf("%d", &opcion);
    return opcion;
    
}

void anadirUsuario(Persona matriz[][5], int tamano[]){

    int dia,
    int mes,
    int anio;
    char nombre[25];

    printf("Nombre ");
    scanf("%s", &nombre);

    printf("Anio ");
    scanf("%d", &anio);

    printf("Mes ");
    scanf("%d", &mes);

    printf("Dia ");
    scanf("%d", &dia);

    printf("Nacionalidad:\n 1-Colombiana\n 2-Extranjero\n");
    int nacion;
    scanf("%d", &nacion);

    if (tamano[mes - 1] <= 4) {
    
           if (nacion = 1) {
             Nacionalidad nan = COLOMBIANA
           }
           else  
              Nacionalidad nan = EXTRANJERO
   
        Persona p;
        strcpy(p.nombre, nombre);
        strcpy(p.dia, dia);
        strcpy(p.anio, anio);
        strcpy(p.nacionalidad, nan);
        matriz[mes - 1][tamano[mes - 1]] = p;
        tamano[mes - 1]= tamano[mes - 1]+1;
    }
    else
        printf("Numero de Usuarios Excedido en el mes %d\n", mes);
}

void buscarMes(Persona matriz[][5], int tamano[])
{
    int mes;
    printf("Mes ");
    scanf("%d", &mes);
    int i;
    for (i = 0; i < tamano[mes- 1]; i=i+1) {
        Persona p = matriz[mes - 1][i];
        printf("Nombre del usuario: %s\n Dia de N: %d\n Mes de N: %d\n Anio de N: %d\n Nacionalidad:", p.nombre, p.dia, p.mes, p.anio);
        if (p.nacionalidad == COLOMBIANA)
            printf(" Ciudadano Nacional \n");
        else
            printf("Ciudadano Extranjero \n ");
    }
}

int fibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void dayFibonacci(User mat[][5], int sizes[])
{
    char name[20];

    printf("Nombre: ");
    scanf("%s", &name);

    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            User u = mat[i][j];

            if (!strcmp(u.name, name))
                printf("Numero: %d\n", fibonacci(u.day));
        }
    }
}

void searchByGender(User mat[][5], int sizes[])
{
    printf("Genero:\n1)Hombre\n2)Mujer\n");
    int genderChoice;
    scanf("%d", &genderChoice);
    Gender g = genderChoice == 1 ? Male : Female;

    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            User u = mat[i][j];

            if (u.gender == g)
                printf("Nombre: %s\nFecha de nacimiento: %d/%d/%d\n-----------\n", u.name, u.day, i + 1, u.year);
        }
    }
}
