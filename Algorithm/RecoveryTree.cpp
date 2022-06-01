#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct no
{
    int key;
    struct no *lf;
    struct no *rt;
};

void printTree(const std::string &prefix, const no *root, bool isLeft)
    {
        if (root != NULL && root->key != 0)
        {
            cout << prefix;
            cout << (isLeft ? "├── " : "└── ");
            cout << root->key << endl;
            printTree(prefix + (isLeft ? "│   " : "    "), root->lf, true);
            printTree(prefix + (isLeft ? "│   " : "    "), root->rt, false);
        }
        else
        {
            cout << prefix;
            cout << (isLeft ? "├── " : "└── ");
            cout << "*" << endl;
        }
    }

void getTree(no *arv, vector<int>& preOrd, vector<int>& simOrd,int preI,int preF, int simI,int simF)
{
    int count = 0;
    int i;
    for ( i = simI; simF>= i; i++)
    {
        if (simOrd[i] == preOrd[preI])
        {
            arv->key=preOrd[preI];
            count++;
            break;
        }
    }

    if(preI>=preF){
        arv->lf = NULL;
        arv->rt = NULL;
        return;
    }
    if(simI==simF){
        arv->lf = NULL;
        arv->rt = NULL;
        return;
    }
    if(!count){
        arv->lf = NULL;
        arv->rt = NULL;
        return;
    }
    int tamL=i-simI;
    arv->lf = new no;
    arv->rt = new no;
    getTree(arv->lf, preOrd, simOrd,preI+1,preI+tamL,simI,i-1);
    getTree(arv->rt, preOrd, simOrd,preI+tamL+1,preF,i+1,simF);
}

int main()
{
    vector<int> preOrd = {50, 40, 30, 45, 60, 55};
    vector<int> simOrd = {30, 40, 45, 50, 55, 60};
    no *aux = new no;
    getTree(aux, preOrd, simOrd,0,preOrd.size()-1,0,simOrd.size()-1);
    printTree("",aux,false);
    return 0;
}