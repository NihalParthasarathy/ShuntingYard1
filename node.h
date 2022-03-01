//Nihal Parthasarathy
//2/28/2022
//This program use stacks and queues to translate infix equations to postfix then uses a bindary tree to translate that to prefix, postfix, and infix form

//Imports
#include <iostream>
#include <cstring>

using namespace std;

//Makes the node struct
struct Node {
  //Initilizes struct varubles
  Node* next;
  Node* prev;
  char value;
};
