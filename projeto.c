#include "util.h"

/*
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

int verifica_dados(char** dados);

int verifica_tabuleiro(char **tabuleiro);

Pilha* entrada_dados(void);

void free_matriz(char ***lixo);
*/


Pilha* ramifica(Pilha* arvore,int *nivel){
	Pilha *auxiliar = create_stack();
	char **ramo,**temp;
	char troca;
	int a,b;
	/*Aloca espaço na memória para o tabuleiro temporario*/
	temp = (char**)malloc(3*sizeof(char*));
	temp[0] = (char*)malloc(3*sizeof(char));
	temp[1] = (char*)malloc(3*sizeof(char));
	temp[2] = (char*)malloc(3*sizeof(char));	

	while(!empty(arvore)){
		ramo = pop(arvore);
		if(verifica_tabuleiro(ramo)){
			free_matriz(temp);
			free_matriz(ramo);
			free_stack(arvore);
			return NULL;
		}
		for(a=0;a<3;a++){
			for(b=0;b<3;b++){
				if (ramo[a][b] == '0')
				{
					break;
				}
			}
			if (ramo[a][b] == '0')
			{
				break;
			}
		}		
		if(a == 1 || a == 2){
			/*1° possibilidade ir pra cima*/
			copia_tabuleiro(ramo,temp);
			troca = temp[a-1][b];
			temp[a-1][b] = temp[a][b];
			temp[a][b] = troca;
			push(auxiliar,temp);			
		}
		if(a == 1 || a == 0){
			/*1° possibilidade ir pra baixo*/
			copia_tabuleiro(ramo,temp);
			troca = temp[a+1][b];
			temp[a+1][b] = temp[a][b];
			temp[a][b] = troca;
			push(auxiliar,temp);
		}
		if(b == 1 || b == 0){
			/*1° possibilidade ir pra direita*/
			copia_tabuleiro(ramo,temp);
			troca = temp[a][b+1];
			temp[a][b+1] = temp[a][b];
			temp[a][b] = troca;
			push(auxiliar,temp);
		}
		if(b == 2 || b == 1){
			/*1° possibilidade ir pra direita*/
			copia_tabuleiro(ramo,temp);
			troca = temp[a][b-1];
			temp[a][b-1] = temp[a][b];
			temp[a][b] = troca;
			push(auxiliar,temp);
		}
	}

	free_matriz(temp);
	free_matriz(ramo);
	free_stack(arvore);

	*nivel = *nivel + 1;
	return auxiliar;
}

int main(int argc, char const *argv[])
{
	Pilha* arvore;
	arvore = entrada_dados();		
	int nivel=0;

	do{
		arvore = ramifica(arvore,&nivel);
	}while(arvore != NULL);	

	printf("Número de passos %d\n",nivel);

	
	return 0;
}
