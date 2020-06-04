#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chofer2.h"

int menu ()
{
  int opcion;
  system("cls");
  printf ("\n 1.   LISTA CHOFER ");
  printf ("\n 2.   LISTA CAMION/CHOFER   ");
  printf ("\n 3.   LISTA CHOFER / CAMION ");
  printf ("\n 4.   ALTA CAMION  ");
  printf ("\n 5.   BAJA CAMION ");
  printf ("\n 6.   MODIFICAR CAMION ");
  printf ("\n 7.   ALTA CHOFER ");
  printf ("\n 8.   BAJA CHOFER ");
  printf ("\n 9.   ORDENAR CAMION *TIPO ");
  printf ("\n 10.  MODIFICAR CHOFER");
  printf ("\n 11.  MOSTRAR CHOFER CON CAMIONES");
  printf ("\n 12.  ");
  printf ("\n 13.  ");
  printf ("\n 14.  ");
  printf ("\n\t\t SELECCIONE UNA OPCION:  ");
  scanf("%d",&opcion);
    return opcion;
}
//iniciar
void inicializar_estado (eChoferes listachofer[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        listachofer[i].estado = LIBRE;
    }
}
// hardcodear datos

void hardcodeo_Choferes(eChoferes listachofer[], int tam)
{
    char nombre[6][30]= {"lucrecia","jorge","natalia","matias","jeremias","santiago"};
    char apellido[6][30]= {"perez","davila","ramirez","peon","arias","bolounes"};
    int dni[6] = {958893,956578,957592,959463,957693,956593};
    int legajo[6]= {1234,1237,1236,12348,1239,1235};
    char nacionalidad[6][30]= {"colombiano","venezolano","boliviano","uruguayo","argentino","checo"};
    int telefono[6]= {111111,112222,1155555,1166666,1133333,1144444};
    int edad[6]={45,23,45,14,41,25};
    char sexo [6][10]= {"femenino","masculino","femenino","femenino","masculino","masculino"};
    int estado_ [6]={1,1,1,1,1,1};
    int id_ = generar_Idchofer (listachofer,tam);
    int i;

    for (i=0; i<6; i++)
    {
         listachofer[i].idchofer =id_++;
         strcpy(listachofer[i].nombre,nombre[i]);
         strcpy(listachofer[i].apellido,apellido[i]);
         listachofer[i].dni = dni[i];
         listachofer[i].legajo = legajo[i];
         strcpy(listachofer[i].nacionalidad,nacionalidad[i]);
         listachofer[i].telefono = telefono[i];
         listachofer[i].edad = edad[i];
         strcpy(listachofer[i].sexo,sexo[i]);
         listachofer[i].estado = estado_[i];

    }
}


// generar  id
int generar_Idchofer (eChoferes listachofer[],int tam)
{
   int id_aux = 999;
   int i;
   for (i=0;i<tam;i++)
   {
       if (listachofer[i].estado == OCUPADO)
       {
            if (listachofer[i].idchofer>id_aux)
            {
                id_aux = listachofer[i].idchofer;
            }
       }

   }
    return id_aux +1;
}

// buscar por id
int buscarid_chofer(eChoferes listachofer[], int tam)
{
    int i;
    int aux_id=-1;
    int retorno;
    printf ("\n Ingrese el id a buscar:\n");
    scanf("%d",&aux_id);

    for(i=0; i<tam; i++)
    {
      if( listachofer[i].idchofer==aux_id)
        {
            retorno=i;
            break;
        }
    }
  return retorno;
}

// buscar libre
int buscarLibre_chofer(eChoferes listachofer[], int tam)
{
    int j;
    int index = -1;
    for (j=0;j<tam;j++)
    {
        if (listachofer[j].estado==LIBRE )
        {
            index = j;
        }
    }
    return  index;
}
// mostrar un chofer
void mostrar_Chofer (eChoferes chofer)
{
    printf(" %10d %10s %10s %10d %10d %10s %10d %10d %10s %10d \n ",chofer.idchofer,
                                              chofer.nombre,
                                              chofer.apellido,
                                              chofer.dni,
                                              chofer.legajo,
                                              chofer.nacionalidad,
                                              chofer.telefono,
                                              chofer.edad,
                                              chofer.sexo,
                                              chofer.estado);



}

