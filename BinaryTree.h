#include <iostream>
#include <cstring>

class BinaryTree {
 public:
  BinaryTree* getNext();
  BinaryTree();
  void setNext(BinaryTree*);
  ~BinaryTree();
  char value;
  BindaryTree* right;
  BinaryTree* left;
  
};
