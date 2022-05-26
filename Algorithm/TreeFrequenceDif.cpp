#include <stdio.h>
#include <iostream>
using namespace std;

void getSumFreq(int *f,int *f_, int **F,int size){
    for(int i=0;size>i;i++){
        F[i][i]=f_[i];
    }
    for(int i=0;size>i;i++){
        for(int j=i+1;size>j;j++){
            F[i][j]=F[i][j-1]+f[j]+f_[j];
        }
    }
}

void getCost(int *f,int *f_, int **C,int ** F,int**K,int size){
    
    getSumFreq(f,f_,F,size);
    for(int dif=1;size>dif;dif++){
        for(int j=1;size>j;j++){
            int min= __INT_MAX__;
            int i=j-dif;
            if(i<0)continue;
            for(int k=i+1;j+1>k;k++){
                int aux= C[i][k-1]+C[k][j]+F[i][j];
                if(min>aux){
                    min=aux;
                    C[i][j]=aux;
                    K[i][j]=k;
                }
            }
        }
    }
}



int** matriz(int size){
    int** a= new int*[size];
    for(int i=0;size>i;i++){
        a[i]=new int[size];
        for(int j=0;size>j;j++){
            a[i][j]=0;
        }
    }
    
    return a;
}

void printMatriz(int **M,int size, int casa_dec){
    for(int i=0;size>i;i++){
        cout <<"\n";
        for(int j=0;size>j;j++){
            cout << M[i][j]<< " ";
            
        }
    }
    cout <<"\n";
}

int main(){
    int size=6;
    int f[]={0,2,10,3,5,9};
    int f_[]={3,1,1,1,1,2};
    int **F=matriz(size);
    int **C=matriz(size);
    int **K=matriz(size);
    getCost(f,f_,C,F,K,size);
    printMatriz(F,size,3);
    printMatriz(C,size,3);
    printMatriz(K,size,3);
}