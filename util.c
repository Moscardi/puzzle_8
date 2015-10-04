#include "util.h"


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

int verifica_tabuleiro(char **tabuleiro){
	if(tabuleiro[0][0] != '1' || tabuleiro[0][1] != '2' || tabuleiro[0][2] != '3'
		|| tabuleiro[1][0] != '8' || tabuleiro[1][1] != '0' || tabuleiro[1][2] != '4'
		|| tabuleiro[2][0] != '7' || tabuleiro[2][1] != '6' || tabuleiro[2][2] != '5'){
		return (1 == 0);
	}
	return (1 == 1);
}

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

void free_matriz(char **lixo){
	free(lixo[0]);
	free(lixo[1]);
	free(lixo[2]);
	free(lixo);
}