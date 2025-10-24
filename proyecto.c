#include <stdio.h>

#define filas 7
#define columnas 7
#define ficha 'X'
#define vacio ' '
#define invalido 'O'

int a = 0;

char matriz[filas][columnas];
int soluciones[100][4];

void leer_datos();
void imprimir_matriz();
int comprobar_movimiento(int [],int [], int , int , int);
int resolver();
void mover(int [],int [], int , int , int);
int  ganar();
void devolver(int[], int[], int, int, int);

int main(){
    int h,p;
    leer_datos();
    imprimir_matriz();
    if (resolver()) {
        printf("Solucion encontrada:\n");
        imprimir_matriz();
    } else {
        printf("No tiene solucion.\n");
    }
    for(h = 0; h < 100; h++){
        for(p = 0; p < 4; p++){
            printf("%d,", soluciones[h][p]);
        }
        printf("\n");
    }
    return 0;
}

void leer_datos(){
    int i, j;
    for (i = 0; i < filas; i++) {
        for(j = 0 ; j < columnas ; j++){
            scanf("%c", &matriz[i][j]);
            if(matriz[i][j] == '\n' || matriz[i][j] == '\r'){
                j--;
            }
        }
    }
}

int resolver(){
    int i, j, k;
    int pos1[] = {-1, 1, 0, 0};
    int pos2[]= {0, 0, -1, 1};
    if (ganar()){
        return 1;
    }

    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            if(matriz[i][j] == ficha){
                for(k = 0 ; k < 4 ; k++){
                    if ((comprobar_movimiento(pos1, pos2, k, i, j))){
                        mover(pos1, pos2, k, i, j);
                        if (resolver()){
                            soluciones[a][0] = i + 1;
                            soluciones[a][1] = j + 1;
                            soluciones[a][2] = i + pos1[k] + pos1[k] + 1;
                            soluciones[a][3] = j + pos2[k] + pos2[k] + 1;
                            a++;
                            return 1;
                        }
                        devolver(pos1, pos2, k, i, j);
                    }
                }
            }
        }
    }
    return 0;
}

int ganar (){
    int i, j, contador = 0;

    for(i = 0 ; i < filas ; i++){
        for (j = 0 ; j < columnas ; j++){
            if(matriz[i][j] == ficha){
                contador++;
            }
        }
    }

    if ((matriz[3][3] == ficha) && (contador == 1)){
        return 1;
    }

    return 0; 
}

void imprimir_matriz(){
    int i, j;
    for(i = 0 ; i < filas ; i++){
        for (j = 0 ; j < columnas ; j++){
            printf("%1c", matriz[i][j]);
        }
        printf("\n");
    }
}

int comprobar_movimiento(int pos1[],int pos2[], int k, int i, int j){
    int posi, posj, doblei, doblej;
    posi = (i + (pos1[k]));
    posj = (j +(pos2[k]));
    doblei = (i + (2*pos1[k]));
    doblej = (j + (2*pos2[k]));
 
    if((doblei < 0) || (doblei >= filas) || (doblej < 0) || (doblej >= columnas)){
        return 0;
    }
    if ((matriz[i][j] == ficha) && (matriz[posi][posj] == ficha) && (matriz[doblei][doblej] == vacio)){
        return 1;
    }
    return 0;
}

void mover(int pos1[], int pos2[], int k, int i, int j){
    matriz[i][j] = vacio;
    matriz[i + (pos1[k])][j +(pos2[k])] = vacio;
    matriz[i + (2*pos1[k])][j + (2*pos2[k])] = ficha;

}

void devolver(int pos1[], int pos2[], int k, int i, int j){
    matriz[i][j] = ficha;
    matriz[i + (pos1[k])][j +(pos2[k])] = ficha;
    matriz[i + (2*pos1[k])][j + (2*pos2[k])] = vacio;
} 