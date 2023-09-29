all: programa
programa: main functions 
	gcc -o Ejec main.o functions.o
main: main.c
	gcc -c main.c
functions: functions.c
	gcc -c functions.c