//Nihal Parthasarathy
//2/28/2022
//This program use stacks and queues to translate infix equations to postfix then uses a bindary tree to translate that to prefix, postfix, and infix form
//Help from kushal

//Imports and Inclusions
#include "node.h"
#include "quee.h"
#include "BinaryTree.h"
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

//Function prototypes
void push(Node* &head, char value);
char peek(Node* top);
void pop(Node* &head);
void enqueue(Queue* &front, Queue* &tail, char value);
void dequeue(Queue* &front, Queue* &tail);
void printQueue(Queue* top);
char peekQueue(Queue* top);
void binaryPush(BinaryTree* &binaryHead, BinaryTree* &current);
char binaryPeek(BinaryTree* top);
void binaryPop(BinaryTree* &binaryHead, BinaryTree* &current);
void printTree(BinaryTree* binaryHead);
void prefix(BinaryTree* current);
void postfix(BinaryTree* current);
void infix(BinaryTree* current);

int main() {
  //Initilizations of Varubles
  Node* head = NULL;
  Queue* front = NULL;
  Queue* tail = NULL;
  BinaryTree* binaryHead = NULL;
  char input[200];
  
  cout << "enter in your equation" << endl;
  cin.getline(input, 200);
  
  char tempArray[200];
  int count = 0;

  //Makes a temporary array without spaces
  for (int i = 0; i <strlen(input); i++) {
    if (input[i] != ' ') {
      tempArray[count] = input[i];
      count++;
    }
  }

  //Translates the array with no spaces to the original array
  for (int i = 0; i <strlen(input); i++) {
    input[i] = tempArray[i];
  }

  //Translates the infix equation to postfix
  for (int i = 0; i < strlen(input); i++) {
    if (isdigit(input[i])) {//Checks to see if the input is a number
	char a = input[i];
	enqueue(front, tail, a);//Adds the number to queue
	//printQueue(front);
    }
    else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '(' || input[i] == '^') {//Checks to see if the input is an operation thats not a right parenthisis
      char a = input[i];
      push(head, a);//Pushes the operation to the stack
      //cout << peek(head) << endl;
    }
    else if (input[i] == ')') {//Check to see if input is a right parenthisis
      char data;
      while (head->value != '(') {//While the value in the stack is not a left parenthiss
	data = peek(head);
	pop(head);
	//cout << data << endl;
	enqueue(front, tail, data);//Adds the the operation to the queue
      }
      pop(head);//Deletes the left parenthisis
    }
  }
  
  //Adds the remaning operations in the stack to the queue after the for loop is done
  while (head != NULL) {
    char data;
    data = peek(head);
    pop(head);
    enqueue(front, tail, data);
  }
 
  printQueue(front);//Prints the queue
  

  cout << "Now making binary Tree" << endl;

  //Makes the binary Tree
  while (front != NULL) {
    char a = peekQueue(front);
    dequeue(front, tail);//Removes the front from the queue
    if (isdigit(a)) {//Checks if digit
      BinaryTree* newNode = new BinaryTree(a);//Makes a new node
      binaryPush(binaryHead, newNode);
      //char t = binaryPeek(binaryHead);
    }
    else {//If charector is a digit
      
      BinaryTree* newNode = new BinaryTree(a);//Makes new node
      BinaryTree* temp = NULL;
      binaryPop(binaryHead, temp);
      newNode->setRight(temp);//Sets right
      binaryPop(binaryHead, temp);
      newNode->setLeft(temp);//Sets left
      binaryPush(binaryHead, newNode);//Pushes to stack
    }
  }
  
  cout << "prefix: ";
  prefix(binaryHead);
  cout << endl;
  cout << "postfix: ";
  postfix(binaryHead);
  cout << endl;
  cout << "infix: ";
  infix(binaryHead);
}

void push(Node* &head, char value) {//Function to push stack node to the front of the stack
  Node* temp = new Node();
  temp->value = value;
  temp->next = head;
  head = temp;
}

void pop(Node* &head) {//Deletes the Node from the stack
  if (head == NULL) {
    cout << "Nothing to pop" << endl;
  }
  else {
    Node* temp;
    temp = head;
    head = temp->next;//Rerouts pointer
    free(temp);//Deletes the old charector
  }
}

char peek(Node* top) {//Returns the charector at the top of the stack
  if (top == NULL) {
    cout << "Nothng in stack" << endl;
  }
  else {
    return top->value;
  }
}

void enqueue(Queue* &front, Queue* &tail, char value) {//Adds the charector to the queue
  //Initilizes new queue node
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

void dequeue(Queue* &front, Queue* &tail) {//Takes the charector out of the queue
  if (front == NULL) {//Checks if front is null
    cout << "Queueu Empty" << endl;
    return;
  }
  if (front == tail) {//Checks if there is only one element in the queue
    free(front);
    front = tail = NULL;
  }
  else {
    Queue* temp = front;
    front = front->next;
    free(temp);
  }
}

void printQueue(Queue* top) {//Prints out the queue
  Queue* curr = top;
  while (curr != NULL) {
    cout << curr->value << " ";
    curr = curr->next;
  }
  cout << endl;
}

char peekQueue(Queue* top) {//Looks at the front of the queue
  return top->value;
}

void binaryPop(BinaryTree* &binaryHead, BinaryTree* &current) {//Removes the element from the stack
   current = binaryHead;
   binaryHead = binaryHead->next;
}

void binaryPush(BinaryTree* &binaryHead, BinaryTree* &current) {//Adds an element to the stack
  BinaryTree* temp = current;
  temp->next = binaryHead;
  binaryHead = temp;
}

char binaryPeek(BinaryTree* head) {//Looks at the element on top of the stack
  return head->value;
}

//USED TO PROVE TREE WORKS
void printTree(BinaryTree* binaryHead) {//Prints the tree
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
  }
}

void prefix(BinaryTree* current) {//Prints out the prefix equation
  cout << current->value;
  if (current->left != NULL) {
    prefix(current->left);//Recurcive call
  }
  if (current->right != NULL) {
    prefix(current->right);//Recurcive call
  }
}

void postfix(BinaryTree* current) {//Prints out the postfix equation
  if (current->left != NULL) {
    postfix(current->left);//Recurcive call
  }
  if (current->right != NULL) {
    postfix(current->right);//Recurcive call
  }
  cout << current->value;
}

void infix(BinaryTree* current) {//Prints out the infix equation
  if (current->left != NULL) {
    infix(current->left);//recurcive call
  }
  cout << current->value;
  if (current->right != NULL) {
    infix(current->right);//Recurcive call
  }
}
