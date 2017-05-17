/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.----------- 
           Archivo: TrabajoGrupal.c 
           Autores: Ra�l Jim�nez Ju�rez. Beatriz Mag�n Pinto.
           Descripcion: POR COMPLETAR SEGUN PLANTILLA !!!!!!!!!!!!!!

           Version: 0.1
           Fecha de �ltima modificacion: 3 de Mayo de 2017
 -----------------------------------------------------------------------
*/
    


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Libreria a�adida por nosotros 

#define ESTADO_CREADA 0
#define ESTADO_RESOLVIENDOSE 1
#define ESTADO_SOLUCIONADA 2

#define NOM_FICHERO "h_incidencias.bin"

/* ZONA DE DECLARACI�N DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

/* Tipo con la informacion de una incidencia */
typedef struct 
{
unsigned NumIncidencia;
unsigned Prioridad;
char Asunto[150];
char Sistema[9];
char Subsistema[9];
char Fecha[11];
char Descripcion [500];
unsigned Estado;
}tIncidencia;

<<<<<<< HEAD

typedef struct
{
	tNodo *anterior;
	tNodo *siguiente;
	tIncidencia *incidencia;
}tNodo;

=======
>>>>>>> master





/**
NOMBRE: Partir.
DESCRIPCI�N: Funci�n que devuelve la nueva posici�n del pivote y que separa los dos subvectores que son  tratados en las dos siguientes llamadas recursivas a QuickSort.
PARAMETROS DE ENTRADA/SALIDA:
V[]: puntero a las incidencias.
Primero: posici�n del primer elemento
Ultimo: posici�n del �ltimo elemento
PorNumero: indica si la ordenacion se va a realizar por n�mero de incidencia (TRUE) o por prioridad (FALSE)
RETORNO DE LA FUNCI�N: nueva posici�n del pivote.
EECTOS COLATERALES: No tiene. 
*/
int Partir (tIncidencia *incidencias, int primero, int ultimo, tBoolean PorNumero);

/**
NOMBRE: QuickSort.
DESCRIPCI�N: Funci�n que implementa el algoritmo de ordenaci�n QuickSort.
PARAMETROS DE ENTRADA/SALIDA:
V[]: puntero a las incidencias.
izda: primera posici�n del vector a ordenar
dcha: �ltima posici�n del vector a ordenar
PorNumero: indica si la ordenacion se va a realizar por n�mero de incidencia (TRUE) o por prioridad (FALSE)
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void QuickSort (tIncidencia *incidencias, int izda, int dcha, tBoolean PorNumero);

/**
NOMBRE: GuardarIncidencias
DESCRIPCI�N: Funci�n que guarda las incidencias en un fichero.Las incidencias
deber�n guardarse ordenadas por n�mero de incidencia.
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void GuardarIncidencias (tIncidencia *incidencias, unsigned N);

/**
NOMBRE: LeerIncidencias
DESCRIPCI�N: Funci�n que lee las incidencias en un fichero.
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void LeerIncidencias (tIncidencia *incidencias, unsigned N);

/**
NOMBRE: OrdenarIncidencias
DESCRIPCI�N: Ordena las incidencias llamando a la funcion QuickSort y presenta
en pantalla las incidencias m�s prioritarias con todos sus datos (como maximo 
presentar� cinco incidencias).
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void OrdenarIncidencias (tIncidencia *incidencias, unsigned N);

/**
NOMBRE: ModificarIncidencia
DESCRIPCI�N: Permite modificar los datos de una incidencia.  
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: numero de la incedencia a modificar.
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void ModificarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad);

/**
NOMBRE: BuscarIncidencia
DESCRIPCI�N: Permite buscar los datos de una incidencia.  
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: numero de la incedencia a buscar.
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene. 
*/

void BuscarIncidencia (unsigned Incidencia, tIncidencia *incidencias, unsigned Cantidad);


//Funciones generadas por nosotros:

