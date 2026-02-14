#include <stdio.h>

//Definindo as matrizes

int main(){

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

//Preencher o tabuleiro com 0

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;       
         }
    }

//Navio horizontal
//Linha 2 & Colunas 3, 4, 5

    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

//Navio vertical
//Coluna 7 & Linhas 5, 6, 7

    tabuleiro[4][6] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;

//Navio diagonal
//Colunas 2, 3, 4 & Linhas 4, 5, 6

    tabuleiro[3][3] = 3;
    tabuleiro[4][2] = 3;
    tabuleiro[5][1] = 3;

//Navio diagonal
//Colunas 4, 5, 6 & Linhas 8, 9, 10

    tabuleiro[7][3] = 3;
    tabuleiro[8][4] = 3;
    tabuleiro[9][5] = 3;

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