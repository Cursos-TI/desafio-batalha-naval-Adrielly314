#include <stdio.h>
#include <stdlib.h> // para abs()

int main() {
    // Criando o tabuleiro 10x10, inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Definindo navios (cada parte do navio recebe o valor 3)
    int Navio_Horizontal[3] = {3, 3, 3};
    int Navio_Vertical[3]   = {3, 3, 3};
    int Navio_Diagonal1[3]  = {3, 3, 3};
    int Navio_Diagonal2[3]  = {3, 3, 3};

    // Coordenadas iniciais para posicionar os navios
    int Linha_H = 2;  // Linha 3 (índice 2)
    int Coluna_H = 4; // Coluna E (índice 4)

    int Linha_V = 5;  // Linha 6 (índice 5)
    int Coluna_V = 7; // Coluna H (índice 7)

    int Linha_D1 = 0; // Diagonal ↘ começa no canto superior esquerdo (0,0)
    int Coluna_D1 = 0;

    int Linha_D2 = 0; // Diagonal ↙ começa no canto superior direito (0,9)
    int Coluna_D2 = 9;

    // --- Colocar Navio Horizontal ---
    if (Coluna_H + 3 <= 10) { // Verifica se cabe na horizontal
        for (int i = 0; i < 3; i++) {
            tabuleiro[Linha_H][Coluna_H + i] = Navio_Horizontal[i];
        }
    } else {
        printf("Navio horizontal não cabe no tabuleiro!\n");
    }

    // --- Colocar Navio Vertical ---
    int pode_colocar = 1;
    if (Linha_V + 3 <= 10) { // Verifica se cabe na vertical
        // Verifica sobreposição
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[Linha_V + i][Coluna_V] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[Linha_V + i][Coluna_V] = Navio_Vertical[i];
            }
        } else {
            printf("Navio vertical não pode ser colocado: sobreposição!\n");
        }
    } else {
        printf("Navio vertical não cabe no tabuleiro!\n");
    }

    // --- Colocar Navio Diagonal ↘ ---
    pode_colocar = 1;
    if (Linha_D1 + 3 <= 10 && Coluna_D1 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[Linha_D1 + i][Coluna_D1 + i] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[Linha_D1 + i][Coluna_D1 + i] = Navio_Diagonal1[i];
            }
        } else {
            printf("Navio diagonal (↘) não pode ser colocado: sobreposição!\n");
        }
    } else {
        printf("Navio diagonal (↘) não cabe no tabuleiro!\n");
    }

    // --- Colocar Navio Diagonal ↙ ---
    pode_colocar = 1;
    if (Linha_D2 + 3 <= 10 && Coluna_D2 - 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[Linha_D2 + i][Coluna_D2 - i] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[Linha_D2 + i][Coluna_D2 - i] = Navio_Diagonal2[i];
            }
        } else {
            printf("Navio diagonal (↙) não pode ser colocado: sobreposição!\n");
        }
    } else {
        printf("Navio diagonal (↙) não cabe no tabuleiro!\n");
    }

    // ========== HABILIDADES ESPECIAIS ==========
    // Representadas pelo número 5 no tabuleiro

    // Ponto de origem da habilidade: Cone (formato triangular)
    int origem_Linha = 4;
    int origem_Coluna = 4;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i >= j && i + j <= 4) { // Condição para o cone apontando para baixo
                int lin = origem_Linha + i;
                int col = origem_Coluna + j - 2;
                if (lin >= 0 && lin < 10 && col >= 0 && col < 10 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 5;
            }
        }
    }

    // Habilidade: Cruz (5x5)
    origem_Linha = 7;
    origem_Coluna = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) { // linhas e colunas centrais formam cruz
                int lin = origem_Linha - 2 + i;
                int col = origem_Coluna - 2 + j;
                if (lin >= 0 && lin < 10 && col >= 0 && col < 10 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 5;
            }
        }
    }

    // Habilidade: Octaedro (forma de diamante)
    origem_Linha = 1;
    origem_Coluna = 8;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) { // condição para formar o octaedro
                int lin = origem_Linha - 2 + i;
                int col = origem_Coluna - 2 + j;
                if (lin >= 0 && lin < 10 && col >= 0 && col < 10 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 5;
            }
        }
    }

    // --- Exibição do tabuleiro ---
    printf(" ==== BATALHA NAVAL ====\n\n");
    printf("    A B C D E F G H I J\n"); // Letras para colunas

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~"); // Água
            else if (tabuleiro[i][j] == 3)
                printf(" N"); // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" *"); // Área especial / habilidade
            else
                printf(" ?"); // Para qualquer outro valor inesperado
        }
        printf("\n");
    }

    return 0;
}
