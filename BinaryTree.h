//Nihal Parthasarathy
//2/28/2022
//This program use stacks and queues to translate infix equations to postfix then uses a bindary tree to translate that to prefix, postfix, and infix form


#include <iostream>
#include <cstring>

class BinaryTree {//Class
 public:
  //Function Prototypes
  BinaryTree* getRight();
  BinaryTree* getLeft();
  BinaryTree* getNext();
  void setNext(BinaryTree* newnext);
  BinaryTree(char newvalue);
  void setRight(BinaryTree* newright);
  void setLeft(BinaryTree* newleft);
  ~BinaryTree();

  //Varubles
  char value;
  BinaryTree* right;
  BinaryTree* left;
  BinaryTree* next;
  
};
