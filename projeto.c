#include "estrutura.h"
#include <time.h>

/** \brief Essa função testa todas as possibilidades de movimento até solucionar o puzzle, retornando o menor número de movimentos
 * \param Lista* processados
 * \param Lista* espera
 * \return int
 */
unsigned short int TotalPassos(Lista* processados, Lista* espera)
{
    No* processar = removeFromList(espera);
    int newPuzzle;
    unsigned short int newPasso;
    insertInList(processados,processar->tabuleiro,processar->passo);

    printf("----------------------------------------------------------\n");
    printf("Tabuleiro processado: pontuação %d\n\n",processar->custo);
    printMatrizInt(processar->tabuleiro);
    if(verifica_tabuleiro(processar->tabuleiro))
    {
        unsigned short int menor_passo = processar->passo;
        free(processar);
        free_list(espera);
        free_list(processados);
        return menor_passo;
    }
    int x,y;
    getSpace(processar->tabuleiro,&x,&y);
    if(x == 0 || x == 1)
    {
        newPuzzle = processar->tabuleiro;
        moveRight(&newPuzzle);
        if(!puzzleExist(processados,newPuzzle) && !puzzleExist(espera,newPuzzle))
        {
            newPasso = processar->passo + 1;
            insertInList(espera,newPuzzle,newPasso);
        }
    }
    if(x == 1 || x == 2)
    {
        newPuzzle = processar->tabuleiro;
        moveLeft(&newPuzzle);
        if(!puzzleExist(processados,newPuzzle) && !puzzleExist(espera,newPuzzle))
        {
            newPasso = processar->passo + 1;
            insertInList(espera,newPuzzle,newPasso);
        }
    }
    if(y == 0 || y == 1)
    {
        newPuzzle = processar->tabuleiro;
        moveDown(&newPuzzle);
        if(!puzzleExist(processados,newPuzzle) && !puzzleExist(espera,newPuzzle))
        {
            newPasso = processar->passo + 1;
            insertInList(espera,newPuzzle,newPasso);
        }
    }
    if(y == 1 || y == 2)
    {
        newPuzzle = processar->tabuleiro;
        moveUp(&newPuzzle);
        if(!puzzleExist(processados,newPuzzle) && !puzzleExist(espera,newPuzzle))
        {
            newPasso = processar->passo + 1;
            insertInList(espera,newPuzzle,newPasso);
        }
    }

    //scanf("%d",&newPuzzle);
    free(processar);
    return TotalPassos(processados,espera);
}

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
    unsigned short int numeroPassos = 0;
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
    int temporario_puzzle = matrizToInt(temp);
    insertInList(puzzle,temporario_puzzle,numeroPassos);

    /**< Pega o tempo inicial do sistema para calcular o tempo gasto */
    inicio = clock();

    /**<Chama a função que retorna o menor número de passos*/
    numeroPassos = TotalPassos(create_list(),puzzle);

    /**< Obtem o tempo do sistema para fazer o calculo do tempo gasto*/
    fim = clock();
    free_matriz(temp);

    /**< Mostra os dados*/
    printf("\n\n\nO menor número de passos para resolver o tabuleiro são %d passos\n",numeroPassos);
    printf("\n\nExecução do algoritimo em %ld segundos\n", (fim - inicio)/ CLOCKS_PER_SEC);
    return 0;
}
