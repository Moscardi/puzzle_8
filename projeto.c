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

#include "util.h"

//Função que processa os Nos e ramifica os "galhos" com as novas possibilidades
Pilha* ramifica(Pilha* arvore,int *nivel){
	//Instancia uma pilha auxiliar para armazenar as jogadas possiveis
	Pilha *auxiliar = create_stack();
	//Instancia variaveis temporarias para receber os dados da Pilha
	char **ramo,**temp;
	//Instancia variavel de troca de dados
	char troca;
	//Instancia variaveis contadoras para laço de repetição
	int a,b;
	/*Aloca espaço na memória para o tabuleiro temporario*/
	temp = (char**)malloc(3*sizeof(char*));
	temp[0] = (char*)malloc(3*sizeof(char));
	temp[1] = (char*)malloc(3*sizeof(char));
	temp[2] = (char*)malloc(3*sizeof(char));	
	//Varre toda a Pilha recebida
	while(!empty(arvore)){
		ramo = pop(arvore);
		//verifica se o estado do puzzle atual está correto
		if(verifica_tabuleiro(ramo)){
			//remove as variaveis temporarias e as recebidas
			free_matriz(temp);
			free_matriz(ramo);
			free_stack(arvore);
			free_stack(auxiliar);
			//retorna NULL quando achou o resultado
			return NULL;
		}
		//Acha onde está o espaço vazio ou '*'
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
		//Para cada possibilidade de jogada, com base na localização
		//do espaço vazio, é criada um estado do puzzle e armazenada
		//na pilha auxiliar
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
			/*1° possibilidade ir pra esquerda*/
			copia_tabuleiro(ramo,temp);
			troca = temp[a][b-1];
			temp[a][b-1] = temp[a][b];
			temp[a][b] = troca;
			push(auxiliar,temp);
		}
	}
	//remove as variaveis auxiliares criadas
	free_matriz(temp);
	free_matriz(ramo);
	free_stack(arvore);
	//aumenta o contador de jogadas
	*nivel = *nivel + 1;
	//retorna todas as novas possibilidades de jogada
	return auxiliar;
}

/*
 *Função Main
 */
int main(int argc, char const *argv[])
{
	// declara uma Pilha arvore
	Pilha* arvore;
	//faz arvore receber a entrada do usuário
	arvore = entrada_dados();		
	// declara e atribui um valor para a variável que contará o número de passos
	int nivel=0;

	//Laço de repetição que controlá quando o algoritimo achou o resultado
	do{
		//chama a função para criar uma arvore de possibilidades
		arvore = ramifica(arvore,&nivel);
	}while(arvore != NULL);	
	//imprime o resultado para o usuário
	printf("Número de passos %d\n",nivel);
	//fim do programa	
	return 0;
}