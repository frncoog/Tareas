/*
 -Autores: Franco Gajardo, Vicente Gonzalez.
 -Fecha de entrega: 26-10-2025
 -Tema: Continental/Solitario.
*/ 
#include <stdio.h>

#define filas 7
#define columnas 7
#define ficha 'X'
#define vacio ' '
#define invalido 'O'

int a = 0;

void leer_datos(char [][columnas]);
int resolver(char [][columnas], int [][4]);
int comprobar_movimiento(char [][columnas],int [],int [], int , int , int);
void mover(char [][columnas],int [],int [], int , int , int);
int  ganar(char [][columnas]);
void devolver(char [][columnas],int[], int[], int, int, int);
void imprimir_resultados(int [][4]);

int main(){
    
    char matriz[filas][columnas];
    int soluciones[100][4];
    
    leer_datos(matriz);
    if (resolver(matriz, soluciones)) {

        printf("\nSolucion encontrada: ");
        
    } else {
        printf("No tiene solucion.\n");
    }
    printf("En 31 movimientos se encontro la solucion\n\n");
    imprimir_resultados(soluciones);
    
    
    
    return 0;
}

void leer_datos(char matriz[][columnas]){
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

void imprimir_resultados(int soluciones[][4]){

    int h= 0,p = 0, k = 1, i = 2, j = 3;

    for(h = 0; h < 100; h++){
        if((h) == 31){
            break;
        }
       
        printf("%d: posicion <%d,%d> a posicion <%d,%d>\n",h +1, soluciones[h][p],soluciones[h][k],soluciones[h][i],soluciones[h][j]);
               
    }
}

int resolver(char matriz[][columnas], int soluciones[][4]){
    int i, j, k;
    int pos1[] = {-1, 1, 0, 0};
    int pos2[]= {0, 0, -1, 1};
    
    if (ganar(matriz)){
        return 1;
    }

    for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            if(matriz[i][j] == ficha){
                for(k = 0 ; k < 4 ; k++){
                    if ((comprobar_movimiento(matriz, pos1, pos2, k, i, j))){
                        mover(matriz, pos1, pos2, k, i, j);
                        if (resolver(matriz, soluciones)){
                            soluciones[a][0] = i + 1;
                            soluciones[a][1] = j + 1;
                            soluciones[a][2] = i + pos1[k] + pos1[k] + 1;
                            soluciones[a][3] = j + pos2[k] + pos2[k] + 1;
                            a++;
                            return 1;
                        }
                        devolver(matriz, pos1, pos2, k, i, j);
                    }
                }
            }
        }
    }
    return 0;
}

int comprobar_movimiento(char matriz[][columnas],int pos1[],int pos2[], int k, int i, int j){

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

void mover(char matriz[][columnas], int pos1[], int pos2[], int k, int i, int j){

    matriz[i][j] = vacio;
    matriz[i + (pos1[k])][j +(pos2[k])] = vacio;
    matriz[i + (2*pos1[k])][j + (2*pos2[k])] = ficha;

}

void devolver(char matriz[][columnas],int pos1[], int pos2[], int k, int i, int j){

    matriz[i][j] = ficha;
    matriz[i + (pos1[k])][j +(pos2[k])] = ficha;
    matriz[i + (2*pos1[k])][j + (2*pos2[k])] = vacio;
}

int ganar (char matriz[][columnas]){
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