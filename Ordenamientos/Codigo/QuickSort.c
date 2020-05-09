#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h> 
#define SIZE 100000 //Modificar cada vez que se intente leer una lista de tamaño n
 int Comparar=0;
    int Cambios=0;
FILE* abrirFile(char path[], char modo[]) 
{
	if (path != NULL) 
	{
		FILE* pFile = fopen(path, modo);
		return pFile;
	}
	return NULL;
}


void intercambiar(int arreglo[], int posicion1, int posicion2) {
	int tmp;
	tmp = arreglo[posicion2];
	arreglo[posicion2] = arreglo[posicion1];
	arreglo[posicion1] = tmp;
	Cambios=Cambios+1;
}


/* Función que entrega la posición del pivote, tomando como pivote inicial el elemento del final de la lista */
int partirYOrdenarPivoteInicial(int arreglo[], int posPrimerElem,
		int posUltimoElem) {
	int valorPivote = arreglo[posPrimerElem]; // Valor del pivote
	int posIzquierda = posPrimerElem + 1; // Se incrementa uno  pq el primer elemento será el pivote
	int posDerecha = posUltimoElem;

	
	//Se mueven elementos mientras que no se crucen los indices
	do {
		while (posIzquierda <= posDerecha
				&& arreglo[posIzquierda] <= valorPivote) {
			//Los elementos estan en el lado correcto, no hay que intercambiar.
			//Se avanza para encontrar elemento a intercambiar
			posIzquierda++;
			
		}
		while (posIzquierda <= posDerecha && arreglo[posDerecha] > valorPivote) {
			//Los elementos estan en el lado correcto, no hay que intercambiar.
			//Se avanza para encontrar elemento a intercambiar
			posDerecha--;
	Comparar=Comparar+1;
		}
		//Se encontraron elementos en posiciones que deben intercambiarse
		if (posIzquierda < posDerecha) {
			
			intercambiar(arreglo, posIzquierda, posDerecha);
			posIzquierda++;
			posDerecha--;
			
		

		}
	} while (posIzquierda <= posDerecha);
	
			
	//intercambiar pivote
	if (arreglo[posDerecha] != valorPivote) {
		
		intercambiar(arreglo, posPrimerElem, posDerecha);

	}
	
	
	//Retorna la posicion del pivote
	return posDerecha;
}

/* Función que implementa ordenamiento por quicksort. */
void quickSort(int arreglo[], int posIzquierda, int posDerecha) {
	//Posición del pivote
	int Comparar=0;
    int Cambios=0;
	int posPivote;
	
	if (posIzquierda < posDerecha) {
		//Ordenar elementos para un pivote
		posPivote = partirYOrdenarPivoteInicial(arreglo, posIzquierda,
				posDerecha);
		
		//Repetir el proceso con los arreglos resultantes
		
		quickSort(arreglo, posIzquierda, posPivote - 1);
		
		quickSort(arreglo, posPivote + 1, posDerecha);
	}
	
}



int main(){
	int arreglo[SIZE+1];

	FILE* pFile = fopen("Datos.txt","r");
	if(pFile != NULL) {
		fread(arreglo,sizeof(int),SIZE,pFile);
		fclose(pFile);		
	} else {
		printf("No se pudo acceder el archivo\n");
	}
	

	clock_t inicio;
	inicio = clock();
	
	char path[] = "ResumenQuickSort.txt";
	char modo[] = "a";
	FILE * pFileResumen = abrirFile(path, modo);
	if(pFileResumen!=NULL){

		fprintf(pFileResumen,"Algoritmo quicksort %d\n Inicio de Corrida: %d \n", SIZE, inicio);
	
		
	} else {
		printf("No se pudo acceder al archivo\n");
	}

	quickSort(arreglo,0,SIZE-1);

clock_t fin =0; 
	fin=clock();  
	float duracion;



		fprintf(pFileResumen,"Tiempo de Final de Corrida: %d\n Tiempo de ejecucion: %f\n Comparaciones %d\n Intercambios %d\n\n ",fin, duracion, Comparar, Cambios);
	


	fclose(pFileResumen);
}