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
    return 1;
}

TLista *insercao(TLista **pInicio, int chave)
{
    TLista *novoElemento = (TLista *)malloc(sizeof(TLista));
    novoElemento->chave = chave;
    novoElemento->prox = *pInicio;
    *pInicio = novoElemento;
    return novoElemento->prox;
}

TLista *remove_L_adc_LR(TLista **pInicioL, TLista **pInicioLR)
{
    TLista *auxL = *pInicioL,*auxLR;
    while (auxL)
    {
        auxLR=insercao(pInicioLR, auxL->chave);// Adiciona na lsita LR
        remocao(&auxL); // Remove a lsita L
    }
    return auxLR;
}

int main()
{
    // Coloquei chave para ficar mais facil de vizualizar essa ordenação
    TLista *L = (TLista *)malloc(sizeof(TLista)); // Pilha 1 
    L->prox = NULL;
    TLista *LR = (TLista *)malloc(sizeof(TLista));// Pilha 2
    LR->prox = NULL;
    insercao(&L, 40);// Insere em L a chave 40 ( um nó com  chave 40)
    insercao(&L, 30);// Insere em L a chave 30 ( um nó com  chave 30)
    insercao(&L, 20);// Insere em L a chave 20 ( um nó com  chave 20)
    insercao(&L, 10);// Insere em L a chave 10 ( um nó com  chave 10)
    TLista *auxL = L;
    printf("Lista L : \n ");
    while (auxL->prox)
    {
        printf("%d ",auxL->chave);
        auxL=auxL->prox;
    }
    
    TLista *auxLR = remove_L_adc_LR(&L, &LR), *antLR;
    printf("\nLista LR : \n ");
    while (auxLR->prox)
    {
        printf("%d ",auxLR->chave);
        antLR= auxLR;
        auxLR=auxLR->prox;
        free(antLR); // Pra nao desgastar o PC liberar memoria, não está no algoritmo.
    }
}