#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Estructura de las preguntas del juego
typedef struct {
    char pregunta[256];
    char opciones[4][70];
    char respuestaCorrecta;
} Pregunta;


int main() {
    int puntaje = 0;
    int totalPreguntas = 8;
    char respuesta; 
    Pregunta pregunta; 

    printf("¡Bienvenido al juego de trivia sobre Git y GitHub!\n");

    // Leemos las preguntas que utilizaremos en el juego. 

    FILE *archivo = fopen("preguntas.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de preguntas.\n");
        return 1; // Salir del programa con código de error
    }

    // Arreglo que contendrá todas nuestras preguntas
    Pregunta preguntas[totalPreguntas];

    // Leer las preguntas desde el archivo
    for (int i = 0; i < totalPreguntas; i++) {
        fgets(preguntas[i].pregunta, sizeof(preguntas[i].pregunta), archivo); // Leer la pregunta
        for (int j = 0; j < 4; j++) {
            fgets(preguntas[i].opciones[j], sizeof(preguntas[i].opciones[j]), archivo); // Leer las opciones
        }
        fscanf(archivo, "%c\n", &preguntas[i].respuestaCorrecta); // Leer la respuesta correcta
    }

    fclose(archivo); 

    printf("\nTu puntaje total es: %i de %i\n", puntaje, totalPreguntas);

    return 0; 

}


