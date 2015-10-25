#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 *Essa biblioteca foi criada para servir como uma interface para usar o tabuleiro
 */

/**
 *\brief Verifica se um tabuleiro está correto ou errado
 *\param int* tabuleiro
 *\return int
 */
int verifica_tabuleiro(int *tabuleiro);

/**
 *\brief Retira da memória uma determinada matrix 3x3
 *\param char[3][3] lixo
 *\return void
 */
void free_matriz(char **lixo);

/**
 *\brief Retorna uma matriz 3x3
 *\param void
 *\return char[3][3]
 */
char ** create_matriz();

/**
 *\brief Verifica a igualdade de dois tabuleiros, retornando se são diferentes ou não.
 *\param int* tab1
 *\param int* tab2
 *\return int
 */
int compara_tabuleiros(int *tab1, int* tab2);

/**
 *\brief Transforma um inteiro em uma matriz char 3x3
 *\param int tabuleiro
 *\return char[3][3]
 */
char** intToMatriz(int tabuleiro);

/**
 *\brief Transforma uma matriz char 3x3 em int
 *\param char[3][3]
 *\return int
 */
int matrizToInt(char **tabuleiro);

/**
 *\brief Retorna por ponteiro a localizalção do espaço vazio
 *\param int* tabuleiro
 *\param int* x
 *\param int* y
 *\return void
 */
void getSpace(int *tabuleiro, int *x, int *y);

/**
 *\brief Faz o movimento para a direita
 *\param int* tabuleiro
 *\return void
 */
void moveRight(int *tabuleiro);

/**
 *\brief Faz o movimento para a esquerda
 *\param int* tabuleiro
 *\return void
 */
void moveLeft(int *tabuleiro);

/**
 *\brief Faz o movimento para cima
 *\param int* tabuleiro
 *\return void
 */
void moveUp(int *tabuleiro);


/**
 *\brief Faz o movimento para baixo
 *\param int* tabuleiro
 *\return void
 */
void moveDown(int *tabuleiro);

/**
 *\brief Imprime o tabuleiro char
 *\param char[3][3]
 *\return void
 */
void printMatrizChar(char **puzzle	);

/**
 *\brief Imprime o tabuleiro int
 * \param int* tabuleiro
 *\return void
 */
void printMatrizInt(int *tabuleiro);

/**
 *\brief Retorna o custo de um tabuleiro
 *\param int* tabuleiro
 *\return unsigned short int
 */
unsigned short int getCusto(int *tabuleiro);

