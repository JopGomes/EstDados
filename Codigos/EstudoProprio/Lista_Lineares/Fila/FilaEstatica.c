#include <stdio.h>
#include <stdlib.h>

#define tam 51

int busca_lista(int array[],int inicio, int fim, int chave)
{
    for(int i = inicio; fim>=i;i++){
        if(chave==array[i]) return i;
    }
    return -1;
}

int push(int *array,int *inicio, int *fim, int chave)
{
    if (busca_lista(array, *inicio,  *fim, chave) !=-1)
        return 0;
    if(*fim==*inicio && *fim==0){
        array[*fim]=chave;
        *fim+=1;
        int count =*fim;
    }
    else if(tam > *fim && *fim != *inicio ){
        array[*fim]=chave;
        *fim+=1;
        int count =*fim;
    }else if(tam==*fim && *fim != *inicio){
        *fim =0;
        array[*fim] = chave;
    }else {
        return -1;
    }
    return 1;
}

int pop(int *array, int *inicio, int *fim)
{
    if(tam > *inicio && *fim != *inicio ){
        *inicio+=1;
    }else if(tam==*inicio && *fim != *inicio){
        *inicio=0;
    }else {
        return -1;
    }
    return 1;
}



int main()
{
    int array[tam],inicio=0,fim=0;
    push(array,&inicio,&fim, 10);
    printf("%d\n",array[0]);
    push(array,&inicio,&fim, 10);
    printf("%d\n",array[0]);
    push(array,&inicio,&fim, 20);
    printf("%d\n",array[1]);
    push(array,&inicio,&fim, 30);
    printf("%d\n",array[2]);
    pop(array,&inicio,&fim);
    printf("i:%d f:%d",inicio,fim);
}