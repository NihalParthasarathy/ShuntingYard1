#include <iostream>
#include <cstring>

class BinaryTree {
 public:
  BinaryTree* getRight();
  BinaryTree* getLeft();
  BinaryTree(char newvalue);
  void setRight(BinaryTree* newright);
  void setLeft(BinaryTree* newleft);
  ~BinaryTree();
  
  char value;
  BinaryTree* right;
  BinaryTree* left;
  
};
