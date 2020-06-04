#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camionChofer.h"
#include "Camion3.h"
#include "Chofer2.h"

int cargar_Nombrechofer(char nombre_chofer[],int id_camion, eChoferes listachofer[], int tamChofer)
{
    int todoOK = 0;

    for(int i=0; i<tamChofer; i++)
    {
        if(listachofer[i].idchofer==id_camion)
        {
            strcpy(nombre_chofer,listachofer[i].nombre);
            todoOK = 1;
        }
    }

    return todoOK;
}
// mostrar un camion
void mostrar_Camion (eCamiones camion, eChoferes listachofer[],int tam_chofer )
{
    char  nombrechofer [30];
    cargar_Nombrechofer(nombrechofer,camion.idchofer, listachofer,tam_chofer);

    printf("\t %10d  %10s  %10s  %10d  %10dkg. %10d  %10s  %10s   \n\n ",camion.idcamion,
                                                                camion.patente,
                                                                camion.marca,
                                                                camion.anio,
                                                                camion.peso,
                                                                camion.cantidadruedas,
                                                                camion.tipo,
                                                                nombrechofer);
}

// Mostrar Lista de camiones
void Mostrar_Listacamiones(eCamiones listacamion[], int tam, eChoferes listachofer[],int tamchofer)
{
    printf("\n id:   patente:    marca:   anio:   peso:   cant/ruedas:   tipo: \n");
    int i;
        for (i=0;i<tam;i++)
        {
            if (listacamion[i].estado == OCUPADO)
            {
               mostrar_Camion (listacamion[i],listachofer, tamchofer );
            }//else
            //{
              //  printf("nada");
            //}
        }
}
 // alta camion
 void alta_camion (eCamiones listacamion[],int tamcamion, eChoferes listachofer[],int tamchofer)
 {
     int posicion;
     int aux_idcamion;
     int auxid;
     char respuesta;

     eCamiones aux_camion;

     posicion = buscarLibre_camion( listacamion,tamcamion);

     if (posicion != -1)
     {
        Mostrar_Listachoferes(listachofer,tamchofer);
        auxid = buscarid_chofer(listachofer,tamchofer);
        if (auxid ==-1)
        {
            printf("\n No existe el chofer.  \n");
            auxid = buscarid_chofer(listachofer,tamchofer);
        }
            aux_camion.idchofer = listachofer[auxid].idchofer;

        aux_idcamion = generar_Idcamion(listacamion,tamcamion);
        printf ("\n INGRESE PATENTE: \n");
        fflush (stdin);
        fgets  (aux_camion.patente,20,stdin);
        printf ("\n INGRESE MARCA: \n");
        fflush (stdin);
        fgets (aux_camion.marca,10,stdin);
        printf ("\n INGRESE ANIO: \n");
        scanf("%d",&aux_camion.anio);
        printf ("\n INGRESE PESO: \n");
        scanf("%d",&aux_camion.peso);
        printf ("\n INGRESE CANTIDAD DE RUEDAS: \n");
        scanf("%d",&aux_camion.cantidadruedas);
        printf ("\n INGRESE EL TIPO: \n");
        fflush (stdin);
        fgets (aux_camion.tipo,20,stdin);
        aux_camion.idcamion = aux_idcamion;


        printf("\n Desea agregar el Camion? (s/n)\n" );
        fflush (stdin);
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            aux_camion.estado = OCUPADO;
            listacamion[posicion]=aux_camion;
            printf ("\n\t** CAMION CARGADO CON EXITO!!  **\n ");

        }else
        {
            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
        }

     }else
     {
         printf("\n no se encontro libre \n");
     }
 }
 // modificar camion
