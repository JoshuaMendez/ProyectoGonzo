all: programa
programa: funciones Main
	gcc -o Ejec Main.o  functions.o
Main: Main.c
	gcc -c Main.c
funciones: funciones.c
	gcc -c functions.c