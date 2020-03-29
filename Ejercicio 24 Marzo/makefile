all: Programa

Programa: Usuario Main
	gcc main.o persona.o -o Sistema.exe	

Usuario: persona.c persona.h
	gcc -c persona.c

Main: main.c persona.c
	gcc -c main.c
