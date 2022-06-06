//
//  main.c
//  recupera-arv
//
//  Created by Luiz Araujo on 27/04/22.
//

#include <stdio.h>
#include <stdlib.h>

int pre[8]={40,30,10,20,60,50,70,80};
int sim[8]={10,20,30,40,50,60,70,80};

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *arv=NULL;

struct no *recupera (int *pre, int *sim, int ip, int fp, int is, int fs)
{
    struct no *aux;
    int NR_esq = 0;
    int NR_dir = 0;
    if (ip == fp) // problema infantil
    {
        aux = malloc (sizeof(struct no));
        aux->chave = pre[ip];
        aux->esq = NULL;
        aux->dir = NULL;
    }
    else
    {
        int i;
        aux = malloc (sizeof(struct no));
        aux->chave = pre[ip];
        for (i=is; sim[i] != pre[ip]; i++)
        {
        }
        if (i == is) // Não há ramo esquerdo
        {
            aux->esq = NULL;
        }
        else
        {
            NR_esq = i - is;
            aux->esq = recupera(pre,sim,ip+1,ip+NR_esq,is,i-1);
        }
        if (i == fs)
        {
            aux->dir = NULL;
        }
        else
        {
            NR_dir = fs - i;
            aux->dir = recupera(pre,sim,ip+NR_esq+1,fp,i+1,fs);
        }
    }
    return aux;
}

void pre_ordem (struct no *r)
{
    if (r != NULL)
    {
        printf ("%d, ",r->chave);
        pre_ordem (r->esq);
        pre_ordem(r->dir);
    }
}

struct no *busca (int chave, struct no *raiz, struct no **pai)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->chave == chave)
        return raiz;
    else
    {
        if (chave < raiz->chave && raiz->esq != NULL)
        {
            *pai = raiz;
            return busca (chave, raiz->esq, pai);
        }
        else if (chave > raiz->chave && raiz->dir != NULL)
        {
            *pai = raiz;
            return busca(chave, raiz->dir, pai);
        }
        return raiz;
    }
}

int inserir (int chave, struct no **raiz)
{
    struct no *aux;
    struct no *pai = NULL;
    struct no *novo=NULL;
    aux = busca (chave, *raiz, &pai);
    
    if (aux == NULL) // Tratamento da árvore vazia
    {
        novo = malloc(sizeof(struct no));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    else
    {
        if (aux->chave == chave)
            return 0;
        else
        {
            novo = malloc (sizeof(struct no));
            novo->chave=chave;
            novo->esq = NULL;
            novo->dir = NULL;
            if (chave < aux->chave)
                aux->esq = novo;
            else
                aux->dir = novo;
            return 1;
        }
    }
}


struct no *remove_aux (int chave, struct no **raiz, int exato)
{
    struct no *aux = NULL, *pai = NULL;
    struct no *aux1 = NULL;
    aux = busca (chave,*raiz,&pai);
    if (aux == NULL)
        return NULL;
    else if (aux->chave != chave && exato == 1)
        return NULL;
    {
        if (aux->esq == NULL && aux->dir == NULL) // caso 1
        {
            if (pai == NULL) // Árvore unitária, folha que tb é raiz
            {
                *raiz = NULL;
                return aux;
            }
            else // Folha qualquer
            {
                if (aux->chave < pai->chave)
                    pai->esq = NULL;
                else
                    pai->dir = NULL;
                return aux;
            }
        }
        else if (aux->dir == NULL || aux->esq == NULL) //caso 2
        {
            if (pai == NULL) // Remoção da raiz caso 2
            {
                if (aux->dir != NULL)
                    *raiz = aux->dir;
                else
                    *raiz = aux->esq;
                return aux;
            }
            else
            {
                if (aux->chave > pai->chave) // 1 e 2
                {
                    if (aux->esq != NULL)
                        pai->dir = aux->esq;
                    else
                        pai->dir = aux->dir;
                    return aux;
                }
                else // 3 e 4
                {
                    if (aux->dir != NULL)
                        pai->esq = aux->dir;
                    else
                        pai->esq = aux->esq;
                    return aux;
                }
            }
        }
        else
        {
            aux1 = remove_aux (chave, &(aux->esq),0);
            aux1->dir = aux->dir;
            aux1->esq = aux->esq;
            if (pai == NULL) // remoção da raiz
            {
                *raiz = aux1;
                return aux;
            }
            else
            {
                if (aux1->chave < pai->chave)
                    pai->esq = aux1;
                else
                    pai->dir = aux1;
                return aux;
            }
        }
    }
}


int remover (int chave, struct no **raiz)
{
    struct no *aux;
    aux = remove_aux (chave, raiz, 1);
    if (aux != NULL)
    {
        free (aux);
        return 1;
    }
    else
        return 0;
}

int main(int argc, const char * argv[]) {
  
    struct no *aux, *pai = NULL;
    
    printf("Teste\n");
    arv = recupera (pre,sim,0,7,0,7);
    pre_ordem (arv);
 //   aux = busca (70, arv, &pai);
 //   printf("\n chave %d, pai %d",aux->chave,pai->chave);
 //   pai = NULL;
 //   aux = busca (75, arv, &pai);
 //   inserir (75,&arv);
 //   pai = NULL;
//    aux = busca (75, arv, &pai);
//    printf("\n chave %d, pai %d",aux->chave,pai->chave);
    remover (80,&arv);
    printf("\n");
    pre_ordem(arv);
    printf("\n");
    remover (30,&arv);
    pre_ordem(arv);
    printf("\n");
    remover (60,&arv);
    pre_ordem(arv);
    printf("\n");
    remover (40,&arv);
    pre_ordem(arv);


}


