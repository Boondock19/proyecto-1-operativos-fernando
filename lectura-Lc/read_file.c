#include "read_file.h"

Parada* g_paradas[MAX_STOPS];
int cantidad_paradas = 0;

// Note: This function returns a pointer to a substring of the original string.
// If the given string was allocated dynamically, the caller must not overwrite
// that pointer with the returned value, since the original pointer must be
// deallocated using the same allocator with which it was allocated.  The return
// value must NOT be deallocated using free() etc.
char* trim_white_space(char* str){
    char* end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

//funcion que busca una parada por su codigo en la lista de paradas
Parada* obtener_parada(char* codigo) {
    for(int i = 0; i < MAX_STOPS; i++){
        if(g_paradas[i] != NULL) {
            if(strcmp(g_paradas[i]->codigo, codigo) == 0)
                return g_paradas[i];
        } else {
            break;
        }
    }
    return NULL;
}

void obtener_caracterizacion(char* ruta) {
    char* line = NULL;
    char* token;
    size_t len = 0;
    ssize_t read;
    
    // Abrimos el archivo para leerlo
    FILE* fp = fopen(ruta, "r");

    // Verificamos que el archivo se haya abierto correctamente
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    while ((read = getline(&line, &len, fp)) != -1){
        //printf("Linea leida: %s", line);
        // Usamos la función strtok para obtener los contenidos de la línea
        token = strtok(line, " ");
        //printf("Token: %s\n", token);
        Parada* parada;
        int i = 0;
        
        if (obtener_parada(token) == NULL) {
            printf("La parada %s no existe\n",token);
            continue;
            /*
            parada = (Parada *) malloc (sizeof(Parada));
            strcpy(parada -> codigo, token);
            printf("Codigo de parada: %s\n", parada -> codigo);
            */
        } else {
            parada = obtener_parada(token);
            printf("Parada %s\n", parada -> codigo);
        }
        
        while (token != NULL) {
            char* tk;
            char hora[6] = {'\0'};
            char capacidad[4] = {'\0'};
            Bus* bus = (Bus *) malloc (sizeof(Bus));
            token = strtok(NULL, " ");
            if (token == NULL) 
                break;

            printf("Autobus %d\n", i);
            tk = (char *) malloc (strlen(token) + 1);
            strcpy(tk, token);
            for (int i = 0; i < strlen(tk); i++) {
                if (token[i] == '(') {
                    capacidad[0] = token[i+1];
                    capacidad[1] = token[i+2];
                    capacidad[2] = '\0';
                    break;
                }
                hora[i] = token[i];
            }
            strcpy(bus->hora, hora);
            bus->capacidad = atoi(capacidad);
            printf("capacidad: %d\n", bus -> capacidad);
            parada->buses[i] = bus;
            parada->cantidad_buses++;
            i++;
            free(tk);
        }
        printf("\n");
    }
    
    // Cerramos el archivo y liberamos la memoria asignada para la línea
    fclose(fp);
    if (line)
        free(line);
}

void obtener_carga(char* ruta) {
    char* line = NULL;
    char* token;
    int horas[25] = {-1};
    int j = 0;
    size_t len = 0;
    ssize_t read;
    
    // Abrimos el archivo para leerlo
    FILE* fp = fopen(ruta, "r");

    // Verificamos que el archivo se haya abierto correctamente
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    
    read = getline(&line, &len, fp);
    if (read != -1) {
        token = strtok(line, ",");
        int i = 0;
        while (token != NULL) {
            //printf("Token: %s\n", token);
            //printf("int: %d\n", atoi(token));
            if (atoi(token) != 0) {
                horas[i] = atoi(token);
                //printf("Hora: %d\n", horas[i]);
                i++;
            }
            token = strtok(NULL, ",");            
        }
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char* codigo;
        char* nombre;
        char* recorrido;
        // Usamos la función strtok para obtener los contenidos de la línea
        token = strtok(line, ",");
        Parada* parada;
        int i = 0;
        
        parada = (Parada *) malloc (sizeof(Parada));
        codigo = trim_white_space(token);
        strcpy(parada->codigo, codigo);

        token = strtok(NULL, ",");
        nombre = trim_white_space(token);
        strcpy(parada->nombre, nombre);

        token = strtok(NULL, ",");
        recorrido = trim_white_space(token);
        strcpy(parada->duracion_recorrido, recorrido);

        printf("Parada %s %s:\n", codigo, nombre);
        while (token != NULL) {
            int usuarios;
            Carga* carga_parada = (Carga *) malloc (sizeof(Carga));
            token = strtok(NULL, " ");
            if (token == NULL)
                break;

            carga_parada->hora = horas[i];
            usuarios = atoi(token);
            carga_parada->usuarios = usuarios;
            printf("Hora: %d, usuarios: %d\n", carga_parada->hora, carga_parada->usuarios);
            i++;
        }
        g_paradas[j] = parada;
        cantidad_paradas++;
        j++;
        printf("\n");
    }
    
    // Cerramos el archivo y liberamos la memoria asignada para la línea
    fclose(fp);
    if (line)
        free(line);
}

void listar_paradas(){
    for (int i = 0; i < 100; i++) {
        if (g_paradas[i] != NULL) {
            printf("Parada %s\n", g_paradas[i] -> codigo);
        } else{
            break;
        }
    }
}

void free_paradas() {
    for (int i = 0; i < MAX_STOPS; i++) {
        if (g_paradas[i] != NULL) {
            for (int j = 0; j < MAX_BUSES; j++) {
                if (g_paradas[i] -> buses[j] != NULL) {
                    free(g_paradas[i] -> buses[j]);
                } else{
                    break;
                }
            }
            free(g_paradas[i]);
        } else{
            break;
        }
    }
}