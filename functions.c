#include "operations.h"

/*Aqui empieza la implementacion de la lista enlazada*/

List crearListaDeck()
{
    List l;
    l.size = 0;
    l.head = NULL;

    return l;
}
//Complejidad O(1)
Node *crearNodo(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    return n;
}
//Complejidad O(1)
void append(List *l, int data)
{
    Node *n = crearNodo(data);

    if (l->size == 0)
    {
        l->head = n;
    }
    else
    {
        Node *temp = l->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    l->size += 1;
}
//siendo n el tamaño de la lista
//Complejidad O(n)
void print_list(List list, CartaData *cartasNum, Carta *cartasText)
{
    int i = 0;
    Node *tmp = list.head;
    printf("\n---------------------------------------\n");
    printf("Cartas en el Deck:\n");
    while (i < list.size)
    {
        printf("%d. %s: %s\n", i + 1, cartasText[tmp->data].nombre, cartasText[tmp->data].descripcion);
        tmp = tmp->next;
        i += 1;
    }
    printf("\n---------------------------------------\n");
}
//n = tamaño de la lista
// Complejidad O(n)
void pop(List *l)
{
    if (l->size == 0)
    {
        return;
    }
    else if (l->size == 1)
    {
        free(l->head);
        l->head = NULL;
    }
    else
    {
        Node *temp = l->head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    l->size -= 1;
}
// complejidad O(1)
void shift(List *l, int data)
{
    Node *n = crearNodo(data);
    n->next = l->head;
    l->head = n;
    l->size += 1;
}

// complejidad O(1)

void add(List *l, int data, int index)
{
    if (index < 0 || index > l->size)
    {
    }
    else if (index == 0)
    {
        shift(l, data);
    }
    else if (index == l->size)
    {
        append(l, data);
    }
    else
    {
        Node *n = crearNodo(data);
        Node *temp = l->head;
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        l->size += 1;
    }
}

// complejidad O(1)

int info(List l, int pos)
{
    int count;
    Node *tmp = l.head;

    for (count = 0; count < pos; count++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}
// n = a pos
// complejidad O(1)

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
// n = el tamaño del deck
// complejidad O(n)

void tienda(Carta cartasText[MAX_CARTAS], PersonajeData valoresPersonajes[MAX_PERSONAJES])
{

    int d;
    printf("\nEstan a la venta las siguientes cartas: \n");
    for (d = 0; d < 20; d++)
    {
        printf("%s: %s, Precio: %d monedas\n", cartasText[d].nombre, cartasText[d].descripcion, cartasText[d].precio);
    }

    int comprarCartas = 0;
    printf("\nCuantas cartas desea comprar: ");
    scanf("%d", &comprarCartas);

    int seguirComprando = 0;
    while (seguirComprando != 1)
    {

        int valorCarta, cantidadCarta = 0;
        printf("\nIngrese el numero de la carta para comprarla: ");
        scanf("%d", &valorCarta);
        valorCarta--;

        if (valoresPersonajes[numPersonaje].dinero > cartasText[valorCarta].precio)
        {
            printf("La carta ha sido comprada");
            valoresPersonajes[numPersonaje].dinero -= cartasText[valorCarta].precio;
        }
        else
        {
            printf("No tiene suficiente dinero para comprar esa carta");
        }

        printf("\nDesea seguir comprando: \n1. No \n2. Si \nIngrese una opcion: ");
        scanf("%d", &seguirComprando);
    }

    int opcionZonaDescanso = 0;
    printf("\nMenu de la Zona de Descanso: \n1. Recuperar \n3. Guardar \n4. Seguir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcionZonaDescanso);
}
// n = veces que decida seguir comprando
// complejidad O(n)
void recuperar(PersonajeData valoresPersonajes[MAX_PERSONAJES])
{

    if (valoresPersonajes[numPersonaje].vida < 100)
    {
        valoresPersonajes[numPersonaje].vida = 100;
        printf("\nHa recuperando el total de puntos de vida\n");
    }
    else
    {
        printf("\nTus puntos de vida ya estan al maximo.\n");
    }
}
   
// complejidad O(1)
/*se hace todos los datos que veremmos en la terminal como las cartas el personaje principal etc...*/

void datosInterfaz(Monster bestiarioText[MAX_MONSTERS], MonsterData bestiarioNum[MAX_MONSTERS],
                   Personaje nombresPersonajes[MAX_PERSONAJES], PersonajeData valoresPersonajes[MAX_PERSONAJES],
                   int enemigoAzar, int cartasTurno[3], Carta cartasText[MAX_CARTAS], CartaData cartasNum[MAX_CARTAS],
                   int cartasUsables[5], int numPersonaje)
{
    printf("\n---------------------------------------\n");
    printf("\n\nEnemigo: %s     Puntos de vida: %d\n\n", bestiarioText[enemigoAzar].nombre, bestiarioNum[enemigoAzar].vida);
    printf("personaje: %s     Puntos de vida: %d    Puntos de poder: %d\n\n", nombresPersonajes[numPersonaje].nombre, valoresPersonajes[0].vida, valoresPersonajes[0].puntosPoder);
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
//complejidad O(1)