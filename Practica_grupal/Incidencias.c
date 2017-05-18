/*
 --------- TRABAJO GRUPAL. ESTRUCTURAS DE DATOS Y ALGORITMOS.-----------
           Archivo: Incidencias.c
           Autores: Raúl Jiménez Juárez. Beatriz Magán Pinto.

           Descripcion: Contiene la implementacion de las funciones relacionadas
           con la estructura incidencias.

           Version: 2.0
           Fecha de última modificacion: 18 de Mayo de 2017
 -----------------------------------------------------------------------
*/


#include <stdio.h>
#include <string.h> //Libreria añadida por nosotros 
#include <stdlib.h>
#include <time.h>//Añado la libreria <time.h> porque necesitare que la fecha se ajuste automaticamente.
#include "Incidencias.h"


void Copiar(tIncidencia *origen, tIncidencia *destino) {
	if(origen == destino)
		return;
	strcpy(destino->Asunto, origen->Asunto);
	strcpy(destino->Descripcion, origen->Descripcion);
	strcpy(destino->Fecha, origen->Fecha);
	strcpy(destino->Sistema, origen->Sistema);
	strcpy(destino->Subsistema, origen->Subsistema);
	destino->Estado = origen->Estado;
	destino->NumIncidencia = origen->NumIncidencia;
	destino->Prioridad = origen->Prioridad;
}


tBoolean BuscarIncidencia (unsigned Incidencia, tIncidencia *incidencias, unsigned inicio, unsigned Cantidad, unsigned *posicion) {
	tBoolean encontrado = FALSE;
	unsigned mitad= ( inicio +Cantidad )/ 2;

	if(incidencias[mitad].NumIncidencia==Incidencia ) {
		*posicion = mitad;
		encontrado = TRUE;
	} else if(incidencias[inicio].NumIncidencia==Incidencia) {
		*posicion = inicio;
		encontrado = TRUE;
	} else if(incidencias[Cantidad].NumIncidencia==Incidencia) {
		*posicion = Cantidad;
		encontrado = TRUE;
	} else if(inicio == Cantidad) {
		return encontrado;
	} else if(incidencias[mitad].NumIncidencia<Incidencia) {
		encontrado = BuscarIncidencia(Incidencia, incidencias, mitad+1, Cantidad, posicion);
	} else if(incidencias[mitad].NumIncidencia>Incidencia && mitad != 0) {
		encontrado = BuscarIncidencia(Incidencia, incidencias, inicio, mitad-1, posicion);
	}
	return encontrado;


}


void OrdenarIncidencias (tIncidencia *incidencias, unsigned N) {
	
	if(incidencias==NULL) {
		printf("No se puede ordenar porque no existen incidencias\n");
		return;
	}
	
	//Ordena las incidencias por prioridad
	QuickSort(incidencias, 0, N-1, FALSE);
	
	//Muestra las 5 primeras, o todas si hay menos
	printf(" Incidencias ordenadas por prioridad:\n");
	if(N > 4)
		MostrarTodasIncidencias(incidencias, 5);
	else
		MostrarTodasIncidencias(incidencias, N);

	
	QuickSort(incidencias, 0, N-1, TRUE);
}

void ModificarIncidencia (unsigned Incidencia, tIncidencia *p, unsigned Cantidad) {
	
	//Guarda la posicion de la incidencia a modificar
	unsigned Indice = 0;
	
	//Si la incidencia se ha encontrado, te pide los nuevos datos
	if(BuscarIncidencia(Incidencia, p, 0, Cantidad-1, &Indice) != FALSE) {

		printf("\n Datos de la incidencia a modificar:\n");
		MostrarIncidencia(p+Indice);
		printf("Estado: %u\n", p[Indice].Estado);

		printf("\nIntroduzca los nuevos datos de la incidencia:\n");
		PedirDatos(p+Indice);
		printf("\nIncidencia modificada: \n");
		MostrarIncidencia(p+Indice);
		printf("Estado: %u\n", p[Indice].Estado);
	} else {
		printf("\nNo se ha encotrado la incidencia.\n");
	}

}

void MostrarIncidencia (tIncidencia *incidencia) { //Autoria: Beatriz
	//Si la incidencia es NULL no existe y no se puede mostrar
	if(incidencia==NULL) {
		printf("No se puede mostrar la incidencia.\n");
		return;
	}

	//Mostramos los valores de la estructura tIncidencias (menos estado)
	printf("\n\n\tNumero de incidencia: %u\n", incidencia->NumIncidencia);
	printf("\n\tPrioridad: %u\n", incidencia->Prioridad );
	printf("\n\tAsunto: %s\n", incidencia->Asunto);
	printf("\n\tSistema: %s\n", incidencia->Sistema);
	printf("\n\tSubsistema: %s\n", incidencia->Subsistema);
	printf("\n\tFecha: %s\n", incidencia->Fecha);
	printf("\n\tDescripcion: %s\n", incidencia->Descripcion);
}


