/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Ficheros.h

           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.

           Descripcion: Contiene la declaracion de las funciones de leer y escribir incidencias

           Version: 2
           Fecha de última modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/


#ifndef FICHEROS_H
#define FICHEROS_H

#include "types.h"

/**
NOMBRE: GuardarIncidencias
DESCRIPCIÓN: Función que guarda las incidencias en un fichero.Las incidencias
deberán guardarse ordenadas por número de incidencia.
PARAMETROS DE ENTRADA/SALIDA:
incidencias: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: No tiene.
EECTOS COLATERALES: No tiene.
*/
void GuardarIncidencias (tIncidencia *incidencias, unsigned N);


/**
NOMBRE: LeerIncidencias
DESCRIPCIÓN: Función que lee las incidencias en un fichero.
PARAMETROS DE ENTRADA/SALIDA:
incidencias: puntero a las incidencias.
N: número de incidencias.
RETORNO DE LA FUNCIÓN: tIncidencia* puntero a las incidencias
EECTOS COLATERALES: No tiene.
*/
tIncidencia * LeerIncidencias (tIncidencia *incidencias, unsigned *N);


#endif
