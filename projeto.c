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
*/

#include "estrutura.h"

/*
 *Função Main
 */
int main(int argc, char const *argv[])
{
	printf("%d\n", manhattan(765804123));
	return 0;
}