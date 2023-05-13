#include "Funciones.h"

typedef struct
{
    char nombre1[1000];
    char nombre2[1000];
    char separador[1000];
    char fecha[1000];

}cabecera;

int elegir_fichero(FILE *P)
{
    int fichero;

    printf("\n");
    printf("ELECCION DE DOCUMENTO:\n\n");
    printf("1 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("2 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("3 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("4 = GENERACION POR TECNOLOGIAS (2021-2022)\n");
    printf("\n");

    do
    {
        printf("Seleccione el documento (1,2...):\n\n");
        scanf("%i",&fichero);
        printf("\n");
    }while((fichero!=1)&&(fichero!=2)&&(fichero!=3)&&(fichero!=4));


    if(fichero==1)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                fichero = -1;
            }
        else
            {
                fichero =  1;
            }
    }
    if(fichero==2)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                fichero = -1;
            }
        else
            {
                fichero = 2;
            }
    }
    if(fichero==3)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                fichero = -1;
            }
        else
            {
                fichero = 3;
            }
    }
    if(fichero==4)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                fichero = -1;
            }
        else
            {
                fichero = 4;
            }
    }

    return fichero;
}

void estadistica(void)
{
    FILE *P;
    int opcion = elegir_fichero(P);

    if(opcion==-1)
    {
        printf("Ha ocurrido un error.\n");
    }
    if(opcion==1)
    {
        printf("TAL.\n");

        P =
    }
    if(opcion==2)
    {

    }
    if(opcion==3)
    {

    }
    if(opcion==4)
    {

    }
}
void extraer_datos(void)
{

}
void consultar_datos(void)
{

}
