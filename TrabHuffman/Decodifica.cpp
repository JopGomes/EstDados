#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
  char value;
  Node *pRight,*pLeft;
  Node(char value):
    value(value), pLeft(NULL), pRight(NULL) {
  }
  Node(const Node &n):
    value(n.value), pLeft(n.pLeft), pRight(n.pRight) {
  }

  bool operator==(Node &n) {
    return value == n.value;
  }
};

void decode(Node *n, ifstream &ifs) {

  Node *aux = n ;
  char c;

  do {
    ifs.get(c);
    if(ifs.eof()) {return;}
    if(c == '0') {
      aux = aux->pLeft;
      if(aux->pLeft == NULL && aux->pRight == NULL) {
        cout << aux->value;
        aux = n;
      }
    }
    else {
      aux = aux->pRight;
      if(aux->pLeft == NULL && aux->pRight == NULL) {
        cout << aux->value;
        aux =n;
      }
    }
  } while(true);
}


Node* retrieveTree(vector<Node> &preorder, vector<Node> &inorder, int pr_begin, int pr_end, int in_begin, int in_end) {
  int index = in_begin, leftSize = 0, rightSize=0;

  //Handle the trivial case
  if(in_begin == in_end) {
    return &preorder[pr_begin];
  }
  
  Node aux = preorder[pr_begin];

  // Search the first element of PREORDER in INORDER
  for( ; index<=in_end ; index++) {
    if(inorder[index] == aux) break;
  }
  leftSize = index - in_begin;
  rightSize = in_end - index;
  
  // Find the root of the left subtree
  if(leftSize>0)
    preorder[pr_begin].pLeft = retrieveTree(preorder, inorder, pr_begin + 1, pr_begin + leftSize, in_begin, index - 1);
  
  // Find the root of the right subtree
  if(rightSize>0)
    preorder[pr_begin].pRight = retrieveTree(preorder, inorder, pr_begin + leftSize + 1, pr_end, index + 1, in_end);
  
  return &preorder[pr_begin];
}

int main() {

  ifstream ifs("output.txt", ios::in);
  char c;

  vector<Node> preorder;
  vector<Node> inorder;

  //Collecting the preorder traversal
  do {
    ifs.get(c);
    preorder.push_back(Node(c));
  } while(c != '\n');

  do {
    ifs.get(c);
    if(c == '\n') break;
    preorder.push_back(Node(c));
  } while(c != '\n');

  //Collecting the inorder traversal
  do {
    ifs.get(c);
    inorder.push_back(Node(c));
  } while(c != '\n');

  do {
    ifs.get(c);
    if(c == '\n') break;
    inorder.push_back(Node(c));
  } while(c != '\n');

  Node *pRoot;

  pRoot = retrieveTree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
  decode(pRoot, ifs);
  
  ifs.close();

  return 0;
}