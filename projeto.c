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

int processamento(Fila *pais, Fila *filhos, int passos){
	Fila *novos_filhos = create_queue();
	Fila *filhos_selecionado = create_queue();
	int menor_custo, x,y;
	int estado_pai;
	int temp_estado;
	while(!empty(filhos)){		
		novos_filhos = create_queue();
		estado_pai = dequeue(filhos);
		enqueue(pais,estado_pai);
		if (verifica_tabuleiro(&estado_pai))
		{
			free_queue(novos_filhos);
			free_queue(filhos_selecionado);
			free_queue(pais);
			free_queue(filhos);
			return passos;
		}
		returnSpace(estado_pai,&x,&y);
		if(x == 0 || x == 1){
			temp_estado = moveRight(estado_pai);
			if(!tabuleiro_exist(pais,temp_estado)){
				enqueue(novos_filhos,temp_estado);
			}	
		}if (x == 1 || x == 2)
		{
			temp_estado = moveLeft(estado_pai);
			if(!tabuleiro_exist(pais,temp_estado)){
				enqueue(novos_filhos,temp_estado);
			}	
		}if (y == 0 || y == 1)
		{
			temp_estado = moveDown(estado_pai);
			if(!tabuleiro_exist(pais,temp_estado)){
				enqueue(novos_filhos,temp_estado);
			}	
		}if (y == 1 || y == 2)
		{
			temp_estado = moveUp(estado_pai);
			if(!tabuleiro_exist(pais,temp_estado)){
				enqueue(novos_filhos,temp_estado);
			}	
		}
		//seleciona o melhor filho e mata os demais
		if (empty(novos_filhos))
		{
			printf("Deu merda!!!!\n");
			return 0;
		}
		menor_custo = 999;
		while(!empty(novos_filhos)){
			temp_estado = dequeue(novos_filhos);
			if(menor_custo > getCusto(temp_estado)){
				free_queue(filhos_selecionado);
				filhos_selecionado = create_queue();
				enqueue(filhos_selecionado,temp_estado);
			}
			else if(menor_custo == getCusto(temp_estado)){
				enqueue(filhos_selecionado,temp_estado);
			}
		}
		free_queue(novos_filhos);
	}
	free_queue(filhos);
	return processamento(pais, filhos_selecionado,++passos);

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
	
	Fila *jogo = create_queue();
	enqueue(jogo,matrizToInt(temp));
	free_matriz(temp);
	////////////////////
	clock_t inicio, fim;
	inicio = clock();	
	/*
	 *Colocar aqui as chamadas de função para poder obter o tempo final de execução
	 */
	printf("O número de passos foi %d\n", processamento(create_queue(),jogo,0));
	/////////////////////////////////
	fim = clock();
	printf("\n\nExecução do algoritimo em %ld segundos\n", (fim - inicio)/ CLOCKS_PER_SEC);
	return 0;
}