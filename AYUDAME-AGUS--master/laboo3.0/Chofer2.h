#ifndef CHOFER2_H_INCLUDED
#define CHOFER2_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int idchofer;
  char nombre[30];
  char apellido[30];
  int dni ;
  int legajo;
  char nacionalidad[30];
  int telefono;
  int  edad;
  char sexo[10];
  int estado;
}eChoferes;



#endif // CHOFER_H_INCLUDED



int menu ();
void inicializar_estado (eChoferes listachofer[],int tam);
int generar_Idchofer (eChoferes listachofer[],int tam);
int buscarid_chofer(eChoferes listachofer[], int tam);
void hardcodeo_Choferes(eChoferes listachofer[], int tam);
int buscarLibre_chofer(eChoferes listachofer[], int tam);
void mostrar_Chofer (eChoferes chofer);
void Mostrar_Listachoferes(eChoferes listachofer[], int tam);
void alta_chofer (eChoferes listachofer[], int tam);
void baja_Chofer (eChoferes listachofer[], int tam);
void modificar_chofer(eChoferes listachofer[], int tam);
