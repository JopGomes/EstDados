#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} TLista;

TLista *busca_lista(TLista **pInicio, int chave)
{
    TLista *aux = *pInicio, *ant = NULL;
    while (aux)
    {
        if (aux->chave == chave)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return aux;
}

int remocao(TLista **pInicio)
{
    TLista *aux = *pInicio;
    *pInicio = aux->prox;
    free(aux);
    aux = NULL;
    return 1;
}

int insercao(TLista **pInicio, int chave)
{
    TLista *novoElemento = (TLista *)malloc(sizeof(TLista));
    if (busca_lista(pInicio, chave))
        return 0;
    novoElemento->chave = chave;
    novoElemento->prox = *pInicio;
    *pInicio = novoElemento;
    return 1;
}

int main()
{
    TLista *inicio = (TLista *)malloc(sizeof(TLista));
    inicio->prox = NULL;
    insercao(&inicio, 10);
    insercao(&inicio, 20);
    remocao(&inicio);
    remocao(&inicio);
}