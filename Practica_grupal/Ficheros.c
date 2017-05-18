/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Ficheros.c

           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.
           Descripcion: Implementacion de las funciones GuardarIncidencias
           y LeerIncidencias

           Version: 2.0
           Fecha de última modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "types.h"
#include "Incidencias.h"
#include "Ficheros.h"



void GuardarIncidencias (tIncidencia *incidencias, unsigned N) {
	
	//Si no hay incidencias se retorna la funcion
	if(incidencias == NULL || N == 0) {
		printf("\nNo hay incidencias...\n");
		return;
	}

	FILE *fout = fopen(NOM_FICHERO, "wb");
	//Si no se ha podido abrir el fichero salimos de la funcion
	if(!fout) {
		printf("\nError de fichero.\n");
		return;
	}

	//Guardamos en el fichero binario el array de estructuras en bytes
	fwrite(incidencias, sizeof(tIncidencia), N, fout);
	fclose(fout);
}


tIncidencia *LeerIncidencias (tIncidencia *incidencias, unsigned *N) {
	
	//Abrimos el fichero en modo de lectura binaria
	FILE *fin = fopen(NOM_FICHERO, "rb");
	
	//Si no de ha podido abrir el fichero salimos de la funcion
	if(!fin) {
		printf("\nError de fichero.\n");
		return 0;
	}
	
	//Indice: guarda la ultima posicion libre del array de incidencias
	//posicion: guarda el indice de la incidencia a buscar
	unsigned indice =*N, posicion = 0;
	//existe: guarda si existe la incidencia leida o no
	tBoolean existe = FALSE;
	//Estructura auxiliar para guardar la incidencia leida
	tIncidencia aux;

	//Leemos de 1 en uno las estructuras guardadas en el documento
	while(fread(&aux, sizeof(tIncidencia), 1, fin) > 0) {
		existe = FALSE;
		
		//Comprobamos si el numero de incidencia leida existe o no
		if(indice > 2)
			existe = BuscarIncidencia(aux.NumIncidencia, incidencias, 0, indice-1, &posicion);

		//Si no existe se añade. Si existe no se añade y muestra un mensaje por pantalla
		if(existe == FALSE) {
			//Se reserva memoria para la nueva incidencia y se copian los datos
			incidencias = (tIncidencia *)realloc(incidencias, (indice+1)*sizeof(tIncidencia));
			Copiar(&aux, incidencias+indice);
			
			//Mostramos la incidencia agregada
			printf("\nIncidencia agregada:\n");
			MostrarIncidencia(incidencias+indice);

			indice++;
		} else {
			printf("\nEl numero de esta incidencia ya se encuentra en la lista. Incidencia no agregada.\n");
			MostrarIncidencia(&aux);
		}


	}

	*N = indice;
	fclose(fin);
	return incidencias;
}
