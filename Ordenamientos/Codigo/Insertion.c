#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h> 
#define SIZE 1000000

FILE* abrirFile(char path[], char modo[]) 
{
	if (path != NULL) 
	{
		FILE* pFile = fopen(path, modo);
		return pFile;
	}
	return NULL;
}



void ordernarInsercion(int lista[],int inicio) {

	int i, j, temp;
	 int Comparar=0;
    int Cambios=0;
	for (i = 1; i < SIZE; i++) {
		//temp= elemento a ubicar correctamente
		temp =lista[i];
		//Subindice del elemento que se quiere ubicar correctamente
		j = i;
		while (temp < lista[j - 1] && j > 0) {
			//Se mueven los elementos que se necesiten del lista hacia adelante
			lista[j] = lista[j - 1];
			j--;
			Comparar=Comparar+1;
		}
		//Se ubica el temp en la posicion correcta
		lista[j] = temp;
		Cambios=Cambios+1;
	}

		clock_t fin =0; 
	fin=clock();  
	float duracion;
	duracion = fin-inicio;
	char path[] = "ResumenInsertion.txt";
	char modo[] = "a";
	FILE * pFileResumen = abrirFile(path, modo);
	if(pFileResumen!=NULL){

		fprintf(pFileResumen,"Tiempo de Final de Corrida: %d\n Tiempo de ejecucion: %f\n Comparaciones %d\n Intercambios %d\n\n ",fin, duracion, Comparar, Cambios);

	}
	fclose(pFileResumen);
}


int main(){
	int lista[SIZE+1];

	FILE* pFile = fopen("Datos.txt","r");
	if(pFile != NULL) {
		fread(lista,sizeof(int),SIZE,pFile);
		fclose(pFile);		
	} else {
		printf("No se pudo acceder el archivo\n");
	}
	

	clock_t inicio;
	inicio = clock();
	
	char path[] = "ResumenInsertion.txt";
	char modo[] = "a";
	FILE * pFileResumen = abrirFile(path, modo);
	if(pFileResumen!=NULL){

		fprintf(pFileResumen,"Algoritmo Insertion %d\n Inicio de Corrida: %d \n", SIZE, inicio);
	
		fclose(pFileResumen);
	} else {
		printf("No se pudo acceder al archivo\n");
	}

	ordernarInsercion(lista,inicio);

	
}