#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "fichero.h"

void convertirMayusculas(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = toupper((unsigned char) str[i]);
    }
}

void buscarEmpresa(){
    char linea[256];
    FILE *file = fopen("data/stock_info.txt", "r");
    char busqueda[32];
    char modificado[100];

    printf("---Introduce el nombre de la empresa: ");
    scanf("%s", busqueda);

    while(fgets(linea, sizeof(linea), file) != NULL){
        char *ticker = strtok(linea, ",");
        char *name = strtok(NULL, ",");

        if(strlen(name)>strlen(busqueda)){
            strncpy(modificado, name, strlen(busqueda));
        }

        convertirMayusculas(modificado);
        convertirMayusculas(busqueda);


       if(strcmp(modificado, busqueda) == 0){
            printf("Nombre de la empresa: %s, Ticker de la empresa: %s \n",name, ticker);
        }
    }
}

void añadirEmpresa(){
    FILE *file = fopen("data/stock_info.txt","a");
    char ticker[10];
    char nombre[100];
    char linea[110];

    printf("Introduce el TICKER de la empresa: ");
    scanf("%s", ticker);

    printf("Introduce el nombre de la empresa: ");
    scanf("%s", nombre);

    fprintf(file, "%s,%s", ticker, nombre);

    fclose(file);
}

void eliminarEmpresa(){
    char original[] = "data/stock_info.txt";
    char temporal[] = "data/temporal.txt";
    char tickerUsuario[10];
    char linea[250];

    FILE *ficheroOriginal = fopen(original, "r");
    FILE *ficheroTemporal = fopen(temporal, "w");

    printf("Introduce el ticker de la empresa que quieres borrar: \n");
    scanf("%s", tickerUsuario);

    while(fgets(linea, 250, ficheroOriginal)){
        char *tickerEmpresa = strtok(linea, ",");

        if(strcmp(tickerEmpresa, tickerUsuario) != 0){
            fputs(linea, ficheroTemporal);
        }
    }
    fclose(ficheroOriginal);
    fclose(ficheroTemporal);

    remove(original);
    rename(temporal, original);

}

bool comprobarCredenciales(char mail[], char contraseña[]){
    char filename[] = "data/config.txt";
    char line[30];

    FILE *file = fopen(filename, "r");

    while(fgets(line, sizeof(line), file) != NULL){
        char *uemail = strtok(line, ";");
        char *upass = strtok(NULL, ";");

        if(strcmp(uemail, mail) == 0 && strcmp(upass, contraseña) == 0){
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}
