/*
typedef struct node
{
	int tabuleiro;
	struct node* next;
}No;

typedef struct fila
{
	No *head;
	No *end
}Fila;

int verifica_tabuleiro(int *tabuleiro);

void free_matriz(char **lixo);

char ** create_matriz();

int compara_tabuleiros(int* tab1, int* tab2);

void copia_tabuleiro(int *info, int *copia);

char** intToMatriz(int tabuleiro);

int matrizToInt(char **tabuleiro);

void returnSpace(int tabuleiro);

int moveRight(int tabuleiro);

int moveLeft(int tabuleiro);

int moveUp(int tabuleiro);

int moveDown(int tabuleiro);

Fila* create_queue (void);

void enqueue (Fila *f, int puzzle);

int dequeue (Fila *f);

int empty (Fila *f);

void free_queue (Fila *f);

int tabuleiro_exist(Fila *f, int tabuleiro);

int tam_fila(Fila* f);

int manhattan(int tabuleiro);

void printMatriz(char **puzzle);

int getCusto(int tabuleiro);
*/

#include "estrutura.h"
#include <time.h>

int processamento(Fila *pais, Fila *filhos, int *passos){
	Fila *novos_filhos = create_queue();
	Fila *melhores_filhos = create_queue();
	int puzzle,x,y,tab_possivel;
	while(!empty(filhos)){
		puzzle = dequeue(filhos);
		if(verifica_tabuleiro(&puzzle)){
			return (1 == 1);
		}	
		//processa as possibilidades
		returnSpace(puzzle,&x,&y);
		if (y == 0 || y == 1)
		{			
			tab_possivel = moveDown(puzzle);
			if(!tabuleiro_exist(pais,tab_possivel)){
				enqueue(novos_filhos,tab_possivel);
			}
		}
		if (y == 1 || y == 2)
		{		
			tab_possivel = moveUp(puzzle);
			if(!tabuleiro_exist(pais,tab_possivel)){
				enqueue(novos_filhos,tab_possivel);
			}
		}
		if (x == 0 || x == 1)
		{
			tab_possivel = moveRight(puzzle);
			if(!tabuleiro_exist(pais,tab_possivel)){
				enqueue(novos_filhos,tab_possivel);
			}
		}
		if (x == 1 || x == 2)
		{
			tab_possivel = moveLeft(puzzle);
			if(!tabuleiro_exist(pais,tab_possivel)){
				enqueue(novos_filhos,tab_possivel);
			}
		}		
	}
	int custo = 9999;
	while(!empty(novos_filhos)){
		puzzle = dequeue(novos_filhos);
		if(custo > getCusto(puzzle)){
			free_queue(melhores_filhos);
			melhores_filhos = create_queue();
			enqueue(melhores_filhos,puzzle);
			custo = getCusto(puzzle);
		}
		else if (custo == getCusto(puzzle))
		{
			enqueue(melhores_filhos,puzzle);
		}
	}
	free_queue(filhos);
	filhos = create_queue();
	filhos = melhores_filhos;

	*passos = *passos + 1;
	return (1 == 0);
}

/*
 *Função Main
 */
int main(int argc, char const *argv[])
{	
	char **temp = create_matriz();
	printf("Digite o tabuleiro desejado:\n");
	__fpurge(stdin);
	scanf("%c%c%c",&(temp[0][0]),&(temp[0][1]),&(temp[0][2]));
	__fpurge(stdin);
	scanf("%c%c%c",&(temp[1][0]),&(temp[1][1]),&(temp[1][2]));
	__fpurge(stdin);
	scanf("%c%c%c",&(temp[2][0]),&(temp[2][1]),&(temp[2][2]));
	
	Fila *jogo = create_queue(), *historico = create_queue();
	enqueue(jogo,matrizToInt(temp));
	free_matriz(temp);
	int passos=0;
	////////////////////
	clock_t inicio, fim;
	inicio = clock();	
	/*
	 *Colocar aqui as chamadas de função para poder obter o tempo final de execução
	 */
	 while(!processamento(historico,jogo,&passos));
 	//processamento(create_queue(),jogo,&passos);
	printf("O número de passos foi %d\n", passos);
	/////////////////////////////////
	fim = clock();
	printf("\n\nExecução do algoritimo em %ld segundos\n", (fim - inicio)/ CLOCKS_PER_SEC);
	return 0;
}