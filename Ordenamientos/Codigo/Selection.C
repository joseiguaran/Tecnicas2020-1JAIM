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



void selection(int lista[],int inicio){
    int i, j,orden,temp;
    int Comparar=0;
    int Cambios=0;
    for (i=0; i<=SIZE-1; i=i+1){
        orden=i;
        for (j=i+1; j<=SIZE-1; j=j+1){
			Comparar=Comparar+1;
            if (lista[j] < lista[orden]){
                orden=j;
            }
        }
        temp=lista[i];
        lista[i]=lista[orden];
        lista[orden]=temp;
		if (temp>lista[i]){
			Cambios=Cambios+1;
		}
    }

	clock_t fin =0; 
	fin=clock();  
	float duracion;
	duracion = fin-inicio;
	char path[] = "ResumenSelection.txt";
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
	
	char path[] = "ResumenSelection.txt";
	char modo[] = "a";
	FILE * pFileResumen = abrirFile(path, modo);
	if(pFileResumen!=NULL){

		fprintf(pFileResumen,"Algoritmo Selection %d\n Inicio de Corrida: %d \n", SIZE, inicio);
	
		fclose(pFileResumen);
	} else {
		printf("No se pudo acceder al archivo\n");
	}

	selection(lista,inicio);

	
}