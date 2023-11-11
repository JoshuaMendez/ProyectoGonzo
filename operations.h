#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#ifndef HEADER_FILE

typedef struct Personaje
{
    char nombre[20];
    int fuerza;
    int durezaFisica;
    int durezaMagica;
    int inteligencia;
};

// Estructura para representar una zona
struct Zona {
    char tipo[100];
    // Otras propiedades de la zona
};

int mostrarMenuInicial();
int elegirPersonaje(struct Personaje personajes[]);
void explorarZona(struct Zona *zona);

#endif