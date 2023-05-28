#include <stdio.h>
#include "Funciones.h"
#include "Funciones.c"



int main ()
{
    int respuesta;
    int volver;

    do
    {
        printf("#####BIENVENID@####\n\n");
    printf("Este programa consta de varias opciones de consulta\n");
    printf("y estadisticas sobre datos extraidos de la pagina web\n");
    printf("de la Red Electrica Espanola (REE).\n\n");

    respuesta = 1;

    if(respuesta==1)
    {
        volver = estadistica();
    }

    }while(volver!=0);


    return 0;

}
