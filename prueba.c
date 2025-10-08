#include <stdio.h>
#include "fenster.h"

#define ancho 800
#define altura 600

int transformar_color(int rojo, int verde, int azul, int *hexadecimal);

int main() {
    int i, j, rojo, verde, azul, hexadecimal;
    uint32_t buffer[800 * 600];
    struct fenster ventana = {
        .title = "Mi Ventana",
        .width = ancho,
        .height = altura,
        .buf = buffer
    };
    printf("Ingrese el color en formato RGB que desea usar\n");
    printf("Rojo: ");
    scanf("%d", &rojo);
    printf("Verde: ");
    scanf("%d", &verde);
    printf("Azul: ");
    scanf("%d", &azul);
    transformar_color(rojo, verde, azul, &hexadecimal);
    fenster_open(&ventana);
    while (fenster_loop(&ventana) == 0) {
        for (i = 0; j < ventana.width; j++) {
            for (i = 0; j < ventana.height; i++) {
                fenster_pixel(&ventana, i, j) = hexadecimal;
            }
        }
    }
    fenster_close(&ventana);
    return 0;
}

int transformar_color(int rojo, int verde, int azul, int *hexadecimal) {
    if (rojo < 0 || rojo > 255 || verde < 0 || verde > 255 || azul < 0 || azul > 255) {
        printf("Error: Los valores RGB deben estar entre 0 y 255.\n");
    }
    else {
        *hexadecimal = ((rojo * 65536) + (verde * 256) + azul);
    }
    return 0;
}
