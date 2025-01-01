#include <stdio.h>
#include <stdlib.h>

// define structure of node
typedef struct Node {
    int data; // data cell
    struct Node* next; // pointer to next node
} Node;

// method to create node
struct Node* createNode(int data);

// method to display current linked list
void display_linked_list();

/*
method to insert element at first position
*/
void insertAtFirst();

/*
method to insert element at end position
*/
void insertAtEnd();

/*
method to insert element at specific position
*/
void insertAtPosition();

/*
method to delete element at first position
*/
void deleteAtFirst();

/*
method to delete element at end position
*/
void deleteAtEnd();

/*
method to delete element at specific position
*/
void deleteAtPosition();

// main
int main(int argc, char* argv[]) {

    return 0;
}
