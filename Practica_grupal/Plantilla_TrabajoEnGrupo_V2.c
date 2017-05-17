/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.----------- 
           Archivo: TrabajoGrupal.c 
           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.
           Descripcion: POR COMPLETAR SEGUN PLANTILLA !!!!!!!!!!!!!!

           Version: 0.1
           Fecha de última modificacion: 3 de Mayo de 2017
 -----------------------------------------------------------------------
*/
    


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Libreria añadida por nosotros 
#include <time.h>//Añado la libreria <time.h> porque necesitare que la fecha se ajuste automaticamente.

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
unsigned Partir (tIncidencia *incidencias, unsigned primero, unsigned ultimo, tBoolean PorNumero);

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
void QuickSort (tIncidencia *incidencias, unsigned izda, unsigned dcha, tBoolean PorNumero);

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
void GuardarIncidencias (tIncidencia *incidencias, unsigned N);

/**
NOMBRE: LeerIncidencias
DESCRIPCIÓN: Función que lee las incidencias en un fichero.
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene. 
*/
void LeerIncidencias (tIncidencia *incidencias, unsigned N);

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
void OrdenarIncidencias (tIncidencia *incidencias, unsigned N);

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

tBoolean BuscarIncidencia (unsigned Incidencia, tIncidencia *incidencias, unsigned inicio, unsigned Cantidad, unsigned *posicion);



//Funciones generadas por nosotros:

/**
NOMBRE: MostrarIncidencia
DESCRIPCIÓN: Muestra por consola la incidencia requerida por el usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia que queremos mostrar
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void MostrarIncidencia (tIncidencia *incidencia);

/**
NOMBRE: PedirDatos
DESCRIPCIÓN: Funcion que pide al usuario los datos de la incidencia para su posterior registro. 
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void PedirDatos (tIncidencia *incidencia);

/**
NOMBRE: AgregarIncidencia
DESCRIPCIÓN: Funcion que inserta la incidencia requerida al usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
Cantidad: cantidad de incidencias
RETORNO DE LA FUNCIÓN: Devuelve el puntero incidencia.
EECTOS COLATERALES: El hecho de que el almacen de incidencias aumenta en cantidad al añadir la incidencia.
*/
tIncidencia *AgregarIncidencia( tIncidencia *incidencias , unsigned Cantidad);


//Funciones generadas por nosotros:

/**
NOMBRE: MostrarIncidencia
DESCRIPCIÓN: Muestra por consola la incidencia requerida por el usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia que queremos mostrar
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void MostrarIncidencia (tIncidencia *incidencia);


/**
NOMBRE: TodasIncidencias
DESCRIPCIÓN: Muestra por consola todas las incidencias guardadas.
PARAMETROS DE ENTRADA/SALIDA:
Incidencias: incidencias que estan guardadas de tipo tIncidencia y Cantidad de las mimsas de tipo unsigned.
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void TodasIncidencias(tIncidencia *incidencias, unsigned Cantidad);
/**
NOMBRE: PedirDatos
DESCRIPCIÓN: Funcion que pide al usuario los datos de la incidencia para su posterior registro. 
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene. 
*/
void PedirDatos (tIncidencia *incidencia);

void Copiar(tIncidencia *origen, tIncidencia *destino)
{
  if(origen == destino)
      return;
	strcpy(destino->Asunto, origen->Asunto);
	strcpy(destino->Descripcion, origen->Descripcion);
	strcpy(destino->Fecha, origen->Fecha);
	strcpy(destino->Sistema, origen->Sistema);
	strcpy(destino->Subsistema, origen->Subsistema);
	destino->Estado = origen->Estado;
	destino->NumIncidencia = origen->NumIncidencia;
	destino->Prioridad = origen->Prioridad;	
}


