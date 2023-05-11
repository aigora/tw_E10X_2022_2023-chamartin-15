#include "Funciones.h"

int elegir_fichero(void)
{
    FILE *P;
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

    return fichero;
}

void estadistica(void)
{
    int
    switch()
}
void extraer_datos(void)
{

}
void consultar_datos(void)
{

}
