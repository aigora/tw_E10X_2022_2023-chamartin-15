#include "Funciones.h"

int elegir_fichero(FILE *P)
{
    int fichero;

    printf("\n");
    printf("ELECCIÓN DE DOCUMENTO:\n\n");
    printf("1 = GENERACIÓN POR TECNOLOGÍAS (2021-2022).\n");
    printf("2 = GENERACIÓN POR TECNOLOGÍAS (2021-2022).\n");
    printf("3 = GENERACIÓN POR TECNOLOGÍAS (2021-2022).\n");
    printf("4 = GENERACIÓN POR TECNOLOGÍAS (2021-2022)\n");
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
                return -1;
            }
        else
            {
                printf("Fichero abierto correctamente.\n");
                return 0;
            }
    }
    if(fichero==2)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                return -1;
            }
        else
            {
                printf("Fichero abierto correctamente.\n");
                return 0;
            }
    }
    if(fichero==3)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                return -1;
            }
        else
            {
                printf("Fichero abierto correctamente.\n");
                return 0;
            }
    }
    if(fichero==4)
    {
        P = fopen("generacion2122.csv","r");
        if (P == NULL)
            {
                printf("Error al abrir el fichero.\n");
                return -1;
            }
        else
            {
                printf("Fichero abierto correctamente.\n");
                return 0;
            }
    }

    return fichero;
}

void estadistica(void)
{
    FILE *P;
    elegir_fichero(P);
}
void extraer_datos(void)
{

}
void consultar_datos(void)
{

}
