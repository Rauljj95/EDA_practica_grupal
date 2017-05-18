/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Ficheros.h

           Autores: Ra�l Jim�nez Ju�rez. Beatriz Mag�n Pinto.

           Descripcion: Contiene la declaracion de las funciones de leer y escribir incidencias

           Version: 2
           Fecha de �ltima modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/


#ifndef FICHEROS_H
#define FICHEROS_H

#include "types.h"

/**
NOMBRE: GuardarIncidencias
DESCRIPCI�N: Funci�n que guarda las incidencias en un fichero.Las incidencias
deber�n guardarse ordenadas por n�mero de incidencia.
PARAMETROS DE ENTRADA/SALIDA:
incidencias: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene.
*/
void GuardarIncidencias (tIncidencia *incidencias, unsigned N);


/**
NOMBRE: LeerIncidencias
DESCRIPCI�N: Funci�n que lee las incidencias en un fichero.
PARAMETROS DE ENTRADA/SALIDA:
incidencias: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: tIncidencia* puntero a las incidencias
EECTOS COLATERALES: No tiene.
*/
tIncidencia * LeerIncidencias (tIncidencia *incidencias, unsigned *N);


#endif
