#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


struct no
{
    int freq;
    char ch;
    struct no *lf;
    struct no *rt;
};



int freq[130];
vector<no> arvores;


void getFreq()
{
    char ch;
    ifstream fin("teste.txt");
    while (fin.get(ch))
    {
        freq[ch - '0']++;
    }
}

bool sortAux(no a, no b)
{
    if (a.freq < b.freq)
        return true;
    else
        return false;
}
void setTree()
{

    for (int i = 0; 130 > i; i++)
    {
        if (freq[i])
        {
            struct no aux;
            int j = i+48;
            char ch = j;
            aux.ch = ch;
            aux.freq = freq[i];
            arvores.push_back(aux);
        }
    }
    sort(arvores.begin(), arvores.end(), sortAux);
    cout << arvores[0].ch;
}


void algHuffman(){
    if(arvores.size()==1) return;
    struct no aux;
    aux.freq=arvores[0].freq+arvores[1].freq;
    aux.lf=arvores[0];
    aux.rt=arvores[1];
    arvores.erase(arvores.begin()+1);
    arvores.push_back(aux);
    sort(arvores.begin(), arvores.end(), sortAux);
    algHuffman();
}


int main()
{
    getFreq();
    setTree();
    algHuffman();
}
