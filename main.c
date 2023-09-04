#include <stdio.h>

/*                                 Calonso        Guty          LaRata    */
int estadisticasPersonajes[3][4]={{50,35,70,20},{20,40,95,60},{40,55,87,70}};
/*                            Fuerza, Dureza Física, Dureza Mágica, Inteligencia */

int elegirPersonaje(){
    int personaje;
    printf("Elije tu personaje:\n1:Calonso\n2:Guty\n3.LaRata\n");
    scanf("%d", &personaje);
    personaje -= 1;
    return personaje;
}
int menuPrincipal(int personaje){
    int opc;
    printf("Elija la opción que deseas realizar: \n1.Explorar\n2.Deck\n3.Bestiario\n4.Salir\n");
    scanf("%d", &opc);
    switch (opc){
    case 1:
        /* explorar */
        break;
    case 2:
        /* Deck */
        break;
    case 3:
        /* Bestiario */
        break;
    case 4:
        /* salir */
        break;
    }
}
void menu(){
    int save=0;
    int exit=0;
    int opc;
    int personajeSelect;
    while(exit == 0){
        printf("Elija la opción que deseas realizar: \n");
        if(save == 0){
            printf("1. Nuevo juego\n2.Salir\n");
            scanf("%d", &opc);
            switch (opc){
            case 1:
               personajeSelect = elegirPersonaje();
                jugar(personajeSelect);
                break;
            
            case 2:
                printf("Fin del juego\n");
                exit = 1;
                break;
            }
        }
        else{
            printf("1. Nuevo juego\n2.Continuar\n2.Salir\n");
            scanf("%d",&opc);
            switch (opc){
            case 1:
                personajeSelect = elegirPersonaje();
                jugar(personajeSelect);
                break;
            
            case 2:
                /* continuar debe cargar una partida previamente jugada*/
                break;
            case 3:
                printf("Fin del juego\n");
                exit = 1;
                break;
            }
        }
    }
    
}

int main(){
    menu;
    return 0;
}