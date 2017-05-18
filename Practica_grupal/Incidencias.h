/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Incidencias.h
           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.

           Descripcion: Declaracion de las funciones para la estructura
           tIncidencias

           Version: 2.0
           Fecha de última modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/



#ifndef INCIDENCIAS_H
#define INCIDENCIAS_H


//Incluimos las cabeceras de tipos de datos y ordenacion
#include "types.h"
#include "Ordenacion.h"



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
NOMBRE: MostrarTodasIncidencias
DESCRIPCIÓN: Muestra por consola todas las incidencias guardadas.
PARAMETROS DE ENTRADA/SALIDA:
Incidencias: incidencias que estan guardadas de tipo tIncidencia y Cantidad de las mimsas de tipo unsigned.
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void MostrarTodasIncidencias(tIncidencia *incidencias, unsigned Cantidad);


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
NOMBRE: Copiar
DESCRIPCIÓN: Funcion que copia una estructura tIncidencia en otra.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia origen: Incidencia que queremos copiar.
Incidencia destino: Estructura donde queremos copiar la incidencia
RETORNO DE LA FUNCIÓN: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void Copiar(tIncidencia *origen, tIncidencia *destino);


#endif
