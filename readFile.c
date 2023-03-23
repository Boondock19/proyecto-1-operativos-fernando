#include "readFile.h"

void readCsv(char* route) {
    FILE *fp;
    char row[MAX_CHAR];
    char *token;
    int hours[25] = {-1};

    fp = fopen(route, "r");
    if (fp == NULL) {
        printf("Error opening file");
    }

    fgets(row, MAX_CHAR, fp);

    if (feof(fp) != true) {
        
        printf("%s", row);
        int i = 0;
        token = strtok(row, ",");
        printf("Este es el token %s\n", token);
        printf("Este es el valor num %d\n", atoi(token));
        if (atoi(token) != 0) {
            hours[i] = atoi(token);
            i++;
        }

        while (token != NULL) {
         
            printf("Este es el token %s\n", token);
            printf("Este es el valor num %d\n", atoi(token));
            token = strtok(NULL, ",");
        }
    }

    while (feof(fp) != true) {
        fgets(row, MAX_CHAR, fp);
        char* cod;
        char* recorrido;

        int i = 0;
        token = strtok(row, ",");
        cod = token;
        printf("Este es el codigo %s\n", cod);


        token = strtok(NULL, ",");
        recorrido = token;
        printf("Este es el token %s\n", token);

        while (token != NULL) {
            int users;
            token = strtok(NULL, " ");
            if (token == NULL)
                break;
            users = atoi(token);
            printf("Este es el la cantidad de users %d\n", users);
        }
        i++;
    }

}