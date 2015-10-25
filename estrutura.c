#include "estrutura.h"

Lista* create_list (void)
{
    Lista *f = (Lista*)malloc(sizeof(Lista));
    f->head = NULL;
    return f;
}

No* create_no(int* tabuleiro, unsigned short int* passo)
{
    printf("INicio da função que cria nó\n");
    No* novo = (No*)malloc(sizeof(No));
    novo->custo = getCusto(tabuleiro);
    novo->tabuleiro = *tabuleiro;
    novo->passo = *passo;
    novo->next = NULL;
    return novo;
}

void insertInList (Lista *f, No* novo)
{
    printf("Inicio função inserir na lista");
    if(listaIsEmpty(f) || novo->custo < f->head->custo)
    {
        novo->next = f->head;
        f->head = novo;
        return;
    }
    Lista* l = f;
    while(!listaIsEmpty(l))
    {
        if(l->head->next == NULL || novo->custo < l->head->next->custo)
        {
            novo->next = l->head->next;
            l->head->next = novo;
            return;
        }
        l->head = l->head->next;
    }
    printf("Erro ao inserir No na Lista\n");
    exit(1);
}

No* removeFromList (Lista *f)
{
    if (listaIsEmpty(f))
    {
        printf("Erro:fila vazia!");
        exit(1); /*aborta programa*/
    }
    No* retorno = f->head;
    f->head = f->head->next;
    retorno->next = NULL;
    return retorno;
}

int listaIsEmpty (Lista *f)
{
    return (f->head == NULL);
}

void free_list (Lista *f)
{
    No *temp;
    while(!listaIsEmpty(f))
    {
        temp = f->head;
        f->head = temp->next;
        free(temp);
    }
    free(f);
}

int puzzleExist(Lista *f, int* puzzle)
{
    Lista* aux = f;

    while(!listaIsEmpty(aux))
    {
        if(compara_tabuleiros(&(aux->head->tabuleiro),puzzle)){
            return (1 == 1);
        }
        aux->head = aux->head->next;
    }
    return (1 == 0);
}
