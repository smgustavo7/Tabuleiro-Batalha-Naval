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

    int origemlinha = 2;
    int origemcoluna = 7;

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

    int origemOctLinha = 6;
    int origemOctColuna = 2;

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){

            int linhatab = origemOctLinha + (i - centro);
            int colunatab = origemOctColuna + (j - centro);

            if (linhatab >= 0 && linhatab < 10 &&
            colunatab >= 0 && colunatab < 10){

                if (octaedro[i][j] == 1){
                tabuleiro[linhatab][colunatab] = 2; // número diferente
                }
            }
        }
    }

    int origemConeLinha = 7;
    int origemConeColuna = 7;

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){

            int linhatab = origemConeLinha + (i - centro);
            int colunatab = origemConeColuna + (j - centro);

            if (linhatab >= 0 && linhatab < 10 &&
            colunatab >= 0 && colunatab < 10){

                if (cone[i][j] == 1){
                tabuleiro[linhatab][colunatab] = 1; // outro número
                }
             }
        }
    }

//Posicionando Navio Vertical
//Coluna B & Linhas 2, 3, 4

    tabuleiro[1][1] = 3;
    tabuleiro[2][1] = 3;
    tabuleiro[3][1] = 3;

//Posicionando Navio Horizontal
//Colunas D, E, F & Linha 1

    tabuleiro[0][3] = 3;
    tabuleiro[0][4] = 3;
    tabuleiro[0][5] = 3;

//Posicionando Navio Diagonal
//Colunas E, F, G & Linhas 4, 5, 6

    tabuleiro[5][6] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[3][4] = 3;

//Colunas C, D, E & Linhas 8, 9, 10

    tabuleiro[9][2] = 3;
    tabuleiro[8][3] = 3;
    tabuleiro[7][4] = 3;

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
