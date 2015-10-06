#include "estrutura.h"

/*
typedef struct node
{
	char **tabuleiro;
	struct node* next;
}No;

typedef struct lista
{
	No *inicio;
	No *fim;
}Lista;
*/

Pilha* create_list(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->inicio = NULL;
	p->fim = NULL;
	return p;
}

void free_list(Pilha *p){
	No *n = p->inicio;
	char* aux;
	while(n != NULL){
		No *temp = n->next;
		aux = n->tabuleiro[0];
		free(aux);
		aux = n->tabuleiro[1];
		free(aux);
		aux = n->tabuleiro[2];
		free(aux);
		free(n->tabuleiro);
		free(n); /*desalocando os nós*/
		n = temp;
	}	
	free(p); /*desalocando pilha*/
}

int empty (Pilha *p){
	return (p->inicio == NULL);
}

void push(char **jogada){
	No* adicional = (No*)malloc(sizeof(No));
	

}