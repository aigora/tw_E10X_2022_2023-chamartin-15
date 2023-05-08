#include <stdio.h>



int main ()
{
    int respuesta;

    printf("#####BIENVENID@####\n\n");
    printf("Este programa consta de varias opciones de consulta\n");
    printf("y estadísticas sobre datos extraídos de la página web\n");
    printf("de la Red Electrica Española (REE).\n\n");
    printf("¿Qué quiere realizar?\n\n");
    printf("1 = Estadísica.\n");
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

    return 0;
}
