#ifndef CAMIONCHOFER_H_INCLUDED
#define CAMIONCHOFER_H_INCLUDED



#endif // CAMION_CHOFER_H_INCLUDED

#include "Camion3.h"
#include "Chofer2.h"


int cargar_Nombrechofer(char nombre_chofer[],int id_camion, eChoferes listachofer[], int tamChofer);
void mostrar_Camion (eCamiones camion, eChoferes listachofer[],int tam_chofer );
void Mostrar_Listacamiones(eCamiones listacamion[], int tam, eChoferes listachofer[],int tamchofer);
void alta_camion (eCamiones listacamion[],int tamcamion, eChoferes listachofer[],int tamchofer);
void modificar_camion (eCamiones listacamion[], int tam,eChoferes listachofer[],int tamchofer);
void ordenar_Camion_portipo (eCamiones listacamion[],int tam,eChoferes listachofer[] ,int tamchofer);

void mostrar_UnCamion (eCamiones camion);
void mostrarChofer_yCamion (eChoferes listachofer[],int tamchofer,eCamiones listacamion[],int tamcamion);
void mostrar_chofercon_camiones(eChoferes listachofer[],int tamcho,eCamiones listacamion[],int tamcamion);
