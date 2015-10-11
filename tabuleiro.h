#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Essa biblioteca foi criada para servir como uma interface 
para usaro tabuleiro*/

int verifica_tabuleiro(int *tabuleiro);

void free_matriz(char **lixo);

char ** create_matriz();

int compara_tabuleiros(int tab1, int tab2);

void copia_tabuleiro(int *info, int *copia);

char** intToMatriz(int tabuleiro);

int matrizToInt(char **tabuleiro);

void returnSpace(int tabuleiro, int *x, int *y);

int moveRight(int tabuleiro);

int moveLeft(int tabuleiro);

int moveUp(int tabuleiro);

int moveDown(int tabuleiro);

int manhattan(int tabuleiro);

void printMatriz(char **puzzle);

int getCusto(int tabuleiro);