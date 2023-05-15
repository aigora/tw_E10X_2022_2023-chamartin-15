#include "Funciones.h"

typedef struct
{
    int day;
    int month;
    int year;

}FECHA;



typedef struct
{

    FECHA fechas[23];
    float hidraulica[23];
    float turbinacion[23];
    float nuclear[23];
    float carbon[23];
    float fuel_gas[23];
    float mot_diesel[23];
    float turbina_gas[23];
    float turbina_vapor[23];
    float ciclo_combinado[23];
    float hidroeolica[23];
    float eolica[23];
    float solar_fotovoltaica[23];
    float solar_termica[23];
    float otras_renovables[23];
    float cogeneracion[23];
    float residuos_no_renovables[23];
    float residuos_renovables[23];
    float generacion_total[23];

}DATOS_GEN;

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
        P = fopen("generacion2122.txt","r");
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
    int opcion = elegir_fichero(P),i=0;
    DATOS_GEN datos;

    if(opcion==-1)
    {
        printf("Ha ocurrido un error.\n");
    }
    if(opcion==1)
    {
        printf("TAL.\n\n");


        while(fscanf(P,"%i/%i/%i %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
                     &datos.fechas[i].day,&datos.fechas[i].month,&datos.fechas[i].year,
                     &datos.hidraulica[i],&datos.turbinacion[i],&datos.nuclear[i],
                     &datos.carbon[i],&datos.fuel_gas[i],&datos.mot_diesel[i],
                     &datos.turbina_gas[i],&datos.turbina_vapor[i],&datos.ciclo_combinado[i],
                     &datos.hidroeolica[i],&datos.eolica[i],&datos.solar_fotovoltaica[i],
                     &datos.solar_termica[i],&datos.otras_renovables[i],&datos.cogeneracion[i],
                     &datos.residuos_no_renovables[i],&datos.residuos_renovables[i],&datos.generacion_total[i])!=EOF)
        {
            i++;
        }

        for(i=0;i<=100;i++)
        {
            printf(".");
            printf("%c\t",datos.carbon[i]);
        }

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
