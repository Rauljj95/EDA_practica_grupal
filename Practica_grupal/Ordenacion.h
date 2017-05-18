/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Ordenacion.h

           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.

           Descripcion: Contiene la declaracion de las funciones de ordenacion QuickSort y Partir

           Version: 0.1
           Fecha de última modificacion: 3 de Mayo de 2017
 -----------------------------------------------------------------------
*/


#ifndef ORDENACION_H
#define ORDENACION_H

#include "types.h"


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


#endif

