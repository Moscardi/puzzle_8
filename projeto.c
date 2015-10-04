#include "estrutura.h"

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
*/

Pilha* entrada_dados(void){
	Pilha* temp = create_stack();
	char** dados = (char**)malloc(3*sizeof(char*));
	dados[0] = (char*)malloc(3*sizeof(char));
	dados[1] = (char*)malloc(3*sizeof(char));
	dados[2] = (char*)malloc(3*sizeof(char));
	do{		
		system("clear");
		printf("Digite os valores do tabuleiro (escreva-os como se estivesse criando um tabuleiro)\n" );
		__fpurge(stdin);
		scanf("%c%c%c",&dados[0][0],&dados[0][1],&dados[0][2]);
		__fpurge(stdin);
		scanf("%c%c%c",&dados[1][0],&dados[1][1],&dados[1][2]);
		__fpurge(stdin);
		scanf("%c%c%c",&dados[2][0],&dados[2][1],&dados[2][2]);
	}while(!verifica_dados(dados));

	push(temp,dados);
	free(dados);
	return temp;
}

int verifica_dados(char** dados){
	int i,a;
	for (i = 0; i < 3; ++i)
	{
		for (a = 0; a < 3; ++a)
		{
			if(dados[i][a] < 48 || dados[i][a] > 57){
				return (1 == 0);
			}
		}		
	}
	return (1 == 1);
}

int* ramifica(Pilha* arvore,int *nivel){
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
			return nivel;
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

	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	free(ramo[0]);
	free(ramo[1]);
	free(ramo[2]);
	free(ramo);
	free_stack(arvore);

	*nivel = *nivel + 1;
	return ramifica(auxiliar,nivel);
}

int verifica_tabuleiro(char **tabuleiro){
	if(tabuleiro[0][0] != '1' || tabuleiro[0][1] != '2' || tabuleiro[0][2] != '3'
		|| tabuleiro[1][0] != '8' || tabuleiro[1][1] != '0' || tabuleiro[1][2] != '4'
		|| tabuleiro[2][0] != '7' || tabuleiro[2][1] != '6' || tabuleiro[2][2] != '5'){
		return (1 == 0);
	}
	return (1 == 1);
}

int main(int argc, char const *argv[])
{
	Pilha* arvore;
	arvore = entrada_dados();		
	int nivel=0;
	ramifica(arvore,&nivel);
	printf("Número de passos %d\n",nivel);

	free_stack(arvore);
	return 0;
}
