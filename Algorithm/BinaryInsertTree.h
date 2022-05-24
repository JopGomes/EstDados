#ifndef Insert
#define Insert
#define Search
class Arvore
{
    no *pt;
public:
    Arvore(no *root) { pt = root; }
    int binarySearch(int x, no **pt)
    {
        if (!*pt)
            return 0
        else if (x == *pt->key)
        {
            return 1
        }
        else if (x < *pt->key)
        {
            if (*pt->lf)
                binarySearch(x, *pt->lf, f);
            else
                return 2;
        }
        else if (x > *pt->key)
        {
            if (*pt->rt)
                binarySearch(x, pt->rt, f);
            else
                return 3;
        }
    }
    void binaryInsert(int x, no *pt=pt)
    {
        int k=binarySearch(x,&pt);
        if(k==0)return;
        else{
            no* pt1=new no;
            pt1.chave=x;
            pt1.lf=NULL;
            pt1.rt=NULL;
            if(k==1) pt=pt1;
            else if(k==2){
                pt->lf = pt1;
            }
            else {pt->rt=pt1;}
        }
    }
};
#endif