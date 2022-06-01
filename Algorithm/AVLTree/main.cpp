#include "AVLTree.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    AVL p;
    p.insert(100);
    p.printBalance(p.getRoot());
    cout << "\n";
    p.insert(150);
    p.printBalance(p.getRoot());
    cout << "\n";
    p.insert(50);
    p.printBalance(p.getRoot());
    cout << "\n";
    p.insert(20);
    p.printBalance(p.getRoot());
    cout << "\n";
    p.insert(70);
    p.printBalance(p.getRoot());
    cout << "\n";
    p.insert(60);
    p.printBalance(p.getRoot());
    cout << "\n";
    cout << "\n";
    p.print("", p.getRoot(),false);
    cout << "\n";
    return 0;
}