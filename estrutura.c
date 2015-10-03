#include "estrutura.h"

/*

*/

Pilha* create_stack(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

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

int compara_tabuleiros(char** tab1, char** tab2){
	int a, b;
	for (a = 0; a < 3; ++a)
	{
		for (b = 0; b < 3; ++b)
		{
			if(tab1[a][b] != tab2[a][b]){
				return (1 == 0);
			}
		}
	}
	return (1 == 1);
}

void copia_tabuleiro(char **info, char**copia){
	int a,b;	
	for(a=0;a<3;a++){
		for(b=0;b<3;b++){
			copia[a][b] = info[a][b];
		}
	}
}

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

int empty (Pilha *p){
	return (p->topo == NULL);
}
