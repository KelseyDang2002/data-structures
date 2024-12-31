#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_SIZE 10

// queue class
typedef struct Queue {
    int arr[MAX_SIZE];
    int front; // indicates index to be dequeued
    int rear; // indicates index to be enqueued
} Queue;

// method to initialize queue
void init_queue(Queue *queue) {
    // set front index to -1 which indicates empty queue
    queue->front = -1;
    // rear points to index 0 indicating the start of the array where an element gets enqueued
    queue->rear = 0;
}

/*
method to check if queue is empty

Is empty:
    Time Complexity: O(1)
    Space Complexity: O(1)
    It only checks the position stored in the first and last pointer.
    No extra space is required to check the value of the first and last pointer.
*/
bool is_empty(Queue *queue) {
    // indicates front has been reached before rear, which all elements have been dequeued
    return (queue->front == queue->rear - 1);
}

/*
method to check is queue is full

Is full:
    Time Complexity: O(1)
    Space Complexity: O(1)
    It only performs an arithmetic operation to check if the queue is full or not.
    It requires no extra space.
*/
bool is_full(Queue *queue) {
    /*
    rear points to index for next element to be inserted
    as elements are added, rear increments
    when rear reaches MAX_SIZE - 1, it means the array has no more space to enqueue
    */
    return (queue->rear == MAX_SIZE - 1);
}

/*
method to display current queue
*/
void display_queue(Queue *queue) {
    // check if queue is empty
    if (is_empty(queue)) {
        printf("\nQueue is empty.\n");
        return;
    }

    /*
    print element from front of queue up to but not including rear of queue
    index of first element = queue->front + 1
    elements are stored between front + 1 and rear - 1 (inclusive)
    */
    printf("\nCurrent Queue (%d):", MAX_SIZE - (queue->front + 2)); // +2 since front pointer started at -1
    printf("\n(front) ");
    for (int i = queue->front + 1; i < queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("(rear)\n");
}

/*
method to insert element to queue

Enqueue:
    Time Complexity: O(1)
    Space Complexity: O(1)
    A single element is inserted at the last position. This takes a single memory
    allocation operation which is done in constant time. No extra space is being used.
*/
void enqueue(Queue *queue, int value) {
    // check if queue is full
    if (is_full(queue)) {
        printf("\nQueue is full, can't enqueue %d.\n", value);
        return;
    }

    /*
    assigns new value to the position at the rear of the queue
    queue->arr is the structure and queue-rear is the index of the rear
    */
    queue->arr[queue->rear] = value;
    queue->rear++; // moves rear pointer up one after the insertion
    printf("\nPushed %d to the rear of queue.\n", value);
}

/*
method to remove element from queue

Dequeue:
    Time Complexity: O(1)
    Space Complexity: O(1)
    In array implementation, only an arithmetic operation is performed i.e., the
    front pointer is incremented by 1. This is a constant time function. No extra
    space is utilized for deleting an element from the queue.
*/
void dequeue(Queue *queue) {
    // check is queue is empty
    if (is_empty(queue)) {
        printf("\nQueue is empty, can't dequeue.\n");
        return;
    }

    // moves front pointer to the next element in the queue
    queue->front++;
    printf("\nDequeue.\n");
}

/*
method to return element at front of queue

Peek:
    Time Complexity: O(1)
    Space Complexity: O(1)
    In this operation, only a memory address is accessed. This is a constant time operation.
    No extra space is utilized to access the first value.
*/
int peek(Queue *queue) {
    // if queue is empty
    if (is_empty(queue)) {
        printf("\nQueue is empty.\n");
        return -1;
    }

    // get element at the front of the queue without modifying the queue
    return printf("\nFront of queue : %d\n", queue->arr[queue->front + 1]);
}

// main
int main(int argc, char* argv[]) {
    Queue queue;
    init_queue(&queue);
    display_queue(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 40);
    enqueue(&queue, 80);
    enqueue(&queue, 160);
    enqueue(&queue, 320);
    enqueue(&queue, 640);
    enqueue(&queue, 1280);
    enqueue(&queue, 2560);
    
    display_queue(&queue);
    
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    display_queue(&queue);

    peek(&queue);

    return 0;
}
