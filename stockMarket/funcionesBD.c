#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "funcionesBD.h"

void insertar_nombre(const char *nombre, int id) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int result;

    // Abrir la base de datos y verificar errores
    if (sqlite3_open("JP.sqlite", &db) != SQLITE_OK) {
        printf("Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Consulta SQL corregida
    const char *sql = "UPDATE usuario SET nombre_usuario = ? WHERE id_usuario = ?;";

    // Preparar la consulta
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error preparando consulta: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Asignar valores a los parámetros
    sqlite3_bind_text(stmt, 1, nombre, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);

    // Ejecutar la consulta
    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        printf("Error modificando el nombre: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Nombre modificado correctamente: %s\n", nombre);
    }

    // Liberar recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void insertar_apellido(const char *apellido, int id) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int result;

    // Abrir la base de datos y verificar errores
    if (sqlite3_open("JP.sqlite", &db) != SQLITE_OK) {
        printf("Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Consulta SQL corregida
    const char *sql = "UPDATE usuario SET apellido_usuario = ? WHERE id_usuario = ?;";

    // Preparar la consulta
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error preparando consulta: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Asignar valores a los parámetros
    sqlite3_bind_text(stmt, 1, apellido, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);

    // Ejecutar la consulta
    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        printf("Error modificando el apellido: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Apellido modificado correctamente: %s\n", apellido);
    }

    // Liberar recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
