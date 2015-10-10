#include "estrutura.h"
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

int compara_tabuleiros(int tab1, int tab2);

void copia_tabuleiro(int *info, int *copia);

char** intToMatriz(int tabuleiro);

int matrizToInt(char **tabuleiro);

void returnSpace(int tabuleiro);

int moveRight(int tabuleiro);

int moveLeft(int tabuleiro);

int moveUp(int tabuleiro);

int moveDown(int tabuleiro);
*/

Fila* create_queue (void) {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->head = NULL;
    f->end = NULL;
    return f;
}

void enqueue (Fila *f, int puzzle) {
    No *novo = (No*)malloc(sizeof(No));
    novo->tabuleiro = puzzle;
    novo->next = NULL;
    if(empty(f)){
    	f->head = novo;
    	f->end = novo;   	
    	return;    	
    }    
    (f->end)->next = novo;
    f->end = novo;
}

int dequeue (Fila *f) {
    if (empty(f)) {
        printf("Erro:fila vazia!");
        exit(1); /*aborta programa*/
    }
    int v = (f->head)->tabuleiro;
    No *lixo = f->head;
    f->head = (f->head)->next;
    free(lixo);
    return v;
}

int empty (Fila *f) {
    return (f->head == NULL);
}

void free_queue (Fila *f) {
    No *temp;
    while(!empty(f)){
    	temp = f->head;
    	f->head = temp->next;
    	free(temp);
    }
    free(f);
}

int tabuleiro_exist(Fila *f, int tabuleiro){
	No *temp;
	Fila *aux = f;
	while(!empty(f)){
		temp = aux->head;
		aux->head = temp->next;
		if(compara_tabuleiros(temp->tabuleiro, tabuleiro)){
			return (1 == 1);
		}
	}
	return (1 == 0);
}

int tam_fila(Fila* f){
	No *temp;
	Fila *aux = f;
	int contador=0;
	while(!empty(aux)){
		temp = f->head;
		f->head = temp->next;
		contador++;
	}
	return contador;
}