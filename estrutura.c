#include "estrutura.h"

/*
 *Cria uma nova pilha instanciando os ponteiros como NULL
 */
Pilha* create_stack(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

/*
 *Adiciona um No a pilha encadeada, tem como esntrada um estado
 *do puzzle.
 */
void push (Pilha *p, char **tabuleiro){
	No *n = (No*)malloc(sizeof(No));
	n->tabuleiro = (char**)malloc(3*sizeof(char*));
	n->tabuleiro[0] = (char*)malloc(3*sizeof(char));
 	n->tabuleiro[1] = (char*)malloc(3*sizeof(char));
 	n->tabuleiro[2] = (char*)malloc(3*sizeof(char));
 	n->tabuleiro[0][0] = tabuleiro[0][0];
 	n->tabuleiro[0][1] = tabuleiro[0][1];
 	n->tabuleiro[0][2] = tabuleiro[0][2];
 	n->tabuleiro[1][0] = tabuleiro[1][0];
 	n->tabuleiro[1][1] = tabuleiro[1][1];
 	n->tabuleiro[1][2] = tabuleiro[1][2];
 	n->tabuleiro[2][0] = tabuleiro[2][0];
 	n->tabuleiro[2][1] = tabuleiro[2][1];
 	n->tabuleiro[2][2] = tabuleiro[2][2];
	n->next = p->topo;
	p->topo = n;
}

/*
 *Remove o ultimo No adicionado na Pilha, retornando um estado do
 *puzzle
 */
char** pop (Pilha *p){
	if (empty(p))
	{
		exit(1);/*Pilha vazia*/
	}
	No *n = p->topo;
	char** elem = n->tabuleiro;
	p->topo = n->next;
	free(n);
	return elem;
}

/*
 *Remove da memória a Pilha inteira
 */
void free_stack(Pilha *p){
	No *n = p->topo;
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

/*
 *Verifica se a pilha está vazia
 */
int empty (Pilha *p){
	return (p->topo == NULL);
}
