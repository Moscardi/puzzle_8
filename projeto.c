/*
typedef struct node
{
	int tabuleiro;
	struct node* next;
}No;

typedef struct fila
{
	struct node *head;
	struct node *end;
}Fila;

Fila* create_queue (void);

void enqueue (Fila *f, int puzzle);

int dequeue (Fila *f);

int empty (Fila *f);

void free_queue (Fila *f);

int tabuleiro_exist(Fila *f, int tabuleiro);

int tam_fila(Fila* f);

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
*/

#include "estrutura.h"
#include <time.h>

void calcula_passos(Fila *historico, Fila *possibilidade, int *passos){
	int x,y,puzzle,tab_possivel;
	Fila *filhos = create_queue();
	while(!empty(possibilidade)){
		puzzle = dequeue(possibilidade);
		//verifica se um tabuleiro filho está correto
		if(verifica_tabuleiro(&puzzle)){
			free_queue(filhos);
			free_queue(historico);
			free_queue(possibilidade);
			return ;			
		}
		//processa as possibilidades
		returnSpace(puzzle,&x,&y);
		if (y == 0 || y == 1)
		{
			copia_tabuleiro(&puzzle,&tab_possivel);
			tab_possivel = moveDown(tab_possivel);
			if(!tabuleiro_exist(historico,tab_possivel)){
				enqueue(filhos,tab_possivel);
			}
		}
		if (y == 1 || y == 2)
		{
			copia_tabuleiro(&puzzle,&tab_possivel);
			tab_possivel = moveUp(tab_possivel);
			if(!tabuleiro_exist(historico,tab_possivel)){
				enqueue(filhos,tab_possivel);
			}
		}
		if (x == 0 || x == 1)
		{
			copia_tabuleiro(&puzzle,&tab_possivel);
			tab_possivel = moveRight(tab_possivel);
			if(!tabuleiro_exist(historico,tab_possivel)){
				enqueue(filhos,tab_possivel);
			}
		}
		if (x == 1 || x == 2)
		{
			copia_tabuleiro(&puzzle,&tab_possivel);
			tab_possivel = moveLeft(tab_possivel);
			if(!tabuleiro_exist(historico,tab_possivel)){
				enqueue(filhos,tab_possivel);
			}
		}
		enqueue(historico,puzzle);
	}
	free_queue(possibilidade);
	*passos = *passos + 1;
	calcula_passos(historico,filhos,passos);
}

/*
 *Função Main
 */
int main(int argc, char const *argv[])
{	
	clock_t inicio, fim;	
	Fila *possibilidade = create_queue();
	//Pega dados
	char **temp = create_matriz();
	int passos = 0;
	printf("Digite o tabuleiro:\n");
	__fpurge(stdin);
	scanf("%c%c%c",&(temp[0][0]),&(temp[0][1]),&(temp[0][2]));
	__fpurge(stdin);
	scanf("%c%c%c",&(temp[1][0]),&(temp[1][1]),&(temp[1][2]));
	__fpurge(stdin);
	scanf("%c%c%c",&(temp[2][0]),&(temp[2][1]),&(temp[2][2]));
	//tranforma dados
	enqueue(possibilidade,matrizToInt(temp));
	free_matriz(temp);
	///////////////////////////////////
	inicio = clock();
	/*
	 *Colocar aqui as chamadas de função para poder obter o tempo final de execução
	 */	
	calcula_passos(create_queue(),possibilidade,&passos);

	printf("Números de passos: %d\n", passos);	
	/////////////////////////////////s
	fim = clock();
	printf("\n\nExecução do algoritimo em %ld segundos\n", (fim - inicio)/ CLOCKS_PER_SEC);
	return 0;
}