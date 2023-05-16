#include "Funciones.h"

typedef struct
{
    int month;
    int year;

}FECHA;

typedef struct
{
    char titulo[100];
    char sistema[100];
    char magnitudes[100];
    char separador[100];
}CABECERA;

typedef struct
{
    char nombre[100];
    FECHA fecha[23];
    float magnitud[23];
}DATO;

typedef struct
{

    CABECERA principio;
    DATO fechas;
    DATO hidraulica;
    DATO turbinacion;
    DATO nuclear;
    DATO carbon;
    DATO fuel_gas;
    DATO mot_diesel;
    DATO turbina_gas;
    DATO turbina_vapor;
    DATO ciclo_combinado;
    DATO hidroeolica;
    DATO eolica;
    DATO solar_fotovoltaica;
    DATO solar_termica;
    DATO otras_renovables;
    DATO cogeneracion;
    DATO residuos_no_renovables;
    DATO residuos_renovables;
    DATO generacion_total;

}DATOS_GEN;

int elegir_fichero(void)
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

    return fichero;
}

void estadistica(void)
{
    FILE *P;
    int opcion = elegir_fichero();
    int columnas=23;
    int i=0;
    DATOS_GEN datos_gen;
    int nLINEAS=0;
    int nCOLUMNAS=0;
    char c;

    datos_gen.principio.titulo[100] = "ESTRCUTURA DE LA GENERACION POR TECNOLOGIAS";
    datos_gen.principio.sistema[100] = "NACIONAL";
    datos_gen.principio.magnitudes[100] = "GWh";
    datos_gen.principio.titulo[100] = "\n\n";

    if(opcion==-1)
    {
        printf("Ha ocurrido un error.\n");
    }
    if(opcion==1)
    {
        printf("TAL.\n\n");

        P = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");

        while(fscanf(P,"%c",&c)!=EOF)
        {
            if(c=='\n')
            {
                nLINEAS++;
            }
        }

        while(fscanf(P,"%10[^,],",&c)!=EOF)
        {
            if(c=='\n')
            {
                nLINEAS++;
            }
        }


        printf("TIENE %i LINEAS\n\n",nLINEAS);
        printf("TIENE %i COLUMNAS\n\n",nCOLUMNAS);



        fclose(P);



    }
    if(opcion==2)
    {
        P = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");
    }
    if(opcion==3)
    {
        P = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");
    }
    if(opcion==4)
    {
        P = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");
    }
}
void extraer_datos(void)
{

}
void consultar_datos(void)
{

}
