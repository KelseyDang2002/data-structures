#include <stdio.h>
#include <stdbool.h>

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
        printf("Queue is empty.\n");
        return;
    }

    /*
    print element from front of queue up to but not including rear of queue
    index of first element = queue->front + 1
    elements are stored between front + 1 and rear - 1 (inclusive)
    */
    printf("\nCurrent Queue (%d):\n", queue->rear);
    for (int i = queue->front + 1; i < queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

/*
method to insert element to queue

Enqueue:
    Time Complexity: O(1)
    Space Complexity: O(1)
*/
void enqueue(Queue *queue, int value) {
    // check if queue is full
    if (is_full) {
        printf("Queue is full, can't enqueue %d.\n", value);
        return;
    }

    // loop
}

/*
method to remove element from queue

Dequeue:
    Time Complexity: O(1)
    Space Complexity: O(1)
*/
void dequeue();

/*
method to return element at front of queue

Peek:
    Time Complexity: O(1)
    Space Complexity: O(1)
*/
int peek();

// main
int main(int argc, char* argv[]) {
    Queue queue;
    init_queue(&queue);
    display_queue(&queue);

    return 0;
}
