#include "operations.h"

int main()
{
    system("clear"); // Linux
    // system("cls"); // Windows
    printf("\n");
    printf("    ,o888888o.           .8.          8 8888          8 8888 `8.`8888.      ,8'  ,o888888o.     8 888888888o.   8 8888     ,88' \n");
    printf("   8888     `88.        .888.         8 8888          8 8888  `8.`8888.    ,8'. 8888     `88.   8 8888    `88.  8 8888    ,88'  \n");
    printf(",8 8888       `8.      :88888.        8 8888          8 8888   `8.`8888.  ,8',8 8888       `8b  8 8888     `88  8 8888   ,88'   \n");
    printf("88 8888               . `88888.       8 8888          8 8888    `8.`8888.,8' 88 8888        `8b 8 8888     ,88  8 8888  ,88'    \n");
    printf("88 8888              .8. `88888.      8 8888          8 8888     `8.`88888'  88 8888         88 8 8888.   ,88'  8 8888 ,88'     \n");
    printf("88 8888             .8`8. `88888.     8 8888          8 8888      `8. 8888   88 8888         88 8 888888888P'   8 8888 88'      \n");
    printf("88 8888            .8' `8. `88888.    8 8888          8 8888       `8 8888   88 8888        ,8P 8 8888`8b       8 888888<       \n");
    printf("`8 8888       .8' .8'   `8. `88888.   8 8888          8 8888        8 8888   `8 8888       ,8P  8 8888 `8b.     8 8888 `Y8.     \n");
    printf("   8888     ,88' .888888888. `88888.  8 8888          8 8888        8 8888    ` 8888     ,88'   8 8888   `8b.   8 8888   `Y8.   \n");
    printf("    `8888888P'  .8'       `8. `88888. 8 888888888888  8 8888        8 8888       `8888888P'     8 8888     `88. 8 8888     `Y8. \n");
    printf("\n");
    printf("Cargando...\n");
    int i, total = 100;
    for (i = 0; i <= total; ++i)
    {
        printf("[");
        for (int j = 0; j < i; ++j)
        {
            printf("=");
        }
        for (int j = i; j < total; ++j)
        {
            printf(" ");
        }
        printf("] %d%%", i);
        printf("\r");   // Devolver el cursor al principio de la línea
        fflush(stdout); // Limpiar el búfer de salida

        usleep(50000); // Dormir durante 100,000 microsegundos (0.1 segundos)
    }
    sleep(1);
    printf("\n");
    system("clear"); // Linux
    // system("cls"); // Windows
    int firstMenu;
    int ejecutarJuego = 1;
    printf("[1] Nuevo Juego\n");
    printf("[2] Continuar Juego\n");
    printf("[3] Salir\n");
    scanf("%d", &firstMenu);
    if (firstMenu == 1)
    {
        system("clear"); // Linux
        // system("cls"); // Windows
        printf("Hola! Escoge un personaje para empezar\n");
        printf("[1] la Rata\n");
        printf("[2] Gutyfarra\n");
        printf("[3] Calrare\n");
        scanf("%d", &numPersonaje);
        numPersonaje--;

        List l = crearListaDeck();
        /*se escogen 6 cartas al azar (Se puede repetir) al deck de las cartas existentes*/

        srand(time(NULL));
        int conta6Cartas;
        for (conta6Cartas = 0; conta6Cartas < 6; conta6Cartas++)
        {
            int cAzarDeckIni = (rand() % 19) + 0;
            append(&l, cAzarDeckIni);
        }
        /*Declaracion de todos los enemigos, datos de los enemigos, cartas y datos de las cartas*/
        Monster bestiarioText[MAX_MONSTERS] = {
            {"Umbraserpiente", "Serpiente de las sombras que envenena con sus mordiscos"},
            {"Esporapúa", "Criatura espinosa que libera esporas venenosas"},
            {"Vivisombra", "Entidad sombría que absorbe la energía vital"},
            {"Gélirata", "Rata gélida capaz de congelar con su aliento"},
            {"Ignisbestia", "Bestia ardiente que embiste y provoca llamas"},
            {"Ilusionéspectro", "Ser espectral que engaña con ilusiones confusas"},
            {"Espinamuerto", "No-muerto espinoso que ataca con sus púas"},
            {"Penumbraente", "Entidad oscura que controla sombras y penumbras"},
            {"Sigilosoácaro", "Insecto venenoso que se desliza sigilosamente"},
            {"Aquilumbrante", "Criatura alada con plumaje luminiscente que emite destellos cegadores"},
            {"Sombrafiera", "Bestia sombría que aterroriza con su presencia"},
            {"Espinafría", "Criatura helada que congela con sus espinas gélidas"},
            {"Vorágineoscuro", "Ente de las sombras que consume la luz"},
            {"Gélidocuervo", "Cuervo gélido que hiela con su graznido"},
            {"Infernífugo", "Bestia ígnea que incinera todo a su paso"},
            {"Ilusionazote", "Espectro ilusorio que confunde con proyecciones engañosas"},
            {"Muertespina", "No-muerto con espinas venenosas que envenena con su contacto"},
            {"Nochedensa", "Entidad oscura que sume todo en una penumbra eterna"},
            {"Sigilosopúa", "Araña sigilosa que teje telarañas venenosas"},
            {"Aquilumina", "Criatura alada resplandeciente que deslumbra con su luz"}};

        MonsterData bestiarioNum[MAX_MONSTERS] = {
            {30, 1, 15}, {20, 1, 45}, {25, 1, 30}, {15, 1, 50}, {35, 1, 20}, {40, 1, 25}, {45, 1, 10}, {30, 1, 40}, {10, 1, 35}, {50, 1, 55}, {30, 1, 1}, {35, 1, 20}, {28, 1, 30}, {40, 1, 50}, {45, 1, 20}, {20, 1, 25}, {26, 1, 10}, {33, 1, 40}, {42, 1, 35}, {50, 1, 55}};

        Personaje nombresPersonajes[MAX_PERSONAJES] = {
            {"la Rata"}, {"Gutyfarra"}, {"Calrare"}};

        PersonajeData valoresPersonajes[MAX_PERSONAJES] = {
            {4, 2, 100, 3, 0}, {5, 1, 100, 2, 0}, {3, 2, 100, 5, 0}};

        Carta cartasText[MAX_CARTAS] = {
            {"Cuchillas de éter", "Genera cuchillas místicas que cortan al enemigo, infligen 2 x la inteligencia del personaje", 10},
            {"Destructor óseo", "Destroza los huesos del enemigo, inflige 1 x la fuerza del personaje", 800},
            {"Ira implacable", "Desata una furia incontrolable que inflige 3 x la fuerza del personaje", 80},
            {"Ataque sigiloso", "Realiza un golpe sigiloso en la zona abdominal del enemigo, inflige 4 + la fuerza del personaje", 321},
            {"Centella divina", "Una centella divina que envuelve al enemigo en llamas e inflige 3 x la inteligencia del personaje", 90},
            {"Tajo astuto", "Ejecuta un tajo astuto que inflige 2.5 x la inteligencia del personaje", 120},
            {"Huracán de puños", "Desata un huracán de puñetazos que inflige 1.5 x la fuerza del personaje", 872},
            {"Flechas certeras", "Dispara flechas certeras que infligen 3 x la inteligencia del personaje", 321},
            {"Impacto contundente", "Libera un impacto contundente que inflige 2 x la fuerza del personaje", 452},
            {"Explosión psíquica", "Detona una explosión psíquica que inflige 1.5 x la inteligencia del personaje", 203},
            {"Embate salvaje", "Embiste al enemigo con furia desatada que inflige 6 + la fuerza del personaje", 102},
            {"Sombra ilusoria", "Desaparece en las sombras para evadir el ataque enemigo y contraataca infligiendo 8 + la inteligencia del personaje", 147},
            {"Inferno ardente", "Invoca una conflagración ardente que inflige 15 + x la inteligencia del personaje", 789},
            {"Desilusión profunda", "Envuelve al enemigo en una sensación de desilusión que inflige 4 + la fuerza del personaje", 963},
            {"Furia desencadenada", "Entra en un estado de furia que aumenta la fuerza del personaje en 10 + durante un turno", 321},
            {"Llamarada ígnea", "Invoca una intensa llamarada de fuego que inflige 2.5 x la destreza del personaje", 645},
            {"Tormenta glacial", "Provoca una tormenta de hielo que inflige 4 x la inteligencia del personaje", 987},
            {"Mazo divino", "Utiliza un mazo divino que inflige 2.2 x la fuerza del personaje", 753},
            {"Vórtice sombrío", "Genera un vórtice sombrío que inflige 1.8 x la agilidad del personaje", 159},
            {"Fulgor celestial", "Desata un fulgor celestial que inflige 3.5 x la sabiduría del personaje", 486}};

        /**/
        CartaData cartasNum[MAX_CARTAS] = {
            {1, 2 * valoresPersonajes[numPersonaje].inteligencia, 1},
            {0, 1 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 3 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 4 + valoresPersonajes[numPersonaje].fuerza, 1},
            {1, 16 + valoresPersonajes[numPersonaje].inteligencia, 2},
            /*aqui se repiten las cartas*/
            {1, 2 * valoresPersonajes[numPersonaje].inteligencia, 1},
            {0, 1 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 3 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 4 + valoresPersonajes[numPersonaje].fuerza, 1},
            {1, 16 + valoresPersonajes[numPersonaje].inteligencia, 2},
            {1, 2 * valoresPersonajes[numPersonaje].inteligencia, 1},
            {0, 1 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 3 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 4 + valoresPersonajes[numPersonaje].fuerza, 1},
            {1, 16 + valoresPersonajes[numPersonaje].inteligencia, 2},
            {1, 2 * valoresPersonajes[numPersonaje].inteligencia, 1},
            {0, 1 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 3 * valoresPersonajes[numPersonaje].fuerza, 1},
            {0, 4 + valoresPersonajes[numPersonaje].fuerza, 1},
            {1, 16 + valoresPersonajes[numPersonaje].inteligencia, 2}};

        printf("\n---------------------------------------\n");
        printf("<~~~~ Welcome to CaliYork %s ~~~~>", nombresPersonajes[numPersonaje].nombre);
        printf("\n---------------------------------------\n");

        /*inicio de la logica*/
        while (ejecutarJuego == 1)
        {
            valoresPersonajes[numPersonaje].vida = 100;
            int respuestaMenu;
            printf("\n---------------------------------------\n");
            printf("Elija una opcion:\n\n1. Explorar\n2. Deck\n3. Bestiario\n4. Salir\n");
            printf("\n---------------------------------------\n");
            scanf("%d", &respuestaMenu);
            printf("\n---------------------------------------\n\n");
            if (respuestaMenu == 1)
            {
                int answerDescanso = 0, flagBB = 0;
                do
                {
                    printf("* -- Zona de Descanso -- *\n");
                    printf("Quieres combatir?\n");
                    printf("[1] Si     [2] No\n");

                    scanf("%d", &answerDescanso);

                    if (answerDescanso == 1)
                    {
                        flagBB = 1;
                    }

                } while (flagBB == 0);

                printf("* -- Zona de Combate -- *\n");
                srand(time(NULL));
                int enemigoAzar = rand() % 9 + 0;
                int answerCombate;
                int flagBandera = 1;
                do
                {
                    printf("Tu enemigo es -> %s\n", bestiarioText[enemigoAzar].nombre);
                    printf("Elige una opción:\n");
                    printf("[1] Iniciar Combate\n");
                    printf("[2] Cambiar Enemigo\n");

                    scanf("%d", &answerCombate);

                    switch (answerCombate)
                    {
                    case 1:
                        flagBandera = 0;
                        break;
                    case 2:
                        srand(time(NULL));
                        enemigoAzar = rand() % 9 + 0;
                        flagBandera = 0;
                        break;
                    default:
                        printf("Opción no válida.\n");
                    }

                } while (flagBandera == 1);

                int enemigoencontrado = 0;
                while (enemigoencontrado == 0)
                {
                    if (bestiarioNum[enemigoAzar].vida <= 0)
                        enemigoencontrado = 0;
                    else
                        (enemigoencontrado = 1);
                }

                int terminarBucle = 0;
                int cartasTurno[5];
                int seleccionCarta;
                while (terminarBucle != 1)
                {
                    int cartasUsables[] = {1, 1, 1, 1, 1};
                    miniDeck(cartasTurno, l);
                    int terminarHabilidades = 0;
                    srand(time(NULL));
                    int danoEnemigo = (rand() % 60) + 1;
                    valoresPersonajes[numPersonaje].puntosPoder = 3;
                    while (terminarHabilidades != 1)
                    {
                        int noPuntosP = 0;
                        datosInterfaz(bestiarioText, bestiarioNum, nombresPersonajes, valoresPersonajes, enemigoAzar, cartasTurno, cartasText, cartasNum, cartasUsables, numPersonaje);
                        printf("\n---------------------------------------\n");
                        printf("\n\nEl enemigo te hará %d de dano al cabo de tu turno\n\n", danoEnemigo);
                        printf("\n---------------------------------------\n");
                        scanf("%d", &seleccionCarta);
                        {
                            if (seleccionCarta == 1 && cartasUsables[0] == 1)
                            {
                                if (valoresPersonajes[numPersonaje].puntosPoder - cartasNum[cartasTurno[0]].puntosPoderNecesarios >= 0)
                                {
                                    valoresPersonajes[numPersonaje].puntosPoder -= cartasNum[cartasTurno[0]].puntosPoderNecesarios;
                                    bestiarioNum[enemigoAzar].vida -= cartasNum[cartasTurno[0]].dano;
                                    cartasUsables[0] = 0;
                                }
                                else
                                {
                                    noPuntosP = 1;
                                }
                            }
                            else if (seleccionCarta == 2 && cartasUsables[1] == 1)
                            {
                                if (valoresPersonajes[numPersonaje].puntosPoder - cartasNum[cartasTurno[1]].puntosPoderNecesarios >= 0)
                                {
                                    valoresPersonajes[numPersonaje].puntosPoder -= cartasNum[cartasTurno[1]].puntosPoderNecesarios;
                                    bestiarioNum[enemigoAzar].vida -= cartasNum[cartasTurno[1]].dano;
                                    cartasUsables[1] = 0;
                                }
                                else
                                {
                                    noPuntosP = 1;
                                }
                            }
                            else if (seleccionCarta == 3 && cartasUsables[2] == 1)
                            {
                                if (valoresPersonajes[numPersonaje].puntosPoder - cartasNum[cartasTurno[2]].puntosPoderNecesarios >= 0)
                                {
                                    valoresPersonajes[numPersonaje].puntosPoder -= cartasNum[cartasTurno[2]].puntosPoderNecesarios;
                                    bestiarioNum[enemigoAzar].vida -= cartasNum[cartasTurno[2]].dano;
                                    cartasUsables[2] = 0;
                                }
                                else
                                {
                                    noPuntosP = 1;
                                }
                            }
                            else if (seleccionCarta == 4 && cartasUsables[3] == 1)
                            {
                                if (valoresPersonajes[numPersonaje].puntosPoder - cartasNum[cartasTurno[3]].puntosPoderNecesarios >= 0)
                                {
                                    valoresPersonajes[numPersonaje].puntosPoder -= cartasNum[cartasTurno[3]].puntosPoderNecesarios;
                                    bestiarioNum[enemigoAzar].vida -= cartasNum[cartasTurno[3]].dano;
                                    cartasUsables[3] = 0;
                                }
                                else
                                {
                                    noPuntosP = 1;
                                }
                            }
                            else if (seleccionCarta == 5 && cartasUsables[4] == 1)
                            {
                                if (valoresPersonajes[numPersonaje].puntosPoder - cartasNum[cartasTurno[4]].puntosPoderNecesarios >= 0)
                                {
                                    valoresPersonajes[numPersonaje].puntosPoder -= cartasNum[cartasTurno[4]].puntosPoderNecesarios;
                                    bestiarioNum[enemigoAzar].vida -= cartasNum[cartasTurno[4]].dano;
                                    cartasUsables[4] = 0;
                                }
                                else
                                {
                                    noPuntosP = 1;
                                }
                            }
                            else if (seleccionCarta == 6)
                            {
                                terminarHabilidades = 1;
                            }
                            else
                            {
                                printf("\n---------------------------------------\n");
                                printf("Opción no válida. Ingresa una opción válida\n");
                                printf("\n---------------------------------------\n");
                            }
                            if (noPuntosP == 1)
                            {
                                printf("\n---------------------------------------\n");
                                printf("\n\nNo tienes suficientes puntos de poder\n");
                                printf("\n---------------------------------------\n");
                            }
                            if (bestiarioNum[enemigoAzar].vida <= 0)
                            {
                                printf("\n---------------------------------------\n");
                                printf("¡Has derrotado al enemigo!\n");
                                printf("\nTu recompensa: %d de oro\n", bestiarioNum[enemigoAzar].recompensa);
                                printf("\n---------------------------------------\n");
                                terminarBucle = 1;
                                terminarHabilidades = 1;
                                valoresPersonajes[numPersonaje].dinero += bestiarioNum[enemigoAzar].recompensa;
                                printf("Enhorabuena, elije una de las 3 cartas siguientes par agregarla a tu deck:\n\n");
                                int cartasNuevas[3];
                                int contador = 0;
                                int cartaPasada = 0;
                                srand(time(NULL));
                                while (contador < 3)
                                {
                                    int cartaAzar = (rand() % 19) + 0;
                                    if (cartaAzar != cartaPasada)
                                    {
                                        cartasNuevas[contador] = cartaAzar;
                                        cartaPasada = cartaAzar;
                                        ++contador;
                                    }
                                }
                                printf("\n1. %s: %s\n", cartasText[cartasNuevas[0]].nombre, cartasText[cartasNuevas[0]].descripcion);
                                printf("\n2. %s: %s\n", cartasText[cartasNuevas[1]].nombre, cartasText[cartasNuevas[1]].descripcion);
                                printf("\n3. %s: %s\n", cartasText[cartasNuevas[2]].nombre, cartasText[cartasNuevas[2]].descripcion);
                                printf("\n---------------------------------------\n");
                                int eleccionCartaNueva;
                                int elejirNuevaC = 1;
                                while (elejirNuevaC == 1)
                                {
                                    scanf("%d", &eleccionCartaNueva);
                                    elejirNuevaC = 0;
                                    if (eleccionCartaNueva == 1)
                                        append(&l, cartasNuevas[0]);
                                    else if (eleccionCartaNueva == 2)
                                        append(&l, cartasNuevas[1]);
                                    else if (eleccionCartaNueva == 3)
                                        append(&l, cartasNuevas[2]);
                                    else
                                        elejirNuevaC = 1;
                                }
                            }
                        }
                    }
                    valoresPersonajes[numPersonaje].vida -= danoEnemigo;
                    if (valoresPersonajes[numPersonaje].vida <= 0)
                    {
                        printf("\n---------------------------------------\n");
                        printf("¡Ha muerto el personaje principal!\n");
                        printf("\n---------------------------------------\n");
                        terminarBucle = 1;
                        terminarHabilidades = 1;
                    }
                }
            }
            else if (respuestaMenu == 2)
            {
                print_list(l, cartasNum, cartasText);
            }
            else if (respuestaMenu == 3)
            {
                int recorreMons;
                char estadoMons;
                printf("\n---------------------------------------\n");
                printf("Mounstruos:\n");
                for (recorreMons = 0; recorreMons < 20; recorreMons++)
                {
                    if (bestiarioNum[recorreMons].vida <= 0)
                        printf("%d. %s: %s\nEstado: Muerto\n\n", recorreMons + 1, bestiarioText[recorreMons].nombre, bestiarioText[recorreMons].descripcion);
                    else
                        printf("%d. %s: %s\nEstado: Vivo\n\n", recorreMons + 1, bestiarioText[recorreMons].nombre, bestiarioText[recorreMons].descripcion);
                }
                printf("\n---------------------------------------\n");
            }
            else if (respuestaMenu == 4)
            {
                printf("SALIENDO...\n");
                printf("\n---------------------------------------\n");
                ejecutarJuego = 0;
            }
            else
                printf("Opcion no existente");
        }
    }
    else if (firstMenu == 3)
    {
        printf("SALIENDO...\n");
        printf("\n---------------------------------------\n");
        ejecutarJuego = 0;
    }

    return 0;
}
