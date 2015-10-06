#include "util.h"

/*
 *Função responsavel por verificar se em uma determinada matriz 3x3 existem letras 
*/
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

/*
 *Verifica se um tabuleiro está correto ou errado 
 */
int verifica_tabuleiro(char **tabuleiro){
	if(tabuleiro[0][0] != '1' || tabuleiro[0][1] != '2' || tabuleiro[0][2] != '3'
		|| tabuleiro[1][0] != '8' || tabuleiro[1][1] != '0' || tabuleiro[1][2] != '4'
		|| tabuleiro[2][0] != '7' || tabuleiro[2][1] != '6' || tabuleiro[2][2] != '5'){
		return (1 == 0);
	}
	return (1 == 1);
}

/*
 *Função para entrada de dados do usuário, ela retorna uma Pilha pronta com 
 *o primeiro estado do puzzle
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

/*
 *Retira da memória uma determinada matrix 3x3
 */
void free_matriz(char **lixo){
	free(lixo[0]);
	free(lixo[1]);
	free(lixo[2]);
	free(lixo);
}

/*
 *Verifica a igualdade de dois tabuleiros, retornando se são diferentes ou não.
 */
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

/*
 *Faz a cópia exata de um estado do puzzle
 */
void copia_tabuleiro(char **info, char**copia){
	int a,b;	
	for(a=0;a<3;a++){
		for(b=0;b<3;b++){
			copia[a][b] = info[a][b];
		}
	}
}