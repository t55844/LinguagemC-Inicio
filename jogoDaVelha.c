#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tabuleiro[3][3];
const char JOGADOR = 'X';
const char MAQUINA = '0';

void limpaTabuleiro();
void imprimeTabuleiro();
int olhaEspacosVazios();
void jogadaDoJogador();
void jogadaDaMaquina();
char verificaVencedor();
void imprimeVencedor(char);

int main()
{
    char vencedor = ' ';
    limpaTabuleiro();

    while (vencedor == ' ' && olhaEspacosVazios() != 0)
    {
        imprimeTabuleiro();

        jogadaDoJogador();

        vencedor = verificaVencedor();
        if (vencedor != ' ' || olhaEspacosVazios() == 0)
        {
            break;
        }

        jogadaDaMaquina();

        vencedor = verificaVencedor();
        if (vencedor != ' ' || olhaEspacosVazios() == 0)
        {
            break;
        }
    }

    imprimeTabuleiro();
    imprimeVencedor(vencedor);

    return 0;
}

void limpaTabuleiro()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
}
void imprimeTabuleiro()
{

    printf("    %c  |   %c  |   %c  \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("-------|------|-------\n");
    printf("    %c  |   %c  |   %c  \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("-------|------|-------\n");
    printf("    %c  |   %c  |   %c  \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}
int olhaEspacosVazios()
{
    int espacosVazios = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] != ' ')
            {
                espacosVazios--;
            }
        }
    }
    return espacosVazios;
}
void jogadaDoJogador()
{
    int x;
    int y;
    do
    {

        printf("Escolha uma linha de 1 a 3: ");
        scanf("%d", &x);
        x--;

        printf("Escolha uma coluna de 1 a 3: ");
        scanf("%d", &y);
        y--;

        if (tabuleiro[x][y] != ' ')
        {
            printf("\nEspaco ja ocupado\n");
        }
        else
        {
            tabuleiro[x][y] = JOGADOR;
            break;
        }
    } while (tabuleiro[x][y] != ' ');
}
void jogadaDaMaquina()
{
    srand(time(0));
    int x;
    int y;
    if (olhaEspacosVazios() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (tabuleiro[x][y] != ' ');

        tabuleiro[x][y] = MAQUINA;
    }
    else
    {
        imprimeVencedor(' ');
    }
}
char verificaVencedor()
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
        {
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
        {
            return tabuleiro[0][i];
        }
        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
        {
            return tabuleiro[0][0];
        }
        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])
        {
            return tabuleiro[0][2];
        }
        return ' ';
    }
}
void imprimeVencedor(char vendor)
{
    if (vendor == JOGADOR)
    {
        printf("\nVoce venceu parabens !!!!\n");
    }
    else if (vendor == MAQUINA)
    {
        printf("\nVoce perdeu que pena \n");
    }
    else
    {
        printf("\nVoce empatou \n");
    }
}
