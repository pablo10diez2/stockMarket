#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funcion.h"

void gestionCSV(){
    printf("hola");
}

bool comprobarCredenciales(){
    return true;
}

void iniciarPrograma(){
    char str[30];

    printf("Welcome to the Admin Menu \n");
    
    iniciarSesion();
    
}

void iniciarSesion(){
    char mail[30];
    char pass[30];
    int num;

    printf("Introduce tu e-mail: \n");
    scanf("%s", mail);

    printf("Introduce tu contraseña: \n");
    scanf("%s", pass);

    if(comprobarCredenciales()){
        printf("Introduce 1 para gestionar el fichero");
        scanf("%d", &num);
        
        if(num == 1){
            gestionCSV();
        }
    }
    else{
        iniciarSesion();
    }
}


