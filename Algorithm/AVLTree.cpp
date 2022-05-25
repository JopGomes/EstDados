#include <stdio.h>

struct no
{
    int key;
    int balance;
    struct no *lf;
    struct no *rt;
}

void rightRotation(struct no **u)
{
    struct no *v = *u->lf;
    struct no *w = v->rt;
    if (v->balance == -1){ // Simple Rotation
        (*u)->lf=v->dir;//Rotation with v and u;
        v->rt = *u;
        (*u)->bal=0;// Change the balance to 0
        v->val=0;
        *u=v;// Change the point of the root
    }
    else {// Couple rotation
        if(w->balance == 1 ){
            *u->balance =0;
            v->balance = -1;
            w->balance=0;
        }
        else{
            *u->balance=1;
            v->balance=0;
            w->balance=0;
        }
        v->rt = w->lf;
        (*u)->lf=w->rt;
        w->lf= v;
        w->rt =*u;
        *u=v;
    }
}

void leftRotation(struct no** u){
    struct no* k= (*u)->rt;
    struct no *m =k->lf;
    if()//Simple Rotation
    {

    }
}

int main()
{

    return 0;
}