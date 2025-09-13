/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

// terminate condition
  if ( in == nullptr ) {
    odds = nullptr;
    evens = nullptr;
    return;
  }

  Node* current = in;
  in = nullptr; // clean the original list

  // even
  if ( current->value % 2 == 0 ) {
    // cout << "even again" << endl;
    evens = current;
    // cout << "add " << in->value << " to even" << endl;
    split(current->next, odds, evens->next);

  // odd
  } else {
    odds = current;
    split(current->next, odds->next, evens);
  }

}

/* If you needed a helper function, write it here */
