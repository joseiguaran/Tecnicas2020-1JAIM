
#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Enum que contiene el tipo de local
typedef enum tipoLocal{
    ALMACEN, OFICINA
} tipo_e ;

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int anioApertura;
	tipo_e tipoLocal;
	int numEmpleados;
	int numVentas;
	int numSucursales;
	int numInventarios;
	// Completelo con lo que quiera
} local_t;


// Operaciones disponibles en el programa (Cada una explicada en el archivo.c)

int menu();
local_t** iniciarMatriz(int fila, int col, int tamano[]);
void disponibilidadLocal(local_t **matriz, int tamano[], int fila, int col);
void anadirUsuario(local_t **matriz, int tamano[], int col, int fila);
int sumarAnios (local_t **matriz, int recursion, int piso, int col);
void buscarOficinas(local_t **matriz, int tamano[], int fila, int col);
void  cambiarNombre(local_t **matriz, int tamano[], int col);
void   vaciarLocal(local_t **matriz, int tamano[]);
void insertionSort(local_t **matriz, int fila, int col );
void selectionSort(local_t **matriz, int fila, int col );
void  startQS(local_t **matriz, int fila, int col);
void  startMS(local_t **matriz, int fila, int col);
void quickSort(int arreglo[], int posIzquierda, int posDerecha);
int partirYOrdenarPivoteInicial(int arreglo[], int posPrimerElem,
        int posUltimoElem);
void intercambiar(int arreglo[], int posicion1, int posicion2);
void merge(int arreglo[], int posInicial, int posMitad, int posFinal);
void mergeSort(int arreglo[], int posInicial, int posFinal);
void guardarCentro(local_t **matriz, int fila, int col);
#endif /* FUNCIONESCC_H_ */
