#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int chave;
    struct no *prox;
    struct no *ant;
} Tlista;

Tlista *busca(int chave, Tlista **lista)
{
    Tlista *aux = *lista;
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

int insert(int chave, Tlista **lista)
{
    Tlista *aux = busca(chave, lista), *novoElemento= (Tlista*) malloc(sizeof(Tlista)),*aux2=*lista;
    if (!aux)
    {
        novoElemento->chave=chave;
        novoElemento->prox=*lista;
        *lista= novoElemento;
        aux2->ant = novoElemento;

        return 1;
    }
    else
    {
        return 0;
    }
}

int remover(int chave, Tlista **lista)
{
    Tlista *aux = busca(chave, lista), *ant, *prox;
    if (aux)
    {
        ant = aux->ant;
        prox = aux->prox;
        if(ant)
            ant->prox = aux->prox;
        prox->ant = aux->ant;
        free(aux);
        aux=NULL;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Tlista *lista = (Tlista*) malloc(sizeof(Tlista));
    lista->prox=NULL;
    lista->ant=NULL;
    insert(30,&lista);
    insert(20,&lista);
    printf("%d %d",remover(10,&lista),remover(20,&lista));
    remover(30,&lista);
    
}