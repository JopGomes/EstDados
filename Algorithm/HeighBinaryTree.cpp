#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct no
{
    int freq;
    int height;
    struct no *lf;
    struct no *rt;
};

vector<no *> arvores;

bool sortAux(no *a, no *b) // Sort the vector of tree with the frequencia f1 < f2
{
    if (a->freq < b->freq)
        return true;
    else
        return false;
}

void setTree()
{

    for (int i = 0;2 > i; i++)
    {
        struct no *aux = new no;
        aux->height = 0;
        aux->freq = i;
        aux->lf = NULL;
        aux->rt = NULL;
        arvores.push_back(aux);
    }
    sort(arvores.begin(), arvores.end(), sortAux);
}

void algHuffman()
{
    if (arvores.size() == 1)
        return;
    struct no *aux = new no;
    aux->freq = arvores[0]->freq + arvores[1]->freq;
    aux->height = 0;
    aux->lf = arvores[0];
    aux->rt = arvores[1];
    arvores.erase(arvores.begin(), arvores.begin() + 2);
    arvores.push_back(aux);
    sort(arvores.begin(), arvores.end(), sortAux);
    algHuffman();
}

void heighTree(no *root)
{    
    int alt1,alt2;
    if (root->lf){
        alt1= root->lf->height;
    }
    else alt1=0;
    if(root->rt){
        alt2=root->rt->height;
    }
    if(alt1>alt2){root->height=alt1+1;}
    else{root->height=alt2+1;}
}

void posOrd(no *aux)
{
    if (aux->lf)
        posOrd(aux->lf);
    if (aux->rt)
        posOrd(aux->rt);
    heighTree(aux);
}



int main()
{
    setTree();    // Create all one-nó-tree from the frequence
    algHuffman(); // Arvores[0] is a binary tree;
    posOrd(arvores[0]); // Set the height of all node of the tree
    cout << arvores[0]->height;
}