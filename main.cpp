#include "node.h"
#include "quee.h"
#include "BinaryTree.h"
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

void push(Node* &head, char value);
char peek(Node* top);
void pop(Node* &head);
void enqueue(Queue* &front, Queue* &tail, char value);
void dequeue(Queue* &front, Queue* &tail);
void printQueue(Queue* top);
char peekQueue(Queue* top);
void createTree();
void binaryPush(BinaryTree* &binaryHead, BinaryTree* &current);
char binaryPeek(BinaryTree* top);
void binaryPop(BinaryTree* &binaryHead, BinaryTree* &current);
void printTree(BinaryTree* binaryHead);

int main() {
  Node* head = NULL;
  Queue* front = NULL;
  Queue* tail = NULL;
  BinaryTree* binaryHead = NULL;
  char input[200];
  cout << "enter in your equation" << endl;
  cin.getline(input, 200);
  char tempArray[200];
  int count = 0;
  
  for (int i = 0; i <strlen(input); i++) {
    if (input[i] != ' ') {
      tempArray[count] = input[i];
      count++;
    }
  }
  
  for (int i = 0; i <strlen(input); i++) {
    input[i] = tempArray[i];
  }
  
  for (int i = 0; i < strlen(input); i++) {
    if (isdigit(input[i])) {
	cout << "it is a digit" << endl;
	char a = input[i];
	enqueue(front, tail, a);
	printQueue(front);
    }
    else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '(' || input[i] == '^') {
      cout << "Is an operation" << endl;
      char a = input[i];
      push(head, a);
      cout << peek(head) << endl;
    }
    else if (input[i] == ')') {
      cout << "Is a right parenthsis" << endl;
      char data;
      while (head->value != '(') {
	data = peek(head);
	pop(head);
	cout << data << endl;
	enqueue(front, tail, data);
      }
      pop(head);
    }
  }
  while (head != NULL) {
    char data;
    data = peek(head);
    pop(head);
    enqueue(front, tail, data);
  }
  printQueue(front);
  

  cout << "Now making binary Tree" << endl;
  /*char a = peekQueue(front);
  cout << a << endl;
  dequeue(front, tail);
  printQueue(front);
  a = peekQueue(front);
  cout << a << endl;*/
  while (front != NULL) {
    char a = peekQueue(front);
    dequeue(front, tail);
    if (isdigit(a)) {
      //cout << a << endl;
      BinaryTree* newNode = new BinaryTree(a);
      binaryPush(binaryHead, newNode);
      char t = binaryPeek(binaryHead);
      //cout << t;
    }
    else {
      BinaryTree* newNode = new BinaryTree(a);
      BinaryTree* temp = NULL;
      binaryPop(binaryHead, temp);
      newNode->setRight(temp);
      binaryPop(binaryHead, temp);
      newNode->setLeft(temp);
      binaryPush(binaryHead, newNode);
      
    }
  }
  //printTree(binaryHead);
}

void push(Node* &head, char value) {
  Node* temp = new Node();
  temp->value = value;
  temp->next = head;
  head = temp;
}

void pop(Node* &head) {
  if (head == NULL) {
    cout << "Nothing to pop" << endl;
  }
  else {
    Node* temp;
    temp = head;
    head = temp->next;
    free(temp);
  }
}

char peek(Node* top) {
  if (top == NULL) {
    cout << "Nothng in stack" << endl;
  }
  else {
    return top->value;
  }
}

void enqueue(Queue* &front, Queue* &tail, char value) {
  Queue* temp = new Queue();
  temp->value = value;
  temp->next = NULL;
  if (front == NULL) {
    front = temp;
    tail = front;
  }
  else {
    tail->next = temp;
    tail = temp;
  }
}

void dequeue(Queue* &front, Queue* &tail) {
  if (front == NULL) {
    cout << "Queueu Empty" << endl;
    return;
  }
  if (front == tail) {
    free(front);
    front = tail = NULL;
  }
  else {
    Queue* temp = front;
    front = front->next;
    free(temp);
  }
}

void printQueue(Queue* top) {
  Queue* curr = top;
  while (curr != NULL) {
    cout << curr->value << " ";
    curr = curr->next;
  }
  cout << endl;
}

char peekQueue(Queue* top) {
  return top->value;
}

void binaryPop(BinaryTree* &binaryHead, BinaryTree* &current) {
   current = binaryHead;
   binaryHead = binaryHead->next;
}

void binaryPush(BinaryTree* &binaryHead, BinaryTree* &current) {
  BinaryTree* temp = current;
  temp->next = binaryHead;
  binaryHead = temp;
}

char binaryPeek(BinaryTree* head) {
  return head->value;
}

void createTree() {
  
}

void printTree(BinaryTree* binaryHead) {
  BinaryTree* temp = binaryHead;
  while (temp != NULL) {
    cout << "top:" << endl;
    cout << temp->value << endl;

    cout << "Left: " << temp->getLeft()->value << " " << "Right " << temp->getRight()->value << endl;
    
    if (isdigit(temp->getLeft()->value)) {
      temp = temp->getRight();
    }
    else if (isdigit(temp->getRight()->value)) {
      temp = temp->getLeft();
    }
    
    /*if (temp->left == NULL) {
      break;
    }
    else {
      cout << "Left: " << temp->getLeft()->value << " " << "Right " << temp->getRight()->value << endl;
      temp = temp->getRight();
      }*/
  }

}
