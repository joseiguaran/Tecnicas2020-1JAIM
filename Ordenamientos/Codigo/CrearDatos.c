#include <stdio.h>
#include <stdlib.h>



int main(){
char path[] = "Datos.txt";
char modo[] = "w";
int cont = 0;
int numDatos= 10;

FILE* pFile = fopen(path, modo);

	for (cont = 0; cont < numDatos; ++cont)
    {
    fprintf(pFile, "%d", rand() % 10);
    }   
	fclose(pFile);

}