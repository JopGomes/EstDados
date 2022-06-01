#ifndef Insert
#define Insert
#define Search
#include <string>
#include <iostream>
struct no
{
    int key;
    struct no *lf;
    struct no *rt;
};
class Arvore
{
    no *pt;

public:
    Arvore(no *root) { pt = root; }
    int binarySearch(int x, no **pt)
    {
        if (!*pt)
            return 0;
        else if (x == (*pt)->key)
        {
            return 1;
        }
        else if (x < (*pt)->key)
        {
            if ((*pt)->lf)
                binarySearch(x, &((*pt)->lf));
            else
                return 2;
        }
        else if (x > (*pt)->key)
        {
            if ((*pt)->rt)
                binarySearch(x, &((*pt)->rt));
            else
                return 3;
        }
    }
    void binaryInsert(int x)
    {
        binaryInsert(x, pt);
    }
    void binaryInsert(int x, no *pt)
    {
        int k = binarySearch(x, &pt);
        if (k == 0)
            return;
        else
        {
            no *pt1 = new no;
            pt1->key = x;
            pt1->lf = NULL;
            pt1->rt = NULL;
            if (k == 1)
                pt = pt1;
            else if (k == 2)
            {
                pt->lf = pt1;
            }
            else
            {
                pt->rt = pt1;
            }
        }
    }
    void printTree(const std::string &prefix, const no *root, bool isLeft)
    {
        if (root != nullptr && root->key != 0)
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├── " : "└── ");
            std::cout << root->key << std::endl;
            printTree(prefix + (isLeft ? "│   " : "    "), root->lf, true);
            printTree(prefix + (isLeft ? "│   " : "    "), root->rt, false);
        }
        else
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├── " : "└── ");
            std::cout << "*" << std::endl;
        }
    }
};
#endif