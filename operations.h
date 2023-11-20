#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_CARACTERES 200
#define MAX_MONSTERS 20
#define DATOS_MONSTERS 5
#define MAX_PERSONAJES 3
#define DATOS_PERSONAJES 15
#define MAX_CARTAS 20
#define DATOS_CARTAS 4

int numPersonaje;

/* Estructura Nodo*/
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/*Estructura lista*/
typedef struct List
{
    int size;
    Node *head;
} List;
typedef struct Monster
{
    char nombre[MAX_CARACTERES];
    char descripcion[MAX_CARACTERES];
} Monster;

typedef struct MonsterData
{
    int vida;
    int habilidad;
    int recompensa;
} MonsterData;

typedef struct Personaje
{
    char nombre[MAX_CARACTERES];
} Personaje;

typedef struct PersonajeData
{
    int fuerza;
    int inteligencia;
    int vida;
    int puntosPoder;
    int dinero;
} PersonajeData;

typedef struct Carta
{
    char nombre[MAX_CARACTERES];
    char descripcion[MAX_CARACTERES];
    int precio = 0;
} Carta;

typedef struct CartaData
{
    int tipo;
    int dano;
    int puntosPoderNecesarios;
} CartaData;

/*Prototipos*/
List crearListaDeck();
Node *crearNodo(int data);
void append(List *l, int data);
void print_list(List list, CartaData *cartasNum, Carta *cartasText);
void pop(List *l);
void shift(List *l, int data);
void add(List *l, int data, int index);
int info(List l, int pos);
void miniDeck(int cartasNum[5], List l);
void datosInterfaz(Monster bestiarioText[MAX_MONSTERS], MonsterData bestiarioNum[MAX_MONSTERS],
                   Personaje nombresPersonajes[MAX_PERSONAJES], PersonajeData valoresPersonajes[MAX_PERSONAJES],
                   int enemigoAzar, int cartasTurno[3], Carta cartasText[MAX_CARTAS], CartaData cartasNum[MAX_CARTAS],
                   int cartasUsables[5], int numPersonaje);