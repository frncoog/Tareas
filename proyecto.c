#include <stdio.h>

#define filas 7
#define columnas 7

char matriz[filas][columnas];

void leer_datos();
void imprimir_matriz();
int comprobar_movimiento(int [],int [], int , int , int);
void resolver();
void mover(int [],int [], int , int , int);
int  ganar();
void devolver(int[], int[], int, int, int);

int main(){
    leer_datos();
    imprimir_matriz();
    resolver();
    imprimir_matriz();
    return 0;
}

void leer_datos(){
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

void resolver(){
    int i, j, k;
    int pos1[] = {-1, 1, 0, 0};
    int pos2[]= {0, 0, -1, 1};
    
    if (ganar()){
        return;
    }

    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            for(k = 0 ; k < 4 ; k++){
                if ((comprobar_movimiento(pos1, pos2, k, i, j))){
                    mover(pos1, pos2, k, i, j);
                    imprimir_matriz();
                    resolver();
                    devolver(pos1, pos2, k, i, j);
                    if (ganar()){
                        return;
                    }
                }
            }
        }
    }
}

int ganar (){
    int i, j, contador = 0;

    for(i = 0 ; i < filas ; i++){
        for (j = 0 ; j < columnas ; j++){
            if(matriz[i][j] == 'X'){
                contador++;
            }
        }
    }

    if ((matriz[3][3] == 'X') && (contador == 1)){
        return 1;
    }

    return 0; 
}

void imprimir_matriz(){
    int i, j;
    for(i = 0 ; i < filas ; i++){
        for (j = 0 ; j < columnas ; j++){
            printf("%c", matriz[i][j]);
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

    if((i < 0) || (i >= filas) || (j < 0) || (j >= columnas)){
        return 0;
    }
    if((posi < 0) || (posi >= filas) || (posj < 0)||(posj >= columnas)){
        return 0;
    }     
    if((doblei < 0) || (doblei >= filas) || (doblej < 0) || (doblej >= columnas)){
        return 0;
    }
    
    if ((matriz[i][j] == 'X') && (matriz[i + (pos1[k])][j +(pos2[k])] == 'X') && (matriz[i + (2*pos1[k])][j + (2*pos2[k])] == ' ')){
        return 1;
    }
    return 0;
}

void mover(int pos1[], int pos2[], int k, int i, int j){
    matriz[i][j] = ' ';
    matriz[i + (pos1[k])][j +(pos2[k])] = ' ';
    matriz[i + (2*pos1[k])][j + (2*pos2[k])] = 'X';
}

void devolver(int pos1[], int pos2[], int k, int i, int j){
    matriz[i][j] = 'X';
    matriz[i + (pos1[k])][j +(pos2[k])] = 'X';
    matriz[i + (2*pos1[k])][j + (2*pos2[k])] = ' ';
}