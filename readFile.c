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
 
}

void readCsv(char* route) {
    FILE *fp;
    char row[MAX_CHAR];
    char *token;
    int hours[25] = {-1};
    int j = 0;

    fp = fopen(route, "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    fgets(row, MAX_CHAR, fp);

    if (feof(fp) != true) {
        
       
        int i = 0;
        token = strtok(row, ",");
        if (atoi(token) != 0) {
            hours[i] = atoi(token);
            i++;
        }

        while (token != NULL) {
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

    }

    fclose(fp);
}

/*
    Funcion que dado un cod de una estacion o Stop
    retorna el Stop que tiene ese cod.
*/

Stop* getStop(char* cod) {
    for(int i = 0; i < MAX_STOPS; i++){
        if(stops[i] != NULL) {
            if(strcmp(stops[i]->cod, cod) == 0)
                return stops[i];
        } else {
            break;
        }
    }
    return NULL;
}



void readTxt (char* route) {
     FILE *fp;
    char row[MAX_CHAR];
    char *token;
    int hours[25] = {-1};
    int j = 0;

    fp = fopen(route, "r");

    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    

    while (feof(fp) != true){
        fgets(row, MAX_CHAR, fp);
        Stop* stop;
        int i = 0; 
        token = strtok(row, " ");

        if(getStop(token) == NULL) {
            printf("No se consiguio a la Stop %s\n",token);
            continue;
        } else {
            stop = getStop(token);
            printf("Se consiguio a la Stop %s\n",stop->cod);
        }

        while (token != NULL) {
            Bus* bus = (Bus *) malloc (sizeof(Bus));
            token = strtok(NULL, " ");
            char* tempToken;
            char hour[6] = {'\0'};
            char loadCapacity[4] = {'\0'};

            if (token == NULL) break;
                
            tempToken = (char *) malloc (strlen(token)+1);
            strcpy(tempToken, token);
            /* 
                Debemos utilzar esta metodologia para poder
                leer el valor de la capacidad en el arhivo
                dado el formato indicado en el PDF.
            */
            for (int i = 0; i < strlen(tempToken); i++) {
                if (token[i] == '(') {
                    loadCapacity[0] = token[i+1];
                    loadCapacity[1] = token[i+2];
                    loadCapacity[2] = '\0';
                    break;
                }
                hour[i] = token[i];
            }
            
            strcpy(bus->time, hour);
            bus->users_space = atoi(loadCapacity);
            printf("Capacidad: %d\n",bus->users_space);
            stop->buses[i] = bus;
            stop->buses_amount++;
            i++;

            free(tempToken);

        }
        printf("\n");
    }
    fclose(fp);
}