/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: TrabajoGrupal.c
           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.
           Descripcion: Archivo principal del proyecto

           **
           Las cabeceras de las funciones se encuentran en los archivos de cabecera.
           Hemos decidido separar por modulos el proyecto para que sea mas facil de implementar,
           leer y revisar.
           **

           Version: 0.1
           Fecha de última modificacion: 3 de Mayo de 2017

           Vercion 2.0
           Fecha de última modificacion: 18 de Mayo de 2017


 -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "Incidencias.h"
#include "Ficheros.h"


/*
	Funcion: Menu
	Descripcion: Muestra las opciones del programa por pantalla
	y pide al ususario una opcion.

	Entrada: void
	Salida: opcion
*/
int Menu () {
	
	int opcion = 0;

	printf (" \n  ***************************** Opciones ********************************");
	printf (" \n  *   1. Registrar incidencia.                                          *");
	printf (" \n  *   2. Buscar incidencia.                                             *");
	printf (" \n  *   3. Modificar incidencia.                                          *");
	printf (" \n  *   4. Guardar incidencias.                                           *");
	printf (" \n  *   5. Leer incidencias.                                              *");
	printf (" \n  *   6. Ordenar incidencias por prioridad.                             *");
	printf("  \n  *   7. Mostrar incidencias por numero.                                *");
	printf (" \n  *   8. Salir.                                                         *");
	printf (" \n  ***********************************************************************");

	printf ( "\n Elija opcion ");
	scanf("%d", &opcion);

	while(getchar()!='\n'); //Control de error: si el usuario no introduce un digito, recogemos el caracter introducido hasta "\n".

	return opcion;
} /*fin menu*/


int main () {
	
	tIncidencia *pIncidencias = NULL;
	unsigned Cantidad=0;
	unsigned Opcion = 0;
	unsigned Incidencia = 0;
	unsigned Indice = 0;

	do {
		Opcion=Menu();
		system("clear");
		switch (Opcion) {
			case 1:
				printf("Agregar incidencia:\n");
				Cantidad++;
				pIncidencias=AgregarIncidencia(pIncidencias, Cantidad);

				break;

			case 2:
				printf("Numero de incidencia a buscar\n");
				scanf("%d",&Incidencia);
				if(BuscarIncidencia(Incidencia, pIncidencias, 0, Cantidad-1, &Indice)!=FALSE) {
					printf("\nLa incidencia se ha encontrado con exito.\n");
					MostrarIncidencia(pIncidencias+Indice);
				} else {
					printf("Lo sentimos, incidencia no encontrada.\n");
				}
				break;
				
			case 3:
				printf("Numero de incidencia a modificar\n");
				scanf("%d",&Incidencia);
				ModificarIncidencia (Incidencia, pIncidencias, Cantidad);
				break;

			case 4:
				printf("Guardar incidencias\n");
				GuardarIncidencias(pIncidencias, Cantidad);
				break;

			case 5:
				printf("Leer incidencias\n");
				pIncidencias = LeerIncidencias (pIncidencias, &Cantidad);
				break;

			case 6:
				printf("Mostrar incidencias por prioridad\n");
				OrdenarIncidencias (pIncidencias, Cantidad);
				break;

			case 7:
				printf("Mostrar incidencias por numero de incidencia\n");
				MostrarTodasIncidencias(pIncidencias, Cantidad);

				break;
			case 8:
				printf("Salir.");
				break;

			default:
				printf("Ha tecleado una opcion incorrecta\n");
				break;
				
		}
		while(getchar()!= '\n');
		system("clear");
		
	} while (Opcion!= 8);
	
	if(pIncidencias != NULL)
		free(pIncidencias);
		
	return 0;
}


