#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// stack class
typedef struct Stack {
    int arr[MAX_SIZE]; // array to store stack elements
    int top; // keep track of index of element on top of stack
} Stack;

// method to create empty stack (initialize)
void init_stack(Stack *stack) {
    stack->top = -1; // set top index to -1 which indicates empty stack
}

/*
method to check if stack is empty

Stack is empty or not:
    Time Complexity: O(1)
    Space Complexity: O(1)
    It only performs an arithmetic operation to check if the stack is empty or not.
    It requires no extra space.
*/
bool is_empty(Stack *stack) {
    return stack->top == -1; // if top index is -1, then stack is empty
}

/*
method to check is stack is full

Stack is full or not:
    Time Complexity: O(1)
    Space Complexity: O(1)
    It only performs an arithmetic operation to check if the stack is full or not.
    It requires no extra space.
*/
bool is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1; // if top index is MAX_SIZE - 1, then stack is full
}

/*
method to display current stack

Current size of the stack:
    Time Complexity: O(1)
    Space Complexity: O(1)
    This operation just performs a basic operation.
    No extra space is required to calculate the value of the top pointer.
*/
void display_stack(Stack *stack) {
    // if stack is empty
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    
    // print element from top to bottom
    printf("\nStack (%d):\n", (stack->top) + 1); // size of stack
    for (int i = stack->top; i >= 0; i--) {
        printf("\t%d\n", stack->arr[i]);
    }
}

/*
method to push element to top of stack 

Push element on top of stack:
    Time Complexity: O(1)
    Space Complexity: O(1)
    In the push function a single element is inserted at the last position. This takes a
    single memory allocation operation which is done in constant time. Space complexity is
    constant as no extra space is being used.
*/
void push(Stack *stack, int value) {
    // check if stack is full before pushing element
    if (is_full(stack)) {
        printf("\nStack overflow, can't push %d.\n", value);
        return;
    }

    // increment top and add new value to top of stack
    stack->arr[++stack->top] = value;
    printf("\nPushed %d to top of stack.\n", value);
}

/*
method to pop element from top of stack

Pop element from top of stack:
    Time Complexity: O(1)
    Space Complexity: O(1)
    In array implementation, only an arithmetic operation is performed i.e., the top pointer
    is decremented by 1. This is a constant time function. No extra space is utilized for
    deleting an element from the stack.
*/
int pop(Stack *stack) {
    // check if stack is empty
    if (is_empty(stack)) {
        printf("\nStack underflow, can't pop.\n");
        return -1;
    }

    int popped = stack->arr[stack->top]; // return top element
    stack->top--; // decrement top pointer
    printf("\nPopped %d from the stack.\n", popped);
    return popped;
}

/*
method to return topmost element from stack 

Peek the topmost element of the stack:
    Time Complexity: O(1)
    Space Complexity: O(1)
    Only a memory address is accessed. This is a constant time operation.
    No extra space is utilized to access the value.
*/
int peek(Stack *stack) {
    // if stack is empty
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    
    // return top element of stack without removing it
    return printf("\nTop of stack: %d\n", stack->arr[stack->top]);
}

int main(int argc, char* argv[]) {
    Stack stack;
    init_stack(&stack);
    display_stack(&stack);
    
    push(&stack, 2);
    display_stack(&stack);

    push(&stack, 4);
    display_stack(&stack);

    push(&stack, 8);
    display_stack(&stack);
    
    push(&stack, 16);
    display_stack(&stack);

    push(&stack, 32);
    display_stack(&stack);

    push(&stack, 64);
    display_stack(&stack);

    push(&stack, 128);
    display_stack(&stack);

    push(&stack, 256);
    display_stack(&stack);

    push(&stack, 512);
    display_stack(&stack);

    push(&stack, 1024);
    display_stack(&stack);

    push(&stack, 2048);
    display_stack(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    display_stack(&stack);

    peek(&stack);

    return 0;
}
