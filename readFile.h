#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define MAX_CHAR 120
#define MAX_STOPS 40

struct passengersLoad{
    int time;
    int users;
}; 
typedef struct passengersLoad PassengersLoad;
struct stop{
    char cod[4];
    char nombre[20];
    char route_duration[6];
    PassengersLoad* load[24];
};
typedef struct stop Stop;

char *trimString(char *str);
void readCsv(char* route);

