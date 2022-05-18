#include <stdio.h>
#include <stdlib.h>

#define tam 51

int busca_lista(int array[],int chave)
{
    for(int i = 1; array[0]>=i;i++){
        if(chave==array[i]) return i;
    }
    return -1;
}

int push(int *array, int chave)
{
    if (busca_lista(array, chave) !=-1)
        return 0;
    else if(tam > array[0]){
        int count =array[0]++;
        array[count]=chave;
    }else{
        array[1]=chave;
    }
    return 1;
}

int pop(int *array)
{
    if(array[0]>1){
        array[0]-=1;
    }
    return 1;
}



int main()
{
    int array[tam];
    array[0]=1;
    push(array, 10);
    printf("%d\n",array[1]);
    push(array, 20);
    printf("%d\n",array[2]);
    push(array, 30);
    printf("%d\n",array[3]);
    pop(array);
    printf("%d",array[0]-1);
}