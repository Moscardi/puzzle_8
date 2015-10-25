#include "estrutura.h"
#include <time.h>



/** \brief Função Main, responsavel por coletar dados digitados e chamar a função para processar as possibilidades *
 * \param int argc
 * \param char const argc[]
 * \return int
 * \author Lucas Giovani
 * \author José Moscardi da Silva Junior
 */
int main(int argc, char const *argv[])
{
    char **temp = create_matriz();
    clock_t inicio, fim;
    int numeroPassos = 0;
    Lista* puzzle = create_list();

    /**< Pega os dados do teclado para montar o tabuleiro */
    printf("Digite o tabuleiro desejado:\n");
    __fpurge(stdin);
    scanf("%c%c%c",&(temp[0][0]),&(temp[0][1]),&(temp[0][2]));
    __fpurge(stdin);
    scanf("%c%c%c",&(temp[1][0]),&(temp[1][1]),&(temp[1][2]));
    __fpurge(stdin);
    scanf("%c%c%c",&(temp[2][0]),&(temp[2][1]),&(temp[2][2]));
    temp[1][1] = '9';

    /**< insere o tabuleiro em uma lista inicial para começar o processamento dos números de passo */
    int *temporario_puzzle;
    *temporario_puzzle = intToMatriz(temp);
    insertInList(puzzle,create_no(temporario_puzzle,0));
    free(temporario_puzzle);

    /**< Pega o tempo inicial do sistema para calcular o tempo gasto */
    inicio = clock();

    /**<Chama a função que retorna o menor número de passos*/
    numeroPassos = TotalPassos(create_list(),puzzle);

    /**< Obtem o tempo do sistema para fazer o calculo do tempo gasto*/
    fim = clock();
    free_matriz(temp);
    printf("\n\nExecução do algoritimo em %ld segundos\n", (fim - inicio)/ CLOCKS_PER_SEC);
    return 0;
}
