#include "operations.h"

// Función para mostrar el menú inicial
int mostrarMenuInicial()
{
    int opcion;

    printf("Menú Inicial\n");
    printf("1. Juego Nuevo\n");
    printf("2. Continuar\n");
    printf("3. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    return opcion;
}

// Función para mostrar la lista de personajes y permitir al jugador elegir uno
int elegirPersonaje(struct Personaje personajes[])
{
    int i, seleccion;

    printf("\nSeleccione un personaje:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%d. %s\n", i + 1, personajes[i].nombre);
    }

    printf("Ingrese el número del personaje seleccionado: ");
    scanf("%d", &seleccion);

    return seleccion - 1; // Restamos 1 para ajustar al índice del array
}

// Función para mostrar información de la zona y opciones correspondientes
void explorarZona(struct Zona *zona) {
    printf("\nExplorando la Zona: %s\n", zona->tipo);

    // Lógica para mostrar información específica de la zona
    // ...

    // Menú de opciones de la zona
    printf("Opciones de la Zona:\n");
    printf("1. Explorar\n");
    printf("2. Mostrar detalles de la Zona\n");
    printf("3. Volver al Menú Principal\n");

    int opcionZona;
    printf("Seleccione una opción: ");
    scanf("%d", &opcionZona);

    switch (opcionZona) {
        case 1: // Explorar
            // Lógica para explorar la zona (puedes llamar a funciones específicas)
            // ...
            break;

        case 2: // Mostrar detalles de la zona
            // Lógica para mostrar detalles adicionales de la zona
            // ...
            break;

        case 3: // Volver al Menú Principal
            printf("Volviendo al Menú Principal.\n");
            // Puedes regresar al menú principal o realizar otras acciones según tus necesidades
            break;

        default:
            printf("Opción no válida.\n");
            break;
    }
}
