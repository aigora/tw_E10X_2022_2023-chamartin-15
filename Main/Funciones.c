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
    printf("\n");

    do
    {
        printf("ELIJA UNA DE LAS OPCIONES:\n\n");
        scanf("%i",&respuesta);
        printf("\n");
    }while((respuesta!=1)&&(respuesta!=2));

    return respuesta;
}

int volver_menu(void)
{
    int volver;
    printf("\n");
    printf("Desea volver al menú principal?\n");
    printf("1 = Volver al menú principal.\n");
    printf("2 = Salir del programa.\n");

    do
    {
        printf("Seleccione una opción: ");
        scanf("%i",&volver);
        printf("\n");
    }while((volver!=1)&&(volver!=2));

    if(volver==1)
    {
        volver=1;
    }
    if(volver==2)
    {
        volver=0;
    }

    return volver;
}

int estadistica(void)
{
    FILE *P;
    DATOS_GEN datos_gen;
    int opcion = elegir_fichero();
    int i=0;
    char c;
    int volver=1;
    int month,year,j,columna,fila;

    float matriz[16][24]={{4057.346783,4517.602492,3715.416012,2745.019022,2159.483245,2182.252545,2209.4646239999997,1883.2608030000001,1396.698883,1023.215446,1199.445532,2536.803672,2085.857451,1174.9701699999998,1764.806206,1782.053848,1922.3023759999999,1190.985484,1043.519078,972.977692,1153.775681,717.70239,1309.281418,2744.808065},
                                    {320.53138900000005,401.29321899999997,330.794555,153.67968,238.708927,105.706304,115.895307,159.688964,118.198104,232.112394,202.80659899999998,269.908819,215.637741,285.079947,273.84815299999997,336.712619,299.880038,270.92393,216.61759400000003,339.372152,304.810326,385.661431,361.66386700000004,485.359059},
                                    {5199.740516,4358.515107,4833.065002,4197.33293,4373.250552,3684.377943,5119.328941,5151.337803,4890.618221,4748.364457000001,3562.2548070000003,3922.833452,5048.424951,4771.058269,4766.690052,4414.715447,4066.355361,4459.459166000001,5073.1524979999995,5122.0469299999995,4847.367123,4021.440771,4231.577244,5161.212451},
                                    {557.975979,176.26671900000002,242.138946,270.100026,331.93111300000004,473.579232,311.10233,319.182668,477.087202,527.419848,576.437576,719.9263739999999,709.9632190000001,568.629528,705.226125,691.004601,527.154558,833.22046,882.232497,819.592534,632.066719,380.972026,321.469754,693.672984},
                                    {203.759973,160.418085,173.283976,187.547789,178.36229999999998,206.220592,239.57681599999998,258.860338,256.964192,233.57056500000002,203.062243,215.79723800000002,210.125165,185.57552600000002,207.451789,205.100257,215.84438,224.847296,242.769547,245.673515,216.066723,202.310552,192.196854,200.24196799999999},
                                    {28.766271,18.026130000000002,27.904377,24.553476999999997,24.916217,34.119217,40.565981,47.885346,71.402214,46.314807,30.058985,29.066882,34.446764,34.328002,38.861714,34.57236,42.307777,47.734021999999996,79.729885,85.527648,84.42261599999999,79.275334,47.409887000000005,48.856536},
                                    {116.282053,104.960847,100.75825900000001,70.652976,62.41677,33.486942000000006,66.13421000000001,99.64419000000001,113.21021300000001,112.484255,115.10902300000001,112.916219,117.429802,102.630663,114.410944,103.636366,86.849653,60.625902,73.213599,102.417012,110.95399099999999,118.59882,93.771169,122.69665499999999},
                                    {2729.183017,1544.065785,2151.091661,3384.471579,2444.871606,3658.878948,3718.134418,4047.368387,4943.197265,4407.05637,6317.636788,5154.143508,5898.394445,4671.261013,3873.2032000000004,3146.865903,3713.6394849999997,6478.937315,8460.459144999999,8082.027681,7704.900731,7066.859015,4672.406377,4368.592847},
                                    {0.99317,1.226483,1.921443,0.835908,3.2270770000000004,3.002042,3.5782179999999997,2.663478,1.429314,1.8534549999999999,1.1397899999999999,1.227861,1.110916,1.482045,2.1263229999999997,1.752528,1.917174,2.44956,3.562943,3.517675,2.0750949999999997,1.350072,1.1694090000000001,0.367104},
                                    {7101.249123,6294.982856,5606.818805,4095.800569,4785.695033,3684.170619,4284.090513,3747.238495,3234.274816,4359.563921,6421.739529,6910.032613,5414.777160000001,4712.962772,6528.440466,5655.806361,4687.64999,3807.180833,4566.002106,4258.846638,4191.189274,5099.919318,6682.534764,5570.2825920000005},
                                    {848.4030740000001,973.686902,1688.757265,1665.571492,2388.831852,2325.571729,2617.534056,2395.8309,1927.916611,1777.274811,1347.957356,1023.70725,1569.2916839999998,1693.011465,1455.368818,2581.307811,3380.729182,3215.923445,3381.1566589999998,3239.672293,2693.50188,2005.3213540000002,1533.099321,1115.958},
                                    {102.634029,138.18132699999998,355.01542700000005,266.787519,645.5974570000001,655.361716,828.492494,661.4451019999999,447.444657,328.182894,172.42624600000002,103.956001,170.978835,208.192368,120.56837399999999,412.77761,621.247495,534.185927,667.2357830000001,619.95899,437.343279,166.240105,104.768426,59.778183},
                                    {390.590396,365.191889,359.459071,392.274795,390.93192700000003,358.010046,352.713786,410.590237,396.278098,433.04749400000003,434.361576,436.423907,428.663218,374.913003,423.887477,430.376969,397.335983,415.748786,409.34559499999995,383.442347,341.437356,366.964524,364.536652,319.642072},
                                    {2405.236806,1838.16573,2253.823616,2193.285205,2206.3288620000003,2181.2767940000003,2243.226356,2106.285519,2166.255198,2147.907197,2173.751719,2175.103528,2147.921609,2119.152721,2217.055737,1709.641446,1870.643862,1467.3834920000002,1053.7381990000001,779.410997,739.19081,1102.000335,1453.363695,1098.167328},
                                    {182.93208900000002,172.740345,184.342436,178.093968,177.333071,198.273452,205.014809,212.202012,179.817184,187.508,179.26082,181.223116,169.946929,144.54671599999998,183.995605,171.926116,170.585177,155.903954,181.020454,164.769537,139.77665599999997,155.069311,127.558061,134.66801500000003},
                                    {59.850282,69.06586800000001,72.598535,74.357494,59.595065999999996,79.50385,81.91575,81.751572,68.076048,68.765996,80.249832,82.210439,79.365292,72.930818,82.06925100000001,72.848577,79.964147,76.946932,75.73252099999999,65.48815,59.668639000000006,71.884421,67.535659,73.273156}
                                    };
    P = fopen("generacion_por_tecnologias_21_22_puntos.txt","r");



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

    if(opcion==1)
    {
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            printf("FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
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
                            fprintf(Q,"FECHA: %i/%i\t",datos_gen.fechas[i].month,datos_gen.fechas[i].year);
                            fprintf(Q,"%f Gwh\n",datos_gen.residuos_renovables.magnitud[i]);

                        }
                    }

                    printf("Los datos se han impreso en el bloc de notas\n");
                    printf("llamado 'resultados' en la carpeta en la que se aloja este programa.\n\n");

                    fclose(Q);

                    }








                }





                if(respuesta == 2)
                {
                    do
                    {
                        printf("Introduce el mes (Ej:11):\t");
                        scanf("%i",&month);
                        printf("\n");
                        printf("Introduce el ano (2021 o 2022):\t");
                        scanf("%i",&year);
                        printf("\n\n");
                    }while((month>12)||(month<1)||(year<2021)||(year>2022));


                    if(year==2021)
                    {
                        columna=month-1;
                    }
                    if(year==2022)
                    {
                        columna=12+month-1;
                    }

                    printf("\n");
                    printf("Para el mes %i / %i la generacion por tencnologias:\n\n",month,year);

                    for(i=0;i<16;i++)
                    {
                        if(i==0)
                        {
                            printf("%s: ",datos_gen.hidraulica.nombre);
                        }
                        if(i==1)
                        {
                            printf("%s: ",datos_gen.turbinacion.nombre);
                        }
                        if(i==2)
                        {
                            printf("%s: ",datos_gen.nuclear.nombre);
                        }
                        if(i==3)
                        {
                            printf("%s: ",datos_gen.carbon.nombre);
                        }
                        if(i==4)
                        {
                            printf("%s: ",datos_gen.mot_diesel.nombre);
                        }
                        if(i==5)
                        {
                            printf("%s: ",datos_gen.turbina_gas.nombre);
                        }
                        if(i==6)
                        {
                            printf("%s: ",datos_gen.turbina_vapor.nombre);
                        }
                        if(i==7)
                        {
                            printf("%s: ",datos_gen.ciclo_combinado.nombre);
                        }
                        if(i==8)
                        {
                            printf("%s: ",datos_gen.hidroeolica.nombre);
                        }
                        if(i==9)
                        {
                            printf("%s: ",datos_gen.eolica.nombre);
                        }
                        if(i==10)
                        {
                            printf("%s: ",datos_gen.solar_fotovoltaica.nombre);
                        }
                        if(i==11)
                        {
                            printf("%s: ",datos_gen.solar_termica.nombre);
                        }
                        if(i==12)
                        {
                            printf("%s: ",datos_gen.otras_renovables.nombre);
                        }
                        if(i==13)
                        {
                            printf("%s: ",datos_gen.cogeneracion.nombre);
                        }
                        if(i==14)
                        {
                            printf("%s: ",datos_gen.residuos_no_renovables.nombre);
                        }
                        if(i==15)
                        {
                            printf("%s: ",datos_gen.residuos_renovables.nombre);
                        }

                        printf("%f Gwh\n",matriz[i][columna]);
                    }

                }


    }

    int max_min_prom;

     if(opcion==2)
    {
        printf("Que quiere calcular?\n\n");
        printf("1 = Maximo\n");
        printf("2 = Minimo\n");
        printf("3 = Promedio\n");

        do
        {
            printf("Seleccione una opcion:");
            scanf("%i",&max_min_prom);
            printf("\n");
        }while((max_min_prom!=1)&&(max_min_prom!=2)&&(max_min_prom!=3));


    }

    if(opcion==3)
    {
        P = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");
    }

    if(opcion==4)
    {
        P = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");
    }

    fclose(P);
    volver = volver_menu();

    return volver;

    }

}



int extraer_datos(void)
{

}
int consultar_datos(void)
{

}
