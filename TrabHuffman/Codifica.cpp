#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct no
{
    int freq;
    char ch;
    struct no *lf;
    struct no *rt;
};

int nfreq[256];
vector<no *> arvores;
fstream fs;
int charNo=128;


void getFreq()
{
    char ch;
    ifstream fin("teste.txt");
    while (fin.get(ch))
    {
        nfreq[ch]++;
    }
}

bool sortAux(no *a, no *b) // Sort the vector of tree with the frequencia f1 < f2
{
    if (a->freq < b->freq)
        return true;
    else
        return false;
}

void setTree()
{

    for (int i = 0; 129 > i; i++)
    {
        if (nfreq[i])
        {
            struct no *aux = new no;
            int j = i;
            char ch = j;
            aux->ch = ch;
            aux->freq = nfreq[i];
            aux->lf = NULL;
            aux->rt = NULL;
            arvores.push_back(aux);
        }
    }
    sort(arvores.begin(), arvores.end(), sortAux);
}

void algHuffman()
{
    if (arvores.size() == 1)
        return;
    struct no *aux = new no;
    aux->freq = arvores[0]->freq + arvores[1]->freq;
    char aux3=  charNo;
    aux->ch =  aux3;//(char) charNo
    charNo++;
    aux->lf = arvores[0];
    aux->rt = arvores[1];
    arvores.erase(arvores.begin(), arvores.begin() + 2);
    arvores.push_back(aux);
    sort(arvores.begin(), arvores.end(), sortAux);
    algHuffman();
}

string WalkTree(no *aux, string ans, char target)
{
    string auxAnsRt, auxAnsLf;
    if ((aux->ch - '\0') <129 && (aux->ch-'\0')>0)
    {
        if (aux->ch == target)
            return ans;
        else
            return "";
    }
    auxAnsLf = WalkTree(aux->lf, ans + "0", target);
    auxAnsRt = WalkTree(aux->rt, ans + "1", target);
    if (auxAnsLf != "")
        return auxAnsLf;
    else if (auxAnsRt != "")
        return auxAnsRt;
    return "";
}

void preOrd(no* aux)
{  
    fs<< aux ->ch;
    if(aux->lf)preOrd(aux->lf);
    if(aux->rt)preOrd(aux->rt);
}
void symOrd(no* aux) 
{  
    if(aux->lf)symOrd(aux->lf);
    fs<< aux ->ch;
    if(aux->rt)symOrd(aux->rt);
    
}
void setText()
{
    char ch;
    ifstream fin("teste.txt");

    // Put the preOrder and the symOrd in the output;
    preOrd(arvores[0]);// Output the pre order
    fs << "\n";
    symOrd(arvores[0]);//Output the symetric order 
    fs << "\n";

    while (fin.get(ch))
    {
        string ans = WalkTree(arvores[0], "", ch);
        fs << ans;
    }
    fs.close();
}

int main()
{
    fs.open("output.txt", fstream::out | fstream::app);
    getFreq(); // Read the input and take the frequence of all characters
    setTree(); // Create all one-nó-tree from the frequence
    algHuffman(); // Algoritmo de Huffman
    setText(); // Creat a text with the OutPut
}
