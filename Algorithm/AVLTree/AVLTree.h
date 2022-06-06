#ifndef AVLTree
#define AVLTree
#define no
#include <stdio.h>
#include <iostream>
#include <string>

struct no
{
    int key;
    int balance;
    struct no *lf;
    struct no *rt;
};

class AVL
{
    no *root;

public:
    AVL() { root = NULL; }
    ~AVL() { delete root; }
    no *getRoot() { return root; }
    void rightRotation(struct no **u)
    {
        struct no *v = (*u)->lf;
        struct no *w = v->rt;
        if (v->balance == -1)
        {                     // Simple Rotation
            (*u)->lf = v->rt; // Rotation with v and u;
            v->rt = *u;
            (*u)->balance = 0; // Change the balance to 0
            v->balance = 0;
            *u = v; // Change the point of the root
        }
        else
        { // Couple rotation
            if (w->balance == 1)
            {
                (*u)->balance = 0;
                v->balance = -1;
                w->balance = 0;
            }
            else
            {
                (*u)->balance = 1;
                v->balance = 0;
                w->balance = 0;
            }
            v->rt = w->lf;
            (*u)->lf = w->rt;
            w->lf = v;
            w->rt = *u;
            *u = w;
        }
    }

    void leftRotation(struct no **u)
    {
        struct no *k = (*u)->rt;
        struct no *m = k->lf;
        if (k->balance == -1) // Simple Rotation
        {
            (*u)->balance = 0;
            k->balance = 0;
            (*u)->rt = k->lf;
            k->lf = *u;
            *u = k;
        }
        else
        { // Couple Rotation
            if (m->balance == -1)
            {
                (*u)->balance = 0;
                m->balance = 0;
                k->balance = 1;
            }
            else
            {
                (*u)->balance = -1;
                m->balance = 0;
                k->balance = 0;
            }
            (*u)->rt = m->lf;
            k->lf = m->rt;
            m->lf = (*u);
            m->rt = k;
            (*u) = m;
        }
    }
    int insert(int key)
    {
        return insert(key, &root);
    }
    int insert(int key, no **r)
    { // return 1 if height of tree increse
        struct no *aux;
        int increase = 0;
        if (root == NULL)
        {
            root = new no;
            root->balance = 0;
            root->key = key;
            root->lf = NULL;
            root->rt = NULL;
            *r = root;
            return 1;
        }
        else if (*r == NULL)
        {
            (*r) = new no;
            (*r)->balance = 0;
            (*r)->key = key;
            (*r)->lf = NULL;
            (*r)->rt = NULL;
            return 1;
        }
        else
        {
            if ((*r)->key == key)
                return 0;
            else
            {
                if ((*r)->key > key)
                { // insert left
                    increase = insert(key, &((*r)->lf));
                    if (increase == 1)
                    {
                        ((*r)->balance)--;
                    }
                    if ((*r)->balance == 0)
                        return 0;
                    else if ((*r)->balance == -1)
                        return 1;
                    else
                    {
                        rightRotation(r);
                        return 0;
                    }
                }
                else
                { // insert right
                    increase = insert(key, &((*r)->rt));
                    if (increase == 1)
                    {
                        ((*r)->balance)++;
                    }
                    if ((*r)->balance == 1)
                        return 1;
                    else if ((*r)->balance == 0)
                        return 0;
                    else
                    {
                        leftRotation(r);
                        return 0;
                    }
                }
            }
        }
    }
    void printBalance(struct no *r)
    {
        if (r != NULL)
        {
            std::cout << "{" << r->key << "," << r->balance << "}";
            printBalance(r->lf);
            printBalance(r->rt);
        }
    }
    void print(const std::string &prefix, const no *root, bool isLeft)
    {
        if (root != nullptr && root->key != 0)
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├── " : "└── ");
            std::cout << root->key << std::endl;
            print(prefix + (isLeft ? "│   " : "    "), root->lf, true);
            print(prefix + (isLeft ? "│   " : "    "), root->rt, false);
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