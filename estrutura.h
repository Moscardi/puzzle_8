#include "tabuleiro.h"

typedef struct node
{
    unsigned short int passo;
    unsigned short int custo;
    int tabuleiro;
    struct node* next;
} No;

typedef struct lista
{
    struct node *head;
} Lista;

/** \brief Cria uma lista vazia
 * \param void
 * \return Lista*
 */
Lista* create_list (void);

/** \brief Cria um nó com o tabuleiro passado e calcula seu custo armazenando-o
 * \param int* tabuleiro
 * \return No*
 */
No* create_no(int tabuleiro, unsigned short int passo);

/** \brief Armazena um Nó em uma lista de forma crescente em relação ao seu custo
 * \param Lista* f
 * \param int* tabuleiro
 * \param unsigned short int* passo
 * \return void
 */
void insertInList (Lista *f, int tabuleiro,unsigned short int passo);

/** \brief Retorna o primeiro Nó da Lista, ou seja, o com o menor valor de custo
 * \param Lista* f
 * \return No*
 */
No* removeFromList (Lista *f);

/** \brief Verifica se a Lista passada está vazia
 * \param Lista* f
 * \return int
 */
int listaIsEmpty (Lista *f);

/** \brief Retira da memória toda uma Lista
 * \param Lista* f
 * \return int
 */
void free_list (Lista *f);

/** \brief Verifica se um determinado tabuleiro existe em uma Lista
 * \param Lista* f
 * \param No* novo
 * \return int
 */
int puzzleExist(Lista *f, int puzzle,int passos);





