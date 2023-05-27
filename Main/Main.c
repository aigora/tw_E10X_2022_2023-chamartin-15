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
    printf("de la Red Electrica Española (REE).\n\n");
    printf("¿Qué quiere realizar?\n\n");
    printf("1 = Estadisica.\n");
    printf("2 = Extraer datos.\n");
    printf("3 = Consultar datos.\n");
    printf("4 = ...\n");
    printf("\n");

    do
    {
        printf("Seleccione una de las opciones (numero) acorde a sus requerimientos: (1/2/3/4...)\n\n");
        scanf("%i",&respuesta);
        printf("\n");

    }while((respuesta!=1)&&(respuesta!=2)&&(respuesta!=3)&&(respuesta!=4));

    if(respuesta==1)
    {
        printf("Caso 1.");
        volver = estadistica();
    }
    if(respuesta==2)
    {
        printf("Caso 2.");
        volver = extraer_datos();
    }
    if(respuesta==3)
    {
        printf("Caso 3.");
        volver = consultar_datos();
    }
    if(respuesta==4)
    {
        printf("Caso 4.");
    }

    }while(volver!=0);


    return 0;

}