/**
NOMBRE: MostrarIncidencia
DESCRIPCI�N: Muestra por consola la incidencia requerida por el usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia que queremos mostrar
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void MostrarIncidencia (tIncidencia *incidencia);

/**
NOMBRE: PedirDatos
DESCRIPCI�N: Funcion que pide al usuario los datos de la incidencia para su posterior registro. 
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void PedirDatos (tIncidencia *incidencia);


<<<<<<< HEAD

//Funciones generadas por nosotros:

/**
NOMBRE: MostrarIncidencia
DESCRIPCI�N: Muestra por consola la incidencia requerida por el usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia que queremos mostrar
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void MostrarIncidencia (tIncidencia *incidencia);

/**
NOMBRE: PedirDatos
DESCRIPCI�N: Funcion que pide al usuario los datos de la incidencia para su posterior registro. 
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void PedirDatos (tIncidencia *incidencia);




int Partir (tNodo *incidencias, int primero, int ultimo, tBoolean PorNumero) 

=======
int Partir (tIncidencia *incidencias, int primero, int ultimo, tBoolean PorNumero)
>>>>>>> master
{
   

/* A RELLENAR POR EL ALUMNO */


  return 0;
}


void QuickSort (tIncidencia *incidencias, int izda, int dcha, tBoolean PorNumero)
{ 
  /* A RELLENAR POR EL ALUMNO */
}


int Menu ()
{
	int opcion;

        system("cls");

	printf (" \n  ***************************** Opciones ********************************");
	printf (" \n  *   1. Buscar incidencia.                                             *");
        printf (" \n  *   2. Guardar las incidencias.                                       *");                                                                            
        printf (" \n  *   3. Registrar incidencia.                                          *");
        printf (" \n  *   4. Leer incidencias.                                              *");
        printf (" \n  *   5. Ordenar incidencias por prioridad.                             *");
        printf (" \n  *   6. Modificar incidencia.                                          *");
        printf (" \n  *   7. Salir.                                                         *");
	printf (" \n  ***********************************************************************");

	printf ( "\n Elija opcion ");
        scanf("%d", &opcion);

        while(getchar()!='\n'); //Control de error: si el usuario no introduce un digito, recogemos el caracter introducido hasta "\n".

    return opcion;
} /*fin menu*/

void BuscarIncidencia (unsigned Incidencia, tIncidencia *incidencias, unsigned Cantidad)
{
<<<<<<< HEAD
  
=======

>>>>>>> master
}

void GuardarIncidencias (tIncidencia *incidencias, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
}

void LeerIncidencias (tIncidencia *incidencias, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
}

void OrdenarIncidencias (tIncidencia *incidencias, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
 
}

void ModificarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad)
{
  /* A RELLENAR POR EL ALUMNO */
}

void MostrarIncidencia (tIncidencia *incidencia) //Autoria: Beatriz
{
    if(incidencia==NULL)
    {
      printf("No existe tal incidencia\n");
      return;
    }

      printf("La incidencia requerida es:\n");

      printf("Numero de incidencia: %d\n", incidencia->NumIncidencia);

      printf("Prioridad: %d\n", incidencia->Prioridad );
    
      printf("Asunto: %s\n", incidencia->Asunto);
      
      printf("Sistema: %s\n", incidencia->Sistema);
  
      printf("Subsistema: %s\n", incidencia->Subsistema);

      printf("Fecha: %s\n", incidencia->Fecha);

      printf("Descripcion:%s\n", incidencia->Descripcion);

      printf("Estado: %d\n", incidencia->Estado);


}


