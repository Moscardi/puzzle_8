#include "tabuleiro.h"

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