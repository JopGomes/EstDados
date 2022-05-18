#include <stdio.h>
#include <stdlib.h>

#define tam1 20
#define tam2 30

int busca_lista1(int array[],int topo1,int chave)
{
    for(int i = 0; topo1>=i;i++){
        if(chave==array[i]) return i;
    }
    return -1;
}
int busca_lista2(int array[],int topo2,int chave)
{
    for(int i = tam2+tam1; i>=topo2;i--){
        if(chave==array[i]) return i;
    }
    return -1;
}

int push1(int *array,int *topo1, int chave)
{
    if (busca_lista1(array, *topo1 ,chave) !=-1)
        return 0;
    else if(tam1 > *topo1){
        int count =*topo1;
        array[count]=chave;
        *topo1+=1;
    }else{
        array[0]=chave;
    }
    return 1;
}
int push2(int *array,int *topo2, int chave)
{
    if (busca_lista2(array, *topo2,chave) !=-1)
        return 0;
    else if(tam1 < *topo2){
        int count =*topo2+tam1-1;
        array[count]=chave;
        *topo2 -=1;
    }else{
        array[tam1+1]=chave;
    }
    return 1;
}

int pop1(int *array,int *topo1)
{
    if(*topo1>0){
        *topo1-=1;
        array[*topo1]=0;
    }
    else{
        array[0]=0;
    }
    return 1;
}

int pop2(int *array,int *topo2)
{
    if(tam2+tam1>*topo2){
        *topo2+=1;
        array[*topo2+tam1-1]=0;
    }
    return 1;
}


int main()
{
    int array[tam1+tam2], topo1=0, topo2=tam2;
    push1(array,&topo1, 10);
    printf("%d\n",array[0]);
    push2(array,&topo2, 20);
    printf("%d\n",array[tam1+1]);
    push1(array,&topo1, 30);
    printf("%d\n",array[1]);
    push2(array,&topo2, 40);
    printf("%d\n",array[tam1+1]);
    pop1(array,&topo1);
    printf("%d\n",topo1);
    pop2(array,&topo2);
    printf("%d\n",topo2);
}