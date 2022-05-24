// f =0 => empty tree
// f>1 => x not in S
// f=1 x in S
#ifndef Search
#define Search
class Arvore
{
    no *pt;
public:
    Arvore(no *root) { pt = root; }
    void binarySearch(int x, no *pt, int *f)
    {
        if (!pt)
            *f = 0;
        else if (x == pt->key)
        {
            *f = 1;
        }
        else if (x < pt->key)
        {
            if (pt->lf)
                binarySearch(x, pt->lf, f);
            else
                *f = 2;
        }
        else if (x > pt->key)
        {
            if (pt->rt)
                binarySearch(x, pt->rt, f);
            else
                *f = 3;
        }
    }
};
#endif