#include "estrutura.h"

Lista* create_list (void)
{
    Lista *f = (Lista*)malloc(sizeof(Lista));
    f->head = NULL;
    return f;
}

No* create_no(int tabuleiro, unsigned short int passo)
{
    No* novo = (No*)malloc(sizeof(No));
    novo->custo = getCusto(tabuleiro);
    novo->tabuleiro = tabuleiro;
    novo->passo = passo;
    novo->next = NULL;
    return novo;
}

void insertInList (Lista *f, int tabuleiro,unsigned short int passo)
{
    No* novo = create_no(tabuleiro,passo);
    Lista* l = create_list();
    l->head = f->head;

    if(!listaIsEmpty(l) && novo->passo == l->head->passo && novo->custo < l->head->custo)
    {
        novo->next = l->head;
        l->head = novo;
        f->head = l->head;
        free(l);
        return;
    }
    else if(listaIsEmpty(l) || novo->passo < l->head->passo)
    {
        novo->next = l->head;
        l->head = novo;
        f->head = l->head;
        free(l);
        return;
    }

    for(; !listaIsEmpty(l); l->head = l->head->next)
    {
        if(l->head->next != NULL && novo->passo == l->head->next->passo && novo->custo < l->head->next->custo)
        {
            novo->next = l->head->next;
            l->head->next = novo;
            free(l);
            return;
        }
        else if(l->head->next == NULL || novo->passo < l->head->next->passo)
        {
            novo->next = l->head->next;
            l->head->next = novo;
            free(l);
            return;
        }
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
    f->head = retorno->next;
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

int puzzleExist(Lista *f, int puzzle)
{
    Lista *aux = create_list();
    aux->head = f->head;

    while(!listaIsEmpty(aux))
    {
        if(aux->head->tabuleiro == puzzle)
        {
            return (1 == 1);
        }
        aux->head = aux->head->next;
    }
    return (1 == 0);
}
