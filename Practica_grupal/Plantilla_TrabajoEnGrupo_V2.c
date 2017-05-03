#include <stdio.h>
#include <stdlib.h>

#define ESTADO_CREADA 0
#define ESTADO_RESOLVIENDOSE 1
#define ESTADO_SOLUCIONADA 2

#define NOM_FICHERO "h_incidencias.bin"

/* ZONA DE DECLARACIÓN DE TIPOS*/

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

/**
NOMBRE: Partir.
DESCRIPCIÓN: Función que devuelve la nueva posición del pivote y que separa los dos subvectores que son  tratados en las dos siguientes llamadas recursivas a QuickSort.
PARAMETROS DE ENTRADA/SALIDA:
V[]: puntero a las incidencias.
Primero: posición del primer elemento
Ultimo: posición del último elemento
PorNumero: indica si la ordenacion se va a realizar por número de incidencia (TRUE) o por prioridad (FALSE)
RETORNO DE LA FUNCIÓN: nueva posición del pivote.
EECTOS COLATERALES: No tiene. 
*/
int Partir (tIncidencia v[], int primero, int ultimo, tBoolean PorNumero);

/**
NOMBRE: QuickSort.
DESCRIPCIÓN: Función que implementa el algoritmo de ordenación QuickSort.
PARAMETROS DE ENTRADA/SALIDA:
V[]: puntero a las incidencias.
izda: primera posición del vector a ordenar
dcha: última posición del vector a ordenar
PorNumero: indica si la ordenacion se va a realizar por número de incidencia (TRUE) o por prioridad (FALSE)
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void QuickSort (tIncidencia v[], int izda, int dcha, tBoolean PorNumero);

/**
NOMBRE: GuardarIncidencias
DESCRIPCIÓN: Función que guarda las incidencias en un fichero.Las incidencias
deberán guardarse ordenadas por número de incidencia.
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void GuardarIncidencias (tIncidencia *p, unsigned N);

/**
NOMBRE: LeerIncidencias
DESCRIPCIÓN: Función que lee las incidencias en un fichero.
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void LeerIncidencias (tIncidencia *p, unsigned N);

/**
NOMBRE: OrdenarIncidencias
DESCRIPCIÓN: Ordena las incidencias llamando a la funcion QuickSort y presenta
en pantalla las incidencias más prioritarias con todos sus datos (como maximo 
presentará cinco incidencias).
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void OrdenarIncidencias (tIncidencia *p, unsigned N);

/**
NOMBRE: ModificarIncidencia
DESCRIPCIÓN: Permite modificar los datos de una incidencia.  
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: numero de la incedencia a modificar.
p: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void ModificarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad);

/**
NOMBRE: BuscarIncidencia
DESCRIPCIÓN: Permite buscar los datos de una incidencia.  
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: numero de la incedencia a buscar.
p: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/

void BuscarIncidencia (unsigned Incidencia, tIncidencia *pIncidencias, unsigned Cantidad);

int Partir (tIncidencia v[], int primero, int ultimo, tBoolean PorNumero)
{
   /* A RELLENAR POR EL ALUMNO */ 
}


void QuickSort (tIncidencia v[], int izda, int dcha, tBoolean PorNumero)
{ 
  /* A RELLENAR POR EL ALUMNO */
}


int Menu (void)
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

    return opcion;
} /*fin menu*/

void BuscarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad)
{
  /* A RELLENAR POR EL ALUMNO */
}

void GuardarIncidencias (tIncidencia *p, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
}

void LeerIncidencias (tIncidencia *p, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
}

void OrdenarIncidencias (tIncidencia *p, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
 
}

void ModificarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad)
{
  /* A RELLENAR POR EL ALUMNO */
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
          GuardarIncidencias (pIncidencias, Cantidad);
          system("PAUSE");
          break;
        case 3: 

          
          Cantidad=Cantidad+1;
          
          
          pIncidencias = (tIncidencia *)realloc((tIncidencia *)pIncidencias, Cantidad*sizeof(tIncidencia));
          
          for (i=0; i<Cantidad; i++)
          { 
           printf("Numero: ");
           fflush(stdin);
           scanf("%u",&((pIncidencias+i)->NumIncidencia));

           printf("Prioridad: ");
           fflush(stdin);
           scanf("%u",&((pIncidencias+i)->Prioridad));
           
           printf("Asunto: ");
           fflush(stdin);
           scanf("%s",(pIncidencias+i)->Asunto);
            
           printf("Sistema: ");
           fflush(stdin);
           scanf("%s",(pIncidencias+i)->Sistema);
            
           printf("Subsistema: ");
           fflush(stdin);
           scanf("%s",(pIncidencias+i)->Subsistema);
           
           printf("Descripcion: ");
           fflush(stdin);
           scanf("%s",(pIncidencias+i)->Descripcion);

           printf("Estado (0 -> Creada, 1 -> Resolviendose, 2 -> Solucionada): ");
           fflush(stdin);
           scanf("%u",&(pIncidencias+i)->Estado);
             
          }
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

        default: printf("Ha tecleado una opción incorrecta\n");

    }
   } while (Opcion!= 7);
    free(pIncidencias);   
    return 0; 
}