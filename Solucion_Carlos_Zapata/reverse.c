#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGITUD_LINEA 1024 // Definimos el tamaño máximo de una línea

// Estructura para almacenar una línea
typedef struct NodoLinea {
    char *linea;              // Puntero para almacenar la línea de texto
    struct NodoLinea *siguiente; // Puntero al siguiente nodo (enlace a la siguiente línea)
} NodoLinea;

// Función para agregar una línea a la lista enlazada
NodoLinea* agregar_linea(NodoLinea *cabeza, char *linea) {
    NodoLinea *nuevo_nodo = (NodoLinea *)malloc(sizeof(NodoLinea)); // Reservamos memoria para un nuevo nodo
    if (nuevo_nodo == NULL) {
        fprintf(stderr, "Error: memoria insuficiente\n");
        exit(1); // Salimos si no hay memoria suficiente
    }
    nuevo_nodo->linea = strdup(linea); // Copiamos la línea en el nuevo nodo
    if (nuevo_nodo->linea == NULL) {
        fprintf(stderr, "Error: memoria insuficiente\n");
        exit(1); // Salimos si no hay memoria suficiente
    }
    nuevo_nodo->siguiente = cabeza; // El nuevo nodo apunta al nodo anterior (el que era cabeza)
    return nuevo_nodo; // Devolvemos el nuevo nodo que ahora es la cabeza de la lista
}

// Función para liberar la memoria de la lista enlazada
void liberar_lineas(NodoLinea *cabeza) {
    NodoLinea *actual = cabeza; // Empezamos desde la cabeza de la lista
    while (actual != NULL) {
        NodoLinea *temporal = actual;   // Guardamos el nodo actual para luego liberarlo
        actual = actual->siguiente;     // Pasamos al siguiente nodo
        free(temporal->linea);          // Liberamos la memoria de la línea
        free(temporal);                 // Liberamos la memoria del nodo
    }
}

// Función principal
int main(int cantidad_argumentos, char *argumentos[]) {
    FILE *archivo_entrada = stdin; // Por defecto, la entrada será el terminal
    FILE *archivo_salida = stdout; // Por defecto, la salida será el terminal
    NodoLinea *lista_lineas = NULL; // Inicializamos la lista de líneas como vacía
    char buffer[MAX_LONGITUD_LINEA]; // Buffer para almacenar temporalmente las líneas leídas

    // Manejo de argumentos
    if (cantidad_argumentos > 3) { // Si se pasan más de dos argumentos, hay un error
        fprintf(stderr, "Uso: reverse <archivo_entrada> <archivo_salida>\n");
        exit(1);
    }

    if (cantidad_argumentos >= 2) { // Si se pasa un archivo de entrada
        archivo_entrada = fopen(argumentos[1], "r"); // Abrimos el archivo de entrada
        if (archivo_entrada == NULL) { // Si no se pudo abrir el archivo, mostramos un error
            fprintf(stderr, "Error: no se puede abrir el archivo '%s'\n", argumentos[1]);
            exit(1);
        }
    }

    if (cantidad_argumentos == 3) { // Si también se pasa un archivo de salida
        archivo_salida = fopen(argumentos[2], "w"); // Abrimos el archivo de salida
        if (archivo_salida == NULL) { // Si no se puede abrir el archivo, mostramos un error
            fprintf(stderr, "Error: no se puede abrir el archivo '%s'\n", argumentos[2]);
            exit(1);
        }

        // Si el archivo de entrada y salida son el mismo, mostramos un error
        if (strcmp(argumentos[1], argumentos[2]) == 0) {
            fprintf(stderr, "Error: el archivo de entrada y salida deben ser diferentes\n");
            exit(1);
        }
    }

    // Leer el archivo de entrada línea por línea y agregar a la lista
    while (fgets(buffer, MAX_LONGITUD_LINEA, archivo_entrada) != NULL) {
        lista_lineas = agregar_linea(lista_lineas, buffer); // Agregamos la línea a la lista
    }

    // Imprimir las líneas en orden inverso
    NodoLinea *actual = lista_lineas;
    while (actual != NULL) {
        fprintf(archivo_salida, "%s", actual->linea); // Escribimos cada línea en el archivo de salida
        actual = actual->siguiente; // Pasamos al siguiente nodo
    }

    // Limpiar y liberar la memoria utilizada
    liberar_lineas(lista_lineas); // Liberamos la memoria de las líneas
    if (archivo_entrada != stdin) fclose(archivo_entrada); // Cerramos el archivo de entrada si no es stdin
    if (archivo_salida != stdout) fclose(archivo_salida);  // Cerramos el archivo de salida si no es stdout

    return 0; // Finalizamos el programa
}

