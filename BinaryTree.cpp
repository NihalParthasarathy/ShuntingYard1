#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree* BinaryTree::getLeft() {
  return left;
}
BinaryTree* BinaryTree::getRight() {
  return right;
}
BinaryTree::BinaryTree(char newvalue) {
  right = NULL;
  left = NULL;
  value = newvalue;
  next = NULL;
}
void BinaryTree::setRight(BinaryTree* newright) {
  right = newright;
}
void BinaryTree::setLeft(BinaryTree* newleft) {
  left = newleft;
}
BinaryTree::~BinaryTree() {
  
}
void BinaryTree::setNext(BinaryTree* newnext) {
  next = newnext;
}
BinaryTree* BinaryTree::getNext() {
  return next;
}
