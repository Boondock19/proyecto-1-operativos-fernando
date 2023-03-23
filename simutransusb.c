#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include "readFile.h"


/*
#define sizeOfBuffer 1024
#define numRoutes 50
#define hMax 24
#define bMax 200
struct load {
    char cod[4];
    char name[64];
    int 

};

struct service {
    char cod[4];
    char 
};

*/

//Vars
float timeOfSim = 0.25;
char *fileOfService = NULL;
char *fileOfCharge = NULL;

int main(int argc, char *argv[]) {

    //Command
    if (strcmp(argv[1], "-s") == 0) {
        fileOfService = argv[2];
        switch (argc)
        {
        case 2:
            printf("Error: No se especifico un txt de categorizacion de servicio\n");
            break;
        case 3:
            printf("No especifico un archivo de carga, se tomara el archivo carga.csv\n");
            printf("No especifico un tiempo de simulacion, se tomara 0.25s\n");
            timeOfSim = 0.25;
            fileOfCharge = "carga.csv";
            readCsv(fileOfCharge);
            break;
        case 5:
            if (strcmp(argv[3], "-c") == 0) {
                printf("Especifico el archivo de carga %s\n",argv[4]);
                printf("No especifico un tiempo de simulacion, se tomara 0.25s\n");
                fileOfCharge = argv[4];
                timeOfSim = 0.25;
                readCsv(fileOfCharge);
            } else if (strcmp(argv[3], "-t") == 0) {
                printf("No especifico un archivo de carga, se tomara el archivo carga.csv\n");
                printf("Especifico el tiempo de simulacion %s\n",argv[4]);
                fileOfCharge = "carga.csv";
                timeOfSim = atof(argv[4]);
                readCsv(fileOfCharge);
            }
            break;
        case 7:
            printf("Especifico el archivo de carga %s\n",argv[4]);
            printf("Especifico el tiempo de simulacion %s\n",argv[6]);
            fileOfCharge = argv[4];
            timeOfSim = atof(argv[6]);
            readCsv(fileOfCharge);
            break;
        default:
            break;
        }

    } else {
        printf("ERROR: File name not inserted in command\n");
    }

    
    return 0;
}