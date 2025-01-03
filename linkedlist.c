#include <stdio.h>
#include <stdlib.h>

// define structure of node
typedef struct Node {
    int data; // data cell
    struct Node* next; // pointer to next node
} Node;

// method to create node
struct Node* createNode(int data) {
    /*
    dynamically allocate memory for new node
    struct Node* - declares newNode as a pointer to a Node structure
    (struct Node*) - casts the result of malloc to a pointer of type struct Node
    malloc(sizeof(struct Node)) - allocates enough memory to hold a single Node structure
    sizeof(struct Node) - calculates the size of the Node structure in bytes
    */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // data assigned to data field of newNode
    newNode->data = data;
    // set next pointer of the new node to NULL, indicating that the node does not point to any other node yet
    newNode->next = NULL;
    return newNode;
}

// method to display current linked list, takes in head (starting node) as an argument
void display_linked_list(struct Node* head) {
    /*
    create temp pointer to traverse linked list
    using a temp pointer avoids modifying the original head pointer
    */
    struct Node* temp = head;
    
    // check if linked list is empty
    if (head == NULL) {
        printf("\nLinked list is empty.\n");
        return;
    }
    
    // traverse each node and print data
    printf("\nLinked List:\n\tHEAD -> ");
    while (temp != NULL) { // until reach the end (when a node points to NULL)
        printf("%d -> ", temp->data);
        temp = temp->next; // advance the pointer to next node in the linked list
    }
    printf("NULL\n");
}

/*
method to insert element at first position

insertAtFirst:
    Time Complexity: O(1)
    Space Complexity: O(1)
    Operation involves only a few pointer manipulations, which take constant time
    regardless of the size of the list. The space required for the operation is constant
    because only one new node is created, and no additional data structures or memory
    proportional to the input size are needed.
*/
void insertAtFirst(struct Node** head, int data) { // pointer to a pointer to head, value
    printf("\nInserting %d at first node.\n", data);

    struct Node* newNode = createNode(data); // create new node with data
    /*
    links the new node to the current first node of the list (if it exists)
    newNode->next - accesses the next pointer of the new node
    *head - dereferences the head pointer to get the address of the current first node in the list
    */
    newNode->next = *head;
    *head = newNode; // set head pointer to the address of the new node
}

/*
method to insert element at end position

insertAtEnd:
    Time Complexity: O(n)
    Space Complexity: O(1)
    Linear time to insert at the end because we need to traverse the entire list to find the last node.
    Only one new node is created, and no extra space proportional to the input size is needed.
*/
void insertAtEnd(struct Node** head, int data) {
    printf("\nInserting %d at end node.\n", data);

    struct Node* newNode = createNode(data); // create new node with data

    // if linked list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head; // temp pointer to traverse linked list

    // keep traversing until the last node is found (temp->next == NULL)
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // set the next pointer to the new node
}

/*
method to insert element at specific position

insertAtPosition:
    Time Complexity: O(n)
    Space Complexity: O(1)
    Linear time because it requires traversing the linked list until the desired position is reached.
    Only one node is created, and no additional memory proportional to the list size is required.
*/
void insertAtPosition(struct Node** head, int data, int position) {
    printf("\nInserting %d at index %d.\n", data, position);

    struct Node* newNode = createNode(data);

    // if position is at the beginning of the linked list
    if (position == 0) {
        insertAtFirst(head, data);
        return;
    }

    struct Node* temp = *head; // temp pointer to traverse linked list

    /*
    traverse linked list to find the node just before the target position
    the loop stops when temp becomes NULL (end of list) or when i == position-1
    which indicates temp now points to the node just before the target position
    the insertion needs to link the new node to the node at position, so we stop
    traversal at position-1
    */
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // if position out of range
    if (temp == NULL) {
        printf("\nPosition out of range.\n");
        free(newNode); // free memory allocated for newNode to avoid a memory leak
        return;
    }
    
    /*
    sets the nex pointer of newNode to point to the node that currently comes after temp
    this ensures that newNode takes the place of the node that was previously at position
    */
   newNode->next = temp->next;
   /*
   sets the next pointer of temp (the node at position - 1) to point to newNode
   the newNode is now inserted between temp and the orginial node at position
   */
   temp->next = newNode;
}

/*
method to delete element at first position

deleteAtFirst:
    Time Complexity: O(1)
    Space Complexity: O(1)
*/
void deleteAtFirst(struct Node** head);

/*
method to delete element at end position

deleteAtEnd:
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
void deleteAtEnd(struct Node** head);

/*
method to delete element at specific position

deleteAtPosition:
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
void deleteAtPosition(struct Node** head, int position);

// main
int main(int argc, char* argv[]) {
    struct Node* head = NULL;
    display_linked_list(head);

    insertAtFirst(&head, 10);
    display_linked_list(head);

    insertAtFirst(&head, 5);
    display_linked_list(head);

    insertAtEnd(&head, 100);
    display_linked_list(head);

    insertAtPosition(&head, 80, 2);
    display_linked_list(head);

    return 0;
}
