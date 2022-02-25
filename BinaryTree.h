#include <iostream>
#include <cstring>

class BinaryTree {
 public:
  BinaryTree* getRight();
  BinaryTree* getLeft();
  BinaryTree* getNext();
  void setNext(BinaryTree* newnext);
  BinaryTree(char newvalue);
  void setRight(BinaryTree* newright);
  void setLeft(BinaryTree* newleft);
  ~BinaryTree();
  
  char value;
  BinaryTree* right;
  BinaryTree* left;
  BinaryTree* next;
  
};
