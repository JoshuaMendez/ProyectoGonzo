#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARACTERES 200
#define MAX_MONSTERS 20
#define DATOS_MONSTERS 5
#define MAX_PERSONAJES 1
#define DATOS_PERSONAJES 5
#define MAX_CARTAS 20
#define DATOS_CARTAS 4

/* Estructura Nodo*/
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

/*Estructura lista*/
typedef struct List
{
    int size;
    Node* head;
} List;
typedef struct Monster {
    char nombre[MAX_CARACTERES];
    char descripcion[MAX_CARACTERES];
} Monster;

typedef struct MonsterData {
    int vida;
    int habilidad;
    int recompensa;
} MonsterData;

typedef struct Personaje {
    char nombre[MAX_CARACTERES];
} Personaje;

typedef struct PersonajeData {
    int fuerza;
    int inteligencia;
    int vida;
    int puntosPoder;
    int dinero;
} PersonajeData;

typedef struct Carta {
    char nombre[MAX_CARACTERES];
    char descripcion[MAX_CARACTERES];
} Carta;

typedef struct CartaData {
    int tipo;
    int dano;
    int puntosPoderNecesarios;
} CartaData;

/*Prototipos*/
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
void datosInterfaz(Monster bestiarioText[MAX_MONSTERS], MonsterData bestiarioNum[MAX_MONSTERS],
                   Personaje nombresPersonajes[MAX_PERSONAJES], PersonajeData valoresPersonajes[MAX_PERSONAJES],
                   int enemigoAzar, int cartasTurno[3], Carta cartasText[MAX_CARTAS], CartaData cartasNum[MAX_CARTAS],
                   int cartasUsables[5]);

/*Aqui empieza la implementacion de la lista enlazada*/

List crearListaDeck(){
    List l;
    l.size = 0;
    l.head = NULL;

    return l;
}

Node* crearNodo(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    return n;
}

