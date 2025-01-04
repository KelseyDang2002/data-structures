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
    This is a constant-time operation as it only involves updating a single pointer.
    No additional memory s required for this operation.
*/
void deleteAtFirst(struct Node** head) {
    // if list is empty
    if (*head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    // create a temp pointer to to store the address of the current head node
    printf("\nDeleting first node.\n");
    struct Node* temp = *head;
    *head = temp->next; // update the head pointer to point to the second node in the linked list
    free(temp); // free the memory allocated by the original head node
}

/*
method to delete element at end position

deleteAtEnd:
    Time Complexity: O(n)
    Space Complexity: O(1)
    Deleting the last node requires traversing through the entrire list to find the second
    to last node which takes linear time.
    No additional memory is required for this operation.
*/
void deleteAtEnd(struct Node** head) {
    // if list is empty
    if (*head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDeleting end node.\n");
    struct Node* temp = *head;

    // if there is only one node in the linked list (first node)
    if (temp->next == NULL) {
        free(temp); // free the memory allocated for that single node
        *head = NULL; // make the list empty
        return;
    }

    /*
    traverse thtough the linked list to find the second to last node whose next
    pointer points to the last node
    */ 
    while(temp->next->next != NULL) {
        temp = temp->next; // move temp pointer to the next node
    }
    free(temp->next); // free the memory of the last node
    // set the next pointer of the second to last node (temp) to NULL, making it the new last node
    temp->next = NULL; 
}

/*
method to delete element at specific position

deleteAtPosition:
    Time Complexity: O(n)
    Space Complexity: O(1)
    Deleting a node at a specific position requires traversing through the list to find the
    specified node, which takes linear time.
    No additional memory is required for this operation.
*/
void deleteAtPosition(struct Node** head, int position) {
    // if list is empty
    if (*head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDeleting node at index %d.\n", position);
    struct Node* temp = *head;

    // if there is only one node in the linked list
    if (position == 0) {
        deleteAtFirst(head);
        return;
    }

    /*
    traverse linked list to find the node just before the target position
    the loop stops when temp becomes NULL (end of list) or when i == position-1
    which indicates temp now points to the node just before the target position
    the insertion needs to link the new node to the node at position, so we stop
    traversal at position-1
    */
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next; // move temp pointer to the next node
    }

    /*
    if position is out of range
    temp becomes NULL when the loop has traversed the entire list and the position-1 does not exist
    this happens when the position is greater than the size of the linked list
    if temp->next == NULL, then temp points to a valid node but its next pointer is NULL itself
    */
    if (temp == NULL || temp->next == NULL) {
        printf("\nPosition is out of range.\n");
        return;
    }
    
    /*
    temp->next points to the node to be deleted
    temp->next->next refers to the node following the one being deleted
    next is used to temporarily store this node so that the link can be re-established later
    */ 
    struct Node* next = temp->next->next;
    // free the memory of the node pointed to by temp->next (the node being deleted)
    free(temp->next);
    temp->next = next; // redirect the next pointer of temp node to skip over the deleted node
}

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

    insertAtPosition(&head, 90, 3);
    display_linked_list(head);

    deleteAtFirst(&head);
    display_linked_list(head);

    deleteAtEnd(&head);
    display_linked_list(head);

    deleteAtPosition(&head, 1);
    display_linked_list(head);

    return 0;
}
