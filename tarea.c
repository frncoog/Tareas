#include <stdio.h>
#include <string.h>


void lee_original(char *, int *);
void inicializa_alfabeto(char *);
void codificar(char *, char *, char *, int);
void graba_mensaje(char *);
void primera_etapa(char *, char *, int);
void segunda_etapa(char *, char *, int);


int main(){

    char original[100];
    char alfabeto[100];
    char codificado[100];
    int N;
    lee_original(original, &N);
    inicializa_alfabeto(alfabeto);
    codificar(original, codificado, alfabeto, N);
    graba_mensaje(codificado);
    return 0;
}

void lee_original(char *original , int *N) {
    int i = 0;
    *N = 0;
    FILE *archivo = fopen("original.txt", "r"); 
    fgets(original, 100, archivo);
    fclose(archivo);
    while (original[i] < '0' || original[i] > '9') {
        i++;
    }
     while (original[i] >= '0' && original[i] <= '9') {
        *N = *N * 10 + (original[i] - '0');
        i++;
    }   
    
        printf("N: %d\n", *N);
}

void inicializa_alfabeto(char *alfabeto) { 
    int i = 0;
    char copiar[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z',' ', '0','1','2','3','4','5','6','7','8','9',
    '!',',','.',':',';','?','-','+','*','/', '\0'};
    for (i ; i < sizeof(copiar); i++) {
        alfabeto[i] = copiar[i];
        printf("%c", alfabeto[i]);
    }

}


void codificar(char *original, char *codificado, char *alfabeto, int N){
    primera_etapa(original, codificado, N);
    segunda_etapa(codificado, alfabeto, N);
}

void primera_etapa(char *original, char *codificado, int N){
    int i = 0;


}