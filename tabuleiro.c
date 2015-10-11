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
			retorno[a][b] = tabuleiro % 10 + 48;			
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
			retorno = retorno + ((int)(tabuleiro[a][b]) - 48) * (int)(pow(10,conta)); 
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
int manhattan(int tabuleiro){
	char **puzzle = intToMatriz(tabuleiro);
	char **matriz_custo = create_matriz();
	int a, b, custo;
	for(a = 0; a < 3; a++){
		for(b = 0; b < 3; b++){
			if(puzzle[a][b] == '1')			
				matriz_custo[a][b] = (abs(0 - a) + abs(0 - b)) + 48;
			else if(puzzle[a][b] == '2')
				matriz_custo[a][b] = (abs(0 - a) + abs(1 - b)) + 48;
			else if(puzzle[a][b] == '3')
				matriz_custo[a][b] = (abs(0 - a) + abs(2 - b)) + 48;
			else if(puzzle[a][b] == '4')
				matriz_custo[a][b] = (abs(1 - a) + abs(2 - b)) + 48;
			else if(puzzle[a][b] == '5')
				matriz_custo[a][b] = (abs(2 - a) + abs(2 - b)) + 48;
			else if(puzzle[a][b] == '6')
				matriz_custo[a][b] = (abs(2 - a) + abs(1 - b)) + 48;
			else if(puzzle[a][b] == '7')
				matriz_custo[a][b] = (abs(2 - a) + abs(0 - b)) + 48;
			else if(puzzle[a][b] == '8')
				matriz_custo[a][b] = (abs(1 - a) + abs(0 - b)) + 48;
			else if(puzzle[a][b] == '0')
				matriz_custo[a][b] = 0 + 48;
		}
	}
	custo = matrizToInt(matriz_custo);
	free_matriz(puzzle);
	free_matriz(matriz_custo);
	return custo;
}

/*
 *Imprime o tabuleiro
 */
 void printMatriz(char **puzzle	){
 	int a,b;
 	printf("----\n");
 	for (a = 0; a < 3; ++a)
 	{
 		for (b = 0; b < 3; ++b)
 		{
 			printf("%c", puzzle[a][b]);
 		}
 		printf("\n");
 	}
 	printf("\n");
 }

 int getCusto(int tabuleiro){
	char **puzzle = intToMatriz(tabuleiro);
	int a, b, custo = 0;
	for(a = 0; a < 3; a++){
		for(b = 0; b < 3; b++){
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
			else if(puzzle[a][b] == '0')
				custo = custo + 0;
		}
	}	
	free_matriz(puzzle);
	return custo;
}