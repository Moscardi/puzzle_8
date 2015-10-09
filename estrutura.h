#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Fila* create_queue (void);

void enqueue (Fila *f, int puzzle);

int dequeue (Fila *f);

int empty (Fila *f);

void free_queue (Fila *f);