all: programa
programa: funciones infoPersonajes main
	gcc -o Ejec main.o  funciones.o infoPersonajes.o
Main: main.c
	gcc -c main.c
funciones: funciones.c
	gcc -c funciones.c
funciones: infoPersonajes.c
	gcc -c infoPersonajes.c