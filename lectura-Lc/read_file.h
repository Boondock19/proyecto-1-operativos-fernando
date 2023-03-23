#ifndef READ_FILE_H_
#define READ_FILE_H_

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <time.h>

#define MAX_STOPS 100
#define MAX_BUSES 100

struct carga{
    int hora;
    int usuarios;
}; 
typedef struct carga Carga;

struct bus{
    int capacidad;
    char parada[4];
    char hora[6];
    char duracion_recorrido[6];
};
typedef struct bus Bus;

struct parada{
    int cantidad_buses;
    char codigo[4];
    char nombre[20];
    char duracion_recorrido[6];
    Bus* buses[MAX_BUSES];
    Carga* cargas[24];
};
typedef struct parada Parada;

extern int cantidad_paradas;
extern Parada* g_paradas[MAX_STOPS];
char* trim_white_space(char* str);
Parada* obtener_parada(char* codigo);
void obtener_caracterizacion(char* ruta);
void obtener_carga(char* ruta);
void listar_paradas();
void free_paradas();


#endif