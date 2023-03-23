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

struct bus{
    int users_space;
    char stop[4];
    char time[6];
    char route_duration[6];
};
typedef struct bus Bus;

typedef struct stop Stop;

void trimWord(char *str, char *str1);
void readCsv(char* route);

