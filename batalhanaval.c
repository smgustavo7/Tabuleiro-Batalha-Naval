#include <stdio.h>
#include <stdlib.h>

//Definindo as matrizes

#define TAM 5

int main(){

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    int cruz[TAM][TAM];
    int cone[TAM][TAM];
    int octaedro[TAM][TAM];

    int centro = TAM / 2;

//Preencher o tabuleiro com 0

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;       
         }
    }

//Construindo Cruz

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (i == centro || j == centro){
                cruz[i][j] = 1;
        } else {
            cruz[i][j] = 0;
        }
      }
    }

//Construindo Octaedro

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (abs(i - centro) + abs(j - centro) <= centro){
                octaedro[i][j] = 1;
        } else {
                octaedro[i][j] = 0;
        }
    }

//Construindo Cone

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (i <= centro && j >= centro - i && j <= centro + i){
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

//Posição no tabuleiro

    int origemlinha = 4;
    int origemcoluna = 5;

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){

            int linhatab = origemlinha + (i - centro);
            int colunatab = origemcoluna + (j - centro);

            if (linhatab >= 0 && linhatab < 10 &&
                colunatab >= 0 && colunatab < 10){

                if ( cruz[i][j] == 1){
                    tabuleiro[linhatab][colunatab] = 5;
                }
                }
        }
    }

//Imprimir letras (A-J)

    printf("  ");
    for (int i = 0; i < 10; i++){
        printf(" %c", linha[i]);
    }
    printf("\n");

//Imprimir números (1-10) e o tabuleiro

    for (int i = 0; i < 10; i++){
        printf("%2d", i + 1);
        for (int j = 0; j < 10; j++){
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}