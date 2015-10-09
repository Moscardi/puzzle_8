#include "fila.h"

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