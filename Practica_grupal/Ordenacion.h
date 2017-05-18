/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Ordenacion.h

           Autores: Ra�l Jim�nez Ju�rez. Beatriz Mag�n Pinto.

           Descripcion: Contiene la declaracion de las funciones de ordenacion QuickSort y Partir

           Version: 0.1
           Fecha de �ltima modificacion: 3 de Mayo de 2017
 -----------------------------------------------------------------------
*/


#ifndef ORDENACION_H
#define ORDENACION_H

#include "types.h"


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
unsigned Partir (tIncidencia *incidencias, unsigned primero, unsigned ultimo, tBoolean PorNumero);


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
void QuickSort (tIncidencia *incidencias, unsigned izda, unsigned dcha, tBoolean PorNumero);


#endif

