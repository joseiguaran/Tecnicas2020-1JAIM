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
    printf("7: Ordenar por Numero de Empleados\n");
    printf("7: Ordenar por Numero de Ventas\n");
    printf("7: Ordenar Piso por Numero de Sucursales\n");
    printf("7: Ordenar Piso por Numero de Inventarios\n");
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
    if (matriz!=NULL){
        for(i = 0; i < fila; i=i+1){
	    //Operacion para reserva de memoria dinamica
        matriz[i] = malloc(sizeof(local_t) * col);
        for (j = 0; j < col; j=j+1)
            matriz[i][j].anioApertura = 0;
	    matriz[i][j].tipoLocal = 0;
    }

	// Operacion para iniciar todos los valores del array tamano en 0
	for(h=0;h<fila;h++){
		tamano[h]=0;
    }
    return matriz;
}
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
void anadirUsuario(local_t **matriz, int tamano[], int col, int fila)
{
    	int idLocal; 
	int pisoLocal;
	int anioApertura;
	int numLocalxPiso;
    int numEmpleados;
    int numVentas;
    int numSucursales;
    int numInventarios;
  
    do{
    printf("Piso del Local ");
    scanf("%d", &pisoLocal);
    
    printf("Numero del Local");
    scanf("%d", &numLocalxPiso);

}while (((matriz[pisoLocal-1][numLocalxPiso-1].anioApertura)=!0) ||(pisoLocal>fila||numLocalxPiso>col)); // asegura que los datos suministrados sean correctos

    // revisa que no exista un local en esa posicion

FILE *resumenLocales;
     resumenLocales= fopen("resumenLocales.txt", "a"); //abre archivo donde se guardaran los locales nuevos
    

	printf("Anio de Apertura ");
        scanf("%s", &anioApertura);

        local_t l;
        printf("Nombre ");
	scanf("%35s",matriz[pisoLocal - 1][numLocalxPiso-1].nombreLocal);

    fprintf(resumenLocales, "%s", matriz[pisoLocal - 1][numLocalxPiso-1].nombreLocal);
        l.pisoLocal=pisoLocal;
    fprintf(resumenLocales, "%d", pisoLocal);
        l.numLocalxPiso=numLocalxPiso;
    fprintf(resumenLocales, "%d",numLocalxPiso);

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
    fprintf(resumenLocales, "%d",anioApertura);
	l.idLocal=1000+(pisoLocal*10)+(numLocalxPiso);
        matriz[pisoLocal - 1][numLocalxPiso-1] = l;
        tamano[pisoLocal - 1]= tamano[pisoLocal - 1]+1;
    fprintf(resumenLocales, "%d",idLocal);

   printf("Numero Empleados ");
        scanf("%s", &numEmpleados);
    printf("Numero Ventas ");
        scanf("%s", &numVentas); 
   printf("Numero Sucursales ");
        scanf("%s", &numSucursales); 
    printf("Numero Inventarios ");
        scanf("%s", &numInventarios); 
    l.numEmpleados=numEmpleados;
fprintf(resumenLocales, "%d",numEmpleados);
    l.numVentas=numVentas;
fprintf(resumenLocales, "%d",numVentas);
    l.numSucursales=numSucursales;
fprintf(resumenLocales, "%d",numSucursales);
    l.numInventarios=numInventarios; 
    fprintf(resumenLocales, "%d",numInventarios); 
fclose (resumenLocales);
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
	
void guardarCentro(local_t **matriz, int fila, int col){ //funcion para guardar la informacion del centro comercial en un archivo.dat
 /* int i, j;
  local_t aux;
  char path[] = "CC.dat";
  FILE *archivoBinario = fopen( path ,"w" );

  if ( archivoBinario =! NULL ){ // aseguraq ue exista acceso
      
   for(i = 0; i < fila; i=i+1){
      for(j = 0; j < col; j=j+1){
        if( matriz[i][j].anioApertura!=0 ){  // solo guarda locales llenos  
          aux = matriz[ i ][ j ];
          fwrite( &aux, sizeof( local_t ), 1, archivoBinario ); 

      }

      }
    } 
    printf( "Se almaceno la infromacion" );   
   fclose( archivoBinario ); 
}
   else {
    printf( "No se puede acceder al archivo" );
   } 
   */
}

void insertionSort(local_t **matriz, int fila, int col ){
    
 int i, j, x, min, temp, spot; 
    int largo;
    x=0;
    temp=0;
    largo= fila * col;
        int lista[ largo ];
  
    for( i = 1; i <= fila; i=i+1 ){
    for( j = 1; j <= col; j=j+1 ){

        lista[ x ] = matriz[i][j].numVentas; // se guarda la infromacion de toda la matriz en un array
        x=x+1;
        }
    }
    for( i = 0; i < largo; i++ ){
    spot = i;
    temp = lista[ i ];

        while( ( spot > 0 ) && ( lista[ spot - 1 ] > temp ) ){
            lista[ spot ] = lista[ spot -1 ];
            spot --;
        } 
        lista[ spot ] = temp;
    }
    printf( "Arreglo Ordenado por numero de Empleados" ); // se imprime el array ordenado
    for( i = 0; i <= largo - 1; i=i+1 ){
        printf( "%d ", lista[ i ] );
    }
}

void selectionSort(local_t **matriz, int fila, int col ){
    int i, j, x, min, temp; 
    int largo;
    x=0;
    temp=0;
    largo=fila * col;
        int lista[ largo ];

    for( i = 1; i <= fila; i=i+1 ){
    for( j = 1; j <= col; j=j+1 ){

        lista[ x ] = matriz[i][j].numEmpleados; // se guarda la infromacion de toda la matriz en un array
        x=x+1;
        }
    }
    
    for( i = 0; i < largo; i=i+1 ){
        min = i;
        for( j = i + 1; j < largo; j++ ){
        if( lista[ j ] < lista[ min ] ){
                min = j;
            }
        }
        temp = lista[ i ];
        lista[ i ] = lista[ min ];
        lista[ min ] = temp;
    }
    printf( "Arreglo Ordenado por numero de Empleados" ); // se imprime el array ordenado
    for( i = 0; i <= largo - 1; i=i+1 ){
        printf( "%d ", lista[ i ] );
    }
}

void intercambiar(int arreglo[], int posicion1, int posicion2) {
    int tmp;
    tmp = arreglo[posicion2];
    arreglo[posicion2] = arreglo[posicion1];
    arreglo[posicion1] = tmp;
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
           
        }
        //Se encontraron elementos en posiciones que deben intercambiarse
        if (posIzquierda < posDerecha) {
            
            intercambiar(arreglo, posIzquierda, posDerecha);
            posIzquierda++;
            posDerecha--;
         
       

        }
    } while (posIzquierda <= posDerecha);

    if (arreglo[posDerecha] != valorPivote) {
    
        intercambiar(arreglo, posPrimerElem, posDerecha);

    }
   
    //Retorna la posicion del pivote
    return posDerecha;
}

