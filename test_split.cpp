/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
    if ( argc <= 1) {
        cout << "please provide a linked list." << endl;
        return 1;
    }

    // creating linked list
    Node* head = new Node(atoi(argv[1]), nullptr);
    // cout << "1 node created." << endl;
    Node* temp = head;
    for ( int i = 2; i < argc; i++) {
        temp->next = new Node(atoi(argv[i]), nullptr);
        // cout << "1 node created." << endl;
        temp = temp->next;
    }

    // temp = head;
    // for (int i=0; i < argc-1; i++) {
    //     cout << temp->value << " ";
    //     temp = temp->next;
    // }
    // cout << endl;

    Node* odds;
    Node* evens;
    split(head, odds, evens);


    temp = evens;
    while(temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = odds;
    while(temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    // deallocate process
    temp = odds;
    while(temp != nullptr) {
        Node* del = temp->next;
        delete temp;
        temp = del;
    }
    temp = evens;
    while(temp != nullptr) {
        Node* del = temp->next;
        delete temp;
        temp = del;
    }



    return 0;
}