// Mostrar Lista de choferes
void Mostrar_Listachoferes(eChoferes listachofer[], int tam)
{
    int i ;
    system("cls");
    printf("\n id:   nombre:   apellido:  dni:  legajo:  nacionalidad:  tel:  edad:  sexo:  \n");

        for (i=0;i<tam;i++)
        {
            if (listachofer[i].estado == OCUPADO)
            {
                mostrar_Chofer (listachofer[i]);

            }
        }
}
// alta chofer
void alta_chofer (eChoferes listachofer[], int tam)
{
    int posicion;
    char respuesta;
    int aux_id;
    eChoferes aux_chofer;

    aux_id = generar_Idchofer(listachofer,tam);
    posicion = buscarLibre_chofer(listachofer,tam);

    if (posicion!=-1)
    {
        printf ("\n INGRESE NOMBRE: \n");
        fflush (stdin);
        fgets(aux_chofer.nombre,30,stdin);

        printf ("\n INGRESE APELLIDO: \n");
        fflush (stdin);
        fgets(aux_chofer.apellido,30,stdin);

        printf ("\n INGRESE DNI: \n");
        scanf("%d",&aux_chofer.dni);

        printf ("\n INGRESE LEGAJO: \n");
        scanf("%d",&aux_chofer.legajo);

        printf ("\n INGRESE NACIONALIDAD: \n");
        fflush (stdin);
        fgets(aux_chofer.nacionalidad,30,stdin);

        printf ("\n INGRESE TELEFONO: \n");
        scanf("%d",&aux_chofer.telefono);

        printf ("\n INGRESE EDAD: \n");
        scanf("%d",&aux_chofer.edad);

        printf ("\n INGRESE SEXO: \n");
        fflush (stdin);
        fgets(aux_chofer.sexo,10,stdin);

        aux_chofer.idchofer = aux_id;

        printf("\n Desea agregar el Chofer? (s/n)\n" );
        fflush (stdin);
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            aux_chofer.estado = OCUPADO;
            listachofer[posicion]=aux_chofer;
            printf ("\n\t** CHOFER CARGADO CON EXITO!!  **\n ");

        }else
        {
            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
        }
    }else
    {
        printf ("\n\t** NO SE ENCONTRO ESPACIO *LLENO*.  **\n ");
    }
}
// baja chofer
 void baja_Chofer (eChoferes listachofer[], int tam)
 {
    int posicion;
    char respuesta;

    Mostrar_Listachoferes(listachofer,tam);
    posicion = buscarid_chofer(listachofer,tam);
    if (posicion != -1)
    {
        printf("\n\t*** CHOFER ENCONTRADO! ***\n");
        printf("\n id:   nombre:   apellido:  dni:  legajo:  nacionalidad:  tel:  edad:  sexo:  \n");
        mostrar_Chofer(listachofer[posicion]);

        printf("\n Desea eliminar de forma permanente el chofer? (s/n) \n");
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            listachofer[posicion].estado=LIBRE;
            printf("\n\t*** CHOFER ELIMINADO! ***\n");
        }

    }else
    {
        printf("\n\t*** CHOFER NO ENCONTRADO! ***\n");
    }
 }
 // modificar chofer
  void modificar_chofer(eChoferes listachofer[], int tam)
  {
      int id_posicion;
      char aux_char[30];
      int aux_int;
      char respuesta;
      eChoferes aux_chofer;
      Mostrar_Listachoferes(listachofer,tam);
      id_posicion = buscarid_chofer(listachofer,tam);

      if(id_posicion!=-1)
      {
          printf("\n\t*** CHOFER ENCONTRADO! ***\n");
          printf("\n id:   nombre:   apellido:  dni:  legajo:  nacionalidad:  tel:  edad:  sexo:  \n");
          mostrar_Chofer(listachofer[id_posicion]);
          aux_chofer=listachofer[id_posicion];

        printf ("\n RE-INGRESE NOMBRE: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.nombre,aux_char);

        printf ("\n RE-INGRESE APELLIDO: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.apellido,aux_char);


        printf ("\n RE-INGRESE DNI: \n");
        scanf("%d",&aux_int);
        aux_chofer.dni=aux_int;

        printf ("\n RE-INGRESE LEGAJO: \n");
        scanf("%d",&aux_int);
        aux_chofer.legajo=aux_int;

        printf ("\n RE-INGRESE NACIONALIDAD: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.nacionalidad,aux_char);

        printf ("\n RE-INGRESE TELEFONO: \n");
        scanf("%d",&aux_int);
        aux_chofer.telefono=aux_int;

        printf ("\n RE-INGRESE EDAD: \n");
        scanf("%d",&aux_int);
        aux_chofer.edad=aux_int;

        printf ("\n RE-INGRESE SEXO: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.sexo,aux_char);

        printf ("\n** Desea efectuar los cambios? (s/n) **\n");
            scanf("%s",&respuesta );
            if (respuesta == 's')
            {
                listachofer[id_posicion] = aux_chofer;
                printf ("\n\t** CAMBIOS EFECTUADOS! **\n");
            }else
            {
                printf ("\n\t** CAMBIOS CANCELADOS! **\n");
            }
      }
  }
