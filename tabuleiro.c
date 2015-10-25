#include "tabuleiro.h"

int verifica_tabuleiro(int *tabuleiro)
{
    return (*tabuleiro == 123894765);
}

void free_matriz(char **lixo)
{
    free(lixo[0]);
    free(lixo[1]);
    free(lixo[2]);
    free(lixo);
}

char ** create_matriz()
{
    char **retorno = (char**)malloc(3*sizeof(char*));
    retorno[0] = (char*)malloc(3*sizeof(char));
    retorno[1] = (char*)malloc(3*sizeof(char));
    retorno[2] = (char*)malloc(3*sizeof(char));
    return retorno;
}

int compara_tabuleiros(int *tab1, int* tab2)
{
    return (*tab1 == *tab2);
}

char** intToMatriz(int tabuleiro)
{
    int a,b;
    char **retorno = create_matriz();
    for (a = 2; a >= 0; --a)
    {
        for ( b = 2; b >= 0; --b)
        {
            retorno[a][b] = tabuleiro % 10 + 48;
            tabuleiro = tabuleiro / 10;
        }
    }
    return retorno;
}

int matrizToInt(char **tabuleiro)
{
    int retorno = 0;
    int a,b,conta=0;
    for (a = 2; a >= 0; --a)
    {
        for ( b = 2; b >= 0; --b)
        {
            retorno = retorno + ((int)(tabuleiro[a][b]) - 48) * (int)(pow(10,conta));
            conta++;
        }
    }
    return retorno;
}

void getSpace(int *tabuleiro, int *x, int *y)
{
    char **temp = intToMatriz(*tabuleiro);
    for (*y = 0; *y < 3; ++(*y))
    {
        for (*x = 0; *x < 3; ++(*x))
        {
            if (temp[*y][*x] == '9')
            {
                free_matriz(temp);
                return;
            }
        }
    }
    free_matriz(temp);
}

void moveRight(int *tabuleiro)
{
    char ** puzzle = intToMatriz(*tabuleiro);
    int x,y;
    char aux;
    returnSpace(tabuleiro, &x, &y);
    aux = puzzle[y][x];
    puzzle[y][x] = puzzle[y][x+1];
    puzzle[y][x+1] = aux;
    *tabuleiro = matrizToInt(puzzle);
    free_matriz(puzzle);
}

void moveLeft(int *tabuleiro)
{
    char ** puzzle = intToMatriz(*tabuleiro);
    int x,y;
    char aux;
    returnSpace(tabuleiro, &x, &y);
    aux = puzzle[y][x];
    puzzle[y][x] = puzzle[y][x-1];
    puzzle[y][x-1] = aux;
    *tabuleiro = matrizToInt(puzzle);
    free_matriz(puzzle);
}

void moveUp(int *tabuleiro)
{
    char ** puzzle = intToMatriz(*tabuleiro);
    int x,y;
    char aux;
    returnSpace(tabuleiro, &x, &y);
    aux = puzzle[y][x];
    puzzle[y][x] = puzzle[y-1][x];
    puzzle[y-1][x] = aux;
    *tabuleiro = matrizToInt(puzzle);
    free_matriz(puzzle);
}

void moveDown(int *tabuleiro)
{
    char ** puzzle = intToMatriz(*tabuleiro);
    int x,y;
    char aux;
    returnSpace(tabuleiro, &x, &y);
    aux = puzzle[y][x];
    puzzle[y][x] = puzzle[y+1][x];
    puzzle[y+1][x] = aux;
    *tabuleiro = matrizToInt(puzzle);
    free_matriz(puzzle);
}

void printMatrizChar(char **puzzle	)
{
    int a,b;
    printf("----\n");
    for (a = 0; a < 3; ++a)
    {
        for (b = 0; b < 3; ++b)
        {
            if(puzzle[a][b] != '9')
                printf("%c", puzzle[a][b]);
            else
                printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrizInt(int *tabuleiro)
{
    char **puzzle = create_matriz();
    puzzle = intToMatriz(*tabuleiro);
    printMatrizChar(puzzle);
    free_matriz(puzzle);
}

unsigned short int getCusto(int *tabuleiro)
{
    char **puzzle = intToMatriz(*tabuleiro);
    int a, b;
    unsigned short int custo = 0;
    for(a = 0; a < 3; a++)
    {
        for(b = 0; b < 3; b++)
        {
            if(puzzle[a][b] == '1')
                custo = custo + (abs(0 - a) + abs(0 - b));
            else if(puzzle[a][b] == '2')
                custo = custo + (abs(0 - a) + abs(1 - b));
            else if(puzzle[a][b] == '3')
                custo = custo + (abs(0 - a) + abs(2 - b));
            else if(puzzle[a][b] == '4')
                custo = custo + (abs(1 - a) + abs(2 - b));
            else if(puzzle[a][b] == '5')
                custo = custo + (abs(2 - a) + abs(2 - b));
            else if(puzzle[a][b] == '6')
                custo = custo + (abs(2 - a) + abs(1 - b));
            else if(puzzle[a][b] == '7')
                custo = custo + (abs(2 - a) + abs(0 - b));
            else if(puzzle[a][b] == '8')
                custo = custo + (abs(1 - a) + abs(0 - b));
        }
    }
    free_matriz(puzzle);
    return custo;
}
