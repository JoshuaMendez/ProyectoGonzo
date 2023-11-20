#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARACTERES 200
#define CANTIDAD_MOUSTROS 20
#define DATOS_MONSTERS 5
#define CANTIDAD_PERSONAJES 1
#define DATOS_PERSONAJES 5
#define MAX_CARTAS 20
#define DATOS_CARTAS 4

/* Estructura Nodo*/
typedef struct Node 
{
    int data;            // Datos del nodo
    struct Node* next;   // Puntero al siguiente nodo
} Node;

/* Estructura lista */
typedef struct List
{
    int size;            // Tamaño de la lista
    Node* head;          // Puntero al primer nodo (cabeza)
} List;

typedef struct Monster {
    char nombre[MAX_CARACTERES];        // Nombre del monstruo
    char descripcion[MAX_CARACTERES];   // Descripción del monstruo
} Monster;

typedef struct MonsterData {
    int vida;          // Puntos de vida del monstruo
    int habilidad;     // Poder de habilidad del monstruo
    int recompensa;    // Recompensa al vencer al monstruo
} MonsterData;

typedef struct Personaje {
    char nombre[MAX_CARACTERES];  // Nombre del personaje
} Personaje;

typedef struct PersonajeData {
    int fuerza;          // Fuerza del personaje
    int inteligencia;    // Inteligencia del personaje
    int vida;            // Puntos de vida del personaje
    int puntosPoder;     // Puntos de poder del personaje
    int dinero;          // Dinero del personaje
} PersonajeData;

typedef struct Carta {
    char nombre[MAX_CARACTERES];        // Nombre de la carta
    char descripcion[MAX_CARACTERES];   // Descripción de la carta
} Carta;

typedef struct CartaData {
    int tipo;                 // Tipo de carta
    int dano;                 // Daño infligido por la carta
    int puntosPoderNecesarios;// Puntos de poder necesarios para usar la carta
} CartaData;

/* Prototipos de funciones */
List crearListaDeck();
Node* crearNodo(int data);
void append(List* l, int data);
void print_list(List list, CartaData* cartasNum, Carta* cartasText);
void pop(List* l);
void shift(List* l, int data);
void add(List* l, int data, int index);
int info(List l, int pos);
void saludoInicialJuego();
void miniDeck(int cartasNum[5], List l);
void datosInterfaz(Monster bestiarioText[CANTIDAD_MOUSTROS], MonsterData bestiarioNum[CANTIDAD_MOUSTROS],
                   Personaje nombresPersonajes[CANTIDAD_PERSONAJES], PersonajeData valoresPersonajes[CANTIDAD_PERSONAJES],
                   int enemigoAzar, int cartasTurno[3], Carta cartasText[MAX_CARTAS], CartaData cartasNum[MAX_CARTAS],
                   int cartasUsables[5]);

