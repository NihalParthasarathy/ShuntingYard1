#include "node.h"
#include "stack.h"
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;


int main() {
  Node* head = NULL;
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
    }
    else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '(' || input[i] == ')') {
      cout << "Is an operation" << endl;
      char tChar = input[i];
      
    }
  }
}

void push(Node* &head, char a) {
  Node* temp = new Node();
  //temp->
}