void PedirDatos (tIncidencia *incidencia) { //AUTORIA: BEATRIZ

	//Variable auxiliar para guardar el texto que introduce el usuario
	char variableAuxiliar[1500];

	//Asignamos al campo de fecha la fecha actual
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	strftime(incidencia->Fecha,11,"%d/%m/%y",tlocal);

	//Pedimos la prioridad, controlando que se encuentre entre 1 y 4
	do {
		printf("\nIntroduce la prioridad, siendo 1 la mayor prioridad y 4 la menor\n");
		fflush(stdin);
		scanf("%u", &incidencia->Prioridad);
		while(getchar()!='\n');
		if(incidencia->Prioridad  >4 || incidencia->Prioridad<1) {
			printf("Por favor, introduzca un numero perteneciente al intervalo [1,4]\n");
		}
	} while(incidencia->Prioridad >4 || incidencia->Prioridad<1);

	//Pedimos el asunto, asegurando que no supere la longitud maxima
	do {
		printf("\nIntroduce el asunto\n");
		fflush(stdin);
		fgets(variableAuxiliar, 1500, stdin);
		variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

		if(strlen(variableAuxiliar)>149) {
			printf("Se ha excedido la longitud del array\n");
		}
	} while(strlen(variableAuxiliar)>149);
	strcpy(incidencia->Asunto, variableAuxiliar);

	//Pedimos el sistema, asegurando que no supere la longitud maxima
	do {
		printf("\nIntroduce el sistema\n");
		fflush(stdin);
		fgets(variableAuxiliar, 1500, stdin);
		variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

		if(strlen(variableAuxiliar)>8) {
			printf("Se ha excedido la longitud del array\n");
		} else if(variableAuxiliar[0]=='\0') //Si esta vacio, se lo decimos al usuario
			printf("Si no conoce a que sistema afecta la incidencia, por favor, teclee '-'.\n");

	} while(strlen(variableAuxiliar)>8 || variableAuxiliar[0]=='\0');
	strcpy(incidencia->Sistema, variableAuxiliar);

	//Pedimos el subsistema, asegurando que no supere la longitud maxima
	do {
		printf("\nIntroduce el Subsistema\n");
		fflush(stdin);
		fgets(variableAuxiliar, 1500, stdin);
		variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

		if(strlen(variableAuxiliar)>8) {
			printf("Se ha excedido la longitud del array\n");
		} else if(variableAuxiliar[0]=='\0') //Si esta vacio, se lo decimos al usuario
			printf("Si no conoce a que sistema afecta la incidencia, por favor, teclee '-'.\n");


	} while(strlen(variableAuxiliar)>8 || variableAuxiliar[0]=='\0');
	strcpy(incidencia->Subsistema, variableAuxiliar);

	printf("\nLa fecha actual es: \n");
	printf("%s\n",incidencia->Fecha);


	//Pedimos la Descripcion, asegurando que no supere la longitud maxima
	do {

		printf("\nIntroduce la Descripcion\n");
		fflush(stdin);
		fgets(variableAuxiliar, 1500, stdin);
		variableAuxiliar[strlen(variableAuxiliar) - 1] = 0;

		if(strlen(variableAuxiliar)>499) {
			printf("Se ha excedido la longitud del array\n");
		} else if (variableAuxiliar[0]=='\0') {
			printf("La descripcion no puede estar vacia.\n");
		}
	} while(strlen(variableAuxiliar)>499 || variableAuxiliar[0]=='\0');

	strcpy(incidencia->Descripcion, variableAuxiliar);

//Pedimos el estado, asegurando que se encuentre entre 0 y 2
	do {
		incidencia->Estado=-1;
		printf("\nIntroduce el estado\n");
		fflush(stdin);
		scanf("%u", &incidencia->Estado);
		while(getchar()!='\n');
		if(incidencia->Estado >2) {
			printf("No es posible. El estado puede ser: 0, 1 o 2\n");
		}
	} while(incidencia->Estado >2);


}


tIncidencia *AgregarIncidencia( tIncidencia *incidencias , unsigned Cantidad) { //AUTORIA: RAUL Y BEA

	unsigned Indice = 0; //Variable que guarda la posicion de una incidencia
	tBoolean existe = FALSE; //Variable que guarda si la incidencia existe o no
	unsigned NumeroIncidencia = 0; //Variable que guarda el numero de incidencia

	//Reasignamos memoria a la estructura para guardar un elemento mas
	incidencias=(tIncidencia*)realloc(incidencias, Cantidad*sizeof(tIncidencia));

	if(incidencias==NULL) {
		printf("\nError de memoria...");
		return incidencias;
	}

	do {
		//Pedimos al usuario el numero de la nueva incidencia
		printf("Introduce numero de la incidencia a guardar\n");
		fflush(stdin);
		scanf("%u", &NumeroIncidencia);
		while(getchar()!= '\n');

		//Comprobamos si el numero de esa incidencia ya existe.
		if(Cantidad > 2)
			existe = BuscarIncidencia(NumeroIncidencia, incidencias, 0, Cantidad-2, &Indice);

		if(NumeroIncidencia <= 0)
			printf("\n El numero de incidencia debe ser mayor de 0.\n");
		else if(existe != FALSE)
			printf("\n Ese numero de incidencia ya existe.\n");

	} while(NumeroIncidencia <= 0 || existe != FALSE);

	//Pedimos el resto de datos de la incidencia
	PedirDatos(&incidencias[Cantidad-1]);

	incidencias[Cantidad-1].NumIncidencia = NumeroIncidencia;

	printf("\nIncidencia agregada:");
	MostrarIncidencia(&incidencias[Cantidad-1]);
	printf("\n\tEstado: %u\n", incidencias[Cantidad-1].Estado);

	//Ordenamos las incidencias por numero de incidencias
	QuickSort(incidencias, 0, Cantidad-1, TRUE);

	return incidencias;
}

void MostrarTodasIncidencias(tIncidencia *incidencias, unsigned Cantidad) {
	unsigned posicion=0; //Variable de posicion

	if(incidencias==NULL) {
		printf("No existen incidencias\n");
		return; //Para no necesitar poner un else. Return sale de la funcion
	}

	//Recorremos todo el array de incidencias y lo mostramos por pantalla
	while(posicion < Cantidad) {
		MostrarIncidencia(incidencias+posicion);
		posicion++;
	}

}
