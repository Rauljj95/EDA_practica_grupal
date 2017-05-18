/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Incidencias.h
           Autores: Ra�l Jim�nez Ju�rez. Beatriz Mag�n Pinto.

           Descripcion: Declaracion de las funciones para la estructura
           tIncidencias

           Version: 2.0
           Fecha de �ltima modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/



#ifndef INCIDENCIAS_H
#define INCIDENCIAS_H


//Incluimos las cabeceras de tipos de datos y ordenacion
#include "types.h"
#include "Ordenacion.h"



/**
NOMBRE: OrdenarIncidencias
DESCRIPCI�N: Ordena las incidencias llamando a la funcion QuickSort y presenta
en pantalla las incidencias m�s prioritarias con todos sus datos (como maximo
presentar� cinco incidencias).
PARAMETROS DE ENTRADA/SALIDA:
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene.
*/
void OrdenarIncidencias (tIncidencia *incidencias, unsigned N);


/**
NOMBRE: ModificarIncidencia
DESCRIPCI�N: Permite modificar los datos de una incidencia.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: numero de la incedencia a modificar.
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene.
*/
void ModificarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad);


/**
NOMBRE: BuscarIncidencia
DESCRIPCI�N: Permite buscar los datos de una incidencia.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: numero de la incedencia a buscar.
p: puntero a las incidencias.
N: n�mero de incidencias.
RETORNO DE LA FUNCI�N: No tiene.
EECTOS COLATERALES: No tiene.
*/

tBoolean BuscarIncidencia (unsigned Incidencia, tIncidencia *incidencias, unsigned inicio, unsigned Cantidad, unsigned *posicion);


/**
NOMBRE: MostrarIncidencia
DESCRIPCI�N: Muestra por consola la incidencia requerida por el usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia que queremos mostrar
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void MostrarIncidencia (tIncidencia *incidencia);


/**
NOMBRE: PedirDatos
DESCRIPCI�N: Funcion que pide al usuario los datos de la incidencia para su posterior registro.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void PedirDatos (tIncidencia *incidencia);


/**
NOMBRE: AgregarIncidencia
DESCRIPCI�N: Funcion que inserta la incidencia requerida al usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
Cantidad: cantidad de incidencias
RETORNO DE LA FUNCI�N: Devuelve el puntero incidencia.
EECTOS COLATERALES: El hecho de que el almacen de incidencias aumenta en cantidad al a�adir la incidencia.
*/
tIncidencia *AgregarIncidencia( tIncidencia *incidencias , unsigned Cantidad);


/**
NOMBRE: MostrarIncidencia
DESCRIPCI�N: Muestra por consola la incidencia requerida por el usuario.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia que queremos mostrar
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void MostrarIncidencia (tIncidencia *incidencia);


/**
NOMBRE: MostrarTodasIncidencias
DESCRIPCI�N: Muestra por consola todas las incidencias guardadas.
PARAMETROS DE ENTRADA/SALIDA:
Incidencias: incidencias que estan guardadas de tipo tIncidencia y Cantidad de las mimsas de tipo unsigned.
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void MostrarTodasIncidencias(tIncidencia *incidencias, unsigned Cantidad);


/**
NOMBRE: PedirDatos
DESCRIPCI�N: Funcion que pide al usuario los datos de la incidencia para su posterior registro.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia: incidencia a pedir sus datos.
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void PedirDatos (tIncidencia *incidencia);


/**
NOMBRE: Copiar
DESCRIPCI�N: Funcion que copia una estructura tIncidencia en otra.
PARAMETROS DE ENTRADA/SALIDA:
Incidencia origen: Incidencia que queremos copiar.
Incidencia destino: Estructura donde queremos copiar la incidencia
RETORNO DE LA FUNCI�N: No tiene. Es void.
EECTOS COLATERALES: No tiene.
*/
void Copiar(tIncidencia *origen, tIncidencia *destino);


#endif
