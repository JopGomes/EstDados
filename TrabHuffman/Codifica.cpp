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

int nfreq[130];
vector<no *> arvores;
fstream fs;

void getFreq()
{
    char ch;
    ifstream fin("teste.txt");
    while (fin.get(ch))
    {
        nfreq[ch - '\0']++;
    }
}

bool sortAux(no *a, no *b) // funcao para alterar o tipo de sort.
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
    aux->ch = '+';
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
    if (aux->ch != '+')
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
    if(aux->lf)preOrd(aux->lf);
    if(aux->rt)preOrd(aux->rt);
    fs<< aux ->ch;
}
void symOrd(no* aux)
{  
    if(aux->lf)symOrd(aux->lf);
    if(aux->rt)symOrd(aux->rt);
    fs<< aux ->ch;
    
}



void setText()
{
    char ch;
    ifstream fin("teste.txt");

    // Put the preOrder and the symOrd in the output;
    preOrd(arvores[0]);
    fs << "\n";
    symOrd(arvores[0]);
    fs << "\n";

    while (fin.get(ch))
    {
        string ans = WalkTree(arvores[0], "", ch);
        fs << ans << " ";
    }
    fs.close();
}

int main()
{
    fs.open("output.txt", fstream::out | fstream::app);
    getFreq();
    setTree();
    algHuffman();
    setText();
}
