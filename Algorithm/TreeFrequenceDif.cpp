#include <stdio.h>
#include <iostream>
#include <vector>
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

struct no{
    int key;
    no* lf;
    no* rt;
};

void setTree(int **K, int i,int j, int* keys,no* root){
    int k= K[i][j];
    root->key=keys[k];
    if(k==0 || i>j || i>k-1 || k>j)return;
    root ->lf = new no;
    root ->rt = new no;
    setTree(K,i,k-1,keys,root->lf);
    setTree(K,k,j,keys,root->rt);
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

void printTree(const string& prefix, const no* root, bool isLeft){
     if( root != nullptr && root->key !=0 )
    {
        cout << prefix;
        cout << (isLeft ? "├── " : "└── " );
        cout << root->key << endl;
        printTree( prefix + (isLeft ? "│   " : "    "), root->lf, true);
        printTree( prefix + (isLeft ? "│   " : "    "), root->rt, false);
    }
    else{
        cout << prefix;
        cout << (isLeft ? "├── " : "└── " );
        cout << "*" << endl;
    }
}

int main(){
    int size=6;
    int f[]={0,1,4,3,1,2};
    int f_[]={2,2,1,1,1,3};
    int keys[]={0,1,2,3,4,5};

    int **F=matriz(size);
    int **C=matriz(size);
    int **K=matriz(size);

    getCost(f,f_,C,F,K,size);
    cout<< "F\n";
    printMatriz(F,size,3);//printing the matriz
    cout<< "C\n";
    printMatriz(C,size,3);
    cout<< "K\n";
    printMatriz(K,size,3);
    cout <<"\n";

    struct no* root=new no;
    setTree(K,0,size-1,keys,root);
    printTree("", root,false);//printing the tree
}