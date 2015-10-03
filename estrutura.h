#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char **tabuleiro;
	struct node* next;
}No;

typedef struct pilha
{
	No *topo;
}Pilha;

Pilha* create_stack(void);

void copia_tabuleiro(char **info, char**copia);

void push (Pilha *p, char **tabuleiro);

int compara_tabuleiros(char** tab1, char** tab2);

char** pop (Pilha *p);

void free_stack(Pilha *p);

int empty (Pilha *p);