void modificar_camion (eCamiones listacamion[], int tam,eChoferes listachofer[],int tamchofer)
{

    int id_Posicion;
    int decision;
    char confirmacion;
    char aux_char[20];
    int aux_int;
    eCamiones aux_camion;

    Mostrar_Listacamiones(listacamion,tam,listachofer,tamchofer);
    id_Posicion = buscarid_camion(listacamion,tam);

    if (id_Posicion != -1)
    {
        printf("\n\t*** CAMION ENCONTRADO! ***\n");
        printf("\n \t       id:   patente:      marca:     anio:       peso:   cant/ruedas:   tipo: \n");

        mostrar_UnCamion(listacamion[id_Posicion]);
        aux_camion=listacamion[id_Posicion];

        printf ("\n** INDIQUE EL DATO A CAMBIAR  **\n");
        printf ("\n** 1. TIPO // 2. CHOFER **\n");
        scanf("%d",&decision);

        switch (decision)
        {
            case 1:
            printf ("\n** RE-INGRESE TIPO:  **\n");
            fflush (stdin);
            fgets (aux_char,20,stdin);
            strcpy(aux_camion.tipo,aux_char);
            printf ("\n** Desea efectuar el cambio? (s/n) **\n");
            scanf("%c",&confirmacion);
            if (confirmacion == 's')
            {
                listacamion[id_Posicion] = aux_camion;
                printf ("\n\t** CAMBIO EFECTUADO! **\n");
            }else
            {
                printf ("\n\t** CAMBIO CANCELADO! **\n");
            }

            break;
            case 2:
            Mostrar_Listachoferes(listachofer,tamchofer);
            printf ("\n** RE-INGRESE ID_CHOFER:  **\n");
            fflush (stdin);
            scanf("%d",&aux_int);
            aux_camion.idchofer=aux_int;
            printf ("\n** Desea efectuar el cambio? (s/n) **\n");
            scanf("%s",&confirmacion);
            if (confirmacion == 's')
            {
                listacamion[id_Posicion] = aux_camion;
                printf ("\n\t** CAMBIO EFECTUADO! **\n");
            }else
            {
                printf ("\n\t** CAMBIO CANCELADO! **\n");
            }
            break;
        }
    }


}
// ordenar camion por TIPO
void ordenar_Camion_portipo (eCamiones listacamion[],int tam,eChoferes listachofer[] ,int tamchofer)
{
    int i;
    int j;
    eCamiones aux_camion;
    for (i=0;i<tam-1;i++)
    {
        for(j=0;j<tam;j++)
        {
            if(strcmp(listacamion[i].tipo,listacamion[j].tipo)<0)// 0=iguales / 1=cadena1>cadena2 / -1= cadena1<cadena2
            {
               aux_camion=listacamion[i];
               listacamion[i]=listacamion[j];
               listacamion[j]=aux_camion;
            }
        }
    }
    printf("\n\t** LISTA ORDENADA! **\n");
    Mostrar_Listacamiones(listacamion,tam,listachofer,tamchofer);
}
void mostrar_UnCamion (eCamiones camion)
{
    printf("\t %10d %10s %10s %10d %10dkg. %10d %10s   \n ",camion.idcamion,
                                                                camion.patente,
                                                                camion.marca,
                                                                camion.anio,
                                                                camion.peso,
                                                                camion.cantidadruedas,
                                                                camion.tipo);
}

// listado de choferes con su respectivo listado de camiones  bandera=1 SI HAY autos =0 si NO
void mostrarChofer_yCamion (eChoferes listachofer[],int tamchofer,eCamiones listacamion[],int tamcamion)
{
    int i;
    int j;
    char bandera_tiene_camion;
    for (i=0;i<tamchofer;i++)
    {
        mostrar_Chofer(listachofer[i]);
        bandera_tiene_camion ='n';

       for (j=0;j<tamcamion;j++)
        {
            if (listachofer[i].idchofer == listacamion[j].idchofer)
            {
                mostrar_UnCamion(listacamion[j]);
                   bandera_tiene_camion ='s';
            }
        }

        if (bandera_tiene_camion == 'n')
        {
            printf("\n NO TIENE CAMION ");
        }

    }

}

// lista chofer con mas de un camion
void mostrar_chofercon_camiones(eChoferes listachofer[],int tamcho,eCamiones listacamion[],int tamcamion)
  {
     int cant_camiones[tamcho];
     int a,b,c,d;

     for (a=0;a<tamcho;a++)
     {
         cant_camiones[a]=0;
     }
     for (b=0;b<tamcho;b++)
     {
         for(c=0;c<tamcamion;c++)
         {
             if (listachofer[b].idchofer==listacamion[c].idchofer)
             {
                 cant_camiones[b]++;
             }
         }
     }
     for (d=0;d<tamcho;d++)
     {
         if(listachofer[d].estado == OCUPADO && cant_camiones[d]>1)
         {
             mostrar_Chofer(listachofer[d]);
             printf("\n** Cantidad de camiones: %d**\n",cant_camiones[d]);
         }
     }
  }


void mostrarChoferesConMasDeUnCamion(eChoferes listado[], int tam,eCamiones listadoCamiones[], int tamCamiones)
{

    int cantidadCamionesPorChofer[tam];

    for(int i = 0; i<tam; i++)
    {

        cantidadCamionesPorChofer[i] = 0;
    }
    for(int k = 0; k<tam; k++)
    {
        for(int i = 0; i<tamCamiones; i++)
        {

            if(listado[k].idchofer == listadoCamiones[i].idchofer)
            {

                cantidadCamionesPorChofer[k]++;
                // printf("\nCantidad de camiones: %d",cantidadCamionesPorChofer[i]);
            }
        }
    }

    for(int j = 0; j<tam; j++)
    {
        if(listado[j].estado == OCUPADO && cantidadCamionesPorChofer[j]> 1)
        {
            mostrar_Chofer(listado[j]);
            printf("\nCantidad de camiones: %d\n",cantidadCamionesPorChofer[j]);
        }
    }
}
