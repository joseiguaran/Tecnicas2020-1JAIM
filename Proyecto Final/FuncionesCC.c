#include "FuncionesCC.h"

int menu()
{
	//Menu con todas las opciones del usuario
    int opcion;
    printf("BIENVENIDO AL SISTEMA DE LOCALES \n");
    printf("Seleccione la opcion \n");
    printf("1: Numero de locales disponibles\n");
    printf("2: Anadir Local\n");
    printf("3: Suma de Anios de Apertura por Piso\n");
    printf("4: Locales por Tipo (Almacen u Oficina)\n");
    printf("5: Cambiar Nombre del Almacen (Almacen u Oficina)\n");
    printf("6: Vaciar Local (Almacen u Oficina)\n");
    printf("0: Salir\n");
    scanf("%d", &opcion);
    return opcion;
}
//operacion para iniciar la matriz con valor 0 en anios de apertura
local_t** iniciarMatriz(int fila, int col,int tamano[])
{
    local_t** matriz = malloc(sizeof(local_t*) * fila);
    int i;
    int j;
    int h;
    for(i = 0; i < fila; i=i+1)
	    //Operacion para reserva de memoria dinamica
    {
        matriz[i] = malloc(sizeof(local_t) * col);
        for (j = 0; j < col; j=j+1)
            matriz[i][j].anioApertura = 0;
	    matriz[i][j].tipoLocal = 0;
    }
	// Operacion para iniciar todos los valores del array tamano en 0
	for(h=0;h<fila;h++)
		tamano[h]=0;
    return matriz;
}
// Operacion para verificar el numero de locales disponibles
void disponibilidadLocal(local_t **matriz, int tamano[], int fila, int col)
{
    int i;
    for (i = 0; i <fila; i=i+1)
    {
	    // Se resta col que contiene la capacidad de locales con tamano que es el contador de locales usados
	printf("En el piso %d se encuentran %d locales vacios\n",(i+1),(col-tamano[i]));
    }
}    
// Operacion para anadir un local nuevo
void anadirUsuario(local_t **matriz, int tamano[], int col)
{
    	int idLocal; 
	int pisoLocal;
	int anioApertura;
	int numLocalxPiso;
  
    do{
    printf("Piso del Local ");
    scanf("%d", &pisoLocal);
    
    printf("Numero del Local");
    scanf("%d", &numLocalxPiso);

}while ((matriz[pisoLocal-1][numLocalxPiso-1].anioApertura)=!0)

    // revisa que no exista un local en esa posicion

    
	    
	printf("Anio de Apertura ");
        scanf("%s", &anioApertura);
	     
        local_t l;
        printf("Nombre ");
	scanf("%35s",matriz[pisoLocal - 1][numLocalxPiso-1].nombreLocal);
        l.pisoLocal=pisoLocal;
        l.numLocalxPiso=numLocalxPiso;
	    printf("Tipo de Local:\n 1-Almacen\n 2-Oficina\n");
        int tipo;
        scanf("%d", &tipo);
    // Establece el tipo de Local
           if (tipo = 1){
            l.tipoLocal= ALMACEN;
                        }
           if (tipo=2) {  
              l.tipoLocal= OFICINA;
	        }
	l.anioApertura=anioApertura; 
	l.idLocal=1000+(pisoLocal*10)+(numLocalxPiso);
        matriz[pisoLocal - 1][numLocalxPiso-1] = l;
        tamano[pisoLocal - 1]= tamano[pisoLocal - 1]+1;
    
   
       
   }     

// Operacion para suma de anios de apertura
int sumarAnios (local_t **matriz, int recursion, int piso, int col)
{
    int anios=0;
    if (recursion<0)
    {
        return 0;
            
    }else
        // Se asegura que exista por lo menos un local restante por sumar
        if (matriz[piso-1][recursion].anioApertura>0)
	     {
		// Se establece que el anio actual es 2020
             anios=2020- matriz[piso-1][recursion].anioApertura;
             return anios + sumarAnios(matriz, recursion-1,piso, col);
             }

}
// Operacion que busca todos los locales por tipo
void buscarOficinas(local_t **matriz, int tamano[], int fila, int col)
{
    printf("Ingrese el Tipo a Buscar:\n 1-Almacen\n 2-Oficina\n");
    int tipo;
 
    scanf("%d", &tipo);
   
	 
    int i;
    int j;
	// Ciclo que recorre cada columna de cada fila de la matriz
    for (i = 0; i <fila; i=i+1)
    {
        for (j = 0; j < tamano[i]; j=j+1)
	{   
        local_t l = matriz[i][j];
            if (l.tipoLocal == tipo)
	    {
                printf("Nombre del Local: %s\n ID del local: %d\n Piso del Local: %d\n Numero del Local: %d\n Anio de Apertura: %d\n", l.nombreLocal, l.idLocal, l.pisoLocal, l.numLocalxPiso,l.anioApertura );
            }
        }
    }
}
// Operacion que cambia el nombre a un local
void  cambiarNombre(local_t **matriz, int tamano[], int col)
{
        int piso;
	int numeroLocal;
	char nombre[35];
        printf("Ingrese el piso del local a cambiar\n");
	scanf("%d", &piso);
	printf("Ingrese el numero del local a cambiar\n");
	scanf("%d", &numeroLocal);
	printf("Ingrese el nuevo nombre\n");
	// Reemplaza el nombre anterio por el suministrado por el usuario
	scanf("%s",matriz[piso - 1][numeroLocal-1].nombreLocal);

}
// Operacion que borra los datos de un local
void   vaciarLocal(local_t **matriz, int tamano[])
{
int piso;
int numeroLocal;
        printf("Piso del local a Borrar: ");
        scanf("%d", &piso);
        printf("Numero del Local a Borrar: ");
        scanf("%d", &numeroLocal);
	// Reestablece el valo criterio de la operacion anadirUsuario a 0 para que pueda ser usado.
	matriz[piso][numeroLocal].anioApertura = 0;
}	
	
