#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define MAX_CHAR 200
#define MAX_STOPS 40

/*
    Struct utilizada para almacenar el tiempo y la carga de un
    transporte/viaje de una parada en un hora determinada.
*/
struct passengersLoad{
    int time;
    int users;
}; 
typedef struct passengersLoad PassengersLoad;

/*
 Struct bus que representa a los autobuses de las paradas.
 Se guarda en ellos la cantidad de espacio que poseen, la parada
 a la que se dirigen/pertenecen, su hora de salida y la duracion 
 del recorrido.
*/
struct bus{
    int users_space;
    char stop[4];
    char time[6];
    char route_duration[6];
};
typedef struct bus Bus;

/*
    Struct stop representa a las paradas de buses de la universidad.
    En esta estructura se almacena el codigo de la parada, su nombre,
    la duracion del recorrido, la cantidad de buses que pasan por la parada
    las instancias de dichos buses y la cantidad de carga de pasajeros 
    dependiendo de la hora.
*/
struct stop{
    char cod[4];
    char nombre[20];
    char route_duration[6];
    int buses_amount;
    Bus* buses[MAX_STOPS];
    PassengersLoad* load[24];
};
typedef struct stop Stop;

/*
    Funcion utilizada para eliminar los espacios en blanco 
    de un string.
*/
void trimWord(char *str, char *str1);

/*
    Funcion encargada de manejar la lectura del archivo de carga
    que son de formato csv, adicionalmente en esta funcion se carga
    la informacion de interes en sus respectivas estructuras para poder ser
    utilizadas en el programa.
*/
void readCsv(char* route);

/* 
    Funcion utilizada para conseguir una parada a partir
    de su codigo.
*/
Stop* getStop(char* cod);

/*
    Funcion encargada de manejar la lectura del archivo de carga
    que son de formato txt, adicionalmente en esta funcion se carga
    la informacion de interes en sus respectivas estructuras para poder ser
    utilizadas en el programa.
*/
void readTxt (char* route);