void PedirDatos (tIncidencia *incidencia) //AUTORIA: BEATRIZ 
{

  char variableAuxiliar[1500];

  printf("Buenos dias, usuario\n");


  printf("Introduce numero de la incidencia a guardar\n");
  fflush(stdin);
  scanf("%d", &incidencia->NumIncidencia);

do{
  printf("Introduce la prioridad, siendo 1 la mayor prioridad y 4 la menor\n");
  fflush(stdin);
  scanf("%d", &incidencia->Prioridad);
  if(strlen(variableAuxiliar)>4)
  {
    printf("Se ha excedido la longitud del array\n");
  }
}
while(strlen(variableAuxiliar)>4);

	do
	{
 		printf("Introduce numero de la incidencia a guardar\n");
		fflush(stdin);
  		scanf("%d", &incidencia->NumIncidencia);
  		while(getchar()!= '\n');
  		if(incidencia->NumIncidencia <= 0){
  			printf("\n El numero de incidencia debe ser mayor de 0.\n");
		}
  	}while(incidencia->NumIncidencia <= 0);

	do{
		printf("Introduce la prioridad, siendo 1 la mayor prioridad y 4 la menor\n");
	    fflush(stdin);
        scanf("%d", &incidencia->Prioridad);
        if(strlen(variableAuxiliar)>4)
	    {
		    printf("Se ha excedido la longitud del array\n");
	    }
	}
	while(strlen(variableAuxiliar)>4);

  
    do{
           printf("Introduce el asunto\n");
           fflush(stdin);
           gets(variableAuxiliar);
          
          if(strlen(variableAuxiliar)>150)
          {
              printf("Se ha excedido la longitud del array\n");
          }
    }
    while(strlen(variableAuxiliar)>150);


    do{
           printf("Introduce el sistema\n");
           fflush(stdin);
           gets(incidencia->Sistema);

           if(strlen(variableAuxiliar)>9)
           {
              printf("Se ha excedido la longitud del array\n");
           }
      }
    while(strlen(variableAuxiliar)>9);

    do{
        printf("Introduce el Subsistema\n");
        fflush(stdin);
        gets(incidencia->Subsistema);

        if(strlen(variableAuxiliar)>9)
        {
          printf("Se ha excedido la longitud del array\n");
        }
      }
    while(strlen(variableAuxiliar)>9);
    
  
    do{
      printf("Introduce la fecha\n");
      fflush(stdin);
      gets(incidencia->Fecha);

      if(strlen(variableAuxiliar)>11)
      {
        printf("Se ha excedido la longitud del array\n");
      }
    }
    while(strlen(variableAuxiliar)>11);
    
  

    do{

      printf("Introduce la Descripcion\n");
      fflush(stdin);
      gets(incidencia->Descripcion);

      if(strlen(variableAuxiliar)>500)
      {
        printf("Se ha excedido la longitud del array\n");
      }
    }
    while(strlen(variableAuxiliar)>500);

  printf("Introduce el estado\n");
  fflush(stdin);
  scanf("%d", &incidencia->Estado);

  
}


int main ()
{
    tIncidencia *pIncidencias;   
    unsigned Cantidad=0;
    unsigned Opcion;
    int i;
    unsigned Incidencia;
    
    pIncidencias=NULL;

    do
   {
     Opcion=Menu();
     switch (Opcion)
    {
      case 1:  
        
        printf("Numero de incidencia a buscar\n");
        scanf("%d",&Incidencia);
        BuscarIncidencia (Incidencia, pIncidencias, Cantidad);
        system("PAUSE");
        break;

        case 2:
        printf("Guardar incidencia:\n");

          GuardarIncidencias (pIncidencias, Cantidad);
          system("PAUSE");
          break;
        case 3: 

          
          Cantidad=Cantidad+1;
          
         
          system("PAUSE");
          break;

        case 4:
          LeerIncidencias (pIncidencias, Cantidad);
          system("PAUSE");
          break;

        case 5:
          OrdenarIncidencias (pIncidencias, Cantidad);
          system("PAUSE");
          break;
        
        case 6:
          printf("Numero de incidencia a modificar\n");
          scanf("%d",&Incidencia);
          ModificarIncidencia (Incidencia, pIncidencias, Cantidad);
          system("PAUSE");
          break;

        case 7: 
          break;

        default: printf("Ha tecleado una opcion incorrecta\n");

    }
   } while (Opcion!= 7);
    free(pIncidencias);   
    return 0; 
}