unsigned Partir (tIncidencia *incidencias, unsigned primero, unsigned ultimo, tBoolean PorNumero)
{

	unsigned i = primero+1, j = ultimo;
  	/*tIncidencia aux = calloc(1, sizeof(tIncidencia));*/
  tIncidencia aux;
  	unsigned pivote = 0;
  		//Elegimos la posicion del pivote.
  		// Si el vector tiene un  tamaño mayor que 3 se elige el pivote. En caso contrario
  		//El pivote sera el primer elemento del vector
		
	if(PorNumero == TRUE)
		pivote = incidencias[primero].NumIncidencia;
	else
		pivote = incidencias[primero].Prioridad;
	
	//Hasta que i y j se crucen se va recorriendo el vector y poniendo los elementos menores o iguales del pivote a su izquierda
	//y los valores mayores a su derecha
	while(i <= j && j > 0)
	{   
		if(i <= j && j > 0)
		{
			if(PorNumero == TRUE)
			{
				if(incidencias[i].NumIncidencia <= pivote)
				i++;
				if(incidencias[j].NumIncidencia > pivote)
				j--;
			}
			else
			{
				if(incidencias[i].Prioridad <= pivote)
				i++;
				if(incidencias[j].Prioridad > pivote)
				j--;
			}
		}

		if(i < j)
		{
			if(PorNumero == TRUE)
      {
				if(incidencias[j].NumIncidencia <= pivote && incidencias[i].NumIncidencia > pivote) 
				{	
					Copiar(incidencias+i, &aux);
					Copiar(incidencias+j, incidencias+i);
					Copiar(&aux, incidencias+j);
					i++;
					j--;
				}
      }
      else
      {
        if(incidencias[j].Prioridad <= pivote && incidencias[i].Prioridad > pivote) 
        { 
          Copiar(incidencias+i, &aux);
          Copiar(incidencias+j, incidencias+i);
          Copiar(&aux, incidencias+j);
          i++;
          j--;
        }
		  }
    }
			
	}
	
	//Intercambiamos el primer elemento, que era el pivote, por la posicion de j
	//Asi los elementos mayores al pivote se encontraran a su derecha y los menores o iguales
	// a su izquierda
  if(j!=primero)
  {
		Copiar(incidencias+primero, &aux);
		Copiar(incidencias+j, incidencias+primero);
		Copiar(&aux, incidencias+j);
  }
	

	return j;

}

void QuickSort (tIncidencia *incidencias, unsigned izda, unsigned dcha, tBoolean PorNumero)
{ 
   //Variables: posicion del pivote
  unsigned pivote = 0;
  //Hasta que se crucen la primera y ultima posicion se llama a la funcion de forma recursiva
  if(izda < dcha)
  {
  	pivote = Partir(incidencias, izda, dcha, PorNumero);
    if(dcha != 0)
  	QuickSort (incidencias, izda, pivote-1, PorNumero);
    QuickSort (incidencias, pivote+1, dcha, PorNumero);
  }
}


int Menu ()
{
	int opcion;

  

	      printf (" \n  ***************************** Opciones ********************************");
	      printf (" \n  *   1. Registrar incidencia.                                          *");
        printf (" \n  *   2. Buscar incidencia.                                             *");                                                                            
        printf (" \n  *   3. Modificar incidencia.                                          *");
        printf (" \n  *   4. Guardar incidencias.                                           *");
        printf (" \n  *   5. Leer incidencias por prioridad.                                *");
        printf (" \n  *   6. Ordenar incidencias por prioridad.                             *");
        printf("  \n  *   7. Mostrar incidencias por numero.                                *");
        printf (" \n  *   8. Salir.                                                         *");
	      printf (" \n  ***********************************************************************");

	printf ( "\n Elija opcion ");
        scanf("%d", &opcion);

        while(getchar()!='\n'); //Control de error: si el usuario no introduce un digito, recogemos el caracter introducido hasta "\n".

    return opcion;
} /*fin menu*/


tBoolean BuscarIncidencia (unsigned Incidencia, tIncidencia *incidencias, unsigned inicio, unsigned Cantidad, unsigned *posicion)
{
   tBoolean encontrado = FALSE;
   unsigned mitad= ( inicio +Cantidad )/ 2;
 
   if(incidencias[mitad].NumIncidencia==Incidencia )
   {
    *posicion = mitad;
    encontrado = TRUE;
   }
   else if(incidencias[inicio].NumIncidencia==Incidencia)
   {
       *posicion = inicio;
       encontrado = TRUE;
   }
   else if(incidencias[Cantidad].NumIncidencia==Incidencia)
    {
       *posicion = Cantidad;
       encontrado = TRUE;
    }
    else if(inicio == Cantidad)
    {
        return encontrado;
    }
    else if(incidencias[mitad].NumIncidencia<Incidencia)
        {
          encontrado = BuscarIncidencia(Incidencia, incidencias, mitad+1, Cantidad, posicion);
        }
    else if(incidencias[mitad].NumIncidencia>Incidencia)
        {
          encontrado = BuscarIncidencia(Incidencia, incidencias, inicio, mitad-1, posicion);
        }
   return encontrado;


}

