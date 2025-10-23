#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define filas 7
#define columnas 7


char matriz[filas][columnas];

void leer_datos(char [][columnas]);
void imprimir_matriz(char [][columnas]);

int main(){
    leer_datos(matriz);
    imprimir_matriz(matriz);






    return 0;
}


void leer_datos(char matriz[][columnas]){
    int i, j;
    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            scanf("%c", &matriz[i][j]);
            if(matriz[i][j] == '\n'){
                j--;
            }
        }
    }
}

void imprimir_matriz(char matriz[][columnas]){
    int i, j;
    for(i = 0 ; i < filas ; i++){
        for (j = 0 ; j < columnas ; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}