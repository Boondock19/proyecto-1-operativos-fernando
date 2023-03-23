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
    Varibles globales de archivos de carga y categorizacion de servicio
    y tiempo de la simulacion.
*/
float timeOfSim = 0.25;
char *fileOfService = NULL;
char *fileOfCharge = NULL;

int main(int argc, char *argv[]) {

    //Lectura de comandos de entrada
    if(argc == 1) {
        printf("No se especifico ningun comando\n");
        return 0;
    }

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
            readTxt(fileOfService);
            break;
        case 5:
            if (strcmp(argv[3], "-c") == 0) {
                printf("Especifico el archivo de carga %s\n",argv[4]);
                printf("No especifico un tiempo de simulacion, se tomara 0.25s\n");
                fileOfCharge = argv[4];
                timeOfSim = 0.25;
                readCsv(fileOfCharge);
                readTxt(fileOfService);
            } else if (strcmp(argv[3], "-t") == 0) {
                printf("No especifico un archivo de carga, se tomara el archivo carga.csv\n");
                printf("Especifico el tiempo de simulacion %s\n",argv[4]);
                fileOfCharge = "carga.csv";
                timeOfSim = atof(argv[4]);
                readCsv(fileOfCharge);
                readTxt(fileOfService);
            }
            break;
        case 7:
            printf("Especifico el archivo de carga %s\n",argv[4]);
            printf("Especifico el tiempo de simulacion %s\n",argv[6]);
            fileOfCharge = argv[4];
            timeOfSim = atof(argv[6]);
            readCsv(fileOfCharge);
            readTxt(fileOfService);
            break;
        default:
            break;
        }

    } else {
        printf("Error: No se especifico un txt de categorizacion de servicio\n");
    }

    
    return 0;
}