void GuardarIncidencias (tIncidencia *incidencias, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
}

void LeerIncidencias (tIncidencia *incidencias, unsigned N)
{
  /* A RELLENAR POR EL ALUMNO */
}

void OrdenarIncidencias (tIncidencia *incidencias, unsigned N) //ORDENAR POR PRIORIDAD
{
  if(incidencias==NULL)
    {
      printf("No se puede ordenar porque no existen incidencias\n");
      return;
    }

  QuickSort(incidencias, 0, N-1, FALSE);
  printf(" Incidencias ordenadas por prioridad:\n");
  if(N > 4)
    TodasIncidencias(incidencias, 5);
  else
    TodasIncidencias(incidencias, N);

  QuickSort(incidencias, 0, N-1, TRUE);
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

      printf("\n\nLa incidencia requerida es:\n");

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

        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        strftime(incidencia->Fecha,11,"%d/%m/%y",tlocal);
        
	do
	{
 		printf("Introduce numero de la incidencia a guardar\n");
		fflush(stdin);
  		scanf("%u", &incidencia->NumIncidencia);
  		while(getchar()!= '\n');
  		if(incidencia->NumIncidencia <= 0){
  			printf("\n El numero de incidencia debe ser mayor de 0.\n");
		    }
  	}while(incidencia->NumIncidencia <= 0);

	do{
		printf("Introduce la prioridad, siendo 1 la mayor prioridad y 4 la menor\n");
	    fflush(stdin);
        scanf("%u", &incidencia->Prioridad);
        while(getchar()!='\n');
        if(incidencia->Prioridad  >4 || incidencia->Prioridad<1)
	    {
		    printf("Por favor, introduzca un numero perteneciente al intervalo [1,4]\n");
	    }
	}
	while(incidencia->Prioridad >4 || incidencia->Prioridad<1);

  
    do{
           printf("Introduce el asunto\n");
           fflush(stdin);
           fgets(variableAuxiliar, 1500, stdin);
           variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;
          
          if(strlen(variableAuxiliar)>150)
          {
              printf("Se ha excedido la longitud del array\n");
          }
    }
    while(strlen(variableAuxiliar)>150 );
    strcpy(incidencia->Asunto, variableAuxiliar);

    do{
           printf("Introduce el sistema\n");
           fflush(stdin);
            fgets(variableAuxiliar, 1500, stdin);
           variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

           if(strlen(variableAuxiliar)>9)
           {
              printf("Se ha excedido la longitud del array\n");
           }
          else if(variableAuxiliar[0]=='\0') //Si esta vacio, se lo decimos al usuario
            printf("Si no conoce a que sistema afecta la incidencia, por favor, teclee '-'.\n");

      }
    while(strlen(variableAuxiliar)>9 || variableAuxiliar[0]=='\0');
    strcpy(incidencia->Sistema, variableAuxiliar);

    do{
        printf("Introduce el Subsistema\n");
        fflush(stdin);
         fgets(variableAuxiliar, 1500, stdin);
           variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

        if(strlen(variableAuxiliar)>9)
        {
          printf("Se ha excedido la longitud del array\n");
        }
        else if(variableAuxiliar[0]=='\0') //Si esta vacio, se lo decimos al usuario
            printf("Si no conoce a que sistema afecta la incidencia, por favor, teclee '-'.\n");
      
      
      }
    while(strlen(variableAuxiliar)>9 || variableAuxiliar[0]=='\0');
    strcpy(incidencia->Subsistema, variableAuxiliar);
    
    printf("La fecha actual es: \n");
    printf("%s\n",incidencia->Fecha);

    do{

      printf("Introduce la Descripcion\n");
      fflush(stdin);
       fgets(variableAuxiliar, 1500, stdin);
           variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

      if(strlen(variableAuxiliar)>500)
      {
        printf("Se ha excedido la longitud del array\n");
      }
      else if (variableAuxiliar[0]=='\0')
      {
          printf("La descripcion no puede estar vacia.\n");
      }
    }
    while(strlen(variableAuxiliar)>500 || variableAuxiliar[0]=='\0');

    strcpy(incidencia->Descripcion, variableAuxiliar);
  

do{
  incidencia->Estado=-1;
  printf("Introduce el estado\n");
  fflush(stdin);
  scanf("%u", &incidencia->Estado);
  while(getchar()!='\n');
  if(incidencia->Estado >2)
      {
        printf("No es posible. El estado puede ser: 0, 1 o 2\n");
      }

}while(incidencia->Estado >2);

  
}


