#include "persona.h"

int main(){

    Persona matriz[12][5];
    int tamano[12] = {};
    int opcion=0;
    do{
        opcion = menu();
        
        switch (opcion)
        {
        case 1:
            anadirUsuario(matriz, tamano);
            break;

        case 2:
            buscarMes(matriz, tamano);
            break;

        case 3:
            int edades;    
            edades=sumarEdad(matriz, tamano);
            printf("La suma de edades del mes es:" %d, edades);
            break;

        case 4:
            buscarNacionalidad(matriz, tamano);
            break;

        default:
            printf("Opcion no Disponible\n");
            break;
        }
    } while (option != 0);
}
