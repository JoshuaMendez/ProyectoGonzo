#include "funciones.h"
#include "infoPersonajes.c"

int main()
{
    List l = crearListaDeck();
/*se escogen 6 cartas al azar (Se puede repetir) al deck de las cartas existentes*/ 

    srand(time(NULL));
    int contarCartas;
    for (contarCartas = 0; contarCartas < 6; contarCartas++){
        int cAzarDeckIni = (rand() % 19) + 0;
        append(&l, cAzarDeckIni);
    }
     CartaData cartasNum[MAX_CARTAS] = {
        {1, 2 * valoresPersonajes[0].inteligencia, 1},
        {0, 1 * valoresPersonajes[0].fuerza, 1},
        {0, 3 * valoresPersonajes[0].fuerza, 1},
        {0, 4 + valoresPersonajes[0].fuerza, 1},
        {1, 16 + valoresPersonajes[0].inteligencia, 2},
        /*aqui se repiten las cartas*/
        {1, 2 * valoresPersonajes[0].inteligencia, 1},
        {0, 1 * valoresPersonajes[0].fuerza, 1},
        {0, 3 * valoresPersonajes[0].fuerza, 1},
        {0, 4 + valoresPersonajes[0].fuerza, 1},
        {1, 16 + valoresPersonajes[0].inteligencia, 2},
        {1, 2 * valoresPersonajes[0].inteligencia, 1},
        {0, 1 * valoresPersonajes[0].fuerza, 1},
        {0, 3 * valoresPersonajes[0].fuerza, 1},
        {0, 4 + valoresPersonajes[0].fuerza, 1},
        {1, 16 + valoresPersonajes[0].inteligencia, 2},
        {1, 2 * valoresPersonajes[0].inteligencia, 1},
        {0, 1 * valoresPersonajes[0].fuerza, 1},
        {0, 3 * valoresPersonajes[0].fuerza, 1},
        {0, 4 + valoresPersonajes[0].fuerza, 1},
        {1, 16 + valoresPersonajes[0].inteligencia, 2}};
   
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("             BIENVENIDO AL PLANETA MORADO                    ");
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    
        /*inicio de la logica*/
    int ejecutarJuego = 1;
    while (ejecutarJuego == 1){
        valoresPersonajes[0].vida = 100;
        int respuestaMenu;
        printf("\n---------------------------------------\n");
        printf("Elija una opcion:\n\n1. Explorar\n2. Deck\n3. Bestiario\n4. Salir\n");
        printf("\n---------------------------------------\n");
        scanf("%d", &respuestaMenu);
        printf("\n---------------------------------------\n\n");
        if (respuestaMenu == 1){
    
        srand(time(NULL));
        int enemigoAzar;
        int enemigoencontrado = 0;
        while (enemigoencontrado == 0){
            int enemigoAzar = (rand() % 9) + 0;
            if (bestiarioNum[enemigoAzar].vida <= 0)enemigoencontrado = 0;
            else(enemigoencontrado = 1);
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
            valoresPersonajes[0].puntosPoder = 3;
            while (terminarHabilidades != 1)
            {
                int noPuntosP = 0;
                datosInterfaz(bestiarioText, bestiarioNum, nombresPersonajes, valoresPersonajes, enemigoAzar, cartasTurno, cartasText, cartasNum, cartasUsables);
                printf("\n---------------------------------------\n");
                printf("\n\nEl enemigo te hará %d de dano al cabo de tu turno\n\n", danoEnemigo);
                printf("\n---------------------------------------\n");
                scanf("%d", &seleccionCarta);
                {
                    if (seleccionCarta == 1 && cartasUsables[0] == 1)
                    {
                        if (valoresPersonajes[0].puntosPoder - cartasNum[cartasTurno[0]].puntosPoderNecesarios >= 0)
                        {
                            valoresPersonajes[0].puntosPoder -= cartasNum[cartasTurno[0]].puntosPoderNecesarios;
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
                        if (valoresPersonajes[0].puntosPoder - cartasNum[cartasTurno[1]].puntosPoderNecesarios >= 0)
                        {
                            valoresPersonajes[0].puntosPoder -= cartasNum[cartasTurno[1]].puntosPoderNecesarios;
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
                        if (valoresPersonajes[0].puntosPoder - cartasNum[cartasTurno[2]].puntosPoderNecesarios >= 0)
                        {
                            valoresPersonajes[0].puntosPoder -= cartasNum[cartasTurno[2]].puntosPoderNecesarios;
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
                        if (valoresPersonajes[0].puntosPoder - cartasNum[cartasTurno[3]].puntosPoderNecesarios >= 0)
                        {
                            valoresPersonajes[0].puntosPoder -= cartasNum[cartasTurno[3]].puntosPoderNecesarios;
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
                        if (valoresPersonajes[0].puntosPoder - cartasNum[cartasTurno[4]].puntosPoderNecesarios >= 0)
                        {
                            valoresPersonajes[0].puntosPoder -= cartasNum[cartasTurno[4]].puntosPoderNecesarios;
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
                        valoresPersonajes[0].dinero += bestiarioNum[enemigoAzar].recompensa;
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
                        while (elejirNuevaC == 1){
                        scanf("%d", &eleccionCartaNueva);
                        elejirNuevaC = 0;
                        if (eleccionCartaNueva == 1)append(&l, cartasNuevas[0]);
                        else if (eleccionCartaNueva == 2)append(&l, cartasNuevas[1]);
                        else if (eleccionCartaNueva == 3)append(&l, cartasNuevas[2]);
                        else elejirNuevaC = 1;
                        }
                    }
                }
            }
            valoresPersonajes[0].vida -= danoEnemigo;
            if (valoresPersonajes[0].vida <= 0)
            {
                printf("\n---------------------------------------\n");
                printf("¡Ha muerto el personaje principal!\n");
                printf("\n---------------------------------------\n");
                terminarBucle = 1;
                terminarHabilidades = 1;
            }
        }
            
        }else if (respuestaMenu == 2){
            print_list(l, cartasNum, cartasText);
        }else if (respuestaMenu == 3){
            int recorreMons;
            char estadoMons;
            printf("\n---------------------------------------\n");
            printf("Mounstruos:\n");
            for (recorreMons = 0; recorreMons < 20; recorreMons++){
                if (bestiarioNum[recorreMons].vida <= 0)printf("%d. %s: %s\nEstado: Muerto\n\n", recorreMons + 1, bestiarioText[recorreMons].nombre, bestiarioText[recorreMons].descripcion);
                else printf("%d. %s: %s\nEstado: Vivo\n\n", recorreMons + 1, bestiarioText[recorreMons].nombre, bestiarioText[recorreMons].descripcion);
            }
            printf("\n---------------------------------------\n");
        }else if (respuestaMenu == 4){
            printf("SALIENDO...\n");
            printf("\n---------------------------------------\n");
            ejecutarJuego = 0;
        }else printf("Opcion no existente");
        
    }
    
    return 0;
}