tIncidencia *AgregarIncidencia( tIncidencia *incidencias , unsigned Cantidad) //AUTORIA: RAUL Y BEA
{
    if(incidencias==NULL)
    {
          incidencias=(tIncidencia*)calloc(1, sizeof(tIncidencia));
    }
    else 
    {
          incidencias=(tIncidencia*)realloc(incidencias, (int)Cantidad);
    }
    PedirDatos(&incidencias[Cantidad-1]);
    printf("Incidencia agregada:\n");
    MostrarIncidencia(&incidencias[Cantidad-1]);
    QuickSort(incidencias, 0, Cantidad-1, TRUE);

    return incidencias;
}

void TodasIncidencias(tIncidencia *incidencias, unsigned Cantidad)
{
    unsigned posicion=0; //Variable de posicion

    if(incidencias==NULL)
    {
      printf("No existen incidencias\n");
      return; //Para no necesitar poner un else. Return sale de la funcion
    }

    for(posicion = 0 ;posicion < Cantidad && (incidencias+posicion)!=NULL; posicion++) 
    {
        MostrarIncidencia(incidencias+posicion);
    }


}
int main ()
{
    tIncidencia *pIncidencias;   
    unsigned Cantidad=0;
    unsigned Opcion;
    unsigned Incidencia;
    unsigned Indice;

    pIncidencias=NULL;

    do
   {
     Opcion=Menu();
     system("clear");
     switch (Opcion)
    {
        case 1:  
              printf("Agregar incidencia:\n");
              Cantidad++;
              pIncidencias=AgregarIncidencia(pIncidencias, Cantidad);
              
              break;

        case 2:
                printf("Numero de incidencia a buscar\n");
                scanf("%d",&Incidencia);
                if(BuscarIncidencia(Incidencia, pIncidencias, 0, Cantidad-1, &Indice)!=FALSE)
                 { 
                  printf("\nLa incidencia se ha encontrado con exito. La incidencia es:\n");
                  printf("\n\nNumero de incidencia: %u", pIncidencias[Indice].NumIncidencia);
                  printf("\n\nPrioridad: %u", pIncidencias[Indice].Prioridad);
                  printf("\n\nAsunto: %s", pIncidencias[Indice].Asunto);
                  printf("\n\nSistema: %s", pIncidencias[Indice].Sistema);
                  printf("\n\nSubsistema:  %s", pIncidencias[Indice].Subsistema);
                  printf("\n\nDescripcion: %s", pIncidencias[Indice].Descripcion);
                  }
                else
                {
                  printf("Lo sentimos, incidencia no encontrada.\n");
                }
                //system("PAUSE");
                break;
        case 3: 
          
               printf("Numero de incidencia a modificar\n");
               scanf("%d",&Incidencia);
               //ModificarIncidencia (Incidencia, pIncidencias, Cantidad);
               
               break;

        case 4:
                printf("Guardar incidencias\n");
                //GuardarIncidencias(pIncidencias, Cantidad);
                
                break;

        case 5:
                printf("Leer incidencias\n");
                //LeerIncidencias (pIncidencias, Cantidad);
                
                break;
        
        case 6:
                printf("Mostrar incidencias por prioridad\n");
                OrdenarIncidencias (pIncidencias, Cantidad);
                
                break;

        case 7: 
                printf("Mostrar incidencias por numero de incidencia\n");
                TodasIncidencias(pIncidencias, Cantidad);
                
                break;
        case 8: 
                printf("Salir.");
                break;

        default: printf("Ha tecleado una opcion incorrecta\n");
           
                 break;
    }
    while(getchar()!= '\n');
    system("clear");
   } while (Opcion!= 8);
    free(pIncidencias);   
    return 0; 
}


