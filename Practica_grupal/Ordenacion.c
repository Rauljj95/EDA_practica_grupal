/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Ordenacion.c

           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.
           Descripcion: Implementacion de las funciones Partir y QuickSort

           Version: 0.1
           Fecha de última modificacion: 3 de Mayo de 2017
 -----------------------------------------------------------------------
*/

#include <stdio.h>
#include "types.h"
#include "Incidencias.h"
#include "Ordenacion.h"

//Funcion privada
unsigned ObtenerValor(tIncidencia *incidencia, tBoolean PorNumero)
{
	if(PorNumero != FALSE)
		return incidencia->NumIncidencia;

	return incidencia->Prioridad;
}

unsigned Partir (tIncidencia *incidencias, unsigned primero, unsigned ultimo, tBoolean PorNumero) {
	
	unsigned i = primero+1, j = ultimo, valori = 0, valorj = 0;
	/*tIncidencia aux = calloc(1, sizeof(tIncidencia));*/
	tIncidencia aux;
	unsigned pivote = 0;
	//Elegimos la posicion del pivote.
	// Si el vector tiene un  tamaño mayor que 3 se elige el pivote. En caso contrario
	//El pivote sera el primer elemento del vector

	if(PorNumero != FALSE)
		pivote = incidencias[primero].NumIncidencia;
	else
		pivote = incidencias[primero].Prioridad;

	//Hasta que i y j se crucen se va recorriendo el vector y poniendo los elementos menores o iguales del pivote a su izquierda
	//y los valores mayores a su derecha
	while(i <= j) {


		if(i <= j) {
		
			if(ObtenerValor(incidencias+i, PorNumero) <= pivote)
			{
				i++;
			}
			
			if(ObtenerValor(incidencias+j, PorNumero) > pivote)
			{
				
				j--;
	 		}
		}


		if(i < j) {
			
			if(ObtenerValor(incidencias+i, PorNumero) > pivote && ObtenerValor(incidencias+ j, PorNumero) <= pivote)
			{
				Copiar(incidencias+i, &aux);
				Copiar(incidencias+j, incidencias+i);
				Copiar(&aux, incidencias+j);
				i++;
				j--;
			}
			
		}

	}

	//Intercambiamos el primer elemento, que era el pivote, por la posicion de j
	//Asi los elementos mayores al pivote se encontraran a su derecha y los menores o iguales
	// a su izquierda
	if(j!=primero) {
		Copiar(incidencias+primero, &aux);
		Copiar(incidencias+j, incidencias+primero);
		Copiar(&aux, incidencias+j);
	}


	return j;

}

void QuickSort (tIncidencia *incidencias, unsigned izda, unsigned dcha, tBoolean PorNumero) {
	//Variables: posicion del pivote
	unsigned pivote = 0;
	//Hasta que se crucen la primera y ultima posicion se llama a la funcion de forma recursiva
	if(izda < dcha) {
		pivote = Partir(incidencias, izda, dcha, PorNumero);

		if(pivote > 0)
			QuickSort (incidencias, izda, pivote-1, PorNumero);

		QuickSort (incidencias, pivote+1, dcha, PorNumero);
	}
}
