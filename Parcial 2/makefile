all: Programa

Programa: Usuario Main
	gcc main.o FuncionesCC.o -o Sistema.exe	

Usuario: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c

Main: main.c FuncionesCC.c
	gcc -c main.c
