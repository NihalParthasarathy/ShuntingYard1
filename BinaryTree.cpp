//Inclusions
#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree* BinaryTree::getLeft() {//returns left
  return left;
}
BinaryTree* BinaryTree::getRight() {//Returns right
  return right;
}
BinaryTree::BinaryTree(char newvalue) {//Constructer
  //Sets next, left, and right to null
  right = NULL;
  left = NULL;
  value = newvalue;
  next = NULL;
}
void BinaryTree::setRight(BinaryTree* newright) {//Sets right
  right = newright;
}
void BinaryTree::setLeft(BinaryTree* newleft) {//Sets left
  left = newleft;
}
BinaryTree::~BinaryTree() {//Destructor
  
}
void BinaryTree::setNext(BinaryTree* newnext) {//Sets next
  next = newnext;
}
BinaryTree* BinaryTree::getNext() {//Returns next
  return next;
}
