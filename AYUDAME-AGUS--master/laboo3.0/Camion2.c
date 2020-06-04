#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Camion3.h"
#include "camionChofer.h"

void hardcodeo_Camiones(eCamiones listacamion[], int tam)
{


    char patente[10][10]= {"027-lpe","039-nri","456-lia","123-ias","853-ias","567-ago","103-mvt","451-tbe","172-rty","547-aoq"};
    char marca[10][10]= {"ford","ford","fiat","fiat","wv","ford","ford","ford","ford","ford"};
    int anio[10] = {2000,2000,2001,2001,2010,2005,2005,2015,2020,2020};
    int peso[10]= {1239,2345,3456,4567,5678,6789,7235,2643,1287,9672};
    int cantidadruedas[10]= {4,6,4,4,8,4,4,6,4,10};
    char tipo [10][20]= {"cortaDistancia","largaDistancia","largaDistancia","cortaDistancia","largaDistancia","cortaDistancia","cortaDistancia","largaDistancia","largaDistancia","largaDistancia"};
    int idchofer[10]= {1000,1000,1001,1001,1002,1003,1003,1004,1004,1004};
    int estados [10] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
    int id_ = generar_Idcamion ( listacamion, tam);
    int i;

    for (i=0; i<tam; i++)
    {
         strcpy(listacamion[i].patente,patente[i]);
         strcpy(listacamion[i].marca,marca[i]);
         listacamion[i].anio = anio[i];
         listacamion[i].peso = peso[i];
         listacamion[i].cantidadruedas = cantidadruedas[i];
         strcpy(listacamion[i].tipo,tipo[i]);
         listacamion[i].estado = estados[i];
         listacamion[i].idchofer= idchofer[i];

             listacamion[i].idcamion = id_++;

    }
}
// inicializar estado
void inicializar_estadocamion (eCamiones listacamion[],int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        listacamion[i].estado = LIBRE;
    }
}
// generar id
int generar_Idcamion (eCamiones listacamion[],int tam)
{
     int id_aux = 9999;
   int i;
   for (i=0;i<tam;i++)
   {
       if (listacamion[i].estado == OCUPADO)
       {
            if (listacamion[i].idcamion>id_aux)
            {
                id_aux = listacamion[i].idcamion;
            }
       }

   }
    return id_aux +1;
}
// buscar por id
int buscarid_camion(eCamiones listacamion[], int tam)
{
    int i;
    int aux_id=-1;
    int retorno;
    printf ("\n Ingrese el id a buscar:\n");
    scanf("%d",&aux_id);

    for(i=0; i<tam; i++)
    {
      if( listacamion[i].idcamion==aux_id)
        {
            retorno=i;
            break;
        }
    }
  return retorno;
}
// buscar libre
int buscarLibre_camion(eCamiones listacamion[], int tam)
{
    int i;
    int index = -1;
    for (i=0;i<tam;i++)
    {
        if (listacamion[i].estado==LIBRE)
        {
            index = i;
        }
    }
    return  index;
}
 // baja camion
 void baja_Camion (eCamiones listacamion[], int tam)
 {
     int posicion;
    char respuesta;

    posicion = buscarid_camion(listacamion,tam);
    if (posicion != -1)
    {
        printf("\n\t*** CAMION ENCONTRADO! ***\n");
        printf("\n \t       id:   patente:      marca:     anio:       peso:   cant/ruedas:   tipo: \n");
        mostrar_UnCamion(listacamion[posicion]);

        printf("\n Desea eliminar de forma permanente el camion? (s/n) \n");
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            listacamion[posicion].estado = LIBRE;
            printf("\n\t*** CAMION ELIMINADO! ***\n");
        }

    }else
    {
        printf("\n\t*** CAMION NO ENCONTRADO! ***\n");
    }
 }
