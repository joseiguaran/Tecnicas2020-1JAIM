#include "Personas.h"

int main(){

    Personas matriz [12][5];
    int tamano[12] = {};
    int opcion=0;
    do{
        option = menu();
        
        switch (option)
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
            buscarGenero(matriz, tamano);
            break;

        case 0:
            break;

        default:
            printf("Opcion no Disponible\n");
            break;
        }
    } while (option != 0);
}
