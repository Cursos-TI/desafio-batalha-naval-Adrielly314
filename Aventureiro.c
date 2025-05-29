#include <stdio.h>

int main() {
    // Criando o tabuleiro:
    int tabuleiro[10][10] = {0};

    // Criando os navios: 
    int Navio_Horizontal[3] = {3, 3, 3};
    int Navio_Vertical[3]   = {3, 3, 3};

    int Navio_Diagonal1[3]  = {3, 3, 3};
    int Navio_Diagonal2[3]  = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int Linha_H = 2;     // Linha 3 (índice começa em 0)
    int Coluna_H = 4;    // Coluna E (índice 4)

    int Linha_V = 5;     // Linha 6 (índice 5)
    int Coluna_V = 7;    // Coluna H (índice 7)

    int Linha_D1 = 0;    // Diagonal ↘ começa no canto superior esquerdo
    int Coluna_D1 = 0;

    int Linha_D2 = 0;    // Diagonal ↙ começa no canto superior direito
    int Coluna_D2 = 9;

    // Validação: verificar se o navio horizontal cabe no tabuleiro
    if (Coluna_H + 3 <= 10) 
    {
        for (int i = 0; i < 3; i++) 
        {
            tabuleiro[Linha_H][Coluna_H + i] = Navio_Horizontal[i];
        }
    } 
    else 
    {
        printf("Navio horizontal não cabe no tabuleiro!\n");
    }

    // Validação: verificar se o navio vertical cabe e não se sobrepõe
    int Pode_Colocar = 1; // flag para checar sobreposição

    if (Linha_V + 3 <= 10) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (tabuleiro[Linha_V + i][Coluna_V] != 0) 
            {
                Pode_Colocar = 0; // já tem algo ali
            }
        }

        if (Pode_Colocar) 
        {
            for (int i = 0; i < 3; i++) 
            {
                tabuleiro[Linha_V + i][Coluna_V] = Navio_Vertical[i];
            }
        } 
        else 
        {
            printf("Navio vertical não pode ser colocado: sobreposição!\n");
        }
    } 
    else 
    {
        printf("Navio vertical não cabe no tabuleiro!\n");
    }

    // Validação: verificar se o navio diagonal ↘ cabe e não se sobrepõe
    Pode_Colocar = 1;

    if (Linha_D1 + 3 <= 10 && Coluna_D1 + 3 <= 10) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (tabuleiro[Linha_D1 + i][Coluna_D1 + i] != 0) 
            {
                Pode_Colocar = 0;
            }
        }

        if (Pode_Colocar) 
        {
            for (int i = 0; i < 3; i++) 
            {
                tabuleiro[Linha_D1 + i][Coluna_D1 + i] = Navio_Diagonal1[i];
            }
        } 
        else 
        {
            printf("Navio diagonal (↘) não pode ser colocado: sobreposição!\n");
        }
    } 
    else 
    {
        printf("Navio diagonal (↘) não cabe no tabuleiro!\n");
    }

    // Validação: verificar se o navio diagonal ↙ cabe e não se sobrepõe
    Pode_Colocar = 1;

    if (Linha_D2 + 3 <= 10 && Coluna_D2 - 2 >= 0) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (tabuleiro[Linha_D2 + i][Coluna_D2 - i] != 0) 
            {
                Pode_Colocar = 0;
            }
        }

        if (Pode_Colocar) 
        {
            for (int i = 0; i < 3; i++) 
            {
                tabuleiro[Linha_D2 + i][Coluna_D2 - i] = Navio_Diagonal2[i];
            }
        } 
        else 
        {
            printf("Navio diagonal (↙) não pode ser colocado: sobreposição!\n");
        }
    } 
    else 
    {
        printf("Navio diagonal (↙) não cabe no tabuleiro!\n");
    }

    // Exibindo o tabuleiro com letras nas colunas
    printf(" ==== BATALHA NAVAL ====\n\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("%2d ", i + 1); // Mostra o número da linha (1 a 10)

        for (int j = 0; j < 10; j++) 
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
