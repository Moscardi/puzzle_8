#include "tabuleiro.h"
/*
 *Verifica se um tabuleiro está correto ou errado 
 */
int verifica_tabuleiro(int *tabuleiro){
	return (*tabuleiro == 123804765);
}

/*
 *Retira da memória uma determinada matrix 3x3
 */
void free_matriz(char **lixo){
	free(lixo[0]);
	free(lixo[1]);
	free(lixo[2]);
	free(lixo);
}
/**
 *Retorna uma matriz 3x3 
 */
char ** create_matriz(){
	char **retorno = (char**)malloc(3*sizeof(char*));
	retorno[0] = (char*)malloc(3*sizeof(char));	
	retorno[1] = (char*)malloc(3*sizeof(char));
	retorno[2] = (char*)malloc(3*sizeof(char));
	return retorno;
}

/*
 *Verifica a igualdade de dois tabuleiros, retornando se são diferentes ou não.
 */
int compara_tabuleiros(int tab1, int tab2){
	return (tab1 == tab2);
}

/*
 *Faz a cópia exata de um estado do puzzle
 */
void copia_tabuleiro(int *info, int *copia){
	*copia = *info;
}

/*
 *Transforma um inteiro em uma matriz char 3x3
 */
char** intToMatriz(int tabuleiro){
	int a,b;
	char **retorno = create_matriz();
	for (a = 2; a >= 0; --a)
	{
		for ( b = 2; b >= 0; --b)
		{
			retorno[a][b] = tabuleiro % 10;			
			tabuleiro = tabuleiro / 10;
		}
	}
	return retorno;
}

/*
 *Transforma uma matriz char 3x3 em int
 */
int matrizToInt(char **tabuleiro){
	int retorno = 0;
	int a,b,conta=0;
	for (a = 2; a >= 0; --a)
	{
		for ( b = 2; b >= 0; --b)
		{
			retorno = retorno + ((int)(tabuleiro[a][b]) + 48) * (int)(pow(10,conta)); 
			conta++;
		}
	}
	return retorno;
}

/*
 *Retorna por ponteiro a localizalção do espaço vazio
 */
void returnSpace(int tabuleiro, int *x, int *y){
	char **temp = intToMatriz(tabuleiro);
	for (*y = 0; *y < 3; ++(*y))
	{
		for (*x = 0; *x < 3; ++(*x))
		{
			if (temp[*y][*x] == '0')
			{
				return;
			}
		}
	}
	free_matriz(temp);
}

/*
 *Faz o movimento para a direita 
 */
int moveRight(int tabuleiro){
	char ** puzzle = intToMatriz(tabuleiro);
	int x,y;
	char aux;
	returnSpace(tabuleiro, &x, &y);
	aux = puzzle[y][x];
	puzzle[y][x] = puzzle[y][x+1];
	puzzle[y][x+1] = aux;
	return matrizToInt(puzzle);
}

/*
 *Faz o movimento para a esquerda
 */
int moveLeft(int tabuleiro){
	char ** puzzle = intToMatriz(tabuleiro);
	int x,y;
	char aux;
	returnSpace(tabuleiro, &x, &y);
	aux = puzzle[y][x];
	puzzle[y][x] = puzzle[y][x-1];
	puzzle[y][x-1] = aux;
	return matrizToInt(puzzle);
}

/*
 *Faz o movimento para cima
 */
int moveUp(int tabuleiro){
	char ** puzzle = intToMatriz(tabuleiro);
	int x,y;
	char aux;
	returnSpace(tabuleiro, &x, &y);
	aux = puzzle[y][x];
	puzzle[y][x] = puzzle[y-1][x];
	puzzle[y-1][x] = aux;
	return matrizToInt(puzzle);
}

/*
 *Faz o movimento para baixo
 */
int moveDown(int tabuleiro){
	char ** puzzle = intToMatriz(tabuleiro);
	int x,y;
	char aux;
	returnSpace(tabuleiro, &x, &y);
	aux = puzzle[y][x];
	puzzle[y][x] = puzzle[y+1][x];
	puzzle[y+1][x] = aux;
	return matrizToInt(puzzle);
}