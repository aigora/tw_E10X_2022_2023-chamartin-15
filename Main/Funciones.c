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
    FECHA fechas[23];
    DATO hidraulica;
    DATO turbinacion;
    DATO nuclear;
    DATO carbon;
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

int pantalla_fichero(void)
{
    int res;
    printf("\n");
    printf("QUIERE MOSTRARLO EN PANTALLA O GUARDARLO\n");
    printf("EN UN BLOC DE NOTAS?\n\n");
    printf("1 = PANTALLA.\n");
    printf("2 = BLOC DE NOTAS.\n");
    printf("\n");
    do
    {
        printf("ELIJA UNA DE LAS OPCIONES:\n\n");
        scanf("%i",&res);
        printf("\n\n");
    }while((res!=1)&&(res!=2));

    return res;
}

int elegir_fichero(void)
{
    int fichero;

    printf("\n\n");
    printf("Que desea hacer? Elija una de las siguientes opciones:\n\n");
    printf("1 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("2 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("3 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("4 = GENERACION POR TECNOLOGIAS (2021-2022).\n");
    printf("\n");

    do
    {
        printf("Seleccione el documento (1,2...):\n\n");
        scanf("%i",&fichero);
        printf("\n");
    }while((fichero!=1)&&(fichero!=2)&&(fichero!=3)&&(fichero!=4));

    return fichero;
}

int opciones_estadistica(void)
{
    int respuesta;

    printf("\n");
    printf("QUE DESEA HACER?:\n\n");
    printf("1 = MOSTRAR DATOS.\n");
    printf("2 = MAXIMO / MÍNIMO / PROMEDIO DE GENERACION DE UNA TECNOLOGIA.\n");
    printf("3 = COMPARACION.\n");
    printf("4 = ??.\n");
    printf("\n");

    do
    {
        printf("ELIJA UNA DE LAS OPCIONES:\n\n");
        scanf("%i",&respuesta);
        printf("\n");
    }while((respuesta!=1)&&(respuesta!=2)&&(respuesta!=3)&&(respuesta!=4));

    return respuesta;
}

int mostrar_datos(void)
{
    int respuesta;

    printf("\n");
    printf("QUE DATOS QUIERE MOSTRAR?\n\n");
    printf("1 = POR NOMBRE.\n");
    printf("2 = POR FECHA.\n");
    printf("3 = TODOS LOS DATOS.\n");
    printf("4 = ??.\n");
    printf("\n");

    do
    {
        printf("ELIJA UNA DE LAS OPCIONES:\n\n");
        scanf("%i",&respuesta);
        printf("\n");
    }while((respuesta!=1)&&(respuesta!=2)&&(respuesta!=3)&&(respuesta!=4));

    return respuesta;
}

void estadistica(void)
{
    FILE *P;
    DATOS_GEN datos_gen;
    int opcion = elegir_fichero();
    int i=0;
    char c;


    if(opcion==1)
    {

        P = fopen("generacion_por_tecnologias_21_22_puntos.txt","r");

        datos_gen.principio.titulo[100] = "ESTRCUTURA DE LA GENERACION POR TECNOLOGIAS";
        datos_gen.principio.sistema[100] = "NACIONAL";
        datos_gen.principio.magnitudes[100] = "GWh";
        datos_gen.principio.titulo[100] = "\n\n";


        while(fscanf(P,"%c",&c)!=EOF)
        {
            if(c==',')
            {
                break;
            }

        }

        for(i=0;i<24;i++)
        {
            fscanf(P,"%i/%i",&datos_gen.fechas[i].month,&datos_gen.fechas[i].year);
            fscanf(P,"%c",&c);
        }

        //ALMACENAMOS DATOS HIDRAULICA

        fscanf(P,"%[^,]s",datos_gen.hidraulica.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.hidraulica.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS TURBINACION

        fscanf(P,"%[^,]s",datos_gen.turbinacion.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.turbinacion.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS NUCLEAR

        fscanf(P,"%[^,]s",datos_gen.nuclear.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.nuclear.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS CARBON

        fscanf(P,"%[^,]s",datos_gen.carbon.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.carbon.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS MOTORES

        fscanf(P,"%[^,]s",datos_gen.mot_diesel.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.mot_diesel.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS TURBINA GAS

        fscanf(P,"%[^,]s",datos_gen.turbina_gas.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.turbina_gas.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS TURBINA VAPOR

        fscanf(P,"%[^,]s",datos_gen.turbina_vapor.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.turbina_vapor.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS CICLO COMBINADO

        fscanf(P,"%[^,]s",datos_gen.ciclo_combinado.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.ciclo_combinado.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS HIDROEOLICA

        fscanf(P,"%[^,]s",datos_gen.hidroeolica.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.hidroeolica.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS EOLICA

        fscanf(P,"%[^,]s",datos_gen.eolica.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.eolica.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS FOTOVOLTAICA

        fscanf(P,"%[^,]s",datos_gen.solar_fotovoltaica.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.solar_fotovoltaica.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS TERMICA

        fscanf(P,"%[^,]s",datos_gen.solar_termica.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.solar_termica.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS OTRAS RENOVABLES

        fscanf(P,"%[^,]s",datos_gen.otras_renovables.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.otras_renovables.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS COGENERACIÓN

        fscanf(P,"%[^,]s",datos_gen.cogeneracion.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.cogeneracion.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS RESIDUOS NO RENOVABLES

        fscanf(P,"%[^,]s",datos_gen.residuos_no_renovables.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.residuos_no_renovables.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS RESIDUOS RENOVABLES

        fscanf(P,"%[^,]s",datos_gen.residuos_renovables.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.residuos_renovables.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //ALMACENAMOS DATOS GENERACIÓN TOTAL

        fscanf(P,"%[^,]s",datos_gen.generacion_total.nombre);
        for(i=0;i<24;i++)
        {
            fscanf(P,",%f",&datos_gen.generacion_total.magnitud[i]);
        }


        fscanf(P,"%c",&c);

        //GUARDAMOS LOS DATOS EN VECTORES COMUNES

        ////////////////////////////////////

        //PREGUNTAMOS QUE SE DESEA HACER

        opcion = opciones_estadistica();

        if(opcion==1)
        {
            int respuesta;
            int res;
            int res2;

            respuesta = mostrar_datos();

            printf("\n\n");



            if(respuesta==1)
            {
                printf("\n");
                printf("COMO QUIERE MOSTRAR LOS DATOS?\n\n");
                printf("1 = POR NOMBRE.\n");
                printf("2 = POR FECHA.\n");
                printf("3 = TODOS LOS DATOS.\n");
                printf("4 = ??.\n");
                printf("\n");

                do
                {
                    printf("ELIJA UNA DE LAS OPCIONES:\n\n");
                    scanf("%i",&res);
                    printf("\n\n");
                }while((res!=1)&&(res!=2)&&(res!=3)&&(res!=4));

                if(res == 1)
                {
                    res2 = pantalla_fichero();

                    if(res2==1)
                    {
                        printf("Seleccione un tipo de tecnología:\n");

                        printf("1 = Hidraulica.\n");
                        printf("2 = Turbinacion.\n");
                        printf("3 = Nuclear.\n");
                        printf("4 = Carbon.\n");
                        printf("5 = Motores Diesel.\n");
                        printf("6 = Turbinas de Gas.\n");
                        printf("7 = Turbinas de Vapor.\n");
                        printf("8 = Ciclo Combinado.\n");
                        printf("9 = Hidroeolica.\n");
                        printf("10 = Eolica.\n");
                        printf("11 = Solar Fotovoltaica.\n");
                        printf("12 = Solar Termica.\n");
                        printf("13 = Otras Renovables.\n");
                        printf("14 = Cogeneracion.\n");
                        printf("15 = Residuos no renovables.\n");
                        printf("16 = Residuos renovables.\n");

                        do
                        {
                            scanf("%i",&respuesta);
                            printf("\n");
                        }while((respuesta!=1)&&(respuesta!=2)&&(respuesta!=3)&&(respuesta!=4)&&
                           (respuesta!=5)&&(respuesta!=6)&&(respuesta!=7)&&(respuesta!=8)&&
                           (respuesta!=9)&&(respuesta!=10)&&(respuesta!=11)&&(respuesta!=12)&&
                           (respuesta!=13)&&(respuesta!=14)&&(respuesta!=15)&&(respuesta!=16));

                    //MOSTRAMOS DATOS HIDRÁULICA

                    if(respuesta==1)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.hidraulica.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.hidraulica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS TURBINACIÓN BOMBEO

                    if(respuesta==2)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.turbinacion.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.turbinacion.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS NUCLEAR

                    if(respuesta==3)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.nuclear.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.nuclear.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS CARBON

                    if(respuesta==4)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.carbon.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.carbon.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS MOTORES DIESEL

                    if(respuesta==5)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.mot_diesel.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.mot_diesel.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS TURBINA GAS

                    if(respuesta==6)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.turbina_gas.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.turbina_gas.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS TURBINA VAPOR

                    if(respuesta==7)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.turbina_vapor.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.turbina_vapor.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS CICLO COMBINADO

                    if(respuesta==8)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.ciclo_combinado.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.ciclo_combinado.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS HIDROEOLICA

                    if(respuesta==9)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.hidroeolica.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.hidroeolica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS EOLICA

                    if(respuesta==10)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.eolica.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.eolica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS SOLAR FOTOVOLTAICA

                    if(respuesta==11)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.solar_fotovoltaica.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.solar_fotovoltaica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS SOLAR TERMICA

                    if(respuesta==12)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.solar_termica.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.solar_termica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS OTRAS RENOVABLES

                    if(respuesta==13)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.otras_renovables.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.otras_renovables.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS COGENERACIÓN

                    if(respuesta==14)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.cogeneracion.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.cogeneracion.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS RESIDUOS NO RENOVABLES

                    if(respuesta==15)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.residuos_no_renovables.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.residuos_no_renovables.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS RESIDUOS RENOVABLES

                    if(respuesta==16)
                    {
                        printf("\n");
                        printf("MOSTRANDO DATOS:\n\n");

                        printf("%s:",datos_gen.residuos_renovables.nombre);
                        printf("\n");

                        for(i=0;i<23;i++)
                        {
                            printf("%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            printf("%f Gwh\n",datos_gen.residuos_renovables.magnitud[i]);

                        }
                    }
                    }

                    if(res2==2)
                    {
                        FILE *Q;

                        Q=fopen("resultados.txt","w");

                        printf("Seleccione un tipo de tecnología:\n");

                        printf("1 = Hidraulica.\n");
                        printf("2 = Turbinacion.\n");
                        printf("3 = Nuclear.\n");
                        printf("4 = Carbon.\n");
                        printf("5 = Motores Diesel.\n");
                        printf("6 = Turbinas de Gas.\n");
                        printf("7 = Turbinas de Vapor.\n");
                        printf("8 = Ciclo Combinado.\n");
                        printf("9 = Hidroeolica.\n");
                        printf("10 = Eolica.\n");
                        printf("11 = Solar Fotovoltaica.\n");
                        printf("12 = Solar Termica.\n");
                        printf("13 = Otras Renovables.\n");
                        printf("14 = Cogeneracion.\n");
                        printf("15 = Residuos no renovables.\n");
                        printf("16 = Residuos renovables.\n");

                        do
                        {
                            scanf("%i",&respuesta);
                            printf("\n");
                        }while((respuesta!=1)&&(respuesta!=2)&&(respuesta!=3)&&(respuesta!=4)&&
                           (respuesta!=5)&&(respuesta!=6)&&(respuesta!=7)&&(respuesta!=8)&&
                           (respuesta!=9)&&(respuesta!=10)&&(respuesta!=11)&&(respuesta!=12)&&
                           (respuesta!=13)&&(respuesta!=14)&&(respuesta!=15)&&(respuesta!=16));

                    //MOSTRAMOS DATOS HIDRÁULICA

                    if(respuesta==1)
                    {
                        fprintf(Q,"%s:",datos_gen.hidraulica.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.hidraulica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS TURBINACIÓN BOMBEO

                    if(respuesta==2)
                    {

                        printf(Q,"%s:",datos_gen.turbinacion.nombre);
                        printf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.turbinacion.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS NUCLEAR

                    if(respuesta==3)
                    {

                        fprintf(Q,"%s:",datos_gen.nuclear.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.nuclear.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS CARBON

                    if(respuesta==4)
                    {

                        fprintf(Q,"%s:",datos_gen.carbon.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.carbon.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS MOTORES DIESEL

                    if(respuesta==5)
                    {

                        fprintf(Q,"%s:",datos_gen.mot_diesel.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.mot_diesel.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS TURBINA GAS

                    if(respuesta==6)
                    {


                        fprintf(Q,"%s:",datos_gen.turbina_gas.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.turbina_gas.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS TURBINA VAPOR

                    if(respuesta==7)
                    {

                        fprintf(Q,"%s:",datos_gen.turbina_vapor.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.turbina_vapor.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS CICLO COMBINADO

                    if(respuesta==8)
                    {

                        fprintf(Q,"%s:",datos_gen.ciclo_combinado.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.ciclo_combinado.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS HIDROEOLICA

                    if(respuesta==9)
                    {


                        fprintf(Q,"%s:",datos_gen.hidroeolica.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.hidroeolica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS EOLICA

                    if(respuesta==10)
                    {


                        fprintf(Q,"%s:",datos_gen.eolica.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.eolica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS SOLAR FOTOVOLTAICA

                    if(respuesta==11)
                    {

                        fprintf(Q,"%s:",datos_gen.solar_fotovoltaica.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.solar_fotovoltaica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS SOLAR TERMICA

                    if(respuesta==12)
                    {

                        fprintf(Q,"%s:",datos_gen.solar_termica.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.solar_termica.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS OTRAS RENOVABLES

                    if(respuesta==13)
                    {

                        fprintf(Q,"%s:",datos_gen.otras_renovables.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.otras_renovables.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS COGENERACIÓN

                    if(respuesta==14)
                    {

                        fprintf(Q,"%s:",datos_gen.cogeneracion.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.cogeneracion.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS RESIDUOS NO RENOVABLES

                    if(respuesta==15)
                    {

                        fprintf(Q,"%s:",datos_gen.residuos_no_renovables.nombre);
                        fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.residuos_no_renovables.magnitud[i]);

                        }
                    }

                    //MOSTRAMOS DATOS RESIDUOS RENOVABLES

                    if(respuesta==16)
                    {

                       fprintf(Q,"%s:",datos_gen.residuos_renovables.nombre);
                       fprintf(Q,"\n");

                        for(i=0;i<23;i++)
                        {
                            fprintf(Q,"%i/%i ",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.residuos_renovables.magnitud[i]);

                        }
                    }

                    printf("Los datos se han impreso en el bloc de notas\n");
                    printf("llamado 'resultados' en la carpeta en el que se aloja este programa.\n\n");

                    fclose(Q);

                    }




                }



                }

                if(res == 2)
                {

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
