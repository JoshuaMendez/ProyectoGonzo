 #include "funciones.h"
 
 /*Declaracion de todos los enemigos, datos de los enemigos, cartas y datos de las cartas*/
 Monster bestiarioText[CANTIDAD_MOUSTROS] = {
    {"Gokuvíbora", "Serpiente guerrera que lanza poderosos ki blasts"},
    {"Vegetquimera", "Criatura con poderosas esporas saiyajin"},
    {"Piccolobscuro", "Entidad oscura que absorbe la energía vital"},
    {"Freezarata", "Rata gélida con un aliento capaz de congelar todo"},
    {"Gohanzote", "Bestia ardiente que embiste con llamas saiyajin"},
    {"Espiritrunks", "Ser espectral que confunde con ilusiones de la espada"},
    {"Cellzar", "No-muerto espinoso que ataca con sus púas regenerativas"},
    {"Dendeúsculo", "Ente oscuro que controla sombras y penumbras curativas"},
    {"Venenkrilín", "Insecto venenoso que se arrastra sigilosamente y realiza sorprendentes ataques"},
    {"AquiluGohan", "Criatura alada con plumaje luminiscente que emite destellos cegadores"}}; 

    
    MonsterData bestiarioNum[CANTIDAD_MOUSTROS] = {
        {30, 1, 15}, {20, 1, 45}, {25, 1, 30}, {15, 1, 50}, {35, 1, 20}, {40, 1, 25}, {45, 1, 10}, {30, 1, 40}, {10, 1, 35}, {50, 1, 55}};

    Personaje nombresPersonajes[CANTIDAD_PERSONAJES] = {
        {"LaRata"}};

    PersonajeData valoresPersonajes[CANTIDAD_PERSONAJES] = {
        {4, 2, 100, 3, 0}};

    Carta cartasText[MAX_CARTAS] = {
    {"Cuchillas Saiyajin", "Desata cuchillas energéticas que caen del cielo e infligen 2 x la energía del guerrero"},
    {"Machaque Óseo", "Golpea las extremidades del enemigo, inflige 1 x la fuerza del personaje"},
    {"Estocada Poderosa", "Realiza una estocada certera que inflige 3 x la fuerza del luchador"},
    {"Golpe Despiadado", "Asesta una patada en el vientre del enemigo, inflige 4 + la fuerza del personaje"},
    {"Fuego Divino", "Invoca un rayo incandescente que envuelve al enemigo en llamas, inflige 3 x la energía del guerrero"},
    {"Corte Astuto", "Realiza un corte preciso que inflige 2.5 x la inteligencia del personaje"},
    {"Tornado de Puños", "Desata una ráfaga de puñetazos que infligen 1.5 x la fuerza del luchador"},
    {"Lluvia de Flechas Místicas", "Dispara una lluvia de flechas místicas que infligen 3 x la energía del guerrero"},
    {"Golpe Aplastante", "Realiza un golpe aplastante que inflige 2 x la fuerza del luchador"},
    {"Explosión Psíquica", "Libera una explosión psíquica que inflige 1.5 x la inteligencia del personaje"},
    {"Embestida Despiadada", "Embiste al enemigo con fuerza bruta, inflige 6 + la fuerza del personaje"},
    {"Engaño de las Sombras", "Se desvanece en las sombras para esquivar el ataque enemigo y contraataca infligiendo 8 + la inteligencia del personaje"},
    {"Inferno Abrasador", "Invoca una llamarada ardiente que inflige 15 + x la inteligencia del personaje"},
    {"Desamor Profundo", "Envuelve al enemigo en una sensación de desamor que inflige 4 + la fuerza del personaje"},
    {"Furia Desatada", "Entra en un estado de furia que aumenta la fuerza del personaje en 10 + durante un turno"},
    {"Llamas Celestiales", "Invoca una poderosa llamarada de fuego que inflige 2.5 x la destreza del personaje"},
    {"Tormenta Glacial", "Desencadena una tormenta de hielo que inflige 4 x la inteligencia del personaje"},
    {"Martillo Divino", "Emplea un martillo divino que inflige 2.2 x la fuerza del luchador"},
    {"Ciclón de Sombras", "Crea un ciclón de sombras que inflige 1.8 x la agilidad del personaje"},
    {"Destello Celestial", "Lanza un destello celestial que inflige 3.5 x la sabiduría del personaje"},
};


    /**/
   
        