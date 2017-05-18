/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: types.h

           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.

           Descripcion: Archivo que contiene la declaracion de constantes y
           tipos de datos

           Version: 2.0
           Fecha de última modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/

#ifndef TYPES_H
#define TYPES_H

#define ESTADO_CREADA 0
#define ESTADO_RESOLVIENDOSE 1
#define ESTADO_SOLUCIONADA 2

#define NOM_FICHERO "h_incidencias.bin"


//Declaracion de la estructura tIncidencia
typedef struct {
	unsigned NumIncidencia;
	unsigned Prioridad;
	char Asunto[150];
	char Sistema[9];
	char Subsistema[9];
	char Fecha[11];
	char Descripcion [500];
	unsigned Estado;
} tIncidencia;

typedef enum {FALSE, TRUE} tBoolean;

#endif
