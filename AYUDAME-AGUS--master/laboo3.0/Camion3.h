#ifndef CAMION3_H_INCLUDED
#define CAMION3_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int idcamion;
  char patente[10];
  char marca[10];
  int anio;
  int peso;
  int cantidadruedas;
  char tipo[20];
  int idchofer;
  int estado;
}eCamiones;

#endif // CAMION3_H_INCLUDED

void inicializar_estadocamion (eCamiones listacamion[],int tam);
int generar_Idcamion (eCamiones listacamion[],int tam);
int buscarid_camion(eCamiones listacamion[], int tam);
void hardcodeo_Camiones(eCamiones listacamion[], int tam);
int buscarLibre_camion(eCamiones listacamion[], int tam);
void baja_Camion (eCamiones listacamion[], int tam);
