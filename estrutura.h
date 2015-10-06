#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	unsigned long int index;
	char **tabuleiro;
	struct node* next;
}No;

typedef struct lista
{
	No *inicio;
	No *fim;
}Lista;

Pilha* create_list(void);

void free_list(Pilha *p);

int empty (Pilha *p);
