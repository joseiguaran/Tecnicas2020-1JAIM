#include "Personas.h"

int main(){

    Persona matriz[12][5];
    int tamano[12] = {};
    int opcion=0;
    do{
        option = menu();
        
        switch (opcion)
        {
        case 1:
            anadirUsuario(matriz, tamano);
            break;

        case 2:
            buscarMes(matriz, tamano);
            break;

        case 3:
            sumarEdad(matriz, tamano);
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
