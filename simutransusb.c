#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>


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
        printf("si tomo la s\n");
        fileOfService = argv[2];
        switch (argc)
        {
        case 3:
            printf("Se toma carga.csv y 0.25s\n");
            timeOfSim = 0.25;
            fileOfCharge = "carga.csv";
            break;
        case 5:
            if (strcmp(argv[3], "-c") == 0) {
                printf("Si toma c y 0.25s\n");
                fileOfCharge = argv[4];
                timeOfSim = 0.25;
            } else if (strcmp(argv[3], "-t") == 0) {
                printf("Si toma t y carga.csv\n");
                fileOfCharge = "carga.csv";
                timeOfSim = atof(argv[4]);
            }
            break;
        case 7:
            printf("Si toma c y t\n");
            fileOfCharge = argv[4];
            timeOfSim = 0.25;
            break;
        default:
            break;
        }

    } else {
        printf("ERROR: File name not inserted in command\n");
    }

    
    return 0;
}