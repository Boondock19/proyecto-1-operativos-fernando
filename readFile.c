#include "readFile.h"


Stop* stops[MAX_STOPS];


void trimWord(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    // Iterate String until last
    // leading space character
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    // Run a for loop from index until the original
    // string ends and copy the content of str to str1
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
 
    // Insert a string terminating character
    // at the end of new string
    str1[k] = '\0';
 
    // Print the string with no whitespaces
   printf("Trimmed String: %s", str1);
}

void readCsv(char* route) {
    FILE *fp;
    char row[MAX_CHAR];
    char *token;
    int hours[25] = {-1};
    int j = 0;

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
        Stop* stop;
        int i = 0;
        token = strtok(row, ",");
        stop = (Stop *) malloc (sizeof(Stop));
        cod = token;
        strcpy(stop->cod, cod);


        token = strtok(NULL, ",");
        
        if (token == NULL)
            break;
        recorrido = token;
        char recorridoTrimmed [10];
        trimWord(recorrido,recorridoTrimmed);
        strcpy(stop->route_duration, recorridoTrimmed);

        while (token != NULL) {
            int users;

            token = strtok(NULL, ",");
            PassengersLoad* load;
            load = (PassengersLoad *) malloc (sizeof(PassengersLoad));

            if (token == NULL)
                break;
            
            load->time = hours[i]; 
            users = atoi(token);
            load->users = users;
            i++;
        }
        stops[j] = stop;
        j++;

        printf("\n");
    }

}