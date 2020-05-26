#include "FuncionesCC.h"
#include <stdio.h>

int main(){
	// Establece las dimensiones del Centro comercial
	int fila, col;
	printf("Ingrese el numero de pisos del centro comercial: ");
	scanf("%d", &fila);
	printf("Ingrese el numero de locales por piso del centro comercial: ");
	scanf("%d", &col);
	// Establece el tamano del array de capacidad
	int tamano[fila];
	local_t** matriz = iniciarMatriz(fila, col, tamano);
	
	
	int opcion=0;
   
do{
        opcion = menu();
        // Operacion con todas las opciones disponibles para el usuario
        switch (opcion)
        {
        case 1:
            disponibilidadLocal(matriz, tamano,fila,col);
            break;

        case 2:
            anadirUsuario(matriz, tamano,col, fila);
            break;

        case 3: ;
            int aniosAper;    
	    int recursion;
     	    int piso;
    	    printf("Piso ");
   	    scanf("%d", &piso);
  	    recursion=tamano[piso-1];
            aniosAper=sumarAnios(matriz, recursion,piso,col);
            printf("El total de Anios de Apertura para locales del piso es: %d", aniosAper);
            break;

        case 4:
            buscarOficinas(matriz, tamano,fila,col);
            break;
	
	case 5:
            cambiarNombre(matriz, tamano,col);
            break;
			
	case 6:
            vaciarLocal(matriz, tamano);
            break;
			
    case 7: 
            selectionSort(matriz, fila, col);
            break;
     case 8: 
            insertionSort(matriz, fila, col);
            break;

     case 9: 
            startQS(matriz, fila, col);
            break;

     case 10: 
            startMS(matriz, fila, col);
            break;


      case 11: guardarCentro( matriz, fila, col);
                break;
        default:
            printf("Opcion no Disponible\n");
            break;
        }
	// Terminar el programa al ingresar 0
    } while (opcion != 0);

return 0;
}