/* Función que implementa ordenamiento por quicksort. */
void quickSort(int arreglo[], int posIzquierda, int posDerecha) {
    //Posición del pivote
    int posPivote;
    
    if (posIzquierda < posDerecha) {
        //Ordenar elementos para un pivote
        posPivote = partirYOrdenarPivoteInicial(arreglo, posIzquierda,
                posDerecha);
        
        quickSort(arreglo, posIzquierda, posPivote - 1);
       
        quickSort(arreglo, posPivote + 1, posDerecha);
    }
}

void  startQS(local_t **matriz, int fila, int col){
    int i, piso;
    int x=0;
    int lista[fila];

    printf( "Piso a Ordenar" );
    scanf( "%d", piso);

    for( i = 1; i <= fila; i=1+1){
       lista[ x ] = matriz[piso][i].numSucursales; // se guarda la infromacion de toda la matriz en un array
        x=x+1;
    }
    int largo = sizeof( lista ) / sizeof( int );
    
    quickSort( lista, 0, largo-1 );

    printf( "Arreglo Ordenado por numero de Sucursales" );
    for(i = 0; i <= largo - 1; i=i+1){
        printf("%d ", lista[ i ]);
    }
}


void merge(int arreglo[], int posInicial, int posMitad, int posFinal) {
    int tamArrayTemp = (posFinal - posInicial)+1;
    int arregloParcial[tamArrayTemp];
    int indexMitadUno = posInicial;
    int indexMitadDos = posMitad + 1;
    int indexArregloParcial = 0;
    int indexArregloFinal;
    
    while (indexMitadUno <= posMitad && indexMitadDos <= posFinal) {
        //Se hacen las comparaciones para el ordenamiento
        if (arreglo[indexMitadUno] <= arreglo[indexMitadDos]) {
            //Se pone primero en el arreglo parcial el contenido de indexMitadUno
            arregloParcial[indexArregloParcial] = arreglo[indexMitadUno];
            //Se incrementa el index de mitad dos para avanzar en el arreglo
            indexMitadUno++;
        } else {
            //Se pone primero en el arreglo parcial el contenido de indexMitadDos
            arregloParcial[indexArregloParcial] = arreglo[indexMitadDos];
            //Se incrementa el index de mitad dos para avanzar en el arreglo
            indexMitadDos++;
        }
        //Se incrementa el indice del arreglo parcial
        indexArregloParcial++;
    }
    //Se acomodan los elementos que faltan
    while (indexMitadUno <= posMitad) {
        arregloParcial[indexArregloParcial] = arreglo[indexMitadUno];
        indexArregloParcial++;
        indexMitadUno++;
    }
    while (indexMitadDos <= posFinal) {
        arregloParcial[indexArregloParcial] = arreglo[indexMitadDos];
        indexArregloParcial++;
        indexMitadDos++;
    }
    //Se actualizan los valores en el arreglo de entrada
   
    
    for (indexArregloParcial = 0; indexArregloParcial < tamArrayTemp;
            indexArregloParcial++) {
        indexArregloFinal = posInicial + indexArregloParcial;
        arreglo[indexArregloFinal] = arregloParcial[indexArregloParcial];
    }
    
}
/* Funcion que ordena usando el algoritmo de ordenamento merge sort */
void mergeSort(int arreglo[], int posInicial, int posFinal) {

    //Condicion de salida recursion
    //Cuando no se cumple, esto indica que se ha llegado a arrays de un elemento
    
    if (posInicial < posFinal) {
        int posMitad = (posInicial + posFinal) / 2;
        //Se parte el arreglo recursivamente
        //Primera mitad ( en la primera iteracion de la 0 a la posMitad)
        mergeSort(arreglo, posInicial, posMitad);
        //Segunda mitad ( en la primera iteracion de la posMitad+1 a posFinal)
        mergeSort(arreglo, posMitad + 1, posFinal);
        //Mezclar arreglo ( En este procedimiento se ordena el arreglo)
        merge(arreglo, posInicial, posMitad, posFinal);
    }else{
        printf(".....Para la recursion\n");
    }

}
void  startMS(local_t **matriz, int fila, int col){
       int i, piso;
    int x=0;
    int lista[fila];

    printf( "Piso a Ordenar" );
    scanf( "%d", piso);

    for( i = 1; i <= fila; i=1+1){
       lista[ x ] = matriz[piso][i].numInventarios; // se guarda la infromacion de toda la matriz en un array
        x=x+1;
    }
    int largo = sizeof( lista ) / sizeof( int );
    mergeSort( lista,0,largo-1);
  printf( "Arreglo Ordenado por numero de Sucursales" );
    for(i = 0; i <= largo - 1; i=i+1){
        printf("%d ", lista[ i ]);
    }
}
