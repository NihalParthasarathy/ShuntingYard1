//Nihal Parthasarathy
//2/28/2022
//This program use stacks and queues to translate infix equations to postfix then uses a bindary tree to translate that to prefix, postfix, and infix form

//Inclusions
#include <cstring>
#include <iostream>

using namespace std;

//Queue struct
struct Queue {
  //Initilizes varubles
  Queue* next;
  Queue* prev;
  char value;

};