void append(List* l, int data){
    Node* n = crearNodo(data);

    if (l->size == 0){
        l->head = n;
    }else {
        Node* temp = l->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    l->size += 1;
    
}

void print_list(List list, CartaData* cartasNum, Carta* cartasText) {
	int i = 0;
	Node* tmp = list.head;
    printf("\n---------------------------------------\n");
    printf("Cartas en el Deck:\n");
	while (i < list.size) {
		printf("%d. %s: %s\n", i + 1, cartasText[tmp->data].nombre, cartasText[tmp->data].descripcion);
		tmp = tmp->next;
		i += 1;
	}
    printf("\n---------------------------------------\n");
}

void pop(List* l) {
    if (l->size == 0) {
        return;
    } else if (l->size == 1) {
        free(l->head);
        l->head = NULL;
    } else {
        Node* temp = l->head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    l->size -= 1;
}

void shift(List* l, int data) {
    Node* n = crearNodo(data);
    n->next = l->head;
    l->head = n;
    l->size += 1;
}

void add(List* l, int data, int index) {
    if (index < 0 || index > l->size) {
    } else if (index == 0) {
        shift(l, data);
    } else if (index == l->size) {
        append(l, data);
    } else {
        Node* n = crearNodo(data);
        Node* temp = l->head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        l->size += 1;
        }
}

int info(List l, int pos){
    int count;
    Node* tmp = l.head;
    
    for (count = 0; count < pos; count++){
        tmp = tmp->next;
    }
    return tmp->data;
}

void miniDeck(int cartasNum[5], List l)
{
    int contador = 0;
    int cartaPasada = 0;
    srand(time(NULL));
    while (contador < 5)
    { 
        int cartaAzar = (rand() % l.size) + 0;
        if (cartaAzar != cartaPasada)
        {
            cartasNum[contador] = cartaAzar;
            cartaPasada = cartaAzar;
            ++contador;
        }
    }
}
/*se hace todos los datos que veremmos en la terminal como las cartas el personaje principal etc...*/

void datosInterfaz(Monster bestiarioText[MAX_MONSTERS], MonsterData bestiarioNum[MAX_MONSTERS],
                   Personaje nombresPersonajes[MAX_PERSONAJES], PersonajeData valoresPersonajes[MAX_PERSONAJES],
                   int enemigoAzar, int cartasTurno[3], Carta cartasText[MAX_CARTAS], CartaData cartasNum[MAX_CARTAS],
                   int cartasUsables[5])
{
    printf("\n---------------------------------------\n");
    printf("\n\nEnemigo: %s     Puntos de vida: %d\n\n", bestiarioText[enemigoAzar].nombre, bestiarioNum[enemigoAzar].vida);
    printf("personaje: %s     Puntos de vida: %d    Puntos de poder: %d\n\n", nombresPersonajes[0].nombre, valoresPersonajes[0].vida, valoresPersonajes[0].puntosPoder);
    printf("Opciones:\n");
    if (cartasUsables[0] == 1)
    {
        printf("\n1: %s  (%s)  Dano: %d\n\n", cartasText[cartasTurno[0]].nombre, cartasText[cartasTurno[0]].descripcion, cartasNum[cartasTurno[0]].dano);
    }
    else
    {
        printf("\n----Carta ya usada----\n\n");
    }
    if (cartasUsables[1] == 1)
    {
        printf("\n2: %s  (%s)  Dano: %d\n\n", cartasText[cartasTurno[1]].nombre, cartasText[cartasTurno[1]].descripcion, cartasNum[cartasTurno[1]].dano);
    }
    else
    {
        printf("\n----Carta ya usada----\n\n");
    }
    if (cartasUsables[2] == 1)
    {
        printf("\n3: %s  (%s)  Dano: %d\n\n", cartasText[cartasTurno[2]].nombre, cartasText[cartasTurno[2]].descripcion, cartasNum[cartasTurno[2]].dano);
    }
    else
    {
        printf("\n----Carta ya usada----\n\n");
    }
    if (cartasUsables[3] == 1)
    {
        printf("\n4: %s  (%s)  Dano: %d\n\n", cartasText[cartasTurno[3]].nombre, cartasText[cartasTurno[3]].descripcion, cartasNum[cartasTurno[3]].dano);
    }
    else
    {
        printf("\n----Carta ya usada----\n\n");
    }
    if (cartasUsables[4] == 1)
    {
        printf("\n5: %s  (%s)  Dano: %d\n\n", cartasText[cartasTurno[4]].nombre, cartasText[cartasTurno[4]].descripcion, cartasNum[cartasTurno[4]].dano);
    }
    else
    {
        printf("\n----Carta ya usada----\n\n");
    }
    printf("\n6: Terminar turno\n\nSeleccione una opcion: ");
}



int main()
{
    List l = crearListaDeck();
/*se escogen 6 cartas al azar (Se puede repetir) al deck de las cartas existentes*/ 

    srand(time(NULL));
    int conta6Cartas;
    for (conta6Cartas = 0; conta6Cartas < 6; conta6Cartas++){
        int cAzarDeckIni = (rand() % 19) + 0;
        append(&l, cAzarDeckIni);
    }
    /*Declaracion de todos los enemigos, datos de los enemigos, cartas y datos de las cartas*/
    Monster bestiarioText[MAX_MONSTERS] = {
    {"Oscurovíbora", "Serpiente sombría que envenena con sus mordiscos"},
    {"Esporquimera", "Criatura espinosa que lanza esporas venenosas"},
    {"Sombrío", "Sombra viviente que drena la energía vital"},
    {"Frionda", "Rata gélida que puede congelar con su aliento"},
    {"Fuegozote", "Bestia ardiente que embiste causando llamas"},
    {"Espiritrama", "Ser espectral que confunde con ilusiones"},
    {"Drízar", "No-muerto espinoso que ataca con sus púas"},
    {"Crespúsculo", "Ente oscuro que controla sombras y penumbras"},
    {"Venenácaro", "Insecto venenoso que se arrastra sigilosamente"},
    {"Aquilucente", "Criatura alada con plumaje luminiscente que emite destellos cegadores"}};
    
    MonsterData bestiarioNum[MAX_MONSTERS] = {
        {30, 1, 15}, {20, 1, 45}, {25, 1, 30}, {15, 1, 50}, {35, 1, 20}, {40, 1, 25}, {45, 1, 10}, {30, 1, 40}, {10, 1, 35}, {50, 1, 55}};

    Personaje nombresPersonajes[MAX_PERSONAJES] = {
        {"Canchaman"}};

    PersonajeData valoresPersonajes[MAX_PERSONAJES] = {
        {4, 2, 100, 3, 0}};

    Carta cartasText[MAX_CARTAS] = {
    {"Lluvia de icor", "Crea dagas mágicas que caen del cielo infligen 2 x la inteligencia del personaje"},
    {"Triturador de huesos", "Golpea los brazos y las piernas del enemigo, inflige 1 x la fuerza del personaje"},
    {"Castigo furioso", "Lanza una estocada certera que inflinge 3 x la fuerza del personaje"},
    {"Golpe bajo", "Lanza una patada en el vientre del enemigo, inflinge 4 + la fuerza del personaje"},
    {"Rayo divino", "Un rayo incandescente sobre el enemigo que lo envuelve en llamas e inflige 3 x la inteligencia del personaje"},
    {"Corte astuto", "Realiza un corte preciso que inflige 2.5 x la inteligencia del personaje"},
    {"Tornado de puñetazos", "Lanza una ráfaga de puñetazos que infligen 1.5 x la fuerza del personaje"},
    {"Lluvia de flechas", "Dispara una lluvia de flechas que infligen 3 x la inteligencia del personaje"},
    {"Golpe aplastante", "Realiza un golpe aplastante que inflige 2 x la fuerza del personaje"},
    {"Estallido psíquico", "Libera una explosión psíquica que inflige 1.5 x la inteligencia del personaje"},
    {"Embestida brutal", "Embiste al enemigo con fuerza bruta que inflige 6 + la fuerza del personaje"},
    {"Sombra engañosa", "Se desvanece en las sombras para esquivar el ataque enemigo y contraataca infligiendo 8 + la inteligencia del personaje"},
    {"Inferno ardiente", "Invoca una llamarada ardiente que inflige 15 + x la inteligencia del personaje"},
    {"Desamor profundo", "Envuelve al enemigo en una sensación de desamor que inflige 4 + la fuerza del personaje"},
    {"Rabia desatada", "Entra en un estado de rabia que aumenta la fuerza del personaje en 10 + durante un turno"},
    {"Llamarada infernal", "Invoca una poderosa llamarada de fuego que inflige 2.5 x la destreza del personaje"},
    {"Tormenta de hielo", "Desencadena una tormenta de hielo que inflige 4 x la inteligencia del personaje"},
    {"Martillo divino", "Emplea un martillo divino que inflige 2.2 x la fuerza del personaje"},
    {"Ciclón de sombras", "Crea un ciclón de sombras que inflige 1.8 x la agilidad del personaje"},
    {"Rayo celestial", "Lanza un rayo celestial que inflige 3.5 x la sabiduría del personaje"},
    };

    /**/
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
        
    printf("\n---------------------------------------\n");
    printf("BIENVENIDO A CANCHALAND");
    printf("\n---------------------------------------\n");
    
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
