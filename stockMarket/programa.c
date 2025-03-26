#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "programa.h"
#include "fichero.h"

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


