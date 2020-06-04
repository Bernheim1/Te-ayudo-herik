#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Camion3.h"
#include "camionChofer.h"
#include "Chofer2.h"


#define LIBRE 0
#define OCUPADO 1
#define MAXCHOFERES 12
#define MAXCAMIONES 25


int main()
{
    char seguir='s';
    char confirma;

    eChoferes lista_choferes[MAXCHOFERES];
    eCamiones lista_camiones[MAXCAMIONES];

    inicializar_estado (lista_choferes,MAXCHOFERES);
    inicializar_estadocamion (lista_camiones,MAXCAMIONES);

    hardcodeo_Choferes(lista_choferes, MAXCHOFERES);
    hardcodeo_Camiones(lista_camiones, MAXCAMIONES);





    do
    {
        switch (menu())
        {
            case 1:
            Mostrar_Listachoferes(lista_choferes,MAXCHOFERES);
            break;
            case 2:
            Mostrar_Listacamiones( lista_camiones,MAXCAMIONES, lista_choferes,MAXCHOFERES);
            break;
            case 3:
            mostrarChofer_yCamion (lista_choferes,MAXCHOFERES,lista_camiones,MAXCAMIONES);
            break;
            case 4:
            alta_camion (lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 5:
            modificar_camion (lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 6:
            modificar_camion (lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 7:
            alta_chofer(lista_choferes,MAXCHOFERES);
            break;
            case 8:
            baja_Chofer(lista_choferes,MAXCHOFERES);
            break;
            case 9:
            ordenar_Camion_portipo(lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 10:
            modificar_chofer(lista_choferes,MAXCHOFERES);
            break;
            case 11:
            mostrar_chofercon_camiones(lista_choferes,MAXCHOFERES,lista_camiones,MAXCAMIONES);
            break;
            case 12:

            //SALIR
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("\n\nIngrese una opcion valida\n\n");

        }
        system("pause");

    }while(seguir == 's');


    return 0;
}

