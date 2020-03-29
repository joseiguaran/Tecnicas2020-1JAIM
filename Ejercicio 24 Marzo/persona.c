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

void buscarMes(Persona matriz[][5], int tamano[]){
    int mes;
    printf("Mes ");
    scanf("%d", &mes);
    int i;
    for (i = 0; i < tamano[mes- 1]; i=i+1) {
        Persona p = matriz[mes - 1][i];
        printf("Nombre del usuario: %s\n Dia de N: %d\n Mes de N: %d\n Anio de N: %d\n Nacionalidad:", p.nombre, p.dia, p.mes, p.anio);
        if (p.nacionalidad == COLOMBIANA){
            printf(" Ciudadano Nacional \n");
        }else
            printf("Ciudadano Extranjero \n ");
    }
}

int sumarEdad (Persona matriz[][5], int tamano[]){
    int recursion;
    int edades=0;
    int mes;
    printf("Mes ");
    scanf("%d", &mes);
    recursion=tamano[mes-1];
    if (recursion<0){
        return 0;
            
    }else
        
        if (matriz[Mes-1][recursion].anio>0){
             edades=2020- matriz[Mes-1][recursion].anio;
             return edades + sumarEdad(Persona matriz[][5], recursion-1);
             }

}




void buscarNacionalidad(Persona matriz[][5], int tamano[]){
    
    printf("Ingrese su Nacionalidad:\n1-Colombiana \n2-Extranjero\n");
    int nacion;
    scanf("%d", &nacion);
    if (nacion = 1) {
             Nacionalidad nan = COLOMBIANA
           }
           else  
              Nacionalidad nan = EXTRANJERO

    int i;
    int j;
    for (i = 1; i <= 12; i=i+1){
        
        for (j = 0; j < tamano[i-1]; j=j+1){   
        Persona p = matriz[i][j];
            if (p.nacionalidad == nan){
                printf("Nombre del usuario: %s\n Dia de N: %d\n Mes de N: %d\n Anio de N: %d\n", p.nombre, p.dia, p.mes, p.anio);
                 }
        }
    }
}
