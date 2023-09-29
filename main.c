#include "operations.h"

int main()
{
    //Se crean los personajes
    struct Personaje GonzoCalonso;
    strcpy(GonzoCalonso.nombre, "Gonzo Calonso");
    GonzoCalonso.fuerza = 60;
    GonzoCalonso.durezaFisica = 70;
    GonzoCalonso.durezaMagica = 35;
    GonzoCalonso.inteligencia = 10;
    
    struct Personaje Gutifarra;
    strcpy(Gutifarra.nombre, "Gutifarra");
    Gutifarra.fuerza = 30;
    Gutifarra.durezaFisica = 40;
    Gutifarra.durezaMagica = 75;
    Gutifarra.inteligencia = 70;
    
    struct Personaje LaRata;
    strcpy(LaRata.nombre, "La Rata");
    LaRata.fuerza = 85;
    LaRata.durezaFisica = 70;
    LaRata.durezaMagica = 35;
    LaRata.inteligencia = 90;
    
    //Se crean los enemigos
    

    return 0;
}