#include <stdio.h>
#define N 9

int busca(int *l, int chave, int TMax)
{
    int i = 1;
    if (l[0] == 0)
        return 0;
    else
    {
        while (l[i] != chave && i <= l[0])
        {
            i++;
        }
        if (i <= l[0]) {
                return i;
            }
            else
            {
                return 0;
            }
    }
}
int inserir(int *l, int chave, int TMax)
{
    int x;
    x = busca(l, chave, TMax);
    if (x == 0)
    {
        if (l[0] == TMax - 1)
            return 0; // lista cheia
        else
        {
            l[0]++;
            l[l[0]] = chave;
            return 1;
        }
    }
    else return 0;
}
int remover(int *l, int chave, int TMax)
{
    int x;
    if (l[0] == 0)
    {
        return 0; // lista vazia
    }
    else
    {
        x = busca(l, chave, TMax);
        if (x == 0)
            return 0;
        else
        {
            int i = x;
            while (i < l[0])
            {
                l[i] = l[i + 1];
                i++;
            }
            l[0]--;
            return 1;
        }
    }
}
int main(int argc, const char *argv[])
{
    int x;
    int lista[N];

    inserir(lista, 10, N);
    inserir(lista, 8, N);
    inserir(lista, 17, N);
    inserir(lista, 30, N);
    inserir(lista, 5, N);

    x = busca(lista, 17, N);
    printf("%d",x);
    remover(lista, 17, N);

    x = busca(lista, 17, N);
    printf("%d",x);
}