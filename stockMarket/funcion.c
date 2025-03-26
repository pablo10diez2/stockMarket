#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcion.h"

void convertirMayusculas(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = toupper((unsigned char) str[i]);
    }
}

void buscarEmpresa(){
    char linea[256];
    FILE *file = fopen("data/stock_info.csv", "r");
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
    FILE *file = fopen("data/stock_info","a");
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

}

void gestionarFicheroEmpresa(){
    int num;

    printf("Pulsa 1 para buscar una empresa por su nombre \n");
    printf("Pulsa 2 para añadir una empresa \n");
    printf("Pulsa 3 para eliminar una empresa \n");

    scanf("%d", &num);

    switch(num){
        case 1:
            buscarEmpresa();
            break;

        case 2:
            añadirEmpresa();
            break;

        case 3:
            eliminarEmpresa();
            break;

        default:
            printf("Opción invalida");
            break;
    }
    gestionarFicheroEmpresa();
}

void gestionarUsuario(){
    printf("Gestionando usuario \n");
}

void gestionCSV(){
    printf("hola \n");
}

void menuAdministrador(){
    int num;

    printf("---Bienvenido al menú administrador \n");
    printf("Introduce 1 para gestionar el fichero de empresas \n");
    printf("Introduce 2 para gestionar un usuario \n");
    printf("Introduce 3 para ... \n");

    scanf("%d", &num);

    switch(num){
        case 1:
            gestionarFicheroEmpresa();
            break;
        case 2:
            gestionarUsuario();
            break;
        case 3:
            break;
        default:
            printf("Opción no valida \n");
    }
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

void iniciarPrograma(){
    char str[30];

    printf("---Welcome to the Admin Menu \n");

    iniciarSesion();

}

void iniciarSesion(){
    char mail[30];
    char pass[30];

    printf("Introduce tu e-mail: \n");
    scanf("%s", mail);

    printf("Introduce tu contraseña: \n");
    scanf("%s", pass);

    if(comprobarCredenciales(mail, pass)){
        menuAdministrador();

   }
    else{
        printf("Credenciales invalidas \n");
        iniciarSesion();
    }
}


