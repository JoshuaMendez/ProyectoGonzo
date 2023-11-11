#include "operations.h"

// Función principal
int main()
{
    // Inicialización de datos del juego (arreglo de zonas)
    struct Zona zonas[] = {
        {"Zona de Descanso"},
        {"Zona de Combate"},
        {"Zona de Descanso"},
        {"Zona de Combate"},
        {"Zona de Descanso Final"}
        // Puedes agregar más zonas según sea necesario
    };
    struct Personaje personajes[3] = {
        {"Guerrero", 10, 8, 5, 3},
        {"Mago", 3, 5, 7, 10},
        {"Arquero", 7, 6, 4, 8}};

    int opcion, seleccionPersonaje;

    do
    {
        opcion = mostrarMenuInicial();

        switch (opcion)
        {
        case 1:
            seleccionPersonaje = elegirPersonaje(personajes);
            printf("Has seleccionado a %s.\n", personajes[seleccionPersonaje].nombre);
            // Aquí puedes iniciar la Lógica Central del juego
            break;

        case 2:
            // Lógica para cargar la partida guardada
            printf("Continuando la partida...\n");
            // Aquí puedes iniciar la Lógica Central del juego
            break;

        case 3:
            printf("Saliendo del juego. Hasta luego.\n");
            break;

        default:
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
            break;
        }

    } while (opcion != 3);

    return 0;
}